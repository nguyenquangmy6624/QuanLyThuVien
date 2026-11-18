#include "luutru.h"

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <limits>

namespace {
const uint32_t PHIEN_BAN_FILE = 1;
const uint32_t GIOI_HAN_BAN_GHI = 1000000;

bool tepTonTai(const std::string& path) {
    std::ifstream file(path.c_str(), std::ios::binary);
    return file.good();
}

bool ghiChuoi(std::ostream& out, const std::string& value) {
    if (value.size() > 1024 * 1024) return false;
    uint32_t length = static_cast<uint32_t>(value.size());
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    if (length > 0) out.write(value.data(), static_cast<std::streamsize>(length));
    return static_cast<bool>(out);
}

bool docChuoi(std::istream& in, std::string& value) {
    uint32_t length = 0;
    in.read(reinterpret_cast<char*>(&length), sizeof(length));
    if (!in || length > 1024 * 1024) return false;
    value.assign(length, '\0');
    if (length > 0) in.read(&value[0], static_cast<std::streamsize>(length));
    return static_cast<bool>(in);
}

bool moTepGhi(const std::string& path, const char magic[8], uint32_t count, std::ofstream& out) {
    out.open(path.c_str(), std::ios::binary | std::ios::trunc);
    if (!out) return false;
    out.write(magic, 8);
    out.write(reinterpret_cast<const char*>(&PHIEN_BAN_FILE), sizeof(PHIEN_BAN_FILE));
    out.write(reinterpret_cast<const char*>(&count), sizeof(count));
    return static_cast<bool>(out);
}

bool moTepDoc(const std::string& path, const char expectedMagic[8], uint32_t& count, std::ifstream& in) {
    in.open(path.c_str(), std::ios::binary);
    if (!in) return false;
    char magic[8] = {};
    uint32_t version = 0;
    in.read(magic, 8);
    in.read(reinterpret_cast<char*>(&version), sizeof(version));
    in.read(reinterpret_cast<char*>(&count), sizeof(count));
    if (!in || !std::equal(magic, magic + 8, expectedMagic) || version != PHIEN_BAN_FILE || count > GIOI_HAN_BAN_GHI) return false;
    return true;
}
}

bool docDanhSachSach(std::vector<Sach>& danhSach, std::string& loi) {
    std::ifstream in;
    uint32_t count = 0;
    const char magic[8] = {'Q','L','T','V','S','A','C','H'};
    if (!moTepDoc("data/sach.dat", magic, count, in)) { loi = "Khong doc duoc data/sach.dat hoac tep khong dung dinh dang."; return false; }
    std::vector<Sach> temp;
    for (uint32_t i = 0; i < count; ++i) {
        Sach item; int32_t nam = 0, tong = 0, con = 0;
        if (!docChuoi(in, item.isbn) || !docChuoi(in, item.tenSach) || !docChuoi(in, item.tacGia) || !docChuoi(in, item.theLoai)) { loi = "Du lieu sach bi hong."; return false; }
        in.read(reinterpret_cast<char*>(&nam), sizeof(nam));
        in.read(reinterpret_cast<char*>(&tong), sizeof(tong));
        in.read(reinterpret_cast<char*>(&con), sizeof(con));
        if (!in) { loi = "Du lieu sach bi hong."; return false; }
        item.namXuatBan = nam; item.soLuongTong = tong; item.soLuongCon = con;
        temp.push_back(item);
    }
    danhSach.swap(temp); loi.clear(); return true;
}

bool ghiDanhSachSach(const std::vector<Sach>& danhSach, std::string& loi) {
    std::ofstream out;
    const char magic[8] = {'Q','L','T','V','S','A','C','H'};
    if (!moTepGhi("data/sach.dat", magic, static_cast<uint32_t>(danhSach.size()), out)) { loi = "Khong tao/ghi duoc data/sach.dat."; return false; }
    for (std::vector<Sach>::const_iterator it = danhSach.begin(); it != danhSach.end(); ++it) {
        int32_t nam = it->namXuatBan, tong = it->soLuongTong, con = it->soLuongCon;
        if (!ghiChuoi(out, it->isbn) || !ghiChuoi(out, it->tenSach) || !ghiChuoi(out, it->tacGia) || !ghiChuoi(out, it->theLoai)) { loi = "Loi khi ghi truong sach."; return false; }
        out.write(reinterpret_cast<const char*>(&nam), sizeof(nam));
        out.write(reinterpret_cast<const char*>(&tong), sizeof(tong));
        out.write(reinterpret_cast<const char*>(&con), sizeof(con));
        if (!out) { loi = "Loi khi ghi du lieu sach."; return false; }
    }
    loi.clear(); return true;
}

