CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -Ikhaibao
SRC = manguon/main.cpp manguon/menu.cpp manguon/phanquyen.cpp manguon/xacthuc.cpp manguon/luutru.cpp manguon/xuatcsv.cpp
TARGET = build/QuanLyThuVien.exe

all: $(TARGET)

$(TARGET): $(SRC) khaibao/menu.h khaibao/phanquyen.h khaibao/xacthuc.h khaibao/luutru.h khaibao/xuatcsv.h khaibao/cacstruct.h
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

test:
	mkdir -p build
	$(CXX) $(CXXFLAGS) kiemthu/test_tinh_nang.cpp manguon/phanquyen.cpp manguon/xuatcsv.cpp manguon/luutru.cpp -o build/test_tinh_nang
	./build/test_tinh_nang

clean:
	rm -rf build

.PHONY: all test clean
