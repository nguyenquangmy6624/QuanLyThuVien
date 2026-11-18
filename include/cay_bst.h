#ifndef CAY_BST_H
#define CAY_BST_H

#include "cacstruct.h"
#include <cstddef>
#include <vector>

// Cay BST dung rieng cho thao tac liet ke sach tang dan bang in-order.
class CayBSTSach {
private:
    struct Nut {
        Sach duLieu;
        Nut* trai;
        Nut* phai;
        explicit Nut(const Sach& sach);
    };
    Nut* goc_;
    std::size_t soLuong_;
    static void giaiPhong(Nut* nut);
    static void duyetInOrder(Nut* nut, std::vector<Sach>& ketQua);
    static void chenTheoTrungVi(CayBSTSach& cay, const std::vector<Sach>& danhSach, std::size_t dau, std::size_t cuoi);
public:
    CayBSTSach();
    ~CayBSTSach();
    CayBSTSach(const CayBSTSach&) = delete;
    CayBSTSach& operator=(const CayBSTSach&) = delete;
    bool them(const Sach& sach);
    void taoTuDanhSach(const std::vector<Sach>& danhSach);
    void duyetInOrder(std::vector<Sach>& ketQua) const;
    std::size_t kichThuoc() const;
};

#endif
