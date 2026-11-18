#ifndef BANGBAM_DOCGIA_H
#define BANGBAM_DOCGIA_H

#include "cacstruct.h"
#include <cstddef>
#include <string>
#include <vector>

// Hash Table tu cai dat bang separate chaining (moi bucket la danh sach nut).
class BangBamDocGia {
private:
    struct Nut {
        DocGia duLieu;
        Nut* tiepTheo;
        explicit Nut(const DocGia& docGia);
    };
    Nut** buckets_;
    std::size_t sucChua_;
    std::size_t soLuong_;
    std::size_t bam(const std::string& khoa) const;
    void moRongNeuCan();
    void doiSucChua(std::size_t sucChuaMoi);
public:
    explicit BangBamDocGia(std::size_t sucChuaBanDau = 17);
    ~BangBamDocGia();
    BangBamDocGia(const BangBamDocGia&) = delete;
    BangBamDocGia& operator=(const BangBamDocGia&) = delete;
    bool them(const DocGia& docGia);
    bool capNhat(const DocGia& docGia);
    bool xoa(const std::string& cmndCccd);
    DocGia* timKiem(const std::string& cmndCccd);
    const DocGia* timKiem(const std::string& cmndCccd) const;
    void toVector(std::vector<DocGia>& ketQua) const;
    std::size_t kichThuoc() const;
    std::size_t sucChua() const;
    std::size_t doDaiDayLonNhat() const;
    void xoaTatCa();
};

#endif
