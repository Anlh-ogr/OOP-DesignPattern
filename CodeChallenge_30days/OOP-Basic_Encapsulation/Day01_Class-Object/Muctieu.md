# Day 01 — Nền tảng C++ cho OOP (mindset dân chuyên)

> Mục tiêu: Ôn/đặt nền C++ phục vụ OOP: **giá trị–đối tượng–vòng đời**, **khởi tạo**, **con trỏ vs tham chiếu**, **const-correctness**, **struct vs class**, **tổ chức mã (header/implementation)** và tư duy **invariant** cho đối tượng. Cuối ngày bạn viết được lớp đơn giản có bất biến rõ ràng và biên dịch chuẩn mực.

---

## 1) Bức tranh lớn: OOP trong C++ = *quản lý vòng đời + bất biến*

* **Object** = dữ liệu + hành vi + *bất biến (invariant)* phải luôn đúng sau mọi thao tác.  
  <!-- Invariant (bất biến)
    Là điều kiện luôn đúng đối với một đối tượng trong suốt vòng (lifetime) đời của nó.
    Phải đảm bảo bất biến từ constructor và duy trì nó qua mọi phương thức public.
    vd: BankAccount balance >= 0 (số dư tài khoản không được âm)
      #include <iostream>
      #include <stdexcept>    // std::invalid_argument, std::runtime_error
      class BankAccount {
          double balance;     // bất biến: balance >= 0
        public:
          Constructor: có 2 loại.
          Default constructor : không tham số và khởi tạo mặc định
          BankAccount() {
            balance = 0;
          }
            
          Parameterized constructor : có tham số - gán giá trị cho thành viên.
          BankAccount(double b) : balance(b) {    // constructor: khởi tạo logic đảm bảo invariant cho balance.
            if (b < 0)
              throw std::invalid_argument("Negative balance");
          }
          void withdraw(double amount) {
              if (amount > balance) 
                throw std::runtime_error("Insufficient funds");
              balance -= amount;
          }
          double getBalance() const { return balance; }
      };

      int main() {
          BankAccount acc(100);
          acc.withdraw(40);
          std::cout << acc.getBalance() << "\n";
          return 0;
      }
  -->

* **C++ đặc thù**: bạn kiểm soát chi tiết **vòng đời** (lifetime), **khởi tạo** (initialization), **quyền sở hữu** (ownership). Muốn OOP vững: nắm vững nền tảng này trước.
  <!-- Lifetime (vòng đời)
    Khoảng thời gian một object tồn tại trong bộ nhớ (khởi tạo -> giải phóng bộ nhớ).
  -->
  <!-- Ownership (quyền sở hữu)
    Admin chịu trách nhiệm quản lý object (delete object khi không dùng nữa).
  -->

**Chuỗi kiến thức liên kết:**

* Ngày 1 (hôm nay): nền C++ → chuẩn hóa cách tạo/giữ đối tượng.
* Ngày 2–7: xây lớp bài bản (ctor/dtor, access control, getter/setter, static, friend…).
* Tuần 2–4: kế thừa, đa hình, RAII, smart pointer, SOLID, design patterns.

---

## 2) Giá trị, đối tượng, vòng đời (lifetime)

**Giá trị (value)** chỉ là dữ liệu. **Đối tượng (object)** tồn tại trong một **miền nhớ** với **vòng đời** xác định.
  <!-- Miền nhớ (storage)
    Vùng bộ nhớ trong máy, nơi mà variable/object được cấp phát và lưu trữ.
    vd: stack, heap, static, thread-local
  -->

* **Automatic storage (stack)**: hủy tự động khi ra khỏi scope → an toàn, rẻ.
  <!-- Stack 
    Đối tượng có vòng đời ngắn, tự động hủy khi ra khỏi scope(phạm vi).
    Nhanh, an toàn, ít rò rỉ bộ nhớ.
    vd:
      int main() {
        int x = 42; // x có automatic storage (stack)
        std::cout << x << "\n";
      } // x bị hủy tự động ở đây
  -->

