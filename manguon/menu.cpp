#include "menu.h"

#include <iostream>
#include <limits>

int showMainMenu() {
    int choice;

    std::cout << "\n============================================\n";
    std::cout << "       CHUONG TRINH QUAN LY THU VIEN\n";
    std::cout << "============================================\n";
    std::cout << "1. Quan ly sach\n";
    std::cout << "2. Quan ly doc gia\n";
    std::cout << "3. Muon - tra sach\n";
    std::cout << "4. Thong ke - bao cao\n";
    std::cout << "5. Goi y va tim kiem nang cao\n";
    std::cout << "6. Luu tru va sao luu du lieu\n";
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
