#ifndef CACSTRUCT_H
#define CACSTRUCT_H

#include <string>

// Thong tin mot dau sach. ISBN la khoa chinh cua he thong.
struct Sach {
    std::string isbn;
    std::string tenSach;
    std::string tacGia;
    std::string theLoai;
    int namXuatBan;
    int soLuongTong;
    int soLuongCon;
};

// Thong tin doc gia. CMND/CCCD la khoa chinh.
struct DocGia {
    std::string cmndCccd;
    std::string hoTen;
    std::string email;
    std::string soDienThoai;
    std::string loaiThe;
};

// Phieu muon duoc quan ly bang danh sach lien ket don.
struct PhieuMuon {
    std::string maPhieu;
    std::string cmndCccd;
    std::string isbn;
    std::string ngayMuon;      // Dinh dang YYYY-MM-DD
    std::string ngayHenTra;    // Dinh dang YYYY-MM-DD
    std::string ngayTra;       // De trong neu chua tra
    bool daTra;
    double tienPhat;
};

// Lich su giao dich duoc quan ly bang mang dong tu cai dat.
struct GiaoDich {
    std::string maGiaoDich;
    std::string loaiGiaoDich;
    std::string doiTuong;
    std::string thoiGian;
    std::string ghiChu;
};

#endif
