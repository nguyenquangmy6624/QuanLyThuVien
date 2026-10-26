#include "menu.h"
#include "xacthuc.h"
#include "luutru.h"
#include "xuatcsv.h"

#include <iostream>
#include <string>

namespace {
void hienThiChuaHoanThanh(const char* tenPhan) {
    std::cout << "[CHUA HOAN THANH] Phan " << tenPhan << " se duoc xay dung theo checklist cac tuan tiep theo.\n";
}

bool kiemTraQuyenTruocKhiThucThi(VaiTro vaiTro, ChucNang chucNang) {
    if (!coQuyen(vaiTro, chucNang)) {
        std::cout << "Tu choi truy cap: vai tro " << tenVaiTro(vaiTro) << " khong co quyen cho chuc nang nay.\n";
        return false;
    }
    return true;
}
}

int main() {
    bool daTaoTaiKhoanMoi = false;
    std::string loiDuLieu;
    bool daTaoDuLieuMau = false;
    if (!khoiTaoDuLieuMauNeuChuaCo(daTaoDuLieuMau, loiDuLieu)) {
        std::cerr << "Khong khoi tao duoc du lieu sach/doc gia: " << loiDuLieu << "\n";
        return 1;
    }
    if (daTaoDuLieuMau) {
        std::cout << "Da tao du lieu sach/doc gia mau trong dulieu/*.dat.\n";
    }

    if (!khoiTaoTaiKhoanNeuChuaCo(daTaoTaiKhoanMoi)) {
        std::cerr << "Khong khoi tao/doc duoc tai khoan trong dulieu/taikhoan.dat.\n";
        return 1;
    }
    if (daTaoTaiKhoanMoi) {
        std::cout << "Da tao tai khoan demo lan dau (hay doi mat khau sau khi dang nhap):\n"
                  << "  admin / Admin123! (Admin)\n"
                  << "  thuthu / ThuThu123! (Thu thu)\n"
                  << "  docgia / DocGia123! (Doc gia)\n";
    }

    bool dangChay = true;
    while (dangChay) {
        TaiKhoanDangNhap taiKhoan;
        if (!dangNhap(taiKhoan)) return 0;
        bool dangTrongPhien = true;

        while (dangChay && dangTrongPhien) {
            const int luaChon = showMainMenu(taiKhoan.vaiTro);
            switch (luaChon) {
                case 1:
                    if (kiemTraQuyenTruocKhiThucThi(taiKhoan.vaiTro, ChucNang::QuanLySach)) hienThiChuaHoanThanh("quan ly sach");
                    break;
                case 2:
                    if (kiemTraQuyenTruocKhiThucThi(taiKhoan.vaiTro, ChucNang::QuanLyDocGia)) hienThiChuaHoanThanh("quan ly doc gia");
                    break;
                case 3:
                    if (kiemTraQuyenTruocKhiThucThi(taiKhoan.vaiTro, ChucNang::MuonTra)) hienThiChuaHoanThanh("muon - tra sach");
                    break;
                case 4:
                    if (kiemTraQuyenTruocKhiThucThi(taiKhoan.vaiTro, ChucNang::ThongKe)) hienThiChuaHoanThanh("thong ke - bao cao");
                    break;
                case 5:
                    if (kiemTraQuyenTruocKhiThucThi(taiKhoan.vaiTro, ChucNang::TimKiem)) hienThiChuaHoanThanh("tim kiem sach");
                    break;
                case 6:
                    if (kiemTraQuyenTruocKhiThucThi(taiKhoan.vaiTro, ChucNang::LuuTru)) hienThiChuaHoanThanh("luu tru va sao luu");
                    break;
                case 7:
                    if (kiemTraQuyenTruocKhiThucThi(taiKhoan.vaiTro, ChucNang::XuatCSV)) menuXuatCSV();
                    break;
                case 8:
                    doiMatKhauTaiKhoan(taiKhoan);
                    break;
                case 9:
                    dangTrongPhien = false;
                    std::cout << "Da dang xuat.\n";
                    break;
                case 0:
                    dangChay = false;
                    std::cout << "Da thoat chuong trinh.\n";
                    break;
                default:
                    std::cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                    break;
            }
        }
    }
    return 0;
}