bool docDanhSachDocGia(std::vector<DocGia>& danhSach, std::string& loi) {
    std::ifstream in;
    uint32_t count = 0;
    const char magic[8] = {'Q','L','T','V','D','O','C','G'};
    if (!moTepDoc("data/docgia.dat", magic, count, in)) { loi = "Khong doc duoc data/docgia.dat hoac tep khong dung dinh dang."; return false; }
    std::vector<DocGia> temp;
    for (uint32_t i = 0; i < count; ++i) {
        DocGia item;
        if (!docChuoi(in, item.cmndCccd) || !docChuoi(in, item.hoTen) || !docChuoi(in, item.email) || !docChuoi(in, item.soDienThoai) || !docChuoi(in, item.loaiThe)) { loi = "Du lieu doc gia bi hong."; return false; }
        temp.push_back(item);
    }
    danhSach.swap(temp); loi.clear(); return true;
}

bool ghiDanhSachDocGia(const std::vector<DocGia>& danhSach, std::string& loi) {
    std::ofstream out;
    const char magic[8] = {'Q','L','T','V','D','O','C','G'};
    if (!moTepGhi("data/docgia.dat", magic, static_cast<uint32_t>(danhSach.size()), out)) { loi = "Khong tao/ghi duoc data/docgia.dat."; return false; }
    for (std::vector<DocGia>::const_iterator it = danhSach.begin(); it != danhSach.end(); ++it) {
        if (!ghiChuoi(out, it->cmndCccd) || !ghiChuoi(out, it->hoTen) || !ghiChuoi(out, it->email) || !ghiChuoi(out, it->soDienThoai) || !ghiChuoi(out, it->loaiThe)) { loi = "Loi khi ghi truong doc gia."; return false; }
    }
    loi.clear(); return true;
}

bool khoiTaoDuLieuMauNeuChuaCo(bool& daTaoMoi, std::string& loi) {
    daTaoMoi = false;
    bool sachMoi = !tepTonTai("data/sach.dat");
    bool docGiaMoi = !tepTonTai("data/docgia.dat");
    if (!sachMoi && !docGiaMoi) { loi.clear(); return true; }

    if (sachMoi) {
        std::vector<Sach> sach;
        Sach a = {"9780131103627", "The C Programming Language", "Kernighan va Ritchie", "Lap trinh", 1988, 4, 4};
        Sach b = {"9780321563842", "C++ Primer", "Stanley B. Lippman", "Lap trinh", 2012, 5, 5};
        Sach c = {"9780132350884", "Clean Code", "Robert C. Martin", "Ky thuat phan mem", 2008, 3, 3};
        sach.push_back(a); sach.push_back(b); sach.push_back(c);
        if (!ghiDanhSachSach(sach, loi)) return false;
    }
    if (docGiaMoi) {
        std::vector<DocGia> docGia;
        DocGia a = {"079000000001", "Nguyen Van An", "an@example.com", "0900000001", "Thuong"};
        DocGia b = {"079000000002", "Tran Thi Binh", "binh@example.com", "0900000002", "VIP"};
        DocGia c = {"079000000003", "Le Minh Chau", "chau@example.com", "0900000003", "Thuong"};
        docGia.push_back(a); docGia.push_back(b); docGia.push_back(c);
        if (!ghiDanhSachDocGia(docGia, loi)) return false;
    }
    daTaoMoi = true; loi.clear(); return true;
}

bool docDanhSachPhieuMuon(std::vector<PhieuMuon>& danhSach, std::string& loi,
                          const std::string& duongDan) {
    std::ifstream in;
    uint32_t count = 0;
    const char magic[8] = {'Q','L','T','V','P','M','0','1'};
    if (!moTepDoc(duongDan, magic, count, in)) {
        loi = "Khong doc duoc " + duongDan + " hoac tep khong dung dinh dang.";
        return false;
    }
    std::vector<PhieuMuon> temp;
    for (uint32_t i = 0; i < count; ++i) {
        PhieuMuon item;
        uint8_t daTra = 0;
        if (!docChuoi(in, item.maPhieu) || !docChuoi(in, item.cmndCccd) ||
            !docChuoi(in, item.isbn) || !docChuoi(in, item.ngayMuon) ||
            !docChuoi(in, item.ngayHenTra) || !docChuoi(in, item.ngayTra)) {
            loi = "Du lieu phieu muon bi hong."; return false;
        }
        in.read(reinterpret_cast<char*>(&daTra), sizeof(daTra));
        in.read(reinterpret_cast<char*>(&item.tienPhat), sizeof(item.tienPhat));
        if (!in || daTra > 1 || item.tienPhat < 0) { loi = "Du lieu phieu muon khong hop le."; return false; }
        item.daTra = daTra != 0;
        temp.push_back(item);
    }
    danhSach.swap(temp);
    loi.clear();
    return true;
}

