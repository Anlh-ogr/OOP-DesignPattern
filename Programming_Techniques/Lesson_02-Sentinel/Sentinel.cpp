#include <iostream>

int findMax(const int arr[], int size) {
    int Max = arr[0];
    for (int i = 0; i < size; ++i)
        if (arr[i] > Max)
            Max = arr[i];
        
    return Max;
}

int findMin(const int arr[], int size) {
    int Min = arr[0];
    for (int i = size - 2; i >= 0; --i)
        if(arr[i] < Min)
            Min = arr[i];
    
    return Min;
}

int main() {
    int array[] = {1, 3, 2, 4, 5, 7, 6, 10, 8, 9};
    int n = sizeof(array)/sizeof(array[0]);

    std::cout << "Max = " << findMax(array, n) << std::endl;
    std::cout << "Min = " << findMin(array, n);

    return 0;
}
