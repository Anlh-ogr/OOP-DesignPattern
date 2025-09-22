# Counting Techniques in Programming

## Chức năng:
- Kiểm tra số lượng trường hợp quan trọng trong một tập hợp các giá trị.

## Ví dụ:
``` cpp - kỹ thuật đếm
    int counter(int arr[], int size, int val) {
        int count = 0;
        for (int i = 0; i < size; ++i)
            if (arr[i] == val)
                count ++; // ++count
        return count;
    }
```
``` cpp - đếm giá trị chẵn
    int countEven(int arr[], int size) {
        int count = 0;
        for (int i = 0; i < size; ++i)
            if (arr[i] % 2 == 0)
                count ++; // ++count
        return count;
    }
```
``` cpp - đếm giá trị lẻ
    int countOdd(int arr[], int size) {
        int count = 0;
        for (int i = 0; i < size; ++i)
            if (arr[i] % 2 != 0)
                count ++; // ++count
        return count;
    }
```
``` cpp - đếm giá trị dương
    int countPositive(int arr[], int size) {
        int count = 0;
        for (int i = 0; i < size; ++i)
            if (arr[i] > 0)
                count ++; // ++count
        return count;
    }
```
``` cpp - đếm giá trị âm
    int countNegative(int arr[], int size) {
        int count = 0;
        for (int i = 0; i < size; ++i)
            if (arr[i] < 0)
                count ++; // ++count
        return count;
    }
```
``` cpp - đếm số nguyên tố
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= sqrt(n); ++i)
            if (n % i == 0)
                return false;
        return true;
    }

    int countPrime(int arr[], int size) {
        int count = 0;
        for (int i = 0; i < size; ++i)
            if (isPrime(arr[i]))
                count ++; // ++count
        return count;
    }
```

- Biến `count` ban đầu được tạo = 0.
- Mỗi khi tìm thấy trường hợp thỏa mãn yêu cầu - tăng `count` lên 1 (++).
- Trả về giá trị của `count` sau khi hoàn thành việc đếm.