# QuanLyThuVien - Do an C++ quan ly thu vien

**Trang thai:** bo khung dang phat trien; cac module nghiep vu chinh se duoc hoan thien theo checklist tuan.

## Muc tieu

Xay dung do an tin hoc quan li thu vien bang ung dung console bang C++11 tro len, quan ly sach, doc gia, muon-tra, thong ke va goi y. Du lieu luu trong file nhi phan `.dat` va file van ban `.txt`; **khong su dung co so du lieu**.

## Cau truc thu muc theo yeu cau giang vien

```text
QuanLyThuVien/
|-- include/       # Header files (.h)
|-- src/           # Source files (.cpp)
|-- data/          # File .dat, log .txt, CSV va backup
|   |-- nhatky/
|   `-- saoluu/
|-- docs/          # SRS.pdf, Design.pdf, so do va huong dan
|-- tests/         # Unit tests va test cases
|-- .vscode/       # Cau hinh VS Code (ten chuan)
|-- Makefile
|-- build.bat
|-- .gitignore
`-- README.md
```

## Cong cu
- C++11 tro len, VS Code, `g++` va Git/GitHub.
- Console menu, khong dung SQL/MySQL/SQLite hay CSDL nao.
- Git commit it nhat moi tuan; commit moi cho tung phan viec.

## Bien dich va chay (Windows / VS Code)
1. Mo thu muc `QuanLyThuVien` trong VS Code.
2. Chon Terminal > New Terminal.
3. Kiem tra `g++ --version`.
4. Chay `./build.bat` (trong PowerShell có thể dùng `./build.bat` hoặc `\.\build.bat`).
5. Chay unit test bang `tests\chaykiemthu.bat`.

## Chuc nang mo rong da co trong bo khung
- Dang nhap, doi mat khau va vai tro Admin / Thu thu / Doc gia.
- Kiem tra quyen tai menu va tai diem xu ly chuc nang.
- Xuat danh sach sach/doc gia ra CSV UTF-8.
- Unit test co ban cho phan quyen va escaping CSV.

Tai khoan demo duoc tao lan dau khi chua co `data/taikhoan.dat`: `admin / Admin123!`, `thuthu / ThuThu123!`, `docgia / DocGia123!`. Hay doi mat khau demo sau khi dang nhap. Ham bam mat khau hien tai chi phuc vu minh hoa do an, chua phu hop he thong that.

## CTDL bat buoc theo de bai
- AVL: quan ly sach theo ISBN.
- BST: in danh muc theo ISBN bang duyet in-order.
- Hash Table: quan ly doc gia theo CMND/CCCD, separate chaining.
- Danh sach lien ket don: phieu muon.
- Mang dong: lich su giao dich.
- Do thi danh sach ke: goi y sach cung the loai bang BFS/DFS.
- CTDL cay tu tim hieu: loai cu the can xac nhan theo dinh chinh cua yeu cau; khong mac dinh la Trie neu giang vien chua chot.
- File I/O: file nhi phan `.dat`, log va bao cao `.txt`.

## Tien do
- Tuan 1: SRS va kho Git/GitHub.
- Tuan 2: Design.pdf, so do lop/module va struct.
- Tuan 3: AVL, BST va kiem thu quan ly sach.
- Tuan tiep theo: Hash Table, danh sach lien ket, mang dong, file I/O, muon-tra, do thi, CTDL tu tim hieu, unit test, benchmark/bao cao.

Xem `docs/SRS.pdf`, `docs/Design.pdf`, `docs/SRS.md`, `docs/Design.md` va `docs/huongdansudung_dangnhap_csv.md`.
