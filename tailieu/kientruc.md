# Thiet ke kien truc va CTDL

## Anh xa CTDL vao chuc nang

| CTDL | Chuc nang | Do phuc tap can phan tich |
|---|---|---|
| AVL | Luu/tim/them/xoa sach theo ISBN | Tim/them/xoa O(log n) |
| BST | Chi muc ISBN de in danh muc theo thu tu in-order | Duyet O(n); thao tac trung binh O(log n), xau nhat O(n) |
| Hash table (separate chaining) | Tra cuu doc gia theo CMND/CCCD | Trung binh O(1), xau nhat O(n) |
| Danh sach lien ket don | Danh sach phieu muon | Them dau O(1), tim O(n) |
| Mang dong | Lich su giao dich | Truy cap chi so O(1), them cuoi trung binh khau hao O(1) |
| Do thi danh sach ke | Lien ket sach de goi y sach cung the loai; BFS/DFS | O(V + E) khi duyet |
| Trie tu cai dat | Tim sach theo tien to | O(L) de di den nut tien to, cong chi phi thu thap ket qua |

## Quy tac dong bo du lieu

- AVL la noi luu ban ghi sach chinh.
- BST chi luu khoa ISBN; khi in in-order, tra ISBN sang AVL de lay chi tiet sach. Khi them/xoa sach, cap nhat ca hai cau truc.
- Hash table luu doc gia theo khoa CMND/CCCD va xu ly va cham bang separate chaining.
- Phieu muon tham chieu den ma doc gia va ISBN; truoc khi tao phieu phai kiem tra doc gia ton tai, sach ton tai, so luong con va cac dieu kien muon.
- Lich su giao dich la mang dong rieng; khong thay the danh sach phieu muon dang hoat dong.
- Moi thay doi du lieu can duoc ghi log va luu ra file theo quy tac da thiet ke.

## Luu tru

- File nhi phan `.dat`: sach, doc gia, phieu muon va du lieu can khoi phuc sau khi khoi dong.
- File van ban `.txt`: log hoat dong va bao cao de doc.
- Backup: tao ban sao theo ngay; khong ghi de ban sao cu neu khong can thiet.
- Can kiem tra file mo duoc hay khong, kich thuoc chuoi khi doc, du lieu sai dinh dang va tinh nhat quan giua cac cau truc.

## CTDL tu tim hieu: Trie

Trie se duoc cai dat tu dau (node, them tien to, tim tien to, duyet cac tu hoan thanh), khong goi thu vien Trie co san. Can kiem thu tien to khong ton tai, nhieu sach chung tien to, chuoi rong va chuoi co dau tieng Viet. UTF-8 can duoc xu ly nhat quan; khong duoc coi moi byte cua tieng Viet la mot ky tu doc lap khi bien doi hoa/thuong.
