#include "danh_sach_phieumuon.h"

using namespace std;

DanhSachPhieuMuon::Nut::Nut(const PhieuMuon& phieu) : duLieu(phieu), tiepTheo(NULL) {}
DanhSachPhieuMuon::DanhSachPhieuMuon() : dau_(NULL), cuoi_(NULL), soLuong_(0) {}
DanhSachPhieuMuon::~DanhSachPhieuMuon() { xoaTatCa(); }

void DanhSachPhieuMuon::themCuoi(const PhieuMuon& phieu) {
    Nut* nutMoi = new Nut(phieu);
    if (cuoi_ == NULL) dau_ = cuoi_ = nutMoi;
    else { cuoi_->tiepTheo = nutMoi; cuoi_ = nutMoi; }
    ++soLuong_;
}

bool DanhSachPhieuMuon::xoa(const string& maPhieu) {
    Nut* hienTai = dau_;
    Nut* truoc = NULL;
    while (hienTai != NULL) {
        if (hienTai->duLieu.maPhieu == maPhieu) {
            if (truoc == NULL) dau_ = hienTai->tiepTheo;
            else truoc->tiepTheo = hienTai->tiepTheo;
            if (hienTai == cuoi_) cuoi_ = truoc;
            delete hienTai;
            --soLuong_;
            if (dau_ == NULL) cuoi_ = NULL;
            return true;
        }
        truoc = hienTai;
        hienTai = hienTai->tiepTheo;
    }
    return false;
}

PhieuMuon* DanhSachPhieuMuon::timKiem(const string& maPhieu) {
    for (Nut* nut = dau_; nut != NULL; nut = nut->tiepTheo)
        if (nut->duLieu.maPhieu == maPhieu) return &nut->duLieu;
    return NULL;
}

const PhieuMuon* DanhSachPhieuMuon::timKiem(const string& maPhieu) const {
    for (Nut* nut = dau_; nut != NULL; nut = nut->tiepTheo)
        if (nut->duLieu.maPhieu == maPhieu) return &nut->duLieu;
    return NULL;
}

void DanhSachPhieuMuon::napTuVector(const vector<PhieuMuon>& danhSach) {
    xoaTatCa();
    for (vector<PhieuMuon>::const_iterator it = danhSach.begin(); it != danhSach.end(); ++it) themCuoi(*it);
}

void DanhSachPhieuMuon::toVector(vector<PhieuMuon>& ketQua) const {
    ketQua.clear();
    ketQua.reserve(soLuong_);
    for (Nut* nut = dau_; nut != NULL; nut = nut->tiepTheo) ketQua.push_back(nut->duLieu);
}

size_t DanhSachPhieuMuon::kichThuoc() const { return soLuong_; }
bool DanhSachPhieuMuon::rong() const { return dau_ == NULL; }

void DanhSachPhieuMuon::xoaTatCa() {
    Nut* nut = dau_;
    while (nut != NULL) {
        Nut* tiep = nut->tiepTheo;
        delete nut;
        nut = tiep;
    }
    dau_ = cuoi_ = NULL;
    soLuong_ = 0;
}
