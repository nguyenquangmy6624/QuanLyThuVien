@echo off
setlocal
if not exist build mkdir build

echo Dang bien dich unit test cho phan quyen va CSV...
g++ -std=c++11 -Wall -Wextra -pedantic -Ikhaibao kiemthu\test_tinh_nang.cpp manguon\phanquyen.cpp manguon\xuatcsv.cpp manguon\luutru.cpp -o build\test_tinh_nang.exe
if errorlevel 1 (
    echo Bien dich test that bai.
    exit /b 1
)
build\test_tinh_nang.exe
if errorlevel 1 exit /b 1
