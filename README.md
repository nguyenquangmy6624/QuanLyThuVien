# QuanLyThuVien — Đồ án C++ quản lý thư viện

Ứng dụng quản lý thư viện viết bằng **C++11 trở lên**, giao diện console menu. Dự án được thực hiện theo checklist 10 tuần của giảng viên.

## 1. Mục tiêu và ràng buộc

- Vận dụng cấu trúc dữ liệu và giải thuật vào bài toán quản lý thư viện.
- Tự cài đặt các cấu trúc dữ liệu theo yêu cầu, không thay thế bằng thư viện có sẵn.
- Lưu dữ liệu bằng **file nhị phân `.dat`** và file văn bản `.txt` (log/báo cáo).
- **Không sử dụng cơ sở dữ liệu** như MySQL, SQL Server, SQLite hoặc các CSDL khác.
- Chia chương trình thành nhiều file `.h` và `.cpp`; kiểm tra dữ liệu nhập và xử lý lỗi file.
- Quản lý mã nguồn bằng Git/GitHub, commit thường xuyên theo tuần.

## 2. Cấu trúc thư mục

```text
QuanLyThuVien/
├── include/       # Header files (.h)
├── src/           # Source files (.cpp)
├── data/          # File .dat, log .txt, CSV và sao lưu
│   ├── nhatky/
│   └── saoluu/
├── docs/          # SRS, Design, sơ đồ và hướng dẫn
├── tests/         # Unit tests và test cases
├── .vscode/       # Cấu hình VS Code
├── Makefile
├── build.bat
├── .gitignore
└── README.md
```

## 3. Công cụ và cách chạy

- Ngôn ngữ: C++11 trở lên.
- IDE: Visual Studio Code.
- Trình biên dịch: `g++`.
- Quản lý mã nguồn: Git và GitHub.
- Giao diện: Console menu.

### Biên dịch và chạy trên Windows

1. Mở thư mục `QuanLyThuVien` bằng VS Code.
2. Chọn **Terminal → New Terminal**.
3. Kiểm tra trình biên dịch:

   ```powershell
   g++ --version
   ```

4. Biên dịch và chạy:

   ```powershell
   .\build.bat
   ```

5. Chạy bộ kiểm thử hiện có:

   ```powershell
   .\tests\chaykiemthu.bat
   ```

## 4. Chức năng mở rộng

- Đăng nhập và đổi mật khẩu.
- Phân quyền theo vai trò **Admin / Thủ thư / Độc giả**.
- Xuất danh sách sách và độc giả ra CSV UTF-8.
- Có bộ kiểm thử ban đầu cho phần phân quyền và xử lý CSV.

> Tài khoản demo được tạo khi chưa có `data/taikhoan.dat`: `admin / Admin123!`, `thuthu / ThuThu123!`, `docgia / DocGia123!`. Hãy đổi mật khẩu sau lần đăng nhập đầu tiên. Cơ chế băm mật khẩu hiện tại chỉ nhằm minh họa đồ án, không dùng cho hệ thống thực tế.

## 5. Cấu trúc dữ liệu theo đề bài

| Cấu trúc dữ liệu | Phạm vi áp dụng |
|---|---|
| Cây AVL | Quản lý sách theo ISBN |
| Cây BST | In danh mục sách theo ISBN bằng duyệt in-order |
| Hash Table (separate chaining) | Quản lý độc giả theo CMND/CCCD |
| Danh sách liên kết đơn | Quản lý phiếu mượn |
| Mảng động | Lưu lịch sử giao dịch |
| Đồ thị danh sách kề | Gợi ý sách cùng thể loại bằng BFS/DFS |
| Cấu trúc cây tự tìm hiểu | Sẽ chốt đúng loại cây theo yêu cầu/đính chính của giảng viên |
| File I/O | Lưu dữ liệu bằng `.dat`, log và báo cáo bằng `.txt` |

## 6. Checklist tiến độ theo tuần

Đánh dấu `[x]` khi nội dung đã hoàn thành và được kiểm tra; để `[ ]` nếu chưa hoàn thành.

| Tuần | Checklist | Sản phẩm / ghi chú |
|---|---|---|
| **Tuần 1** | ☑ Repo Git/GitHub · ☑ SRS.pdf · ☑ Cấu trúc thư mục | Repo GitHub, `docs/SRS.pdf`, cấu trúc dự án |
| **Tuần 2** | ☑ Design.pdf · ☑ Sơ đồ lớp / sơ đồ module · ☑ Định nghĩa struct | `docs/Design.pdf`, `docs/sodolop.png`, `include/cacstruct.h` |
| **Tuần 3** | ☐ AVL · ☐ BST · ☐ Test quản lý sách | Cài đặt AVL/BST và kiểm thử thêm, tìm, xóa, duyệt sách |
| **Tuần 4** | ☐ Hash Table · ☐ Test quản lý độc giả | Hash Table dùng separate chaining và kiểm thử độc giả |
| **Tuần 5** | ☐ LinkedList · ☐ Dynamic Array · ☐ File I/O | Danh sách phiếu mượn, mảng động lịch sử, đọc/ghi `.dat` |
| **Tuần 6** | ☐ Mượn sách · ☐ Trả sách · ☐ Tính phạt | Hoàn thiện quy trình mượn/trả và kiểm tra quá hạn |
| **Tuần 7** | ☐ Graph · ☐ BFS/DFS · ☐ Thống kê Top 10 | Đồ thị gợi ý sách và các báo cáo thống kê |
| **Tuần 8** | ☐ CTDL mới tự tìm hiểu · ☐ Tích hợp · ☐ Demo | Cài đặt từ đầu, tích hợp và demo cấu trúc dữ liệu đã chọn |
| **Tuần 9** | ☐ Unit test đầy đủ · ☐ Bảng so sánh · ☐ User manual | Bộ kiểm thử tự động, so sánh độ phức tạp/hiệu năng, hướng dẫn sử dụng |
| **Tuần 10** | ☐ Báo cáo · ☐ Video · ☐ Slide · ☐ Nộp và ký | Hoàn thiện hồ sơ và sản phẩm nộp cuối kỳ |

## 7. Mục tiêu điểm cộng

| Yêu cầu điểm cộng | Tiến độ |
|---|---|
| Đăng nhập và phân quyền | Đã có phiên bản ban đầu |
| Xuất báo cáo CSV | Đã có phiên bản ban đầu |
| Đo hiệu năng chi tiết và biểu đồ | Chưa thực hiện; sẽ bổ sung sau khi có các CTDL để đo |
| Code sạch và unit test tự động | Đã có test ban đầu; cần mở rộng bao phủ các module |

## 8. Tài liệu dự án

- [`docs/SRS.pdf`](docs/SRS.pdf): Đặc tả yêu cầu phần mềm.
- [`docs/Design.pdf`](docs/Design.pdf): Tài liệu thiết kế.
- [`docs/sodolop.png`](docs/sodolop.png): Sơ đồ thiết kế.
- [`docs/SRS.md`](docs/SRS.md): Bản SRS dạng Markdown.
- [`docs/Design.md`](docs/Design.md): Bản thiết kế dạng Markdown.
- [`docs/huongdansudung_dangnhap_csv.md`](docs/huongdansudung_dangnhap_csv.md): Hướng dẫn đăng nhập, phân quyền và xuất CSV.

---

**Lưu ý tiến độ:** Checklist phản ánh trạng thái hiện tại của bộ dự án tại thời điểm cập nhật README. Chỉ đánh dấu hoàn thành khi mã nguồn/tài liệu tương ứng đã được bổ sung và kiểm tra.
