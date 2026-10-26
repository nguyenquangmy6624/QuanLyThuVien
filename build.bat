@echo off
setlocal
if not exist build mkdir build

echo Dang bien dich chuong trinh C++11...
g++ -std=c++11 -Wall -Wextra -pedantic -Ikhaibao manguon\main.cpp manguon\menu.cpp manguon\phanquyen.cpp manguon\xacthuc.cpp manguon\luutru.cpp manguon\xuatcsv.cpp -o build\QuanLyThuVien.exe
if errorlevel 1 (
    echo Bien dich that bai. Hay kiem tra thong bao loi phia tren.
    exit /b 1
)

echo Bien dich thanh cong. Dang chay chuong trinh...
build\QuanLyThuVien.exe
