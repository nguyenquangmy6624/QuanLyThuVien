# Huong dan Git/GitHub - Tuan 1

Tai lieu nay giup ban tao repository bang danh tinh Git cua chinh minh. Chua nen dung danh tinh cua nguoi khac cho commit do an.

## 1. Kiem tra Git

Mo Terminal trong VS Code va chay:

```powershell
git --version
```

Neu khong hien so phien ban, cai Git for Windows tu https://git-scm.com/install/windows, sau do dong va mo lai VS Code.

## 2. Cau hinh ten va email commit

Thay hai gia tri mau bang ten va email ban dung tren GitHub:

```powershell
git config --global user.name "TEN CUA BAN"
git config --global user.email "EMAIL CUA BAN"
git config --global init.defaultBranch main
```

Kiem tra:

```powershell
git config --global --list
```

## 3. Khoi tao repository local

Dam bao Terminal dang dung o thu muc goc `QuanLyThuVien`, sau do chay:

```powershell
git init
git add README.md .gitignore build.bat Makefile khaibao manguon dulieu tailieu kiemthu .vscode
git status
git commit -m "docs: add project structure and initial SRS"
```

Lenh `git status` giup kiem tra truoc khi commit. Neu Git bao chua co ten/email, quay lai buoc 2.

## 4. Tao repository tren GitHub

1. Dang nhap GitHub va bam **New repository**.
2. Dat ten `QuanLyThuVien`.
3. Neu ban da co README trong thu muc local, de repository GitHub trong (khong tao them README, license hay .gitignore tren web) de tranh xung dot commit ban dau.
4. Copy URL repository HTTPS GitHub cua ban.

Sau do trong Terminal, thay URL mau bang URL that:

```powershell
git remote add origin https://github.com/USERNAME/QuanLyThuVien.git
git remote -v
git push -u origin main
```

`USERNAME` va URL tren chi la mau; khong chay nguyen neu no khong phai repository cua ban.

## 5. Commit tiep theo

Sau moi phan viec nho da kiem tra:

```powershell
git status
git add .
git commit -m "docs: update week 1 checklist"
git push
```

Message commit phai mo ta dung thay doi thuc te. Vi du khi them AVL sau nay co the dung `feat: implement AVL book index`.

## Can nho

- Khong commit file `.exe`, file build, hay du lieu ca nhan nhay cam.
- Khong xoa thu muc `.git` sau khi da khoi tao repository.
- Khong upload mat khau, token GitHub hoac thong tin ca nhan khong can thiet.
