#include "cay_bst.h"

#include <algorithm>

using namespace std;

CayBSTSach::Nut::Nut(const Sach& sach) : duLieu(sach), trai(NULL), phai(NULL) {}
CayBSTSach::CayBSTSach() : goc_(NULL), soLuong_(0) {}
CayBSTSach::~CayBSTSach() { giaiPhong(goc_); }

bool CayBSTSach::them(const Sach& sach) {
    Nut** viTri = &goc_;
    while (*viTri != NULL) {
        if (sach.isbn == (*viTri)->duLieu.isbn) return false;
        viTri = sach.isbn < (*viTri)->duLieu.isbn ? &(*viTri)->trai : &(*viTri)->phai;
    }
    *viTri = new Nut(sach);
    ++soLuong_;
    return true;
}

void CayBSTSach::chenTheoTrungVi(CayBSTSach& cay, const vector<Sach>& danhSach,
                                      size_t dau, size_t cuoi) {
    if (dau >= cuoi) return;
    const size_t giua = dau + (cuoi - dau) / 2;
    cay.them(danhSach[giua]);
    chenTheoTrungVi(cay, danhSach, dau, giua);
    chenTheoTrungVi(cay, danhSach, giua + 1, cuoi);
}

void CayBSTSach::taoTuDanhSach(const vector<Sach>& danhSach) {
    giaiPhong(goc_);
    goc_ = NULL;
    soLuong_ = 0;
    vector<Sach> daSapXep(danhSach);
    sort(daSapXep.begin(), daSapXep.end(), [](const Sach& a, const Sach& b) {
        return a.isbn < b.isbn;
    });
    // Chen theo trung vi de tranh tao cay lech khi du lieu dau vao da duoc sap xep.
    chenTheoTrungVi(*this, daSapXep, 0, daSapXep.size());
}

void CayBSTSach::duyetInOrder(Nut* nut, vector<Sach>& ketQua) {
    if (nut == NULL) return;
    duyetInOrder(nut->trai, ketQua);
    ketQua.push_back(nut->duLieu);
    duyetInOrder(nut->phai, ketQua);
}

void CayBSTSach::duyetInOrder(vector<Sach>& ketQua) const {
    ketQua.clear();
    duyetInOrder(goc_, ketQua);
}

void CayBSTSach::giaiPhong(Nut* nut) {
    if (nut == NULL) return;
    giaiPhong(nut->trai);
    giaiPhong(nut->phai);
    delete nut;
}

size_t CayBSTSach::kichThuoc() const { return soLuong_; }
