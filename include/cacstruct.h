#ifndef CACSTRUCT_H
#define CACSTRUCT_H

#include <string>

// Kieu du lieu dung chung. Du lieu chinh duoc luu trong file nhi phan .dat.
struct Sach {
    std::string isbn;
    std::string tenSach;
    std::string tacGia;
    std::string theLoai;
    int namXuatBan;
    int soLuongTong;
    int soLuongCon;
};

struct DocGia {
    std::string cmndCccd;
    std::string hoTen;
    std::string email;
    std::string soDienThoai;
    std::string loaiThe;
};

#endif
