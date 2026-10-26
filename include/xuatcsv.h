#ifndef XUATCSV_H
#define XUATCSV_H

#include <string>

// Escaping RFC-4180 co ban: bao quote neu co dau phay, quote hoac xuong dong.
std::string chuanHoaTruongCSV(const std::string& giaTri);

bool xuatSachCSV(const std::string& duongDan, std::string& loi);
bool xuatDocGiaCSV(const std::string& duongDan, std::string& loi);
void menuXuatCSV();

#endif
