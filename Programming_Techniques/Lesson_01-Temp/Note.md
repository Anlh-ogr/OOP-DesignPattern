# Temporary Variables in Programming

## Chức năng:
- Lưu một giá trị của một biến khác trước khi nó bị thay đổi hoặc dùng để tính giá trị tạm thời cần được sử dụng ngay.

## Ví dụ:
``` cpp - đặt biến tạm
    int temp;
    temp = first;
    first = second;
    second = temp;
```
- Biến `temp` được sử dụng để làm biến trung gian hoán đổi giá trị của hai biến `first` và `second`.
- Biến `temp` không lưu trữ giá trị để xử lý tiếp ngay khi hoàn thành việc hoán đổi.