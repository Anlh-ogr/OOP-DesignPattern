#pragma once                    // tranh include nhieu lan
#include <bits/stdc++.h>

struct Student_Info {
    std::string name;
    int age{};                  // khoi tao (default) = 0 

    void print() const {
        std::cout << "Name: " << name
                  << ", Age: " << age << std::endl;
    }
};

struct Class_Name {
    std::string class_name;

    // (friend function) // truy cap private/public
    /** syntax: 
     * friend return_type function_name(parameters)
     * friend return_type operatorOP(const ClassName& obj1, const ClassName& obj2);
    */
    friend std::ostream& operator<<(std::ostream& os, const Class_Name &c) {
        // overload << -> cout
        return os << "Class Name: " << c.class_name;
    }

    friend std::istream& operator>>(std::istream& is, Class_Name &c) {
        // overload >> -> cin
        return is >> c.class_name;
    }
};

struct StudentID{
    int value{};
    /** explicit: ngan chan viec chuyen doi ngam -> (sd trong ctor/operator)
     * syntax:
     *  explicit Name_Class (Type parameter);
     * 
    */ 
    explicit StudentID(int v) : value(v) {}     // tranh nham ID vs int khac
};

class Student {
    private:
        std::string name_;
        int age_;
        StudentID id_;
    
    public:
        Student(const std::string& n, int a, StudentID id) 
            : name_(n), age_(a), id_(id) {
                if (a < 0)
                    throw std::invalid_argument("Age cannot be negative");
            }
        
        // Do not allow copying
        Student(const Student&) = delete;               // tranh copy constructor
        Student& operator=(const Student&) = delete;    
        
        std::string to_string() const {
            return "ID: " + std::to_string(id_.value) +
                   ", Name: " + name_ + 
                   ", Age: " + std::to_string(age_);
        }
};