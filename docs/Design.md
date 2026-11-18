# Design - Thiet ke he thong QuanLyThuVien

**Pham vi:** kien truc module, menu/luong chinh, struct du lieu va mapping CTDL theo checklist 10 tuan.

## 1. Nguyen tac thiet ke
- C++11 tro len; console menu; chia header trong `include/` va cai dat trong `src/`.
- Khong su dung co so du lieu. File `.dat` luu du lieu chinh; `.txt` luu log/bao cao; CSV dung cho xuat bao cao.
- Kiem tra du lieu va quyen tai cac diem xu ly, khong chi an muc menu.
- Cac CTDL bat buoc duoc tu cai dat; khong dung container san de thay the CTDL ma bai yeu cau.

## 2. Kien truc module hien tai
| Module | Tep chinh | Trach nhiem |
|---|---|---|
| Dieu phoi va menu | `src/main.cpp`, `src/menu.cpp` | Khoi dong, dang nhap, dieu phoi menu theo vai tro |
| Dang nhap va phan quyen | `src/xacthuc.cpp`, `src/phanquyen.cpp` | Xac thuc tai khoan, doi mat khau, kiem tra quyen |
| Luu tru | `src/luutru.cpp` | Doc/ghi file nhi phan sach, doc gia, phieu muon, giao dich; ghi log TXT |
| Xuat CSV | `src/xuatcsv.cpp` | Xuat danh muc sach va doc gia |
| Quan ly sach | `src/quanly_sach.cpp` | CRUD sach thong qua cay AVL; in danh muc bang BST |
| Cay AVL | `src/cay_avl.cpp` | Chi muc sach theo ISBN, tu can bang sau them/xoa |
| Cay BST | `src/cay_bst.cpp` | Duyet in-order danh muc ISBN tang dan |
| Quan ly doc gia | `src/quanly_docgia.cpp` | CRUD doc gia thong qua Hash Table |
| Hash Table | `src/bangbam_docgia.cpp` | Separate chaining, tu mo rong khi load factor dat nguong |
| Phieu muon | `src/danh_sach_phieumuon.cpp` | Danh sach lien ket don tu cai dat |
| Lich su giao dich | `include/mang_dong.h` | Mang dong tu cai dat, tang suc chua khi can |
| Demo Tuan 5 | `src/menu_tuan5.cpp` | Minh hoa LinkedList, Dynamic Array va luu/nap file |

## 3. Struct du lieu
- `Sach`: ISBN, ten sach, tac gia, the loai, nam xuat ban, so luong tong, so luong con.
- `DocGia`: CMND/CCCD, ho ten, email, so dien thoai, loai the.
- `PhieuMuon`: ma phieu, CMND/CCCD, ISBN, ngay muon, ngay hen tra, ngay tra, trang thai da tra, tien phat.
- `GiaoDich`: ma giao dich, loai giao dich, doi tuong, thoi gian va ghi chu.

## 4. Map CTDL, ly do chon va do phuc tap
| CTDL | Ap dung | Ly do | Do phuc tap muc tieu |
|---|---|---|---|
| AVL | Quan ly sach theo ISBN | Tim kiem on dinh, cay tu can bang | Them/tim/xoa O(log n), duyet O(n) |
| BST | In danh muc sach theo ISBN | In-order cho thu tu tang dan | Them/tim O(h), duyet O(n) |
| Hash Table separate chaining | Quan ly doc gia theo CMND/CCCD | Tra cuu theo khoa dinh danh | Trung binh O(1), xau nhat O(n) |
| LinkedList don | Danh sach phieu muon | Them cuoi O(1), kich thuoc linh hoat | Them cuoi O(1), tim/xoa O(n) |
| Dynamic Array | Lich su giao dich | Truy cap theo chi so nhanh | Truy cap O(1), them cuoi amortized O(1), xoa giua O(n) |
| File I/O | Luu tru sach/doc gia/phieu/giao dich | Dap ung yeu cau khong dung CSDL | Phu thuoc so byte/ban ghi, doc ghi tuan tu O(n) |
| Do thi danh sach ke + BFS/DFS | Goi y sach cung the loai | Bieu dien lien ket sach | Duyet O(V+E), chua trien khai (Tuan 7) |
| CTDL cay tu tim hieu | Phan nang cao | Theo yeu cau muc CTDL tu tim hieu | Can chot loai cay cu the voi giang vien truoc khi code |

