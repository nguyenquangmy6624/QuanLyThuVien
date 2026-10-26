# ĐẶC TẢ YÊU CẦU PHẦN MỀM (SRS)

**Tên dự án:** QuanLyThuVien - Chương trình quản lý thư viện bằng C++  
**Phiên bản:** 1.0 (bản yêu cầu ban đầu)  
**Ngày lập:** 25/10/2026  
**Trạng thái:** Bản nháp để thống nhất phạm vi trước khi thiết kế chi tiết

## 1. Mục đích

Tài liệu này mô tả phạm vi, chức năng, dữ liệu, ràng buộc kỹ thuật và tiêu chí nghiệm thu của đồ án quản lý thư viện. Đây là căn cứ để thiết kế cấu trúc dữ liệu, cài đặt chương trình, xây dựng kiểm thử và viết báo cáo.

## 2. Phạm vi sản phẩm

Sản phẩm là ứng dụng console viết bằng C++11 trở lên, quản lý danh mục sách, độc giả, phiếu mượn/trả, lịch sử giao dịch, thống kê và gợi ý sách. Chương trình phải tự cài đặt các cấu trúc dữ liệu được yêu cầu và lưu dữ liệu bằng file; **không sử dụng CSDL** như MySQL, SQL Server hay SQLite.

## 3. Người dùng và môi trường

- **Thủ thư/Quản trị viên:** thao tác quản lý sách, độc giả, mượn/trả, thống kê và dữ liệu.
- **Độc giả:** có thể là đối tượng dữ liệu của hệ thống; đăng nhập/phân quyền là chức năng mở rộng khuyến khích, không phải điều kiện để hoàn thành các chức năng cốt lõi.
- **Môi trường:** Windows, VS Code; trình biên dịch hỗ trợ C++11 trở lên; Git/GitHub để quản lý phiên bản.
- **Giao diện:** menu console, có thể bổ sung màu hoặc ASCII art nếu không ảnh hưởng tính dễ dùng.

## 4. Yêu cầu chức năng

### FR-01. Quản lý sách

- Thêm, sửa và xóa sách; dữ liệu gồm ISBN, tên sách, tác giả, thể loại, năm xuất bản và số lượng.
- ISBN phải duy nhất; dữ liệu số phải hợp lệ và số lượng không âm.
- Tìm sách theo ISBN; in danh mục theo thứ tự ISBN tăng dần.
- Tìm theo tiền tố tên sách và gợi ý tên phù hợp.
- Import/export danh mục sách qua file văn bản.

### FR-02. Quản lý độc giả

- Thêm, sửa và xóa độc giả; dữ liệu gồm CMND/CCCD, họ tên, email, số điện thoại và loại thẻ.
- CMND/CCCD phải duy nhất.
- Tìm độc giả theo CMND/CCCD và thống kê độc giả theo loại thẻ.

### FR-03. Mượn sách

- Lập phiếu mượn gồm mã phiếu, CMND/CCCD, ISBN, ngày mượn và ngày hẹn trả.
- Chỉ lập phiếu khi độc giả tồn tại, sách tồn tại, còn số lượng cho mượn và dữ liệu ngày hợp lệ.
- Không cho số lượng mượn vượt quá số lượng có thể cho mượn.

### FR-04. Trả sách và tiền phạt

- Ghi nhận trả sách và cập nhật trạng thái phiếu mượn, số lượng sách.
- Nếu trả quá hạn, tính tiền phạt theo số ngày quá hạn nhân với đơn giá phạt mỗi ngày.
- Đơn giá phạt cần được thống nhất với giảng viên/nhóm trước khi chốt bản triển khai; không hard-code một mức tiền chưa được phê duyệt trong tài liệu yêu cầu.

### FR-05. Lịch sử giao dịch

- Ghi lại các giao dịch mượn/trả phục vụ tra cứu và thống kê.
- Dữ liệu lịch sử phải được lưu và đọc lại sau khi khởi động chương trình.

### FR-06. Thống kê và báo cáo

- Đếm lượt mượn theo tháng, thể loại và độc giả.
- Hiển thị Top 10 sách được mượn nhiều nhất và Top 10 độc giả mượn nhiều nhất.
- Xuất báo cáo ra file văn bản.

### FR-07. Tìm kiếm và gợi ý nâng cao

