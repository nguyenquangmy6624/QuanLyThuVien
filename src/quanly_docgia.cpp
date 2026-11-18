#include "quanly_docgia.h"
#include "bangbam_docgia.h"
#include "luutru.h"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace {
string nhapDongDocGia(const string& loiDan) {
    cout << loiDan;
    string giaTri;
    getline(cin, giaTri);
    return giaTri;
}

bool cmndHopLe(const string& cmnd) {
    if (cmnd.size() != 9 && cmnd.size() != 12) return false;
    for (string::const_iterator it = cmnd.begin(); it != cmnd.end(); ++it)
        if (!isdigit(static_cast<unsigned char>(*it))) return false;
    return true;
}

void inDocGia(const DocGia& docGia) {
    cout << "CMND/CCCD: " << docGia.cmndCccd << "\n"
         << "Ho ten: " << docGia.hoTen << "\n"
         << "Email: " << docGia.email << "\n"
         << "So dien thoai: " << docGia.soDienThoai << "\n"
         << "Loai the: " << docGia.loaiThe << "\n";
}

bool napBangBam(BangBamDocGia& bang, string& loi) {
    vector<DocGia> danhSach;
    if (!docDanhSachDocGia(danhSach, loi)) return false;
    for (vector<DocGia>::const_iterator it = danhSach.begin(); it != danhSach.end(); ++it) {
        if (!bang.them(*it)) { loi = "CMND/CCCD trung lap trong file: " + it->cmndCccd; return false; }
    }
    return true;
}

bool luuBangBam(const BangBamDocGia& bang, const string& hanhDong, const string& khoa) {
    vector<DocGia> danhSach;
    string loi;
    bang.toVector(danhSach);
    if (!ghiDanhSachDocGia(danhSach, loi)) { cout << "Loi luu file: " << loi << "\n"; return false; }
    string loiNhatKy;
    if (!ghiNhatKy("Doc gia: " + hanhDong + " CMND_CCCD=" + khoa, loiNhatKy))
        cout << "Canh bao: chua ghi duoc nhat ky: " << loiNhatKy << "\n";
    cout << "Da luu thay doi vao data/docgia.dat.\n";
    return true;
}

bool nhapThongTinDocGia(DocGia& docGia, bool nhapKhoa) {
    if (nhapKhoa) {
        docGia.cmndCccd = nhapDongDocGia("CMND/CCCD (9 hoac 12 chu so): ");
        if (!cmndHopLe(docGia.cmndCccd)) { cout << "CMND/CCCD khong hop le.\n"; return false; }
    }
    docGia.hoTen = nhapDongDocGia("Ho ten: ");
    docGia.email = nhapDongDocGia("Email: ");
    docGia.soDienThoai = nhapDongDocGia("So dien thoai: ");
    docGia.loaiThe = nhapDongDocGia("Loai the (Thuong/VIP): ");
    if (docGia.hoTen.empty() || docGia.loaiThe.empty()) {
        cout << "Ho ten va loai the khong duoc de trong.\n"; return false;
    }
    if (!docGia.email.empty() && docGia.email.find('@') == string::npos) {
        cout << "Email phai co ky tu @ hoac de trong.\n"; return false;
    }
    return true;
}
}

void menuQuanLyDocGia() {
    BangBamDocGia bang;
    string loi;
    if (!napBangBam(bang, loi)) { cout << "Khong nap duoc Hash Table: " << loi << "\n"; return; }

    bool tiepTuc = true;
    while (tiepTuc) {
        cout << "\n====== QUAN LY DOC GIA (HASH TABLE) ======\n"
             << "1. Them doc gia\n2. Sua doc gia\n3. Xoa doc gia\n"
             << "4. Tim theo CMND/CCCD\n5. Liet ke doc gia\n0. Quay lai\nChon: ";
        string luaChon;
        getline(cin, luaChon);
        if (luaChon == "1") {
            DocGia docGia = {"", "", "", "", ""};
            if (!nhapThongTinDocGia(docGia, true)) continue;
            if (!bang.them(docGia)) cout << "CMND/CCCD da ton tai.\n";
            else if (!luuBangBam(bang, "THEM", docGia.cmndCccd)) return;
        } else if (luaChon == "2") {
            string khoa = nhapDongDocGia("Nhap CMND/CCCD can sua: ");
            DocGia* timThay = bang.timKiem(khoa);
            if (timThay == NULL) { cout << "Khong tim thay doc gia.\n"; continue; }
            DocGia docGia = *timThay;
            cout << "Nhap thong tin moi (giu nguyen CMND/CCCD).\n";
            if (!nhapThongTinDocGia(docGia, false)) continue;
            if (bang.capNhat(docGia)) luuBangBam(bang, "SUA", khoa);
        } else if (luaChon == "3") {
            string khoa = nhapDongDocGia("Nhap CMND/CCCD can xoa: ");
            if (!bang.xoa(khoa)) cout << "Khong tim thay doc gia.\n";
            else luuBangBam(bang, "XOA", khoa);
        } else if (luaChon == "4") {
            string khoa = nhapDongDocGia("Nhap CMND/CCCD can tim: ");
            const DocGia* docGia = bang.timKiem(khoa);
            if (docGia == NULL) cout << "Khong tim thay doc gia.\n";
            else inDocGia(*docGia);
        } else if (luaChon == "5") {
            vector<DocGia> danhSach;
            bang.toVector(danhSach);
            sort(danhSach.begin(), danhSach.end(), [](const DocGia& a, const DocGia& b) {
                return a.cmndCccd < b.cmndCccd;
            });
            cout << "\nDANH SACH DOC GIA (HASH TABLE, SEPARATE CHAINING)\n";
            cout << left << setw(16) << "CMND/CCCD" << setw(28) << "Ho ten" << setw(24) << "Email" << "Loai the\n";
            cout << string(88, '-') << "\n";
            for (vector<DocGia>::const_iterator it = danhSach.begin(); it != danhSach.end(); ++it)
                cout << left << setw(16) << it->cmndCccd << setw(28) << it->hoTen.substr(0, 26)
                     << setw(24) << it->email.substr(0, 22) << it->loaiThe << "\n";
            cout << "Tong: " << bang.kichThuoc() << " doc gia | So bucket: " << bang.sucChua() << "\n";
        } else if (luaChon == "0") tiepTuc = false;
        else cout << "Lua chon khong hop le.\n";
    }
}
