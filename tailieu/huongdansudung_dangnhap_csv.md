# Huong dan dang nhap, phan quyen va xuat CSV

## Tai khoan demo lan dau

Neu `dulieu/taikhoan.dat` chua ton tai, chuong trinh tao cac tai khoan demo:

| Ten dang nhap | Mat khau ban dau | Vai tro |
|---|---|---|
| `admin` | `Admin123!` | Admin |
| `thuthu` | `ThuThu123!` | Thu thu |
| `docgia` | `DocGia123!` | Doc gia |

Sau lan chay dau, tai khoan duoc luu trong `dulieu/taikhoan.dat`; chuong trinh khong ghi mat khau dang van ban. Hay dang nhap va dung muc **Doi mat khau** de thay doi mat khau demo.

> Day la ma bam FNV-1a minh hoa cho do an, khong phai co che bao mat mat khau chuan cho san pham that. Khong dung cac tai khoan/mat khau nay cho dich vu that.

## Phan quyen

- **Admin:** truy cap tat ca muc.
- **Thu thu:** quan ly nghiep vu, thong ke va xuat CSV.
- **Doc gia:** chi truy cap chuc nang tra cuu trong bo khung hien tai.

Quyen duoc kiem tra khi hien thi menu va kiem tra lai trong xu ly lua chon. Cac phan quan ly sach/doc gia/muon-tra/thong ke chua duoc cai dat, se bo sung theo checklist tuan.

## Xuat CSV

Dang nhap bang `admin` hoac `thuthu`, chon **7. Xuat CSV**. Tep duoc tao trong thu muc `dulieu/`:

- `dulieu/xuat_sach.csv`
- `dulieu/xuat_docgia.csv`

Du lieu sach va doc gia doc tu tep nhi phan `sach.dat` va `docgia.dat`; chuong trinh tao mot bo du lieu mau khi cac tep nay chua ton tai. CSV co BOM UTF-8 de Excel tren Windows doc tieng Viet de hon, va cac truong co dau phay/dau ngoac kep duoc escape.

## Chay va kiem thu

Tren Windows/VS Code:

```powershell
.\build.bat
.\kiemthu\chaykiemthu.bat
```

Tep du lieu duoc doc/ghi theo dinh dang rieng co phien ban. Khong su dung SQL, SQLite hay co so du lieu nao.
