#ifndef CAY_AVL_H
#define CAY_AVL_H

#include "cacstruct.h"
#include <cstddef>
#include <string>
#include <vector>

// Cay AVL tu cai dat, khoa sap xep la ISBN.
class CayAVL {
private:
    struct Nut {
        Sach duLieu;
        Nut* trai;
        Nut* phai;
        int chieuCao;
        explicit Nut(const Sach& sach);
    };

    Nut* goc_;
    std::size_t soLuong_;

    static int chieuCao(Nut* nut);
    static int heSoCanBang(Nut* nut);
    static Nut* quayPhai(Nut* y);
    static Nut* quayTrai(Nut* x);
    static Nut* chenNut(Nut* nut, const Sach& sach, bool& thanhCong);
    static Nut* timNut(Nut* nut, const std::string& isbn);
    static Nut* nutNhoNhat(Nut* nut);
    static Nut* xoaNut(Nut* nut, const std::string& isbn, bool& daXoa);
    static void duyetInOrder(Nut* nut, std::vector<Sach>& ketQua);
    static void giaiPhong(Nut* nut);
    static bool kiemTraCanBang(Nut* nut, int& chieuCaoThucTe);

public:
    CayAVL();
    ~CayAVL();
    CayAVL(const CayAVL&) = delete;
    CayAVL& operator=(const CayAVL&) = delete;

    bool them(const Sach& sach);
    bool capNhat(const Sach& sach);
    bool xoa(const std::string& isbn);
    const Sach* timKiem(const std::string& isbn) const;
    void duyetTangDan(std::vector<Sach>& ketQua) const;
    std::size_t kichThuoc() const;
    bool rong() const;
    bool cayCanBang() const;
    void xoaTatCa();
};

#endif
