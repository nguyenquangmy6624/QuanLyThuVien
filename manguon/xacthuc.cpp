#include "xacthuc.h"

#include <algorithm>
#include <cstdint>
#include <fstream>
#ifdef _WIN32
#include <conio.h>
#endif
#include <iostream>
#include <limits>
#include <vector>

namespace {
const char* FILE_TAI_KHOAN = "dulieu/taikhoan.dat";
const uint32_t PHIEN_BAN_FILE = 1;
const char MA_FILE[8] = {'Q','L','T','V','U','S','R','1'};

struct BanGhiTaiKhoan {
    std::string tenDangNhap;
    uint64_t hashMatKhau;
    VaiTro vaiTro;
};

std::string nhapMatKhauAn() {
    std::string password;
#ifdef _WIN32
    while (true) {
        int ch = _getch();
        if (ch == '\r' || ch == '\n') break;
        if (ch == 0 || ch == 224) { (void)_getch(); continue; }
        if (ch == 8) {
            if (!password.empty()) {
                password.erase(password.size() - 1);
                std::cout << "\b \b";
            }
            continue;
        }
        if (ch >= 32 && ch <= 255) {
            password += static_cast<char>(ch);
            std::cout << '*';
        }
    }
    std::cout << '\n';
#else
    std::getline(std::cin, password);
#endif
    return password;
}

bool ghiChuoi(std::ostream& out, const std::string& value) {
    if (value.size() > 1024) return false;
    uint32_t length = static_cast<uint32_t>(value.size());
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    out.write(value.data(), static_cast<std::streamsize>(length));
    return static_cast<bool>(out);
}

bool docChuoi(std::istream& in, std::string& value) {
    uint32_t length = 0;
    in.read(reinterpret_cast<char*>(&length), sizeof(length));
    if (!in || length > 1024) return false;
    value.assign(length, '\0');
    if (length > 0) in.read(&value[0], static_cast<std::streamsize>(length));
    return static_cast<bool>(in);
}

// FNV-1a chi dung cho demo hoc tap; khong phai ham bam mat khau an toan cho san pham that.
uint64_t bamMatKhau(const std::string& username, const std::string& password) {
    const std::string input = "QLTV_DEMO_V1:" + username + ":" + password;
    uint64_t hash = 14695981039346656037ULL;
    for (std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
        hash ^= static_cast<unsigned char>(*it);
        hash *= 1099511628211ULL;
    }
    return hash;
}

bool ghiDanhSachTaiKhoan(const std::vector<BanGhiTaiKhoan>& list) {
    std::ofstream out(FILE_TAI_KHOAN, std::ios::binary | std::ios::trunc);
    if (!out) return false;
    out.write(MA_FILE, sizeof(MA_FILE));
    out.write(reinterpret_cast<const char*>(&PHIEN_BAN_FILE), sizeof(PHIEN_BAN_FILE));
    uint32_t count = static_cast<uint32_t>(list.size());
    out.write(reinterpret_cast<const char*>(&count), sizeof(count));
    for (std::vector<BanGhiTaiKhoan>::const_iterator it = list.begin(); it != list.end(); ++it) {
        uint64_t hash = it->hashMatKhau;
        uint8_t role = static_cast<uint8_t>(it->vaiTro);
        if (!ghiChuoi(out, it->tenDangNhap)) return false;
        out.write(reinterpret_cast<const char*>(&hash), sizeof(hash));
        out.write(reinterpret_cast<const char*>(&role), sizeof(role));
        if (!out) return false;
    }
    return true;
}

bool docDanhSachTaiKhoan(std::vector<BanGhiTaiKhoan>& list) {
    std::ifstream in(FILE_TAI_KHOAN, std::ios::binary);
    if (!in) return false;
    char magic[8] = {};
    uint32_t version = 0;
    uint32_t count = 0;
    in.read(magic, sizeof(magic));
    in.read(reinterpret_cast<char*>(&version), sizeof(version));
    in.read(reinterpret_cast<char*>(&count), sizeof(count));
    if (!in || !std::equal(magic, magic + 8, MA_FILE) || version != PHIEN_BAN_FILE || count > 10000) return false;

    std::vector<BanGhiTaiKhoan> loaded;
    for (uint32_t i = 0; i < count; ++i) {
        BanGhiTaiKhoan item;
        uint8_t role = 0;
        if (!docChuoi(in, item.tenDangNhap)) return false;
        in.read(reinterpret_cast<char*>(&item.hashMatKhau), sizeof(item.hashMatKhau));
        in.read(reinterpret_cast<char*>(&role), sizeof(role));
        if (!in || role < 1 || role > 3) return false;
        item.vaiTro = static_cast<VaiTro>(role);
        loaded.push_back(item);
    }
    list.swap(loaded);
    return true;
}
}

