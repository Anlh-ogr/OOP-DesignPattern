# đồng hồ hẹn giờ

### 📌 Danh sách chức năng cần làm (bản FULL chính xác lịch thật)
1. Nhập thời gian bắt đầu
   - Input: ngày, tháng, năm, giờ, phút, giây.
   - Kiểm tra hợp lệ:
      - 1 ≤ day ≤ daysInMonth(month, year)
      - 1 ≤ month ≤ 12
      - year > 0
      - 0 ≤ hour ≤ 23
      - 0 ≤ minute ≤ 59
      - 0 ≤ second ≤ 59
   - Nếu sai → yêu cầu nhập lại.
   - In ra thời gian đã nhập (theo định dạng mặc định dd/mm/yyyy hh:mm:ss).

2. Nhập thời gian kết thúc
   - Tương tự kiểm tra như thời gian bắt đầu.
   - In ra thời gian kết thúc.

3. Kiểm tra tính hợp lệ Start < End
   - So sánh đầy đủ:
      - Nếu endYear < startYear → sai.
      - Nếu endYear == startYear thì so sánh tiếp month.
      - Nếu month bằng nhau → so sánh day, rồi hour, minute, second.
   - Nếu start >= end → báo lỗi.

4. Chọn định dạng hiển thị
   - Người dùng chọn:
      - Case 1: 12h (AM/PM).
      - Case 2: 24h.
   - Lưu lựa chọn vào biến formatType.

5. Hàm hỗ trợ định dạng thời gian
   - printTime24(day, month, year, h, m, s) → hiển thị dạng 24h.
   - printTime12(day, month, year, h, m, s) → hiển thị dạng 12h + AM/PM.
   - Tự động dùng setw(2) + setfill('0') để in chuẩn dd/mm/yyyy hh:mm:ss.

6. Hàm tính số ngày trong tháng
   - daysInMonth(month, year):
      - Tháng 1,3,5,7,8,10,12 → 31 ngày.
      - Tháng 4,6,9,11 → 30 ngày.
      - Tháng 2:
         - Nếu năm nhuận → 29 ngày.
         - Ngược lại → 28 ngày.

7. Hàm kiểm tra năm nhuận
   - isLeapYear(year):
      - (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)

8. Đếm ngược (Countdown)
   - Tính tổng thời gian còn lại từ start → end (theo giây).
   - Dùng biến counter để giảm dần.
   - Mỗi vòng lặp:
      - Trừ đi 1 giây → cập nhật day, month, year, h, m, s.
      - Hiển thị theo định dạng đã chọn.
   - Dừng khi counter = 0.

9. Sử dụng kỹ thuật Flag
   - Biến running = true.
   - Khi countdown hết → running = false.

10.  Kết thúc
   - In ra "Hết giờ!".