#include <bits/stdc++.h>

int countNum(int arr[], int size, int num) {
    int count = 0;
    for (int i = 0; i < size; ++i)
        if (num == arr[i])
            ++count;
    return count;
}

void countEvenOdd(int arr[], int size) {
    int count_e = 0, count_o = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i]%2 == 0)
            ++count_e;
        else
            ++count_o;
    std::cout << "Count Even number is: " << count_e << std::endl;
    std::cout << "Count Odd number is: " << count_o << std::endl;
}

void countPosNeg(int arr[], int size) {
    int count_p = 0, count_n = 0;
    for (int i = size-1; i>=0 ; --i)
        if (arr[i] >= 0)
            ++count_p;
        else
            ++count_n;
    std::cout << "Count Positive number is: " << count_p << std::endl;
    std::cout << "Count Negative number is: " << count_n << std::endl;
}

bool isPrime(int size) {
    if (size < 2) return false;
    for (int i = 2; i <= sqrt(size); ++i)
        if (size % i == 0)
            return false;
    return true;
}

int countPrime(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i)
        if (isPrime(arr[i]))
            ++count;
    return count;
}

int main () {
    int array[] = {1, 2, 3, -4, 5, 2, 7, 8, -9, 5};
    int size = sizeof(array)/sizeof(array[0]);
    int number;

    std::cout << "Enter number: "; std::cin >> number;
    std::cout << "Count number " << number << " is: " << countNum(array, size, number) << std::endl;

    countEvenOdd(array, size);
    countPosNeg(array, size);
    std::cout << "Count prime: " << countPrime(array, size) << std::endl;

    return 0;
}