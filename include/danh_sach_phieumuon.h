#ifndef DANH_SACH_PHIEUMUON_H
#define DANH_SACH_PHIEUMUON_H

#include "cacstruct.h"
#include <cstddef>
#include <vector>

// Danh sach lien ket don tu cai dat de quan ly phieu muon.
class DanhSachPhieuMuon {
private:
    struct Nut {
        PhieuMuon duLieu;
        Nut* tiepTheo;
        explicit Nut(const PhieuMuon& phieu);
    };
    Nut* dau_;
    Nut* cuoi_;
    std::size_t soLuong_;
public:
    DanhSachPhieuMuon();
    ~DanhSachPhieuMuon();
    DanhSachPhieuMuon(const DanhSachPhieuMuon&) = delete;
    DanhSachPhieuMuon& operator=(const DanhSachPhieuMuon&) = delete;
    void themCuoi(const PhieuMuon& phieu);
    bool xoa(const std::string& maPhieu);
    PhieuMuon* timKiem(const std::string& maPhieu);
    const PhieuMuon* timKiem(const std::string& maPhieu) const;
    void napTuVector(const std::vector<PhieuMuon>& danhSach);
    void toVector(std::vector<PhieuMuon>& ketQua) const;
    std::size_t kichThuoc() const;
    bool rong() const;
    void xoaTatCa();
};

#endif
