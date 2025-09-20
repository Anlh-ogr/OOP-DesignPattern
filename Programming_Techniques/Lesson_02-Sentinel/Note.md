# Sentinel Technique in Programming

## Chức năng:
- Đánh dấu tìm ra trường hợp thỏa mãn tốt nhất trong một tập hợp các giá trị.

## Ví dụ:
``` cpp
    int findMax(int arr[], int size) {
        int max = arr[0];
        for (int i = 0; i < size; ++i)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }
```
- Biến `max` được sử dụng để lưu giá trị đầu tiên trong mảng `arr[0]`.
- Trong quá trình duyệt mảng `arr`, nếu tìm thấy giá trị nào > `max`, cập nhật `max` = giá trị đó.
- Kết thúc vòng lặp, `max` sẽ chứa giá trị lớn nhất trong mảng.