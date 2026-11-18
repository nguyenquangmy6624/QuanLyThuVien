@echo off
setlocal
if not exist build mkdir build
if not exist data mkdir data

echo [1/4] Kiem thu tinh nang dang nhap/quyen va CSV...
g++ -std=c++11 -Wall -Wextra -pedantic -Iinclude tests\test_tinh_nang.cpp src\phanquyen.cpp src\xuatcsv.cpp src\luutru.cpp -o build\test_tinh_nang.exe
if errorlevel 1 exit /b 1
build\test_tinh_nang.exe
if errorlevel 1 exit /b 1

echo [2/4] Kiem thu AVL va BST (Tuan 3)...
g++ -std=c++11 -Wall -Wextra -pedantic -Iinclude tests\test_tuan3.cpp src\cay_avl.cpp src\cay_bst.cpp -o build\test_tuan3.exe
if errorlevel 1 exit /b 1
build\test_tuan3.exe
if errorlevel 1 exit /b 1

echo [3/4] Kiem thu Hash Table (Tuan 4)...
g++ -std=c++11 -Wall -Wextra -pedantic -Iinclude tests\test_tuan4.cpp src\bangbam_docgia.cpp -o build\test_tuan4.exe
if errorlevel 1 exit /b 1
build\test_tuan4.exe
if errorlevel 1 exit /b 1

echo [4/4] Kiem thu LinkedList, Dynamic Array, File I/O (Tuan 5)...
g++ -std=c++11 -Wall -Wextra -pedantic -Iinclude tests\test_tuan5.cpp src\danh_sach_phieumuon.cpp src\luutru.cpp -o build\test_tuan5.exe
if errorlevel 1 exit /b 1
build\test_tuan5.exe
if errorlevel 1 exit /b 1

echo.
echo TAT CA KIEM THU DA DAT.