- Gợi ý sách cùng thể loại dựa trên đồ thị và duyệt BFS/DFS.
- Tìm sách theo tiền tố tên bằng CTDL cây đã chốt; loại cây cụ thể cần được xác nhận do có khác biệt giữa ảnh đề bài và đính chính hiện tại.
- Gợi ý sách liên quan dựa trên lịch sử mượn khi dữ liệu lịch sử đủ để tạo liên kết.

### FR-08. Lưu trữ, log và sao lưu

- Tự động đọc dữ liệu từ file khi khởi động.
- Lưu dữ liệu ra file khi có thay đổi và khi thoát an toàn.
- Dùng file nhị phân `.dat` cho dữ liệu chính; file văn bản `.txt` cho log/báo cáo.
- Tạo bản sao lưu theo ngày; lỗi file phải được thông báo và xử lý an toàn.

### FR-09. Chức năng mở rộng

- Đăng nhập bằng tài khoản và mật khẩu; giới hạn 3 lần sai liên tiếp trong một phiên đăng nhập.
- Phân quyền theo vai trò Admin, Thủ thư và Độc giả; kiểm tra quyền ở cả menu và xử lý nghiệp vụ.
- Cho phép người dùng đổi mật khẩu; không lưu mật khẩu dạng văn bản thuần.
- Xuất danh mục sách và danh sách độc giả thành CSV UTF-8 để mở bằng bảng tính; xử lý đúng dấu phẩy/dấu ngoặc kép/xuống dòng trong trường dữ liệu.
- Các chức năng bổ sung như console màu và đa ngôn ngữ được cân nhắc sau khi phần cốt lõi ổn định.

**Lưu ý bảo mật:** bản demo hiện dùng hàm băm FNV-1a tự cài đặt để minh họa lưu mật khẩu, không phải cơ chế chống tấn công mật khẩu dùng trong sản phẩm thật.

## 5. Cấu trúc dữ liệu bắt buộc

| Cấu trúc dữ liệu | Áp dụng | Yêu cầu chính |
|---|---|---|
| Cây AVL | Quản lý sách theo ISBN | Tự cài đặt thêm, tìm, xóa và cân bằng cây |
| Cây BST | In danh mục theo ISBN | Duyệt in-order để in ISBN tăng dần |
| Hash Table | Quản lý độc giả theo CMND/CCCD | Tự cài đặt bảng băm; xử lý va chạm bằng separate chaining |
| Danh sách liên kết đơn | Danh sách phiếu mượn | Tự cài đặt node, thêm, tìm, cập nhật và xóa khi phù hợp |
| Mảng động | Lịch sử giao dịch | Tự quản lý vùng nhớ, kích thước và dung lượng |
| Đồ thị danh sách kề | Gợi ý sách cùng thể loại/liên quan | Cài đặt BFS/DFS và giải thích cách tạo cạnh |
| CTDL tự tìm hiểu (loại cây chờ xác nhận) | Tìm kiếm nâng cao theo tiền tố tên sách | Chốt đúng loại cây trước khi triển khai; tự cài đặt từ đầu, demo riêng và so sánh |
| File I/O | Lưu toàn bộ dữ liệu | Có đọc/ghi file nhị phân và kiểm tra lỗi |

Báo cáo phải nêu rõ mỗi cấu trúc dữ liệu được dùng ở đâu, vì sao chọn và độ phức tạp thời gian/bộ nhớ của thao tác chính.

## 6. Dữ liệu chính

- **Sach:** ISBN, tenSach, tacGia, theLoai, namXuatBan, soLuongTong, soLuongCon.
- **DocGia:** cmndCccd, hoTen, email, soDienThoai, loaiThe.
- **PhieuMuon:** maPhieu, cmndCccd, ISBN, ngayMuon, ngayHenTra, ngayTra (nếu đã trả), trangThai, tienPhat.
- **GiaoDich:** mã giao dịch, loại giao dịch, mã độc giả, ISBN, thời điểm và thông tin phục vụ báo cáo.

Tên trường trong code có thể dùng tiếng Việt không dấu để thống nhất với bộ khung hiện tại. Cần kiểm tra trùng khóa trước khi thêm và kiểm tra tham chiếu trước khi xóa dữ liệu đang được phiếu mượn sử dụng.

## 7. Yêu cầu phi chức năng và ràng buộc

