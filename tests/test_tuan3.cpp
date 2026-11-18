#include "cay_avl.h"
#include "cay_bst.h"

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static Sach taoSach(const string& isbn) {
    Sach sach = {isbn, "Ten " + isbn, "Tac gia", "CNTT", 2024, 5, 5};
    return sach;
}

static void kiemThuBonTruongHopQuay(const string& a, const string& b, const string& c) {
    CayAVL cay;
    assert(cay.them(taoSach(a)));
    assert(cay.them(taoSach(b)));
    assert(cay.them(taoSach(c)));
    assert(cay.cayCanBang());
    assert(cay.kichThuoc() == 3);
    vector<Sach> thuTu;
    cay.duyetTangDan(thuTu);
    assert(thuTu.size() == 3);
    assert(thuTu[0].isbn < thuTu[1].isbn && thuTu[1].isbn < thuTu[2].isbn);
}

int main() {
    // Tuong ung cac truong hop can bang LL, RR, LR va RL.
    kiemThuBonTruongHopQuay("0000000003", "0000000002", "0000000001");
    kiemThuBonTruongHopQuay("0000000001", "0000000002", "0000000003");
    kiemThuBonTruongHopQuay("0000000003", "0000000001", "0000000002");
    kiemThuBonTruongHopQuay("0000000001", "0000000003", "0000000002");

    CayAVL avl;
    const char* ds[] = {"0000000003", "0000000002", "0000000001", "0000000005", "0000000004", "0000000006", "0000000007"};
    for (size_t i = 0; i < sizeof(ds) / sizeof(ds[0]); ++i) assert(avl.them(taoSach(ds[i])));
    assert(!avl.them(taoSach("0000000003")));
    assert(avl.kichThuoc() == 7);
    assert(avl.cayCanBang());
    assert(avl.timKiem("0000000004") != NULL);
    assert(avl.timKiem("9999999999") == NULL);

    Sach capNhat = taoSach("0000000004");
    capNhat.tenSach = "Ten da sua";
    assert(avl.capNhat(capNhat));
    assert(avl.timKiem("0000000004")->tenSach == "Ten da sua");

    assert(avl.xoa("0000000004"));
    assert(!avl.xoa("0000000004"));
    assert(avl.cayCanBang());

    vector<Sach> danhSach;
    avl.duyetTangDan(danhSach);
    for (size_t i = 1; i < danhSach.size(); ++i) assert(danhSach[i - 1].isbn < danhSach[i].isbn);

    CayBSTSach bst;
    bst.taoTuDanhSach(danhSach);
    vector<Sach> ketQuaBST;
    bst.duyetInOrder(ketQuaBST);
    assert(ketQuaBST.size() == danhSach.size());
    for (size_t i = 1; i < ketQuaBST.size(); ++i) assert(ketQuaBST[i - 1].isbn < ketQuaBST[i].isbn);

    cout << "[PASS] Tuan 3: AVL them/tim/sua/xoa/can bang va BST in-order.\n";
    return 0;
}
