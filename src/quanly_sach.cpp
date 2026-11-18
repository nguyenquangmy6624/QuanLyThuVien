#include "quanly_sach.h"
#include "cay_avl.h"
#include "cay_bst.h"
#include "luutru.h"

#include <algorithm>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace {
string nhapDong(const string& loiDan) {
    cout << loiDan;
    string giaTri;
    getline(cin, giaTri);
    return giaTri;
}

bool docSoNguyen(const string& chuoi, int& giaTri) {
    istringstream input(chuoi);
    input >> giaTri;
    return input && input.eof();
}

string chuanHoaISBN(const string& isbn) {
    string so;
    for (string::const_iterator it = isbn.begin(); it != isbn.end(); ++it) {
        if (*it == '-' || isspace(static_cast<unsigned char>(*it))) continue;
        if (!isdigit(static_cast<unsigned char>(*it))) return "";
        so += *it;
    }
    return so;
}

bool isbnHopLe(const string& isbn) {
    const string so = chuanHoaISBN(isbn);
    return so.size() == 10 || so.size() == 13;
}

void hienThiSach(const Sach& sach) {
    cout << "ISBN: " << sach.isbn << "\n"
         << "Ten sach: " << sach.tenSach << "\n"
         << "Tac gia: " << sach.tacGia << "\n"
         << "The loai: " << sach.theLoai << "\n"
         << "Nam xuat ban: " << sach.namXuatBan << "\n"
         << "So luong tong/con: " << sach.soLuongTong << "/" << sach.soLuongCon << "\n";
}

bool napCaySach(CayAVL& cay, string& loi) {
    vector<Sach> danhSach;
    if (!docDanhSachSach(danhSach, loi)) return false;
    for (vector<Sach>::const_iterator it = danhSach.begin(); it != danhSach.end(); ++it) {
        if (!cay.them(*it)) { loi = "Phat hien ISBN trung lap trong data/sach.dat: " + it->isbn; return false; }
    }
    return true;
}

bool luuCaySach(const CayAVL& cay, const string& hanhDong, const string& isbn) {
    vector<Sach> danhSach;
    string loi;
    cay.duyetTangDan(danhSach);
    if (!ghiDanhSachSach(danhSach, loi)) {
        cout << "Loi luu file: " << loi << "\n";
        return false;
    }
    string loiNhatKy;
    if (!ghiNhatKy("Sach: " + hanhDong + " ISBN=" + isbn, loiNhatKy))
        cout << "Canh bao: chua ghi duoc nhat ky: " << loiNhatKy << "\n";
    cout << "Da luu thay doi vao data/sach.dat.\n";
    return true;
}

bool nhapThongTinSach(Sach& sach, bool nhapISBN) {
    if (nhapISBN) {
        sach.isbn = nhapDong("ISBN (10 hoac 13 chu so, co the co dau -): ");
        if (!isbnHopLe(sach.isbn)) { cout << "ISBN khong hop le.\n"; return false; }
        sach.isbn = chuanHoaISBN(sach.isbn);
    }
    sach.tenSach = nhapDong("Ten sach: ");
    sach.tacGia = nhapDong("Tac gia: ");
    sach.theLoai = nhapDong("The loai: ");
    if (sach.tenSach.empty() || sach.tacGia.empty() || sach.theLoai.empty()) {
        cout << "Ten sach, tac gia va the loai khong duoc de trong.\n";
        return false;
    }
    string chuoiNam = nhapDong("Nam xuat ban: ");
    if (!docSoNguyen(chuoiNam, sach.namXuatBan) || sach.namXuatBan < 0 || sach.namXuatBan > 2026) {
        cout << "Nam xuat ban khong hop le.\n"; return false;
    }
    string chuoiTong = nhapDong("So luong tong: ");
    if (!docSoNguyen(chuoiTong, sach.soLuongTong) || sach.soLuongTong < 0) {
        cout << "So luong phai la so nguyen khong am.\n"; return false;
    }
    return true;
}