`n` la so sach/doc gia/ban ghi; `h` la chieu cao BST; `V` va `E` lan luot la so dinh va so canh cua do thi.

## 5. Tuan 3 - Quan ly sach
- Cay AVL duoc dung lam chi muc chinh cho ISBN. Them sach tu choi ISBN trung; sua tim nut theo ISBN va cap nhat noi dung; xoa ho tro nut la, mot con va hai con.
- Sau khi them/xoa, AVL cap nhat chieu cao va xu ly bon truong hop quay LL, RR, LR, RL.
- BST duoc tao tu danh sach sach de duyet in-order va in danh muc tang dan theo ISBN.
- Cac thao tac thay doi sach duoc ghi lai vao `data/nhatky/hoatdong.txt` va luu lai `data/sach.dat`.

## 6. Tuan 4 - Quan ly doc gia
- Hash Table dung mang bucket va danh sach nut lien ket trong tung bucket (separate chaining).
- Ham bam FNV-1a duoc dung cho khoa CMND/CCCD; bang bam tu mo rong khi load factor dat 0.75.
- Ho tro them, tim, sua, xoa va liet ke doc gia. Du lieu duoc luu lai vao `data/docgia.dat`; thao tac duoc ghi log TXT.

## 7. Tuan 5 - LinkedList, Dynamic Array va File I/O
- `DanhSachPhieuMuon` tu cai dat nut lien ket don, co con tro dau/cuoi; them cuoi O(1), tim/xoa O(n).
- `MangDong<T>` tu cai dat bang `new[]`/`delete[]`; tang suc chua gap doi, truy cap O(1), them cuoi amortized O(1).
- `data/phieumuon.dat` luu phieu muon; `data/lichsugiaodich.dat` luu giao dich. File co ma nhan dang, version, so luong ban ghi; chuoi duoc ghi theo do dai truoc, khong ghi truc tiep struct co `std::string`.
- Lop luu tru dung vector trung gian de chuyen du lieu vao/ra file; xu ly nghiep vu va thao tac CTDL van su dung cac CTDL tu cai dat noi tren.
- Menu muc 10 la demo CTDL Tuan 5; chua phai quy trinh muon-tra hoan chinh. Quy tac muon sach, cap nhat so luong, tra sach va tinh phat nam o Tuan 6.

## 8. Luu tru va bao mat
- `data/sach.dat`, `data/docgia.dat`, `data/taikhoan.dat`, `data/phieumuon.dat`, `data/lichsugiaodich.dat`: file nhi phan.
- `data/nhatky/hoatdong.txt`: nhat ky thao tac.
- `data/saoluu/`: thu muc danh cho backup se hoan thien trong phan luu tru.
- Tai khoan demo su dung ham bam FNV-1a de minh hoa; day khong phai giai phap bao mat mat khau cho he thong thuc te.

## 9. Unit test va kiem thu
- `tests/test_tuan3.cpp`: bon truong hop quay AVL, them/tim/sua/xoa, kiem tra can bang va BST in-order.
- `tests/test_tuan4.cpp`: separate chaining, va cham bucket, tu mo rong, khoa trung, tim/sua/xoa.
- `tests/test_tuan5.cpp`: LinkedList, Dynamic Array va doc/ghi file nhi phan round-trip.
- Chay tat ca test bang `tests/chaykiemthu.bat` tren Windows hoac `bash tests/chaykiemthu.sh` tren Linux/macOS/Git Bash.

## 10. Phan chua trien khai
Muon-tra nghiep vu va tinh phat (Tuan 6), do thi BFS/DFS va thong ke Top 10 (Tuan 7), CTDL tu tim hieu/tich hop (Tuan 8), benchmark/huong dan nguoi dung day du (Tuan 9) van la cac phan tiep theo.
