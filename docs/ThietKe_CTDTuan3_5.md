# Thiết kế cấu trúc dữ liệu và cài đặt - Tuần 3, 4, 5

Tài liệu ghi rõ cấu trúc dữ liệu được dùng ở đâu, lý do lựa chọn, cách cài đặt và độ phức tạp dự kiến.

## Tuần 3 - Quản lý sách bằng AVL và BST

### Cây AVL
- Tệp: `include/cay_avl.h`, `src/cay_avl.cpp`.
- Khóa: ISBN của sách.
- Mỗi nút lưu một `Sach`, con trỏ trái/phải và chiều cao.
- Thêm: chèn theo quy tắc BST, cập nhật chiều cao và cân bằng bằng các phép quay LL, RR, LR, RL.
- Tìm: so sánh ISBN từ gốc đến nút cần tìm.
- Sửa: tìm nút theo ISBN và cập nhật thông tin, giữ nguyên khóa.
- Xóa: hỗ trợ nút lá, nút có một con và nút có hai con; sau đó cập nhật chiều cao và cân bằng lại.
- Lý do chọn: ISBN là khóa tra cứu chính; AVL giữ chiều cao cây cân bằng nên hiệu năng tìm kiếm ổn định.
- Độ phức tạp: thêm/tìm/xóa O(log n) khi cây AVL hợp lệ; duyệt O(n).

### Cây BST
- Tệp: `include/cay_bst.h`, `src/cay_bst.cpp`.
- Dữ liệu: sách, khóa là ISBN.
- Chức năng: tạo BST từ danh sách sách và duyệt in-order để in danh mục ISBN tăng dần.
- Khi tạo BST từ danh sách đã sắp xếp, các phần tử được chèn theo trung vị trước để tránh tạo cây lệch hoàn toàn.
- Lý do chọn: minh họa quy tắc cây nhị phân tìm kiếm và phép duyệt in-order theo đề bài.
- Độ phức tạp: thêm/tìm O(h), duyệt in-order O(n); h có thể bằng n nếu cây lệch.

## Tuần 4 - Quản lý độc giả bằng Hash Table

- Tệp: `include/bangbam_docgia.h`, `src/bangbam_docgia.cpp`.
- Khóa băm: CMND/CCCD.
- Mỗi bucket là một danh sách nút liên kết (separate chaining), không dùng `unordered_map` thay thế.
- Khi hệ số tải đạt ngưỡng 0.75, bảng băm tự mở rộng và băm lại các nút.
- Chức năng: thêm, tìm, cập nhật, xóa, liệt kê độc giả.
- Lý do chọn: tra cứu độc giả bằng mã định danh nhanh; separate chaining xử lý trường hợp nhiều khóa rơi vào cùng bucket.
- Độ phức tạp: trung bình O(1) nếu hàm băm phân bố tốt; xấu nhất O(n) nếu nhiều khóa cùng bucket; duyệt toàn bộ O(n + m), với m là số bucket.

## Tuần 5 - LinkedList, Dynamic Array và File I/O

### Danh sách liên kết đơn phiếu mượn
- Tệp: `include/danh_sach_phieumuon.h`, `src/danh_sach_phieumuon.cpp`.
- Mỗi nút chứa một `PhieuMuon` và con trỏ đến nút tiếp theo.
- Hỗ trợ thêm cuối, tìm theo mã phiếu, xóa theo mã phiếu, nạp từ/đưa ra danh sách trung gian để lưu file.
- Độ phức tạp: thêm cuối O(1) nhờ lưu con trỏ cuối; tìm/xóa O(n); duyệt O(n).

### Mảng động lịch sử giao dịch
- Tệp: `include/mang_dong.h`.
- Tự cài đặt bằng `new[]` và `delete[]`, không dùng `std::vector` làm bộ nhớ bên trong.
- Khi đầy, sức chứa tăng gấp đôi; hỗ trợ thêm cuối, truy cập theo chỉ số, xóa tại vị trí.
- Độ phức tạp: truy cập O(1); thêm cuối O(1) trung bình khấu hao; xóa tại vị trí O(n) do phải dịch phần tử.

### File I/O
- Tệp: `src/luutru.cpp`, khai báo trong `include/luutru.h`.
- `data/sach.dat`: sách; `data/docgia.dat`: độc giả; `data/phieumuon.dat`: phiếu mượn; `data/lichsugiaodich.dat`: lịch sử giao dịch.
- File nhị phân có mã nhận dạng, phiên bản và số bản ghi. Chuỗi được ghi độ dài trước nội dung; không ghi trực tiếp struct có `std::string` vào file.
- `ghiNhatKy()` ghi thao tác vào `data/nhatky/hoatdong.txt`.
- Lớp lưu trữ dùng `std::vector` trung gian để chuyển dữ liệu vào/ra file; thao tác nghiệp vụ và các cấu trúc dữ liệu cốt lõi vẫn dùng AVL, Hash Table, LinkedList và Dynamic Array tự cài đặt.

## Kiểm thử tự động

- `tests/test_tuan3.cpp`: bốn trường hợp quay AVL LL/RR/LR/RL; thêm, tìm, sửa, xóa; kiểm tra cân bằng; BST in-order.
- `tests/test_tuan4.cpp`: separate chaining, va chạm bucket, tự mở rộng, khóa trùng, tìm, cập nhật, xóa.
- `tests/test_tuan5.cpp`: LinkedList, Dynamic Array, đọc/ghi file nhị phân và log TXT.
- Windows: `tests\chaykiemthu.bat`.
- Linux/macOS/Git Bash: `bash tests/chaykiemthu.sh`.

## Giới hạn phạm vi

Menu demo Tuần 5 chỉ minh họa thao tác cấu trúc dữ liệu và đọc/ghi tệp cho phiếu mượn/lịch sử. Quy tắc nghiệp vụ mượn sách, kiểm tra số lượng, trả sách và tính tiền phạt sẽ được thực hiện ở Tuần 6.
