# Bubble Sort in Programming

## Chức năng:
- Là thuật toán sắp xếp đơn giản, hoạt động bằng cách lặp đi lặp lại qua danh sách, so sánh các phần tử kề nhau và hoán đổi chúng nếu chúng không theo thứ tự mong muốn.
- Quá trình này được lặp lại cho đến khi không còn hoán đổi nào cần thiết, tức là danh sách đã được sắp xếp.

## Ví dụ:
``` cpp
    for (int i = 0; i < n-1; ++i)
        for (int j = 0; j < n-i-1; ++j)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
```

- dòng lặp ngoài (i)-chạy từ 0 -> n-1: Xác định số lần lặp của toàn mảng (n-1 lần).
- dòng lặp trong (j)-chạy từ 0 -> n-i-1: So sánh các phần tử kề nhau và hoán đổi nếu cần thiết.
- swap(arr[j], arr[j+1]): Hoán đổi hai phần tử nếu chúng không theo thứ tự mong muốn.

## Ứng dụng:
- Sắp xếp các mảng hoặc danh sách nhỏ.
- Giáo dục về các thuật toán sắp xếp cơ bản trong lập trình.
- Không hiệu quả cho các tập dữ liệu lớn so với các thuật toán sắp xếp khác như quicksort hoặc mergesort.