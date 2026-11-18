#ifndef LUUTRU_H
#define LUUTRU_H

#include "cacstruct.h"
#include <string>
#include <vector>

bool docDanhSachSach(std::vector<Sach>& danhSach, std::string& loi);
bool ghiDanhSachSach(const std::vector<Sach>& danhSach, std::string& loi);
bool docDanhSachDocGia(std::vector<DocGia>& danhSach, std::string& loi);
bool ghiDanhSachDocGia(const std::vector<DocGia>& danhSach, std::string& loi);

// File nhi phan cho danh sach phieu muon va lich su giao dich (Tuan 5).
bool docDanhSachPhieuMuon(std::vector<PhieuMuon>& danhSach, std::string& loi,
                          const std::string& duongDan = "data/phieumuon.dat");
bool ghiDanhSachPhieuMuon(const std::vector<PhieuMuon>& danhSach, std::string& loi,
                          const std::string& duongDan = "data/phieumuon.dat");
bool docLichSuGiaoDich(std::vector<GiaoDich>& danhSach, std::string& loi,
                       const std::string& duongDan = "data/lichsugiaodich.dat");
bool ghiLichSuGiaoDich(const std::vector<GiaoDich>& danhSach, std::string& loi,
                       const std::string& duongDan = "data/lichsugiaodich.dat");

// Ghi nhat ky thao tac vao file van ban .txt.
bool ghiNhatKy(const std::string& noiDung, std::string& loi,
               const std::string& duongDan = "data/nhatky/hoatdong.txt");

// Tao file .dat mau neu chua co. Khong ghi de len file da ton tai.
bool khoiTaoDuLieuMauNeuChuaCo(bool& daTaoMoi, std::string& loi);

#endif
