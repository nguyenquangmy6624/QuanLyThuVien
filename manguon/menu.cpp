#include "menu.h"

#include <iostream>
#include <limits>

int showMainMenu(VaiTro vaiTro) {
    int choice = -1;
    std::cout << "\n============================================\n";
    std::cout << "       CHUONG TRINH QUAN LY THU VIEN\n";
    std::cout << "Tai khoan: " << tenVaiTro(vaiTro) << "\n";
    std::cout << "============================================\n";
    if (coQuyen(vaiTro, ChucNang::QuanLySach)) std::cout << "1. Quan ly sach\n";
    if (coQuyen(vaiTro, ChucNang::QuanLyDocGia)) std::cout << "2. Quan ly doc gia\n";
    if (coQuyen(vaiTro, ChucNang::MuonTra)) std::cout << "3. Muon - tra sach\n";
    if (coQuyen(vaiTro, ChucNang::ThongKe)) std::cout << "4. Thong ke - bao cao\n";
    if (coQuyen(vaiTro, ChucNang::TimKiem)) std::cout << "5. Tim kiem sach\n";
    if (coQuyen(vaiTro, ChucNang::LuuTru)) std::cout << "6. Luu tru va sao luu du lieu\n";
    if (coQuyen(vaiTro, ChucNang::XuatCSV)) std::cout << "7. Xuat CSV\n";
    std::cout << "8. Doi mat khau\n";
    std::cout << "9. Dang xuat\n";
    std::cout << "0. Thoat chuong trinh\n";
    std::cout << "--------------------------------------------\n";
    std::cout << "Nhap lua chon: ";

    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}
