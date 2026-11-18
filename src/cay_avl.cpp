#include "cay_avl.h"

#include <algorithm>

using namespace std;

CayAVL::Nut::Nut(const Sach& sach)
    : duLieu(sach), trai(NULL), phai(NULL), chieuCao(1) {}

CayAVL::CayAVL() : goc_(NULL), soLuong_(0) {}
CayAVL::~CayAVL() { xoaTatCa(); }

int CayAVL::chieuCao(Nut* nut) { return nut == NULL ? 0 : nut->chieuCao; }
int CayAVL::heSoCanBang(Nut* nut) {
    return nut == NULL ? 0 : chieuCao(nut->trai) - chieuCao(nut->phai);
}

CayAVL::Nut* CayAVL::quayPhai(Nut* y) {
    Nut* x = y->trai;
    Nut* t2 = x->phai;
    x->phai = y;
    y->trai = t2;
    y->chieuCao = 1 + max(chieuCao(y->trai), chieuCao(y->phai));
    x->chieuCao = 1 + max(chieuCao(x->trai), chieuCao(x->phai));
    return x;
}

CayAVL::Nut* CayAVL::quayTrai(Nut* x) {
    Nut* y = x->phai;
    Nut* t2 = y->trai;
    y->trai = x;
    x->phai = t2;
    x->chieuCao = 1 + max(chieuCao(x->trai), chieuCao(x->phai));
    y->chieuCao = 1 + max(chieuCao(y->trai), chieuCao(y->phai));
    return y;
}

CayAVL::Nut* CayAVL::chenNut(Nut* nut, const Sach& sach, bool& thanhCong) {
    if (nut == NULL) {
        thanhCong = true;
        return new Nut(sach);
    }
    if (sach.isbn < nut->duLieu.isbn) nut->trai = chenNut(nut->trai, sach, thanhCong);
    else if (sach.isbn > nut->duLieu.isbn) nut->phai = chenNut(nut->phai, sach, thanhCong);
    else return nut;

    nut->chieuCao = 1 + max(chieuCao(nut->trai), chieuCao(nut->phai));
    const int canBang = heSoCanBang(nut);
    if (canBang > 1 && sach.isbn < nut->trai->duLieu.isbn) return quayPhai(nut);
    if (canBang < -1 && sach.isbn > nut->phai->duLieu.isbn) return quayTrai(nut);
    if (canBang > 1 && sach.isbn > nut->trai->duLieu.isbn) {
        nut->trai = quayTrai(nut->trai);
        return quayPhai(nut);
    }
    if (canBang < -1 && sach.isbn < nut->phai->duLieu.isbn) {
        nut->phai = quayPhai(nut->phai);
        return quayTrai(nut);
    }
    return nut;
}

CayAVL::Nut* CayAVL::timNut(Nut* nut, const string& isbn) {
    while (nut != NULL) {
        if (isbn == nut->duLieu.isbn) return nut;
        nut = isbn < nut->duLieu.isbn ? nut->trai : nut->phai;
    }
    return NULL;
}

CayAVL::Nut* CayAVL::nutNhoNhat(Nut* nut) {
    while (nut != NULL && nut->trai != NULL) nut = nut->trai;
    return nut;
}

CayAVL::Nut* CayAVL::xoaNut(Nut* nut, const string& isbn, bool& daXoa) {
    if (nut == NULL) return NULL;
    if (isbn < nut->duLieu.isbn) nut->trai = xoaNut(nut->trai, isbn, daXoa);
    else if (isbn > nut->duLieu.isbn) nut->phai = xoaNut(nut->phai, isbn, daXoa);
    else {
        daXoa = true;
        if (nut->trai == NULL || nut->phai == NULL) {
            Nut* con = nut->trai != NULL ? nut->trai : nut->phai;
            delete nut;
            return con;
        }
        Nut* keTiep = nutNhoNhat(nut->phai);
        nut->duLieu = keTiep->duLieu;
        bool boQuaDem = false;
        nut->phai = xoaNut(nut->phai, keTiep->duLieu.isbn, boQuaDem);
    }

    if (nut == NULL) return NULL;
    nut->chieuCao = 1 + max(chieuCao(nut->trai), chieuCao(nut->phai));
    const int canBang = heSoCanBang(nut);
    if (canBang > 1 && heSoCanBang(nut->trai) >= 0) return quayPhai(nut);
    if (canBang > 1 && heSoCanBang(nut->trai) < 0) {
        nut->trai = quayTrai(nut->trai);
        return quayPhai(nut);
    }
    if (canBang < -1 && heSoCanBang(nut->phai) <= 0) return quayTrai(nut);
    if (canBang < -1 && heSoCanBang(nut->phai) > 0) {
        nut->phai = quayPhai(nut->phai);
        return quayTrai(nut);
    }
    return nut;
}

void CayAVL::duyetInOrder(Nut* nut, vector<Sach>& ketQua) {
    if (nut == NULL) return;
    duyetInOrder(nut->trai, ketQua);
    ketQua.push_back(nut->duLieu);
    duyetInOrder(nut->phai, ketQua);
}

void CayAVL::giaiPhong(Nut* nut) {
    if (nut == NULL) return;
    giaiPhong(nut->trai);
    giaiPhong(nut->phai);
    delete nut;
}

bool CayAVL::kiemTraCanBang(Nut* nut, int& chieuCaoThucTe) {
    if (nut == NULL) { chieuCaoThucTe = 0; return true; }
    int caoTrai = 0, caoPhai = 0;
    if (!kiemTraCanBang(nut->trai, caoTrai) || !kiemTraCanBang(nut->phai, caoPhai)) return false;
    chieuCaoThucTe = 1 + max(caoTrai, caoPhai);
    return (caoTrai - caoPhai <= 1 && caoPhai - caoTrai <= 1 && nut->chieuCao == chieuCaoThucTe);
}

bool CayAVL::them(const Sach& sach) {
    bool thanhCong = false;
    goc_ = chenNut(goc_, sach, thanhCong);
    if (thanhCong) ++soLuong_;
    return thanhCong;
}

bool CayAVL::capNhat(const Sach& sach) {
    Nut* nut = timNut(goc_, sach.isbn);
    if (nut == NULL) return false;
    nut->duLieu = sach;
    return true;
}

bool CayAVL::xoa(const string& isbn) {
    bool daXoa = false;
    goc_ = xoaNut(goc_, isbn, daXoa);
    if (daXoa) --soLuong_;
    return daXoa;
}

const Sach* CayAVL::timKiem(const string& isbn) const {
    Nut* nut = timNut(goc_, isbn);
    return nut == NULL ? NULL : &nut->duLieu;
}

void CayAVL::duyetTangDan(vector<Sach>& ketQua) const {
    ketQua.clear();
    duyetInOrder(goc_, ketQua);
}

size_t CayAVL::kichThuoc() const { return soLuong_; }
bool CayAVL::rong() const { return goc_ == NULL; }
bool CayAVL::cayCanBang() const { int cao = 0; return kiemTraCanBang(goc_, cao); }
void CayAVL::xoaTatCa() { giaiPhong(goc_); goc_ = NULL; soLuong_ = 0; }