* **Dynamic storage (heap)**: `new`/`delete` → linh hoạt nhưng dễ rò rỉ. (Sau này ta ưu tiên **RAII + smart pointers**.)
  <!-- Heap
    Đối tượng có vòng đời dài, do người dùng quản lý (new/delete).
    Linh hoạt nhưng dễ rò rỉ bộ nhớ nếu không quản lý tốt.
    vd:
      int* p = new int(42); // p trỏ đến vùng nhớ trên heap
      std::cout << *p << "\n";
      delete p; // giải phóng bộ nhớ
  -->

  <!-- RAII - Resource Acquisition Is Initialization
    Quản lí tài nguyên thông qua khởi tạo.
    Tài nguyên (resource) có thể là bộ nhớ, file handle, socket, mutex lock...
    Khi object ra khỏi scope, tài nguyên cũng được giải phóng tự động.
    vd: std::vector, std::string, smart pointers (std::unique_ptr, std::shared_ptr)
      #include <memory>
      int main() {
        auto p = std::make_unique<int>(123); // p là smart pointer quản lý bộ nhớ
        std::cout << *p << "\n"; // không lo rò rỉ bộ nhớ
      }
  -->

> Quy tắc vàng sớm: *Dùng đối tượng tự động (stack) khi có thể; chỉ heap khi thực sự cần đa hình/động.*

---

## 3) Khởi tạo trong C++ (rất quan trọng cho OOP)

Các dạng khởi tạo bạn sẽ gặp liên tục khi viết class:

* **Default-init**: không gán giá trị (đối với built-in có thể rác).
  <!-- int a; std::cout << a; // giá trị không xác định -->

* **Value-init**: `T t{};` - đảm bảo khởi tạo mặc định (0 cho built-in).
  <!-- int b{}; std::cout << b; // b = 0 -->

* **Direct-init**: `T t(arg);` - gọi constructor với ngoặc tròn.
  <!-- std::string s("Hello"); // gọi ctor với ngoặc () -->

* **List-init (uniform)**: `T t{arg1, arg2};` — an toàn, nhất quán, tránh narrowing().
  <!-- std::vector<int> v{1,2,3}; -->

Ví dụ:

```cpp
int a;        // default-init (không xác định)
int b{};      // value-init (0)
std::string s1;       // chuỗi rỗng
std::string s2{"Hi"};
std::vector<int> v{1,2,3};
```

**Trong class**: luôn khởi tạo thành viên tại **member initializer list** để duy trì bất biến.

---

## 4) Tham chiếu vs Con trỏ & const-correctness

* **Tham chiếu (`T&`)**: alias, luôn trỏ đến một đối tượng hợp lệ, không null, không đổi mục tiêu.
* **Con trỏ (`T*`)**: có thể null/đổi đích; cần kiểm tra, quản lý vòng đời.
* `const` bảo vệ bất biến:

  * `const T x;` → x bất biến.
  * `T* const p;` → p không đổi địa chỉ, *đối tượng trỏ tới có thể đổi*.
  * `const T* p;` → *đối tượng* bất biến qua p.
  * `const` sau phương thức: `int get() const;` cam kết *không thay đổi trạng thái quan sát được*.
  <!--
    const int x = 5; - biến không đổi
    const T& ref - tham chiếu hằng
    void f() const - cam kết hàm không thay đổi trạng thái đối tượng
  -->

> Quy tắc: *Nếu không cần null/đổi đích → dùng tham chiếu; nếu cho phép vắng mặt → dùng con trỏ (sau này cân nhắc `std::optional<T>` hoặc smart pointer).*

---

## 5) Truyền tham số: by value / by (const) reference

* **Nhỏ, copy rẻ (int, double, iterator)** → by value.
* **Lớn/đắt (std::string, vector)** → `const T&` để tránh copy.
* Trả về: ưu tiên *return by value* (NRVO/move tối ưu), trừ khi cần tham chiếu.

---

## 6) Tổ chức mã hiện đại: header/implementation

