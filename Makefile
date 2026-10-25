CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -Ikhaibao
SRC = manguon/main.cpp manguon/menu.cpp
TARGET = build/QuanLyThuVien.exe

all: $(TARGET)

$(TARGET): $(SRC) khaibao/menu.h
	@if not exist build mkdir build
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	@if exist build rmdir /S /Q build

.PHONY: all clean
