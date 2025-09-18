#include <iostream>

void swapWithTemp(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a, b;
    std::cout << "Enter number a: "; std::cin >> a;
    std::cout << "Enter number b: "; std::cin >> b;
    
    std::cout << std::endl;
    std::cout << "Before swap a = " << a << ", b = " << b << std::endl;
    swapWithTemp(a, b);
    std::cout << "After swap a = " << a << ", b = " << b << std::endl;

    return 0;
}