bool ghiDanhSachPhieuMuon(const std::vector<PhieuMuon>& danhSach, std::string& loi,
                          const std::string& duongDan) {
    std::ofstream out;
    const char magic[8] = {'Q','L','T','V','P','M','0','1'};
    if (!moTepGhi(duongDan, magic, static_cast<uint32_t>(danhSach.size()), out)) {
        loi = "Khong tao/ghi duoc tep " + duongDan + "."; return false;
    }
    for (std::vector<PhieuMuon>::const_iterator it = danhSach.begin(); it != danhSach.end(); ++it) {
        const uint8_t daTra = it->daTra ? 1 : 0;
        if (!ghiChuoi(out, it->maPhieu) || !ghiChuoi(out, it->cmndCccd) ||
            !ghiChuoi(out, it->isbn) || !ghiChuoi(out, it->ngayMuon) ||
            !ghiChuoi(out, it->ngayHenTra) || !ghiChuoi(out, it->ngayTra)) {
            loi = "Loi khi ghi truong phieu muon."; return false;
        }
        out.write(reinterpret_cast<const char*>(&daTra), sizeof(daTra));
        out.write(reinterpret_cast<const char*>(&it->tienPhat), sizeof(it->tienPhat));
        if (!out) { loi = "Loi khi ghi du lieu phieu muon."; return false; }
    }
    loi.clear(); return true;
}

bool docLichSuGiaoDich(std::vector<GiaoDich>& danhSach, std::string& loi,
                       const std::string& duongDan) {
    std::ifstream in;
    uint32_t count = 0;
    const char magic[8] = {'Q','L','T','V','G','D','0','1'};
    if (!moTepDoc(duongDan, magic, count, in)) {
        loi = "Khong doc duoc " + duongDan + " hoac tep khong dung dinh dang.";
        return false;
    }
    std::vector<GiaoDich> temp;
    for (uint32_t i = 0; i < count; ++i) {
        GiaoDich item;
        if (!docChuoi(in, item.maGiaoDich) || !docChuoi(in, item.loaiGiaoDich) ||
            !docChuoi(in, item.doiTuong) || !docChuoi(in, item.thoiGian) ||
            !docChuoi(in, item.ghiChu)) {
            loi = "Du lieu lich su giao dich bi hong."; return false;
        }
        temp.push_back(item);
    }
    danhSach.swap(temp);
    loi.clear(); return true;
}

bool ghiLichSuGiaoDich(const std::vector<GiaoDich>& danhSach, std::string& loi,
                       const std::string& duongDan) {
    std::ofstream out;
    const char magic[8] = {'Q','L','T','V','G','D','0','1'};
    if (!moTepGhi(duongDan, magic, static_cast<uint32_t>(danhSach.size()), out)) {
        loi = "Khong tao/ghi duoc tep " + duongDan + "."; return false;
    }
    for (std::vector<GiaoDich>::const_iterator it = danhSach.begin(); it != danhSach.end(); ++it) {
        if (!ghiChuoi(out, it->maGiaoDich) || !ghiChuoi(out, it->loaiGiaoDich) ||
            !ghiChuoi(out, it->doiTuong) || !ghiChuoi(out, it->thoiGian) ||
            !ghiChuoi(out, it->ghiChu)) {
            loi = "Loi khi ghi truong giao dich."; return false;
        }
    }
    loi.clear(); return true;
}

bool ghiNhatKy(const std::string& noiDung, std::string& loi, const std::string& duongDan) {
    std::ofstream out(duongDan.c_str(), std::ios::app);
    if (!out) { loi = "Khong mo duoc tep nhat ky " + duongDan + "."; return false; }
    out << noiDung << '\n';
    if (!out) { loi = "Khong ghi duoc tep nhat ky."; return false; }
    loi.clear();
    return true;
}
