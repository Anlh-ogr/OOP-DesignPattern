#include "A.hpp"

int main() {
    Student_Info stu1;
    std::cout << "Enter student name: ";
    std::cin >> stu1.name >> stu1.age;
    stu1.print();

    Class_Name cla1;
    std::cout << "Enter class name: "; std::cin >> cla1;
    std::cout << "Class name is: " << cla1 << std::endl;
    
    try {
        Student stu2("John Doe", 20, StudentID(12345));
        std::cout << stu2.to_string() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}