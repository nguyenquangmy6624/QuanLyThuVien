CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -Iinclude
SRC = src/main.cpp src/menu.cpp src/phanquyen.cpp src/xacthuc.cpp src/luutru.cpp src/xuatcsv.cpp
HEADERS = include/cacstruct.h include/menu.h include/phanquyen.h include/xacthuc.h include/luutru.h include/xuatcsv.h
TARGET = build/QuanLyThuVien

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

test:
	mkdir -p build
	$(CXX) $(CXXFLAGS) tests/test_tinh_nang.cpp src/phanquyen.cpp src/xuatcsv.cpp src/luutru.cpp -o build/test_tinh_nang
	./build/test_tinh_nang

clean:
	rm -rf build

.PHONY: all test clean
