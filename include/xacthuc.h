#ifndef XACTHUC_H
#define XACTHUC_H

#include "phanquyen.h"

// Tao cac tai khoan demo neu file tai khoan chua ton tai.
// Mat khau duoc luu dang ma bam demo, khong luu dang van ban thuong.
bool khoiTaoTaiKhoanNeuChuaCo(bool& daTaoMoi);

// Cho phep toi da 3 lan dang nhap trong moi lan goi.
bool dangNhap(TaiKhoanDangNhap& taiKhoanHienTai);

// Doi mat khau cho tai khoan dang dang nhap.
bool doiMatKhauTaiKhoan(const TaiKhoanDangNhap& taiKhoanHienTai);

#endif
