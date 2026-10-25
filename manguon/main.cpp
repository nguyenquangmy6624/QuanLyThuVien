#include "menu.h"

#include <iostream>

int main() {
    bool isRunning = true;

    while (isRunning) {
        const int choice = showMainMenu();

        switch (choice) {
            case 1:
                std::cout << "[CHUA HOAN THANH] Phan quan ly sach.\n";
                break;
            case 2:
                std::cout << "[CHUA HOAN THANH] Phan quan ly doc gia.\n";
                break;
            case 3:
                std::cout << "[CHUA HOAN THANH] Phan muon - tra sach.\n";
                break;
            case 4:
                std::cout << "[CHUA HOAN THANH] Phan thong ke - bao cao.\n";
                break;
            case 5:
                std::cout << "[CHUA HOAN THANH] Phan goi y va tim kiem nang cao.\n";
                break;
            case 6:
                std::cout << "[CHUA HOAN THANH] Phan luu tru va sao luu.\n";
                break;
            case 0:
                isRunning = false;
                std::cout << "Da thoat chuong trinh.\n";
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                break;
        }
    }

    return 0;
}