* File **`.hpp`/`.h`** (khai báo), **`.cpp`** (định nghĩa). Dùng `#pragma once` hoặc include guard.
* **Không** `using namespace std;` trong header.
* Biên dịch khuyến nghị:

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -O2 your_file.cpp -o your_prog
```

---

## 7) `struct` vs `class` trong C++

* Khác biệt duy nhất về **mặc định quyền truy cập**: `struct` → `public`, `class` → `private`.
* Cả hai đều có ctor/dtor, phương thức, operator overload, kế thừa.
  <!-- ctor & dtor
    ctor: Hàm đặc biệt được gọi khi tạo object.
    dtor: Hàm đặc biệt được gọi khi object bị hủy - giải phóng tài nguyên.
    vd:
      class Demo {
        private:
          int a, b;
        public:
          Demo(int x, int y) : a(x), b (y) {} // ctor
          ~Demo() {}                          // dtor

          // setter : gán giá trị cho object
          void setA(int x) { a = x; }
          void setB(int y) { b = y; }

          // getter : lấy giá trị từ object
          int getA() const { return a; }
          int getB() const { return b; }
      };

      int main() {
        Demo obj(1, 2); // gọi ctor
        std::cout << obj.getA() << ", " << obj.getB() << "\n";
      } // gọi dtor khi obj ra khỏi scope
  -->

  <!-- operator overload
    Cho phép định nghĩa lại hành vi của toán tử cho kiểu dữ liệu do người dùng tạo.

    Trong C++ có thể overload các toán tử:
    - Toán tử số học: +, -, *, /, %
    - Toán tử so sánh: ==, !=, <, >, <=, >=
    - Toán tử gán: =, +=, -=, *=, /=, %=
    - Toán tử logic: &&, ||, !
    - Toán tử bit: &, |, ^, ~, <<, >>
    - Toán tử tăng giảm: ++, --
    - Toán tử truy cập: [], (), ->, *(dereference)
    - Toán tử lấy địa chỉ: & (address-of)
    - Toán tử điều kiện: , (comma), ->*
    - Toán tử nhập/xuất: <<, >> (ostream/istream)
    - Toán tử new/delete: new, delete, new[], delete[]

    Không thể overload:
    - Toán tử phạm vi: :: (:: scope resolution)
    - Toán tử thành viên pointer: .*, ->* (pointer to member)
    - Toán tử truy cập thành viên: . (member access)
    - Toán tử điều kiện ?: (ternary)
    - Toán tử sizeof: sizeof
    - Toán tử typeid: typeid
    - Toán tử alignof, noexcept, const_cast, static_cast, dynamic_cast, reinterpret_cast
    vd1:
      struct Vec {
        int x;
        Vec(int v) : x(v) {}
        Vec operator+(const Vec& other) const {
          return Vec(x + other.x);
        }

        Vec operator-(const Vec& other) const {
          return Vec(x - other.x);
        }

        Vec operator*(int scalar) const {
          return Vec(x * scalar);
        }
      };

      int main() {
        Vec v1(10);
        Vec v2(20);
        Vec v3 = v1 + v2; // sử dụng toán tử +
        Vec v4 = v2 - v1; // sử dụng toán tử -
        Vec v5 = v1 * 3;  // sử dụng toán tử *
        std::cout << v3.x << ", " << v4.x << ", " << v5.x << "\n"; // in 30, 10, 30
      }

    vd2:
      class Point {
        private:
          int x, y;
        public:
          Point(int x_val, int y_val) : x(x_val), y(y_val) {}
          
          // Overload toán tử +
          Point operator+(const Point& other) const {
            return Point(x + other.x, y + other.y);
          }

          void print() const {
            std::cout << "(" << x << ", " << y << ")\n";
          }
      };

      int main() {
        Point p1(1, 2);
        Point p2(3, 4);
        Point p3 = p1 + p2; // sử dụng toán tử +
        p3.print(); // in (4, 6)
      }
  -->
* Thực hành: Dùng `struct` cho **dữ liệu thuần (POD/DTO)**, `class` cho **đối tượng có bất biến & đóng gói**.
  <!-- POD - Plain Old Data
    struct/class chỉ chứa dữ liệu thuần, không ctor/dtor phức tạp.
    vd:
      struct Point { int x, int y; }; // POD
    
      class Point {
        private:
          int a, b;
        public:
          Point(int x, int y) : a(x), b(y) {} // không phải POD - do có ctor
      };
  -->

  <!-- DTO - Data Transfer Object
    cũng là dữ liệu thuần, thường dùng để trao đổi dữ liệu giữa các tầng của chương trình.
    vd:
      struct UserDTO { std::string name; int age; };

      class User {
        private:
          std::string name_;
          int age_;
        public:
          User(std::string name, int age) : name_(name), age_(age) {}
          const std::string& name() const { return name_; }
          int age() const { return age_; }
      };
  -->

Ví dụ chuyển từ dữ liệu thuần → đối tượng có bất biến:

```cpp
// Dữ liệu thuần (struct):
struct StudentDTO {
    std::string name;
    int age{}; // có thể bị đặt âm nếu không kiểm soát
};

