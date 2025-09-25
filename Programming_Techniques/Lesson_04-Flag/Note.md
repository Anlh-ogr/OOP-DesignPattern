# Flag Technique in Programming

## Chức năng:
- Kiểm soát các trường hợp quan trọng, đánh dấu các trường hợp nếu gặp phải, và sử dụng các cờ đánh dấu để quyết định hành động tiếp theo.

## Ví dụ:
``` cpp - đặt cờ hiệu
    int solution(int arr[], int size) {
        int flag = 1;
        for (int i = 0; i < size; i++) 
            if (arr[i] % 2 != 0) {
                flag = 0; // đặt cờ hiệu
                break;
            }
        return flag;
    }
```
- Tạo biến `flag` với giá trị mặc định là 1 = (true).
- Duyệt qua mảng, nếu gặp giá trị lẻ, đặt `flag = 0` (false) và thoát vòng lặp.
- Trả về `flag`, nếu tất cả giá trị đều chẵn, trả về 1, nếu có ít nhất một giá trị lẻ, trả về 0.

## So sánh với Sentinel:
### Sentinel
- Input: 
    - Mảng/danh sách dữ liệu.
    - Phải thêm phần tử đặc biệt (lính canh) vào cuối/một vị trí nào đó trong mảng/danh sách dữ liệu.
    -> Input bị thay đổi.
- Output:
  - Trả kết quả trực tiếp (kiểu dữ liệu gốc).
  - Không có thêm biến phụ.

### Flag
- Input:
    - Mảng/danh sách dữ liệu.
    - Giữ nguyên mảng/danh sách dữ liệu ban đầu.
    - Thêm biến phụ (cờ hiệu) để đánh dấu các trường hợp quan trọng.
    -> Input không bị thay đổi.
- Output:
    - Trả kết quả chính (vị trí phần tử,...).
    - Cộng thêm trả về là trạng thái của `flag` (true/false).