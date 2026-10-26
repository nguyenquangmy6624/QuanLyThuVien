#ifndef LUUTRU_H
#define LUUTRU_H

#include "cacstruct.h"
#include <string>
#include <vector>

bool docDanhSachSach(std::vector<Sach>& danhSach, std::string& loi);
bool ghiDanhSachSach(const std::vector<Sach>& danhSach, std::string& loi);
bool docDanhSachDocGia(std::vector<DocGia>& danhSach, std::string& loi);
bool ghiDanhSachDocGia(const std::vector<DocGia>& danhSach, std::string& loi);

// Tao file .dat mau neu chua co. Khong ghi de len file da ton tai.
bool khoiTaoDuLieuMauNeuChuaCo(bool& daTaoMoi, std::string& loi);

#endif
