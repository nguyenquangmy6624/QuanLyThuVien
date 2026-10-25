# QuanLyThuVien - Do an C++ quan ly thu vien

> Trang thai hien tai: **bo khung khoi dau**, chua phai phien ban hoan chinh cua do an.

## Muc tieu

Xay dung ung dung quan ly thu vien bang C++11 tro len, giao dien console, khong dung co so du lieu. Du lieu se duoc luu vao file nhi phan `.dat`; log va bao cao duoc ghi ra file van ban.

## Cau truc thu muc

```text
QuanLyThuVien/
|-- khaibao/       # Cac file header (.h)
|-- manguon/       # Cac file cai dat (.cpp)
|-- dulieu/        # Du lieu mau va du lieu khi chay
|-- tailieu/       # Bao cao, thiet ke, phan tich CTDL
|-- kiemthu/       # Test case va kiem thu
|-- .vscode/       # Cau hinh build rieng cua VS Code (giu ten chuan)
|-- Makefile
|-- build.bat
|-- .gitignore
`-- README.md
```

Luu y: `.vscode` duoc giu nguyen ten vi VS Code tu dong nhan dien thu muc cau hinh nay. Cac thu muc noi dung con lai da duoc doi sang tieng Viet khong dau, viet lien.

## Dieu kien

- Windows + VS Code.
- Co `g++` va Git trong PATH.
- C++11 tro len.

## Chay thu bo khung tren Windows

1. Giai nen file ZIP.
2. Mo thu muc `QuanLyThuVien` bang VS Code (File > Open Folder...).
3. Mo Terminal > New Terminal.
4. Kiem tra compiler: `g++ --version`.
5. Chay lenh `./build.bat` trong PowerShell (hoac `build.bat` trong Command Prompt).

Neu terminal khong nhan `g++`, can cai va cau hinh compiler truoc khi chay.

## Lo trinh phat trien

1. Tao model va cac quy tac du lieu.
2. Tu cai dat AVL cho sach theo ISBN.
3. Tu cai dat BST chi muc ISBN va duyet in-order.
4. Tu cai dat hash table separate chaining cho doc gia theo CMND/CCCD.
5. Tu cai dat danh sach lien ket don cho phieu muon va mang dong cho lich su giao dich.
6. Tu cai dat Trie cho tim kiem tien to ten sach.
7. Xay dung do thi danh sach ke cho goi y sach theo the loai, BFS/DFS.
8. Them muon/tra, tinh phat, thong ke, import/export.
9. Them doc/ghi file nhi phan, log, backup, test va ho so bao cao.

## Quy tac lam viec

- Moi chuc nang lon can co test case.
- Khong dung SQL, SQLite hay he quan tri co so du lieu nao.
- Moi CTDL phai duoc giai thich: vi sao chon, chuc nang ap dung va do phuc tap.
- Commit Git theo tung phan viec, khong gom het vao mot commit cuoi cung.
