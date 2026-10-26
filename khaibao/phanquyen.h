#ifndef PHANQUYEN_H
#define PHANQUYEN_H

#include <string>

enum class VaiTro {
    Admin = 1,
    ThuThu = 2,
    DocGia = 3
};

enum class ChucNang {
    QuanLySach,
    QuanLyDocGia,
    MuonTra,
    ThongKe,
    TimKiem,
    LuuTru,
    XuatCSV
};

struct TaiKhoanDangNhap {
    std::string tenDangNhap;
    VaiTro vaiTro;
};

const char* tenVaiTro(VaiTro vaiTro);
bool coQuyen(VaiTro vaiTro, ChucNang chucNang);

#endif
