#include "phanquyen.h"
#include "xuatcsv.h"

#include <cassert>
#include <iostream>

int main() {
    // Admin co toan quyen; thu thu duoc xuat CSV; doc gia chi duoc tim kiem.
    assert(coQuyen(VaiTro::Admin, ChucNang::LuuTru));
    assert(coQuyen(VaiTro::ThuThu, ChucNang::XuatCSV));
    assert(!coQuyen(VaiTro::ThuThu, ChucNang::LuuTru));
    assert(coQuyen(VaiTro::DocGia, ChucNang::TimKiem));
    assert(!coQuyen(VaiTro::DocGia, ChucNang::QuanLySach));
    assert(!coQuyen(VaiTro::DocGia, ChucNang::XuatCSV));

    assert(chuanHoaTruongCSV("sach") == "sach");
    assert(chuanHoaTruongCSV("Lap trinh, C++") == "\"Lap trinh, C++\"");
    assert(chuanHoaTruongCSV("Tac gia \"A\"") == "\"Tac gia \"\"A\"\"\"");
    assert(chuanHoaTruongCSV("dong 1\ndong 2") == "\"dong 1\ndong 2\"");

    std::cout << "Tat ca kiem thu quyen va CSV da dat.\n";
    return 0;
}
