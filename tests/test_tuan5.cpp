#include "danh_sach_phieumuon.h"
#include "mang_dong.h"
#include "luutru.h"

#include <cassert>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Kiem thu LinkedList: them cuoi, tim, xoa dau/giua/cuoi va chuyen doi du lieu.
    DanhSachPhieuMuon danhSach;
    PhieuMuon p1 = {"PM001", "079000000001", "9780131103627", "2026-11-01", "2026-11-08", "", false, 0.0};
    PhieuMuon p2 = {"PM002", "079000000002", "9780321563842", "2026-11-02", "2026-11-09", "", false, 0.0};
    PhieuMuon p3 = {"PM003", "079000000003", "9780132350884", "2026-11-03", "2026-11-10", "", false, 0.0};
    danhSach.themCuoi(p1);
    danhSach.themCuoi(p2);
    danhSach.themCuoi(p3);
    assert(danhSach.kichThuoc() == 3);
    assert(danhSach.timKiem("PM002") != NULL);
    assert(danhSach.xoa("PM001"));
    assert(danhSach.xoa("PM002"));
    assert(danhSach.xoa("PM003"));
    assert(danhSach.rong()); // ca truong hop xoa den nut cuoi cung
    danhSach.themCuoi(p1);
    danhSach.themCuoi(p2);

    // Kiem thu Dynamic Array: tu tang suc chua, truy cap, xoa phan tu.
    MangDong<GiaoDich> lichSu(1);
    for (int i = 0; i < 25; ++i) {
        GiaoDich gd = {"GD" + to_string(i), "THEM", "PM", "2026-11-07", "Ghi chu"};
        lichSu.themCuoi(gd);
    }
    assert(lichSu.kichThuoc() == 25);
    assert(lichSu.sucChua() >= 25);
    assert(lichSu[24].maGiaoDich == "GD24");
    assert(lichSu.xoaTai(0));
    assert(lichSu.kichThuoc() == 24);
    assert(lichSu[0].maGiaoDich == "GD1");

    // Kiem thu File I/O nhi phan cho LinkedList va Dynamic Array.
    vector<PhieuMuon> phieuGhi;
    danhSach.toVector(phieuGhi);
    string loi;
    assert(ghiDanhSachPhieuMuon(phieuGhi, loi, "data/test_phieumuon.dat"));
    vector<PhieuMuon> phieuDoc;
    assert(docDanhSachPhieuMuon(phieuDoc, loi, "data/test_phieumuon.dat"));
    assert(phieuDoc.size() == 2);
    assert(phieuDoc[0].maPhieu == "PM001");

    vector<GiaoDich> gdGhi;
    for (size_t i = 0; i < lichSu.kichThuoc(); ++i) gdGhi.push_back(lichSu[i]);
    assert(ghiLichSuGiaoDich(gdGhi, loi, "data/test_lichsu.dat"));
    vector<GiaoDich> gdDoc;
    assert(docLichSuGiaoDich(gdDoc, loi, "data/test_lichsu.dat"));
    assert(gdDoc.size() == 24);
    assert(gdDoc[0].maGiaoDich == "GD1");

    // Kiem thu file log van ban TXT.
    assert(ghiNhatKy("TEST_LOG_TUAN5", loi, "data/test_nhatky.txt"));
    ifstream logFile("data/test_nhatky.txt");
    string dongLog;
    getline(logFile, dongLog);
    assert(dongLog == "TEST_LOG_TUAN5");

    std::remove("data/test_phieumuon.dat");
    std::remove("data/test_lichsu.dat");
    std::remove("data/test_nhatky.txt");
    cout << "[PASS] Tuan 5: LinkedList, Dynamic Array, file .dat va log .txt.\n";
    return 0;
}
