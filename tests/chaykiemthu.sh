#!/usr/bin/env bash
set -e
mkdir -p build data
CXXFLAGS="-std=c++11 -Wall -Wextra -pedantic -Iinclude"
g++ $CXXFLAGS tests/test_tinh_nang.cpp src/phanquyen.cpp src/xuatcsv.cpp src/luutru.cpp -o build/test_tinh_nang
./build/test_tinh_nang
g++ $CXXFLAGS tests/test_tuan3.cpp src/cay_avl.cpp src/cay_bst.cpp -o build/test_tuan3
./build/test_tuan3
g++ $CXXFLAGS tests/test_tuan4.cpp src/bangbam_docgia.cpp -o build/test_tuan4
./build/test_tuan4
g++ $CXXFLAGS tests/test_tuan5.cpp src/danh_sach_phieumuon.cpp src/luutru.cpp -o build/test_tuan5
./build/test_tuan5
echo "TAT CA KIEM THU DA DAT."