bool khoiTaoTaiKhoanNeuChuaCo(bool& daTaoMoi) {
    daTaoMoi = false;
    std::ifstream exists(FILE_TAI_KHOAN, std::ios::binary);
    if (exists.good()) {
        std::vector<BanGhiTaiKhoan> existing;
        return docDanhSachTaiKhoan(existing);
    }

    std::vector<BanGhiTaiKhoan> defaults;
    BanGhiTaiKhoan admin; admin.tenDangNhap = "admin"; admin.hashMatKhau = bamMatKhau("admin", "Admin123!"); admin.vaiTro = VaiTro::Admin;
    BanGhiTaiKhoan thuThu; thuThu.tenDangNhap = "thuthu"; thuThu.hashMatKhau = bamMatKhau("thuthu", "ThuThu123!"); thuThu.vaiTro = VaiTro::ThuThu;
    BanGhiTaiKhoan docGia; docGia.tenDangNhap = "docgia"; docGia.hashMatKhau = bamMatKhau("docgia", "DocGia123!"); docGia.vaiTro = VaiTro::DocGia;
    defaults.push_back(admin); defaults.push_back(thuThu); defaults.push_back(docGia);
    if (!ghiDanhSachTaiKhoan(defaults)) return false;
    daTaoMoi = true;
    return true;
}

bool dangNhap(TaiKhoanDangNhap& taiKhoanHienTai) {
    std::vector<BanGhiTaiKhoan> accounts;
    if (!docDanhSachTaiKhoan(accounts)) {
        std::cerr << "Loi: khong doc duoc dulieu/taikhoan.dat. File co the hong hoac sai phien ban.\n";
        return false;
    }

    for (int lan = 1; lan <= 3; ++lan) {
        std::string username, password;
        std::cout << "\n========== DANG NHAP HE THONG ==========\n";
        std::cout << "Ten dang nhap: ";
        std::getline(std::cin, username);
        std::cout << "Mat khau: ";
        password = nhapMatKhauAn();

        for (std::vector<BanGhiTaiKhoan>::const_iterator it = accounts.begin(); it != accounts.end(); ++it) {
            if (it->tenDangNhap == username && it->hashMatKhau == bamMatKhau(username, password)) {
                taiKhoanHienTai.tenDangNhap = it->tenDangNhap;
                taiKhoanHienTai.vaiTro = it->vaiTro;
                std::cout << "Dang nhap thanh cong. Xin chao " << username << " (" << tenVaiTro(it->vaiTro) << ").\n";
                return true;
            }
        }
        std::cout << "Sai ten dang nhap hoac mat khau. Con " << (3 - lan) << " lan thu.\n";
    }
    std::cout << "Da vuot qua 3 lan dang nhap. Chuong trinh se dung.\n";
    return false;
}

bool doiMatKhauTaiKhoan(const TaiKhoanDangNhap& taiKhoanHienTai) {
    std::vector<BanGhiTaiKhoan> accounts;
    if (!docDanhSachTaiKhoan(accounts)) {
        std::cout << "Khong doc duoc tep tai khoan.\n";
        return false;
    }

    std::string oldPassword, newPassword, confirmPassword;
    std::cout << "Nhap mat khau hien tai: "; oldPassword = nhapMatKhauAn();
    std::vector<BanGhiTaiKhoan>::iterator found = accounts.end();
    for (std::vector<BanGhiTaiKhoan>::iterator it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->tenDangNhap == taiKhoanHienTai.tenDangNhap) { found = it; break; }
    }
    if (found == accounts.end() || found->hashMatKhau != bamMatKhau(taiKhoanHienTai.tenDangNhap, oldPassword)) {
        std::cout << "Mat khau hien tai khong dung.\n";
        return false;
    }
    std::cout << "Nhap mat khau moi (toi thieu 8 ky tu): "; newPassword = nhapMatKhauAn();
    if (newPassword.size() < 8) {
        std::cout << "Mat khau moi phai co it nhat 8 ky tu.\n";
        return false;
    }
    std::cout << "Nhap lai mat khau moi: "; confirmPassword = nhapMatKhauAn();
    if (newPassword != confirmPassword) {
        std::cout << "Xac nhan mat khau khong khop.\n";
        return false;
    }
    found->hashMatKhau = bamMatKhau(taiKhoanHienTai.tenDangNhap, newPassword);
    if (!ghiDanhSachTaiKhoan(accounts)) {
        std::cout << "Khong luu duoc mat khau moi.\n";
        return false;
    }
    std::cout << "Doi mat khau thanh cong.\n";
    return true;
}
