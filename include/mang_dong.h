#ifndef MANG_DONG_H
#define MANG_DONG_H

#include <cstddef>
#include <stdexcept>
#include <algorithm>

// Mang dong tu cai dat bang cap phat new[]/delete[].
template <typename T>
class MangDong {
private:
    T* duLieu_;
    std::size_t kichThuoc_;
    std::size_t sucChua_;

    void moRong(std::size_t sucChuaMoi) {
        T* moi = new T[sucChuaMoi];
        for (std::size_t i = 0; i < kichThuoc_; ++i) moi[i] = duLieu_[i];
        delete[] duLieu_;
        duLieu_ = moi;
        sucChua_ = sucChuaMoi;
    }
public:
    explicit MangDong(std::size_t sucChuaBanDau = 4)
        : duLieu_(NULL), kichThuoc_(0), sucChua_(sucChuaBanDau) {
        if (sucChua_ > 0) duLieu_ = new T[sucChua_];
    }
    ~MangDong() { delete[] duLieu_; }

    MangDong(const MangDong& other)
        : duLieu_(other.sucChua_ ? new T[other.sucChua_] : NULL),
          kichThuoc_(other.kichThuoc_), sucChua_(other.sucChua_) {
        for (std::size_t i = 0; i < kichThuoc_; ++i) duLieu_[i] = other.duLieu_[i];
    }
    MangDong& operator=(const MangDong& other) {
        if (this == &other) return *this;
        T* moi = other.sucChua_ ? new T[other.sucChua_] : NULL;
        for (std::size_t i = 0; i < other.kichThuoc_; ++i) moi[i] = other.duLieu_[i];
        delete[] duLieu_;
        duLieu_ = moi;
        kichThuoc_ = other.kichThuoc_;
        sucChua_ = other.sucChua_;
        return *this;
    }

    void themCuoi(const T& giaTri) {
        if (kichThuoc_ == sucChua_) moRong(sucChua_ == 0 ? 4 : sucChua_ * 2);
        duLieu_[kichThuoc_++] = giaTri;
    }
    bool xoaTai(std::size_t viTri) {
        if (viTri >= kichThuoc_) return false;
        for (std::size_t i = viTri; i + 1 < kichThuoc_; ++i) duLieu_[i] = duLieu_[i + 1];
        --kichThuoc_;
        return true;
    }
    T& tai(std::size_t viTri) {
        if (viTri >= kichThuoc_) throw std::out_of_range("Vi tri mang dong vuot pham vi");
        return duLieu_[viTri];
    }
    const T& tai(std::size_t viTri) const {
        if (viTri >= kichThuoc_) throw std::out_of_range("Vi tri mang dong vuot pham vi");
        return duLieu_[viTri];
    }
    T& operator[](std::size_t viTri) { return tai(viTri); }
    const T& operator[](std::size_t viTri) const { return tai(viTri); }
    std::size_t kichThuoc() const { return kichThuoc_; }
    std::size_t sucChua() const { return sucChua_; }
    bool rong() const { return kichThuoc_ == 0; }
    void xoaTatCa() { kichThuoc_ = 0; }
};

#endif
