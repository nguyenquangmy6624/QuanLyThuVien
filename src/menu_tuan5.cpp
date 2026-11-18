#include "menu_tuan5.h"
#include "danh_sach_phieumuon.h"
#include "mang_dong.h"
#include "luutru.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace {
string thoiGianHienTai() {
    time_t now = time(NULL);
    tm* local = localtime(&now);
    if (local == NULL) return "khong-ro-thoi-gian";
    ostringstream out;
    out << local->tm_year + 1900 << '-';
    if (local->tm_mon + 1 < 10) out << '0';
    out << local->tm_mon + 1 << '-';
    if (local->tm_mday < 10) out << '0';
    out << local->tm_mday << ' ';
    if (local->tm_hour < 10) out << '0';
    out << local->tm_hour << ':';
    if (local->tm_min < 10) out << '0';
    out << local->tm_min << ':';
    if (local->tm_sec < 10) out << '0';
    out << local->tm_sec;
    return out.str();
}

string nhapDong(const string& loiDan) {
    cout << loiDan;
    string value;
    getline(cin, value);
    return value;
}

void inPhieu(const PhieuMuon& phieu) {
    cout << "Ma phieu: " << phieu.maPhieu
         << " | CMND/CCCD: " << phieu.cmndCccd
         << " | ISBN: " << phieu.isbn << "\n"
         << "Ngay muon: " << phieu.ngayMuon
         << " | Hen tra: " << phieu.ngayHenTra
         << " | Ngay tra: " << (phieu.ngayTra.empty() ? "Chua tra" : phieu.ngayTra)
         << " | Trang thai: " << (phieu.daTra ? "Da tra" : "Dang muon")
         << " | Tien phat: " << phieu.tienPhat << "\n";
}

bool napDuLieuTuan5(DanhSachPhieuMuon& danhSach, MangDong<GiaoDich>& lichSu, string& loi) {
    vector<PhieuMuon> phieu;
    ifstream kiemTraPhieu("data/phieumuon.dat", ios::binary);
    if (!kiemTraPhieu.good()) {
        phieu.clear();
        if (!ghiDanhSachPhieuMuon(phieu, loi)) return false;
    } else if (!docDanhSachPhieuMuon(phieu, loi)) return false;
    danhSach.napTuVector(phieu);

    vector<GiaoDich> giaoDich;
    ifstream kiemTraLichSu("data/lichsugiaodich.dat", ios::binary);
    if (!kiemTraLichSu.good()) {
        giaoDich.clear();
        if (!ghiLichSuGiaoDich(giaoDich, loi)) return false;
    } else if (!docLichSuGiaoDich(giaoDich, loi)) return false;
    for (vector<GiaoDich>::const_iterator it = giaoDich.begin(); it != giaoDich.end(); ++it) lichSu.themCuoi(*it);
    loi.clear();
    return true;
}

bool luuDanhSachPhieu(const DanhSachPhieuMuon& danhSach, string& loi) {
    vector<PhieuMuon> phieu;
    danhSach.toVector(phieu);
    return ghiDanhSachPhieuMuon(phieu, loi);
}

bool luuMangDong(const MangDong<GiaoDich>& lichSu, string& loi) {
    vector<GiaoDich> giaoDich;
    for (size_t i = 0; i < lichSu.kichThuoc(); ++i) giaoDich.push_back(lichSu[i]);
    return ghiLichSuGiaoDich(giaoDich, loi);
}

void hienThiLichSu(const MangDong<GiaoDich>& lichSu) {
    cout << "\nLICH SU GIAO DICH (DYNAMIC ARRAY)\n";
    if (lichSu.rong()) { cout << "Chua co giao dich.\n"; return; }
    for (size_t i = 0; i < lichSu.kichThuoc(); ++i) {
        const GiaoDich& gd = lichSu[i];
        cout << i + 1 << ". " << gd.maGiaoDich << " | " << gd.loaiGiaoDich
             << " | " << gd.doiTuong << " | " << gd.thoiGian
             << " | " << gd.ghiChu << "\n";
    }
    cout << "So phan tu: " << lichSu.kichThuoc() << " | Suc chua: " << lichSu.sucChua() << "\n";
}
}

