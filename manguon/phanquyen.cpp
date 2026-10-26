#include "phanquyen.h"

const char* tenVaiTro(VaiTro vaiTro) {
    switch (vaiTro) {
        case VaiTro::Admin: return "Admin";
        case VaiTro::ThuThu: return "Thu thu";
        case VaiTro::DocGia: return "Doc gia";
        default: return "Khong xac dinh";
    }
}

bool coQuyen(VaiTro vaiTro, ChucNang chucNang) {
    if (vaiTro == VaiTro::Admin) {
        return true;
    }

    if (vaiTro == VaiTro::ThuThu) {
        // Thu thu duoc quan ly nghiep vu thu vien, thong ke va xuat bao cao.
        return chucNang != ChucNang::LuuTru;
    }

    // Doc gia chi duoc tra cuu sach; khong duoc thay doi du lieu hoac xuat danh sach ca nhan.
    return chucNang == ChucNang::TimKiem;
}
