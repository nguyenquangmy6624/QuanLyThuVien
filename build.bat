@echo off
setlocal
if not exist build mkdir build
if not exist data mkdir data
if not exist data\nhatky mkdir data\nhatky
if not exist data\saoluu mkdir data\saoluu

echo Dang bien dich QuanLyThuVien bang C++11...
g++ -std=c++11 -Wall -Wextra -pedantic -Iinclude src\main.cpp src\menu.cpp src\phanquyen.cpp src\xacthuc.cpp src\luutru.cpp src\xuatcsv.cpp -o build\QuanLyThuVien.exe
if errorlevel 1 (
    echo Bien dich that bai. Hay kiem tra thong bao loi phia tren.
    exit /b 1
)
echo Bien dich thanh cong. Dang chay chuong trinh...
build\QuanLyThuVien.exe