void menuDemoTuan5() {
    DanhSachPhieuMuon danhSach;
    MangDong<GiaoDich> lichSu;
    string loi;
    if (!napDuLieuTuan5(danhSach, lichSu, loi)) {
        cout << "Khong nap duoc du lieu Tuan 5: " << loi << "\n";
        return;
    }

    bool tiepTuc = true;
    while (tiepTuc) {
        cout << "\n========== CTDL TUAN 5: LINKED LIST / DYNAMIC ARRAY / FILE I/O ==========\n"
             << "1. Xem danh sach phieu muon (LinkedList)\n"
             << "2. Them phieu muon DEMO vao LinkedList\n"
             << "3. Xoa phieu muon DEMO theo ma phieu\n"
             << "4. Xem lich su giao dich (Dynamic Array)\n"
             << "5. Them giao dich DEMO vao Dynamic Array\n"
             << "6. Luu LinkedList va Dynamic Array ra file .dat\n"
             << "0. Quay lai\nChon: ";
        string luaChon;
        getline(cin, luaChon);

        if (luaChon == "1") {
            cout << "\nDANH SACH PHIEU MUON (LINKED LIST - DUYET TU DAU DEN CUOI)\n";
            if (danhSach.rong()) cout << "Danh sach rong.\n";
            vector<PhieuMuon> tam;
            danhSach.toVector(tam);
            for (vector<PhieuMuon>::const_iterator it = tam.begin(); it != tam.end(); ++it) inPhieu(*it);
            cout << "Tong so nut: " << danhSach.kichThuoc() << "\n";
        } else if (luaChon == "2") {
            PhieuMuon phieu;
            phieu.maPhieu = nhapDong("Ma phieu demo: ");
            if (phieu.maPhieu.empty() || danhSach.timKiem(phieu.maPhieu) != NULL) {
                cout << "Ma phieu trong hoac da ton tai.\n"; continue;
            }
            phieu.cmndCccd = nhapDong("CMND/CCCD: ");
            phieu.isbn = nhapDong("ISBN: ");
            phieu.ngayMuon = nhapDong("Ngay muon (YYYY-MM-DD): ");
            phieu.ngayHenTra = nhapDong("Ngay hen tra (YYYY-MM-DD): ");
            phieu.ngayTra = "";
            phieu.daTra = false;
            phieu.tienPhat = 0.0;
            if (phieu.cmndCccd.empty() || phieu.isbn.empty() || phieu.ngayMuon.empty() || phieu.ngayHenTra.empty()) {
                cout << "Thong tin phieu khong duoc de trong.\n"; continue;
            }
            danhSach.themCuoi(phieu);
            GiaoDich gd = {"GD-" + phieu.maPhieu, "THEM_PHIEU_DEMO", phieu.maPhieu,
                           thoiGianHienTai(), "Them phieu bang demo LinkedList Tuan 5"};
            lichSu.themCuoi(gd);
            cout << "Da them phieu vao LinkedList trong bo nho. Nho chon muc 6 de luu file.\n";
        } else if (luaChon == "3") {
            string ma = nhapDong("Ma phieu can xoa: ");
            if (!danhSach.xoa(ma)) cout << "Khong tim thay ma phieu.\n";
            else cout << "Da xoa nut khoi LinkedList. Chon muc 6 de luu file.\n";
        } else if (luaChon == "4") {
            hienThiLichSu(lichSu);
        } else if (luaChon == "5") {
            GiaoDich gd;
            gd.maGiaoDich = nhapDong("Ma giao dich: ");
            gd.loaiGiaoDich = nhapDong("Loai giao dich: ");
            gd.doiTuong = nhapDong("Doi tuong: ");
            gd.thoiGian = thoiGianHienTai();
            gd.ghiChu = nhapDong("Ghi chu: ");
            if (gd.maGiaoDich.empty() || gd.loaiGiaoDich.empty()) {
                cout << "Ma va loai giao dich khong duoc de trong.\n"; continue;
            }
            lichSu.themCuoi(gd);
            cout << "Da them giao dich vao Dynamic Array. Chon muc 6 de luu file.\n";
        } else if (luaChon == "6") {
            if (!luuDanhSachPhieu(danhSach, loi)) cout << "Loi luu phieu: " << loi << "\n";
            else if (!luuMangDong(lichSu, loi)) cout << "Loi luu lich su: " << loi << "\n";
            else {
                string loiLog;
                ghiNhatKy("Luu du lieu Tuan 5: phieu muon va lich su giao dich", loiLog);
                cout << "Da luu data/phieumuon.dat va data/lichsugiaodich.dat.\n";
            }
        } else if (luaChon == "0") {
            tiepTuc = false;
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    }
}