void inDanhMucBangBST(const vector<Sach>& danhSach) {
    CayBSTSach bst;
    bst.taoTuDanhSach(danhSach);
    vector<Sach> daSapXep;
    bst.duyetInOrder(daSapXep);
    cout << "\nDANH MUC SACH (BST - IN ORDER)\n";
    cout << left << setw(16) << "ISBN" << setw(34) << "Ten sach" << setw(24) << "Tac gia" << "SL con/tong\n";
    cout << string(88, '-') << "\n";
    for (vector<Sach>::const_iterator it = daSapXep.begin(); it != daSapXep.end(); ++it)
        cout << left << setw(16) << it->isbn << setw(34) << it->tenSach.substr(0, 32)
             << setw(24) << it->tacGia.substr(0, 22) << it->soLuongCon << "/" << it->soLuongTong << "\n";
    cout << "Tong so sach: " << daSapXep.size() << " | BST dung duyet in-order de sap xep ISBN.\n";
}
}

void menuQuanLySach() {
    CayAVL cay;
    string loi;
    if (!napCaySach(cay, loi)) {
        cout << "Khong nap duoc cay AVL: " << loi << "\n";
        return;
    }

    bool tiepTuc = true;
    while (tiepTuc) {
        cout << "\n========== QUAN LY SACH (AVL) ==========\n"
             << "1. Them sach\n2. Sua thong tin sach\n3. Xoa sach\n"
             << "4. Tim sach theo ISBN\n5. In danh muc tang dan theo ISBN (BST)\n0. Quay lai\nChon: ";
        string luaChon;
        getline(cin, luaChon);
        if (luaChon == "1") {
            Sach sach = {"", "", "", "", 0, 0, 0};
            if (!nhapThongTinSach(sach, true)) continue;
            sach.soLuongCon = sach.soLuongTong;
            if (!cay.them(sach)) cout << "ISBN da ton tai, khong the them trung.\n";
            else if (!luuCaySach(cay, "THEM", sach.isbn)) return;
        } else if (luaChon == "2") {
            string isbn = chuanHoaISBN(nhapDong("Nhap ISBN can sua: "));
            const Sach* timThay = cay.timKiem(isbn);
            if (timThay == NULL) { cout << "Khong tim thay sach.\n"; continue; }
            Sach sach = *timThay;
            cout << "Nhap thong tin moi (ISBN duoc giu nguyen).\n";
            if (!nhapThongTinSach(sach, false)) continue;
            if (sach.soLuongTong < sach.soLuongCon) {
                cout << "So luong tong khong duoc nho hon so luong con hien tai (" << sach.soLuongCon << ").\n";
                continue;
            }
            if (cay.capNhat(sach)) luuCaySach(cay, "SUA", sach.isbn);
        } else if (luaChon == "3") {
            string isbn = chuanHoaISBN(nhapDong("Nhap ISBN can xoa: "));
            if (!cay.xoa(isbn)) cout << "Khong tim thay ISBN de xoa.\n";
            else luuCaySach(cay, "XOA", isbn);
        } else if (luaChon == "4") {
            string isbn = chuanHoaISBN(nhapDong("Nhap ISBN can tim: "));
            const Sach* sach = cay.timKiem(isbn);
            if (sach == NULL) cout << "Khong tim thay sach.\n";
            else { cout << "Tim thay trong cay AVL: \n"; hienThiSach(*sach); }
        } else if (luaChon == "5") {
            vector<Sach> danhSach;
            cay.duyetTangDan(danhSach);
            inDanhMucBangBST(danhSach);
            cout << "Kiem tra AVL: " << (cay.cayCanBang() ? "hop le" : "mat can bang") << "\n";
        } else if (luaChon == "0") tiepTuc = false;
        else cout << "Lua chon khong hop le.\n";
    }
}


void menuTimKiemSach() {
    CayAVL cay;
    string loi;
    if (!napCaySach(cay, loi)) {
        cout << "Khong nap duoc du lieu sach: " << loi << "\n";
        return;
    }
    string isbn = chuanHoaISBN(nhapDong("Nhap ISBN can tim: "));
    const Sach* sach = cay.timKiem(isbn);
    if (sach == NULL) cout << "Khong tim thay sach co ISBN " << isbn << ".\n";
    else hienThiSach(*sach);
}