- Mã nguồn tuân thủ C++11 trở lên, chia nhiều file `.h` và `.cpp`, không gom toàn bộ chương trình vào một file.
- Cấu trúc thư mục rõ ràng; tên biến/hàm có ý nghĩa; comment tại thuật toán/hàm quan trọng.
- Có menu chính và menu con rõ ràng; không dùng `goto`; hạn chế biến toàn cục.
- Kiểm tra dữ liệu nhập, xử lý nhập sai, file thiếu, file lỗi và trường hợp dữ liệu rỗng.
- Không dùng CSDL hoặc thư viện có sẵn để thay thế các cấu trúc dữ liệu bắt buộc; CTDL tự tìm hiểu phải tự cài đặt từ đầu sau khi chốt loại cây cụ thể.
- Dùng Git/GitHub; commit thường xuyên, ít nhất mỗi tuần theo yêu cầu học phần.
- Tài liệu bàn giao gồm SRS, thiết kế, sơ đồ lớp/struct, test case, báo cáo và hướng dẫn sử dụng.

## 8. Tiêu chí nghiệm thu mức chức năng

1. Có thể thêm/tìm/sửa/xóa sách và từ chối ISBN trùng.
2. AVL vẫn thỏa tính chất BST và cân bằng sau các thao tác thêm/xóa; có kiểm thử trường hợp quay LL, RR, LR, RL.
3. BST in danh mục theo ISBN tăng dần.
4. Hash Table tra cứu được độc giả và xử lý được nhiều khóa cùng bucket bằng separate chaining.
5. Danh sách phiếu mượn và mảng động lịch sử có thêm, truy xuất và kiểm tra dữ liệu.
6. Không cho mượn khi sách hết, độc giả không tồn tại hoặc dữ liệu không hợp lệ; trả sách cập nhật số lượng đúng.
7. CTDL cây đã chốt hỗ trợ đúng chức năng tìm theo tiền tố theo yêu cầu đã thống nhất.
8. File `.dat` được đọc khi khởi động và ghi đúng khi thay đổi; log/báo cáo là file văn bản; backup theo ngày.
9. Có thống kê và Top 10 theo dữ liệu mẫu; trường hợp không có dữ liệu phải hiển thị thông báo phù hợp.
10. Chương trình biên dịch bằng C++11 trở lên, mã nguồn chia file và có tài liệu kiểm thử.

## 9. Các quyết định cần chốt trước khi hoàn thiện

- **Loại CTDL cây tự tìm hiểu:** ảnh yêu cầu ban đầu ghi “Trie”, trong khi đính chính sau đó yêu cầu “Tree, không phải Trie”. “Tree” là tên gọi chung, chưa xác định một loại cây cụ thể. Cần chốt chính xác loại cây trước khi bắt đầu phần CTDL tự tìm hiểu; bản SRS này chưa khóa lựa chọn đó.

- Đơn giá tiền phạt cho mỗi ngày quá hạn.
- Quy tắc xác định ngày hiện tại, định dạng ngày và xử lý dữ liệu lịch sử.
- Quy tắc chuẩn hóa chữ hoa/thường và tiếng Việt có dấu khi tìm tiền tố.
- Chính sách xóa sách/độc giả đang có phiếu mượn chưa trả.
- Định dạng phiên bản file nhị phân để hỗ trợ phát hiện file cũ hoặc hỏng.

## 10. Cấu trúc thư mục dự kiến

```text
QuanLyThuVien/
|-- khaibao/       # File khai bao .h
|-- manguon/       # File cai dat .cpp
|-- dulieu/        # Du lieu mau va file .dat
|   |-- nhatky/    # Log van ban
|   `-- saoluu/    # Backup theo ngay
|-- tailieu/       # SRS, thiet ke, bao cao va huong dan
|-- kiemthu/       # Test case va kiem thu
|-- .vscode/       # Cau hinh VS Code (giu ten chuan)
|-- Makefile
|-- build.bat
|-- .gitignore
`-- README.md
```

## 11. Phạm vi checklist tuần 1

- [x] Tạo cấu trúc thư mục dự án.
- [x] Viết SRS bản đầu tiên và xuất PDF.
- [ ] Khởi tạo Git, tạo commit đầu tiên bằng danh tính Git của sinh viên.
- [ ] Tạo repository trên GitHub và push mã nguồn lên remote.

Hai bước Git cuối cần thực hiện bằng tài khoản của sinh viên; tài liệu hướng dẫn lệnh nằm trong `tailieu/huongdandangit.md`.
