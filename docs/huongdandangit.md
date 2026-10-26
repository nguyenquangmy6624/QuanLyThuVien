# Huong dan Git/GitHub

## Kiem tra trang thai
```powershell
git status
git log --oneline
```

## Luu thay doi theo tung tuan
Sau khi thay doi va chay test:
```powershell
git add README.md .gitignore Makefile build.bat include src data docs tests .vscode
git commit -m "Week 2: Add SRS Design and standard structure"
git push
```

Neu repository cu van con cac thu muc `khaibao/`, `manguon/`, `dulieu/`, `tailieu/`, `kiemthu/`, hay xoa cac thu muc cu sau khi da chuyen het tep can giu sang `include/`, `src/`, `data/`, `docs/`, `tests/`. Khong xoa thu muc `.git/`; thu muc nay giu lich su commit tren may.

## Luu y
- Khong dua file `.dat` phat sinh, file build hay CSV xuat sinh vao commit neu `.gitignore` dang bo qua chung.
- Moi commit can co thong diep ro rang; commit it nhat moi tuan theo yeu cau mon hoc.
