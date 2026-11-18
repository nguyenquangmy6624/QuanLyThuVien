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

5. Chạy toàn bộ unit test cho các tuần đã triển khai:

   ```powershell
   .\tests\chaykiemthu.bat
   ```

   Hoặc trên Linux/macOS/Git Bash:

   ```bash
   bash tests/chaykiemthu.sh
   ```

## 4. Chức năng mở rộng

- Đăng nhập và đổi mật khẩu.
- Phân quyền theo vai trò **Admin / Thủ thư / Độc giả**.
- Xuất danh sách sách và độc giả ra CSV UTF-8.
- Quản lý sách bằng cây AVL (thêm, sửa, xóa, tìm ISBN); dùng BST duyệt in-order để in danh mục tăng dần.
- Quản lý độc giả bằng Hash Table tự cài đặt với separate chaining.
- Có LinkedList tự cài đặt quản lý danh sách phiếu mượn, Dynamic Array tự cài đặt lưu lịch sử giao dịch.
- Đọc/ghi file nhị phân `.dat` cho sách, độc giả, phiếu mượn và lịch sử giao dịch; ghi log `.txt`.
- Unit test tự động cho đăng nhập/quyền và CSV, AVL/BST, Hash Table, LinkedList, Dynamic Array và File I/O.

> Tài khoản demo được tạo khi chưa có `data/taikhoan.dat`: `admin / Admin123!`, `thuthu / ThuThu123!`, `docgia / DocGia123!`. Hãy đổi mật khẩu sau lần đăng nhập đầu tiên. Cơ chế băm mật khẩu hiện tại chỉ nhằm minh họa đồ án, không dùng cho hệ thống thực tế.

## 5. Các mục menu đã triển khai

| Lựa chọn | Chức năng | Trạng thái |
|---|---|---|
| 1 | Quản lý sách: thêm, sửa, xóa, tìm ISBN bằng AVL; in danh mục bằng BST | Đã triển khai |
| 2 | Quản lý độc giả: thêm, sửa, xóa, tìm CMND/CCCD bằng Hash Table | Đã triển khai |
| 5 | Tìm sách theo ISBN | Đã triển khai |
| 7 | Xuất danh sách sách/độc giả ra CSV | Đã có phiên bản ban đầu |
| 10 | Demo LinkedList, Dynamic Array và File I/O của Tuần 5 | Đã triển khai |

Các mục mượn/trả, thống kê, sao lưu và đồ thị vẫn sẽ được hoàn thiện ở các tuần tiếp theo. Mục 10 là demo cấu trúc dữ liệu Tuần 5, chưa phải quy trình mượn-trả nghiệp vụ hoàn chỉnh.

## 6. Cấu trúc dữ liệu theo đề bài

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

## 7. Checklist tiến độ theo tuần

Đánh dấu `[x]` khi nội dung đã hoàn thành và được kiểm tra; để `[ ]` nếu chưa hoàn thành.

| Tuần | Checklist | Sản phẩm / ghi chú |
|---|---|---|
| **Tuần 1** | ☑ Repo Git/GitHub · ☑ SRS.pdf · ☑ Cấu trúc thư mục | Repo GitHub, `docs/SRS.pdf`, cấu trúc dự án |
| **Tuần 2** | ☑ Design.pdf · ☑ Sơ đồ lớp / sơ đồ module · ☑ Định nghĩa struct | `docs/Design.pdf`, `docs/sodolop.png`, `include/cacstruct.h` |
| **Tuần 3** | ☑ AVL · ☑ BST · ☑ Test quản lý sách | `include/cay_avl.h`, `src/cay_avl.cpp`, `include/cay_bst.h`, `src/cay_bst.cpp`, `tests/test_tuan3.cpp` |
| **Tuần 4** | ☑ Hash Table · ☑ Test quản lý độc giả | `include/bangbam_docgia.h`, `src/bangbam_docgia.cpp`, `tests/test_tuan4.cpp`; separate chaining và tự mở rộng bảng |
| **Tuần 5** | ☑ LinkedList · ☑ Dynamic Array · ☑ File I/O | `include/danh_sach_phieumuon.h`, `include/mang_dong.h`, file `.dat` cho phiếu mượn/lịch sử và `tests/test_tuan5.cpp` |
| **Tuần 6** | ☐ Mượn sách · ☐ Trả sách · ☐ Tính phạt | Hoàn thiện quy trình mượn/trả và kiểm tra quá hạn |
| **Tuần 7** | ☐ Graph · ☐ BFS/DFS · ☐ Thống kê Top 10 | Đồ thị gợi ý sách và các báo cáo thống kê |
| **Tuần 8** | ☐ CTDL mới tự tìm hiểu · ☐ Tích hợp · ☐ Demo | Cài đặt từ đầu, tích hợp và demo cấu trúc dữ liệu đã chọn |
| **Tuần 9** | ☐ Unit test đầy đủ · ☐ Bảng so sánh · ☐ User manual | Bộ kiểm thử tự động, so sánh độ phức tạp/hiệu năng, hướng dẫn sử dụng |
| **Tuần 10** | ☐ Báo cáo · ☐ Video · ☐ Slide · ☐ Nộp và ký | Hoàn thiện hồ sơ và sản phẩm nộp cuối kỳ |

## 8. Mục tiêu điểm cộng

| Yêu cầu điểm cộng | Tiến độ |
|---|---|
| Đăng nhập và phân quyền | Đã có phiên bản ban đầu |
| Xuất báo cáo CSV | Đã có phiên bản ban đầu |
| Đo hiệu năng chi tiết và biểu đồ | Chưa thực hiện; sẽ bổ sung sau khi có các CTDL để đo |
| Code sạch và unit test tự động | Đã có test ban đầu; cần mở rộng bao phủ các module |

## 9. Tài liệu dự án

- [`docs/SRS.pdf`](docs/SRS.pdf): Đặc tả yêu cầu phần mềm.
- [`docs/Design.pdf`](docs/Design.pdf): Tài liệu thiết kế.
- [`docs/sodolop.png`](docs/sodolop.png): Sơ đồ thiết kế.
- [`docs/SRS.md`](docs/SRS.md): Bản SRS dạng Markdown.
- [`docs/Design.md`](docs/Design.md): Bản thiết kế dạng Markdown.
- [`docs/huongdansudung_dangnhap_csv.md`](docs/huongdansudung_dangnhap_csv.md): Hướng dẫn đăng nhập, phân quyền và xuất CSV.
- [`docs/ThietKe_CTDTuan3_5.md`](docs/ThietKe_CTDTuan3_5.md): Thiết kế, cách hoạt động và độ phức tạp các CTDL Tuần 3–5.

---

**Lưu ý tiến độ:** Checklist phản ánh trạng thái hiện tại của bộ dự án tại thời điểm cập nhật README. Chỉ đánh dấu hoàn thành khi mã nguồn/tài liệu tương ứng đã được bổ sung và kiểm tra.
