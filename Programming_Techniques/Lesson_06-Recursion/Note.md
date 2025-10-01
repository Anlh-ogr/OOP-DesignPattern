# Recursion in Programming

## Chức năng:
- Là kỹ thuật lập trình trong đó một hàm gọi chính nó để giải quyết một vấn đề.
- Thường được sử dụng để giải quyết các bài toán có cấu trúc lặp lại hoặc phân chia vấn đề thành các phần nhỏ hơn.

## Ví dụ:
``` cpp
    int factorial(int n) {
        if (n == 0 || n == 1)           // base case
            return 1;
        return n * factorial(n - 1);    // recursive case
    }
```
- base case: điều kiện dừng, khi n = 0 hoặc n = 1, hàm trả về 1. Kết thúc đệ quy.
- recursive case: hàm gọi chính nó với n - 1, giảm dần n cho đến khi đạt base case.

## Ứng dụng:
- Giải quyết các bài toán: duyệt cây, tính dãy số, tìm kiếm, chia để trị (divide & conquer).