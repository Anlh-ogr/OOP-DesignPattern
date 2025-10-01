# 🧩 Bài toán: Giải mê cung (Maze Solver) bằng đệ quy

## 🎯 Đề bài
Bạn có một mê cung được mô tả bằng ma trận 2D (m × n):
- 0 → đường đi được.
- 1 → tường (không đi qua).
- S → điểm bắt đầu.
- E → điểm kết thúc.
Hãy viết chương trình tìm đường từ S đến E bằng kỹ thuật đệ quy (DFS).

## 💡 Ý tưởng giải bằng đệ quy
1. Tại một ô (x, y):
   - Nếu là đích → return true.
   - Nếu là tường hoặc đã đi qua → return false.
2. Đánh dấu (x, y) đã đi qua.
3. Thử đi 4 hướng: lên, xuống, trái, phải (dùng đệ quy).
4. Nếu một hướng thành công → propagate kết quả true lên trên.
5. Nếu không hướng nào đi được → backtrack (trả về false).