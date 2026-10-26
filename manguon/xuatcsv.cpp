#include "xuatcsv.h"
#include "luutru.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string chuanHoaTruongCSV(const std::string& giaTri) {
    bool canQuote = giaTri.find_first_of(",\"\r\n") != std::string::npos;
    if (!canQuote) return giaTri;
    std::string result = "\"";
    for (std::string::const_iterator it = giaTri.begin(); it != giaTri.end(); ++it) {
        if (*it == '"') result += "\"\"";
        else result += *it;
    }
    result += '"';
    return result;
}

namespace {
void ghiBOMUTF8(std::ofstream& out) {
    const unsigned char bom[] = {0xEF, 0xBB, 0xBF};
    out.write(reinterpret_cast<const char*>(bom), sizeof(bom));
}

bool moTepCSV(const std::string& path, std::ofstream& out, std::string& loi) {
    out.open(path.c_str(), std::ios::binary | std::ios::trunc);
    if (!out) { loi = "Khong tao duoc tep " + path + ". Hay kiem tra thu muc va quyen ghi."; return false; }
    ghiBOMUTF8(out); // Giup Excel tren Windows nhan dien UTF-8 va tieng Viet.
    loi.clear();
    return true;
}
}

bool xuatSachCSV(const std::string& duongDan, std::string& loi) {
    std::vector<Sach> sach;
    if (!docDanhSachSach(sach, loi)) return false;
    std::ofstream out;
    if (!moTepCSV(duongDan, out, loi)) return false;
    out << "ISBN,TenSach,TacGia,TheLoai,NamXuatBan,SoLuongTong,SoLuongCon\r\n";
    for (std::vector<Sach>::const_iterator it = sach.begin(); it != sach.end(); ++it) {
        out << chuanHoaTruongCSV(it->isbn) << ',' << chuanHoaTruongCSV(it->tenSach) << ','
            << chuanHoaTruongCSV(it->tacGia) << ',' << chuanHoaTruongCSV(it->theLoai) << ','
            << it->namXuatBan << ',' << it->soLuongTong << ',' << it->soLuongCon << "\r\n";
    }
    if (!out) { loi = "Loi khi ghi tep CSV sach."; return false; }
    loi.clear(); return true;
}

bool xuatDocGiaCSV(const std::string& duongDan, std::string& loi) {
    std::vector<DocGia> docGia;
    if (!docDanhSachDocGia(docGia, loi)) return false;
    std::ofstream out;
    if (!moTepCSV(duongDan, out, loi)) return false;
    out << "CMND_CCCD,HoTen,Email,SoDienThoai,LoaiThe\r\n";
    for (std::vector<DocGia>::const_iterator it = docGia.begin(); it != docGia.end(); ++it) {
        out << chuanHoaTruongCSV(it->cmndCccd) << ',' << chuanHoaTruongCSV(it->hoTen) << ','
            << chuanHoaTruongCSV(it->email) << ',' << chuanHoaTruongCSV(it->soDienThoai) << ','
            << chuanHoaTruongCSV(it->loaiThe) << "\r\n";
    }
    if (!out) { loi = "Loi khi ghi tep CSV doc gia."; return false; }
    loi.clear(); return true;
}

void menuXuatCSV() {
    std::cout << "\n========== XUAT DU LIEU CSV ==========\n";
    std::cout << "1. Xuat danh muc sach -> dulieu/xuat_sach.csv\n";
    std::cout << "2. Xuat danh sach doc gia -> dulieu/xuat_docgia.csv\n";
    std::cout << "3. Xuat ca hai tep CSV\n";
    std::cout << "0. Quay lai\n";
    std::cout << "Chon: ";
    std::string choice;
    std::getline(std::cin, choice);
    std::string loi;
    bool ok = true;
    if (choice == "1" || choice == "3") {
        ok = xuatSachCSV("dulieu/xuat_sach.csv", loi);
        if (ok) std::cout << "Da xuat: dulieu/xuat_sach.csv\n";
        else std::cout << "Xuat sach that bai: " << loi << "\n";
    }
    if (ok && (choice == "2" || choice == "3")) {
        ok = xuatDocGiaCSV("dulieu/xuat_docgia.csv", loi);
        if (ok) std::cout << "Da xuat: dulieu/xuat_docgia.csv\n";
        else std::cout << "Xuat doc gia that bai: " << loi << "\n";
    }
    if (choice != "0" && choice != "1" && choice != "2" && choice != "3") {
        std::cout << "Lua chon khong hop le.\n";
    }
}
