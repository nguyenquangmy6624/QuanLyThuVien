#include "bangbam_docgia.h"

using namespace std;

BangBamDocGia::Nut::Nut(const DocGia& docGia) : duLieu(docGia), tiepTheo(NULL) {}

BangBamDocGia::BangBamDocGia(size_t sucChuaBanDau)
    : buckets_(NULL), sucChua_(sucChuaBanDau < 5 ? 5 : sucChuaBanDau), soLuong_(0) {
    buckets_ = new Nut*[sucChua_];
    for (size_t i = 0; i < sucChua_; ++i) buckets_[i] = NULL;
}

BangBamDocGia::~BangBamDocGia() { xoaTatCa(); delete[] buckets_; }

size_t BangBamDocGia::bam(const string& khoa) const {
    unsigned long long hash = 14695981039346656037ULL;
    for (string::const_iterator it = khoa.begin(); it != khoa.end(); ++it) {
        hash ^= static_cast<unsigned char>(*it);
        hash *= 1099511628211ULL;
    }
    return static_cast<size_t>(hash % sucChua_);
}

void BangBamDocGia::doiSucChua(size_t sucChuaMoi) {
    Nut** bangMoi = new Nut*[sucChuaMoi];
    for (size_t i = 0; i < sucChuaMoi; ++i) bangMoi[i] = NULL;
    for (size_t i = 0; i < sucChua_; ++i) {
        Nut* hienTai = buckets_[i];
        while (hienTai != NULL) {
            Nut* tiep = hienTai->tiepTheo;
            unsigned long long hash = 14695981039346656037ULL;
            for (string::const_iterator it = hienTai->duLieu.cmndCccd.begin(); it != hienTai->duLieu.cmndCccd.end(); ++it) {
                hash ^= static_cast<unsigned char>(*it);
                hash *= 1099511628211ULL;
            }
            size_t viTri = static_cast<size_t>(hash % sucChuaMoi);
            hienTai->tiepTheo = bangMoi[viTri];
            bangMoi[viTri] = hienTai;
            hienTai = tiep;
        }
    }
    delete[] buckets_;
    buckets_ = bangMoi;
    sucChua_ = sucChuaMoi;
}

void BangBamDocGia::moRongNeuCan() {
    if (soLuong_ * 4 >= sucChua_ * 3) doiSucChua(sucChua_ * 2 + 1);
}

bool BangBamDocGia::them(const DocGia& docGia) {
    if (docGia.cmndCccd.empty() || timKiem(docGia.cmndCccd) != NULL) return false;
    moRongNeuCan();
    const size_t viTri = bam(docGia.cmndCccd);
    Nut* nutMoi = new Nut(docGia);
    nutMoi->tiepTheo = buckets_[viTri];
    buckets_[viTri] = nutMoi;
    ++soLuong_;
    return true;
}

bool BangBamDocGia::capNhat(const DocGia& docGia) {
    DocGia* timThay = timKiem(docGia.cmndCccd);
    if (timThay == NULL) return false;
    *timThay = docGia;
    return true;
}

bool BangBamDocGia::xoa(const string& cmndCccd) {
    const size_t viTri = bam(cmndCccd);
    Nut* hienTai = buckets_[viTri];
    Nut* truoc = NULL;
    while (hienTai != NULL) {
        if (hienTai->duLieu.cmndCccd == cmndCccd) {
            if (truoc == NULL) buckets_[viTri] = hienTai->tiepTheo;
            else truoc->tiepTheo = hienTai->tiepTheo;
            delete hienTai;
            --soLuong_;
            return true;
        }
        truoc = hienTai;
        hienTai = hienTai->tiepTheo;
    }
    return false;
}

DocGia* BangBamDocGia::timKiem(const string& cmndCccd) {
    const size_t viTri = bam(cmndCccd);
    for (Nut* nut = buckets_[viTri]; nut != NULL; nut = nut->tiepTheo)
        if (nut->duLieu.cmndCccd == cmndCccd) return &nut->duLieu;
    return NULL;
}

const DocGia* BangBamDocGia::timKiem(const string& cmndCccd) const {
    const size_t viTri = bam(cmndCccd);
    for (Nut* nut = buckets_[viTri]; nut != NULL; nut = nut->tiepTheo)
        if (nut->duLieu.cmndCccd == cmndCccd) return &nut->duLieu;
    return NULL;
}

void BangBamDocGia::toVector(vector<DocGia>& ketQua) const {
    ketQua.clear();
    ketQua.reserve(soLuong_);
    for (size_t i = 0; i < sucChua_; ++i)
        for (Nut* nut = buckets_[i]; nut != NULL; nut = nut->tiepTheo) ketQua.push_back(nut->duLieu);
}

size_t BangBamDocGia::kichThuoc() const { return soLuong_; }
size_t BangBamDocGia::sucChua() const { return sucChua_; }

size_t BangBamDocGia::doDaiDayLonNhat() const {
    size_t lonNhat = 0;
    for (size_t i = 0; i < sucChua_; ++i) {
        size_t doDai = 0;
        for (Nut* nut = buckets_[i]; nut != NULL; nut = nut->tiepTheo) ++doDai;
        if (doDai > lonNhat) lonNhat = doDai;
    }
    return lonNhat;
}

void BangBamDocGia::xoaTatCa() {
    for (size_t i = 0; i < sucChua_; ++i) {
        Nut* nut = buckets_[i];
        while (nut != NULL) {
            Nut* tiep = nut->tiepTheo;
            delete nut;
            nut = tiep;
        }
        buckets_[i] = NULL;
    }
    soLuong_ = 0;
}
