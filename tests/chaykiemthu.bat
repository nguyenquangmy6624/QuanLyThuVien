@echo off
setlocal
if not exist build mkdir build

echo Dang bien dich unit test cho phan quyen va CSV...
g++ -std=c++11 -Wall -Wextra -pedantic -Iinclude tests\test_tinh_nang.cpp src\phanquyen.cpp src\xuatcsv.cpp src\luutru.cpp -o build\test_tinh_nang.exe
if errorlevel 1 (
    echo Bien dich test that bai.
    exit /b 1
)
build\test_tinh_nang.exe
if errorlevel 1 exit /b 1
