#include "bangbam_docgia.h"

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

static DocGia taoDocGia(int i) {
    ostringstream khoa;
    khoa << "07900000";
    if (i < 10) khoa << "000";
    else if (i < 100) khoa << "00";
    else khoa << '0';
    khoa << i;
    DocGia dg = {khoa.str(), "Doc gia " + khoa.str(), "test@example.com", "0900000000", "Thuong"};
    return dg;
}

int main() {
    BangBamDocGia bang(5);
    vector<string> khoa;
    for (int i = 1; i <= 80; ++i) {
        DocGia dg = taoDocGia(i);
        khoa.push_back(dg.cmndCccd);
        assert(bang.them(dg));
    }
    assert(bang.kichThuoc() == 80);
    assert(bang.sucChua() > 5); // da tu dong mo rong
    assert(bang.doDaiDayLonNhat() >= 2); // co va cham: mot bucket chua tu hai nut tro len
    assert(!bang.them(taoDocGia(1))); // khoa trung

    const DocGia* timThay = bang.timKiem(khoa[29]);
    assert(timThay != NULL);
    assert(timThay->hoTen == "Doc gia " + khoa[29]);

    DocGia sua = *timThay;
    sua.hoTen = "Ten moi";
    assert(bang.capNhat(sua));
    assert(bang.timKiem(khoa[29])->hoTen == "Ten moi");

    assert(bang.xoa(khoa[29]));
    assert(bang.timKiem(khoa[29]) == NULL);
    assert(!bang.xoa(khoa[29]));

    vector<DocGia> ketQua;
    bang.toVector(ketQua);
    assert(ketQua.size() == 79);
    cout << "[PASS] Tuan 4: Hash Table separate chaining, them/tim/sua/xoa/mo rong.\n";
    return 0;
}
