# 📘 Roadmap Học OOP C++ Trong 30 Ngày

> Lộ trình này giúp bạn đi từ **cơ bản → nâng cao → expert**. Mỗi ngày học 2-3h, có **lý thuyết + bài tập**.

---

## 🔰 Tuần 1: Nền tảng OOP

### 📅 Ngày 1: Ôn C++ cơ bản

* Ôn lại: biến, hàm, con trỏ, tham chiếu, struct.
* Hiểu sự khác nhau giữa struct và class.
* Bài tập: viết struct `Student` lưu tên, tuổi, in ra thông tin.

### 📅 Ngày 2: Class & Object

* Khai báo class, constructor, destructor.
* Khởi tạo object.
* Bài tập: viết class `Car` với thuộc tính `brand`, `speed` + method `showInfo()`.

### 📅 Ngày 3: Access Modifiers

* private, public, protected.
* Bài tập: Viết class `BankAccount` có balance private, method deposit/withdraw public.

### 📅 Ngày 4: Getter / Setter

* Cách đóng gói dữ liệu.
* Bài tập: Viết class `Employee` có private salary, getter/setter kiểm soát salary > 0.

### 📅 Ngày 5: Constructor Overloading

* Nạp chồng constructor.
* Bài tập: Class `Rectangle` có nhiều constructor khác nhau.

### 📅 Ngày 6: Static Members & Friend Class

* Static variable, static function.
* Friend function, friend class.
* Bài tập: Đếm số object đã được tạo.

### 📅 Ngày 7: Ôn tập + Mini project

* Làm project nhỏ: Quản lý sinh viên (Student Manager).

---

## 🔥 Tuần 2: Trừu tượng & Kế thừa

### 📅 Ngày 8: Inheritance (kế thừa)

* public, private, protected inheritance.
* Bài tập: Class `Animal` -> `Dog`, `Cat`.

### 📅 Ngày 9: Multiple Inheritance

* Diamond problem.
* Giới thiệu `virtual base class`.
* Bài tập: Class `Person` + `Worker` + `Student`.

### 📅 Ngày 10: Virtual Functions

* Đa hình run-time.
* Vtable, override.
* Bài tập: `Shape` -> `Circle`, `Rectangle` có hàm `area()`.

### 📅 Ngày 11: Abstract Class & Pure Virtual

* Interface trong C++.
* Bài tập: Abstract class `Shape`, implement bởi `Square`, `Triangle`.

### 📅 Ngày 12: Operator Overloading

* Nạp chồng toán tử `+`, `==`, `<<`.
* Bài tập: Class `Complex` hỗ trợ cộng số phức.

### 📅 Ngày 13: Copy Constructor & Assignment Operator

* Rule of 3.
* Deep copy vs Shallow copy.
* Bài tập: Class `Vector` với copy constructor.

### 📅 Ngày 14: Ôn tập + Mini project

* Quản lý thư viện (Book Manager).

---

## 🚀 Tuần 3: Nâng cao

### 📅 Ngày 15: Polymorphism nâng cao

* Upcasting, downcasting, `dynamic_cast`.
* Bài tập: Class hierarchy `Employee` -> `Manager`, `Engineer`.

### 📅 Ngày 16: Exception & OOP

* Try/catch trong class.
* Bài tập: BankAccount throw exception khi rút tiền âm.

### 📅 Ngày 17: Template + OOP

* Class template.
* Bài tập: Template `Box<T>`.

### 📅 Ngày 18: Namespaces & OOP

* Quản lý code lớn.
* Bài tập: Tách namespace `Math`, `Physics`.

### 📅 Ngày 19: File I/O + OOP

* Lưu object ra file, đọc lại.
* Bài tập: Student Manager có tính năng save/load.

### 📅 Ngày 20: Smart Pointers (RAII)

* unique\_ptr, shared\_ptr, weak\_ptr.
* Bài tập: Quản lý danh sách object bằng smart pointer.

### 📅 Ngày 21: Ôn tập + Mini project

* Quản lý ngân hàng (Banking System).

---

## 🏆 Tuần 4: Expert Level

### 📅 Ngày 22: SOLID Principles

* S, O, L, I, D trong OOP.
* Ví dụ từng nguyên tắc bằng C++.

### 📅 Ngày 23: Design Pattern - Singleton

* Cài đặt thread-safe Singleton.
* Bài tập: Logger system.

### 📅 Ngày 24: Design Pattern - Factory

* Factory Method.
* Bài tập: Shape Factory.

### 📅 Ngày 25: Design Pattern - Observer

* Event system.
* Bài tập: Chatroom user observer.

### 📅 Ngày 26: Design Pattern - Strategy

* Thay đổi thuật toán runtime.
* Bài tập: Payment Strategy (CreditCard, Paypal).

### 📅 Ngày 27: CRTP & Policy-based Design

* Curiously Recurring Template Pattern.
* Ứng dụng trong OOP nâng cao.

### 📅 Ngày 28: Rule of 0/3/5

* Constructor/Destructor/Copy/Move.
* Bài tập: Class `ResourceHandler` quản lý tài nguyên.

### 📅 Ngày 29: Tối ưu & Best Practices

* Khi nào dùng inheritance, khi nào composition.
* Object slicing, RTTI.

### 📅 Ngày 30: Final Project

* Xây dựng **Hệ thống Quản lý Cửa hàng**:

  * Class `Product`, `Customer`, `Order`.
  * Áp dụng kế thừa + đa hình.
  * Áp dụng ít nhất 2 design pattern.

---

# ✅ Kết quả sau 30 ngày

* Hiểu rõ 4 trụ cột OOP.
* Sử dụng thành thạo class, inheritance, polymorphism.
* Nắm vững design patterns phổ biến.
* Hiểu rule of 0/3/5, RAII, smart pointers.
* Có thể đọc/viết code OOP C++ ở level **senior/expert**.
