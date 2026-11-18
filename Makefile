CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -Iinclude
SRC = src/main.cpp src/menu.cpp src/phanquyen.cpp src/xacthuc.cpp src/luutru.cpp src/xuatcsv.cpp \
      src/cay_avl.cpp src/cay_bst.cpp src/quanly_sach.cpp src/bangbam_docgia.cpp \
      src/quanly_docgia.cpp src/danh_sach_phieumuon.cpp src/menu_tuan5.cpp
HEADERS = $(wildcard include/*.h)
TARGET = build/QuanLyThuVien

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	mkdir -p build data/nhatky data/saoluu
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

test:
	bash tests/chaykiemthu.sh

clean:
	rm -rf build

.PHONY: all test clean