// Đối tượng có bất biến (class):
class Student {
    std::string name_;
    int age_{}; // bất biến: age_ >= 0
public:
    Student(std::string name, int age)
        : name_(std::move(name)), age_(age) {
        if (age_ < 0) throw std::invalid_argument("age < 0");
    }
    const std::string& name() const noexcept { return name_; }
    int age() const noexcept { return age_; }
};
```

> Liên kết kiến thức: Hôm nay bạn *định nghĩa bất biến và đảm bảo từ ctor*. Ngày 4 sẽ bàn về getter/setter an toàn; ngày 16 về exception & hợp đồng (contract) chặt chẽ hơn.

---

## 8) I/O nhanh: quy tắc tối thiểu đủ dùng

* Chỉ dùng `iostream` trong ví dụ đơn giản; phần production cân nhắc format thư viện khác.
* Tránh I/O trong ctor (khó test). Thay vào đó cung cấp phương thức.

---

## 9) Bẫy phổ biến khi bước vào OOP C++

* Quên khởi tạo thành viên → giá trị rác.
* Dùng con trỏ thô không cần thiết → rò rỉ/UB. (Sau này: **smart pointers**.)
* Lạm dụng `using namespace std;` trong header → ô nhiễm namespace.
* Thiếu bất biến rõ ràng → lớp khó bảo trì/test.

---

## 10) Checklist cuối ngày

* [ ] Biên dịch được với `-Wall -Wextra -Wpedantic` không cảnh báo.
* [ ] Phân biệt stack/heap; tham chiếu/con trỏ; các kiểu khởi tạo.
* [ ] Viết được `class` đơn giản có bất biến kiểm soát trong ctor.
* [ ] Tách header/implementation tối thiểu.

<!-- 
#include <bits/stdc++.h>

struct Point {          // POD
    int x, y;
};

struct Student {        // DTO
  std::string name;
  int age{};            // khai báo mặc định = 0
};

class BankAccount {
  std::string owner_;
  double balance_;      // invariant: balance_ >= 0

  public:
    // Constructor (direct-init/list-init dùng initializer list)
    BankAccount(std::string owner, double balance)
      : owner_(std::move(owner)), balance_(balance) {
        if (balance_ < 0) throw std::invalid_argument("Negative balance!");
    }

    // Destructor
    ~BankAccount() {
        std::cout << "Account of " << owner_ << " is closed.\n";
    }

    // Deposit: duy trì invariant
    void deposit(double amount) {
        if (amount < 0) throw std::invalid_argument("Negative deposit!");
        balance_ += amount;
    }

    // Withdraw: duy trì invariant
    void withdraw(double amount) {
        if (amount > balance_) throw std::runtime_error("Insufficient funds!");
        balance_ -= amount;
    }

    // Getter const (không đổi state)
    double getBalance() const { return balance_; }

    // Operator overload
    friend std::ostream& operator<<(std::ostream& os, const BankAccount& acc) {
        return os << "[Owner: " << acc.owner_ << ", Balance: " << acc.balance_ << "]";
    }
};

// RAII class: tự động quản lý tài nguyên (ở đây chỉ minh họa)
class Logger {
public:
    Logger() { std::cout << "Logger start.\n"; }
    ~Logger() { std::cout << "Logger end.\n"; }
};

int main() {
  std::cout << "=== POD vs DTO ===\n";
  Point p{1, 2}; // list-init
  StudentDTO dto{"Alice", 20}; // DTO
  std::cout << "Point: (" << p.x << "," << p.y << ")\n";
  std::cout << "StudentDTO: " << dto.name << ", " << dto.age << "\n\n";

  std::cout << "=== Stack vs Heap ===\n";
  BankAccount stackAcc("StackUser", 100); // automatic storage
  auto heapAcc = std::make_unique<BankAccount>("HeapUser", 200); // heap + smart pointer (RAII)
  stackAcc.deposit(50);
  heapAcc->withdraw(30);
  std::cout << "Stack account: " << stackAcc << "\n";
  std::cout << "Heap account: " << *heapAcc << "\n\n";

  std::cout << "=== Khởi tạo (init forms) ===\n";
  int a;           // default-init (rác, không in)
  int b{};         // value-init = 0
  int c(5);        // direct-init
  std::vector<int> v{1, 2, 3}; // list-init
  std::cout << "b = " << b << ", c = " << c << "\n";
  std::cout << "vector v = ";
  for (int x : v) std::cout << x << " ";
  std::cout << "\n\n";

  std::cout << "=== RAII Demo ===\n";
  {
      Logger log; // ctor gọi Logger start, dtor gọi Logger end khi ra khỏi scope
  }
  std::cout << "\n";

  std::cout << "=== Operator overload ===\n";
  std::cout << "Final stackAcc: " << stackAcc << "\n";
  std::cout << "Final heapAcc: " << *heapAcc << "\n";

  return 0;
}


OUTPUT:
  === POD vs DTO ===
  Point: (1,2)
  StudentDTO: Alice, 20

  === Stack vs Heap ===
  Stack account: [Owner: StackUser, Balance: 150]
  Heap account: [Owner: HeapUser, Balance: 170]

  === Khởi tạo (init forms) ===
  b = 0, c = 5
  vector v = 1 2 3 

  === RAII Demo ===
  Logger start.
  Logger end.

  === Operator overload ===
  Final stackAcc: [Owner: StackUser, Balance: 150]
  Final heapAcc: [Owner: HeapUser, Balance: 170]
  Account of HeapUser is closed.
  Account of StackUser is closed.
-->

<!--
  Vấn đề khi dùng std::string trong struct
  Student(std::string n, int a) : name(n), age(a) {}
  - khi gọi Struct, dữ liệu được chuyển thành std::string tạm thời.
  - sau đó được copy vào tham số n.
  - rồi lại copy/move thêm 1 lần nữa gán -> name.
  -> Tốn 2 lần copy (1 copy + 1 move) -> không tối ưu.

  Giải pháp: sử dụng const std::string&
  để ctor tối ưu hơn:
  Student(const std::string& n, int a) : name(n), age(a) {}
  - đưa n vào tham chiếu -> tránh copy
  - chỉ copy 1 lần duy nhất từ n -> name.
  - tăng hiệu suất, giảm overhead.

  Trường hợp move: viết ctor rvalue reference
  Student(std::string&& n, int a) : name(std::move(n)), age(a) {}
  - khi gọi Student s(std::string("Alice"), 20); , dữ liệu được move trực tiếp vào name -> tránh copy.

std::string n -> copy nhiều lần -> chậm
const std::string& n -> copy 1 lần -> an toàn, tối ưu
std::string&& n -> move 1 lần -> tối ưu nhất (khi có thể)

thực tế chỉ cần viết ctor với const std::string& n để tối ưu cho hầu hết trường hợp.
với kiểu dữ liệu nhỏ (int, float,...), không cần dùng tham chiếu.
với kiểu dữ liệu lớn (std::string, std::vector, std::map, std::array<1000>, ...) -> chứa nhiều giá trị nên dùng 'const datatype(lớn)&' để tránh copy không cần thiết.
-->

---

## 11) Bài tập (có gợi ý + mở rộng)

### Bài A — `Student` (struct → class)

**Yêu cầu:**

1. Tạo `Student_Info` (struct) có `name`, `age` và hàm `print()` để in.
2. Viết `Class_Name` (struct) có `class_name` và dùng hàm `friend` để in.
3. Viết `Student` (class) với `name_`, `age_` private; ctor kiểm tra `age_ >= 0`.
4. Thêm phương thức `to_string()` trả về `"Name: ..., Age: ..."`.

**Gợi ý:**

* Khởi tạo bằng *member initializer list*.
  <!-- member initializer list là
    - các thành phần trong ctor để khởi tạo thành viên.
    Name_class(int a, float b) : member_a(a), member_b(b) {} -> là các member initializer list.
  -->
* Dùng `const std::string&` cho tham số đầu vào nếu không move.
* `to_string()` đánh dấu `const`.

**Mở rộng:**

* Cấm copy nếu `Student` đại diện thực thể duy nhất: `Student(const Student&) = delete;`.
* Thêm `StudentId` kiểu riêng (xem Bài 3 mở rộng) để tránh lẫn với `int` khác.

---

### Bài B — `BankAccount` (đặt nền invariant)

**Yêu cầu:**

* Thuộc tính: `owner`, `balance` (double ≥ 0).
* Phương thức: `deposit(amount)`, `withdraw(amount)` đảm bảo **không âm** và không rút quá số dư.
* Viết `print()` hiển thị trạng thái tài khoản.

**Gợi ý:**

* Xác thực đầu vào ngay ở biên (public API).
* Cân nhắc trả `bool` cho thất bại thay vì ném ngoại lệ (ngoại lệ sẽ học ở Ngày 16).
* Đánh dấu `print()` là `const`.

**Mở rộng:**

* Lưu *số lần giao dịch* (counter static hay per-object?).
* Chuẩn bị cho Ngày 19: thêm `save(std::ostream&)` để ghi file (chưa cần cài đặt).

---

### Bài C — *Strong type* cho ID (tránh nhầm lẫn)

**Yêu cầu:**

* Tạo kiểu `StudentId` đơn giản:

```cpp
struct StudentId {
    int value{};
};
```

* Sửa `Student` dùng `StudentId` thay cho `int` thuần.

**Gợi ý:**

* Cho phép khởi tạo `StudentId id{123};`.
* Viết hàm `bool operator==(StudentId, StudentId)` nếu cần so sánh.

**Mở rộng:**

* Ẩn `StudentId` sau namespace `domain::`.
* Cân nhắc bất biến `value > 0`.

---

### Bài D — Tổ chức mã & biên dịch

**Yêu cầu:**

* Tách `Student.hpp` và `Student.cpp`.
* Viết `main.cpp` tạo vài đối tượng, in kết quả.
* Biên dịch bằng:

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -O2 Student.cpp main.cpp -o app
```

**Gợi ý:**

* Dùng `#pragma once` ở header.
* Tránh phụ thuộc vòng (include tối thiểu).

**Mở rộng:**

* Thêm một test cực giản bằng `assert` trong `main.cpp`.

---

### Bài E — Khởi tạo an toàn (uniform initialization)

**Yêu cầu:**

* Viết lớp `Rectangle` với bất biến `width > 0, height > 0`.
* Cung cấp ctor `Rectangle{w, h}` và phương thức `area() const`.
,
**Gợi ý:**

* Dùng `double` và kiểm tra trong ctor.
* `area()` đánh dấu `noexcept` nếu chắc chắn không ném.

**Mở rộng:**

* Viết thêm `perimeter() const`.
* Chuẩn bị cho Ngày 12: overloading toán tử `<<` để in.

---

## 12) Lộ trình tiếp theo (ngày mai)

* **Ngày 02**: Class & Object *bài bản*: ctor/dtor, quy tắc khởi tạo, `explicit`, `=default`, `=delete`, phạm vi truy cập, và cách viết `main()` tối giản để kiểm thử.

> Giữ mindset: *Mọi lớp đều có bất biến rõ ràng và được đảm bảo ngay từ ctor; API public luôn duy trì bất biến đó.*
