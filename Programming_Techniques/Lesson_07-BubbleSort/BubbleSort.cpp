#include <bits/stdc++.h>

/**
 * @brief: bubble sort in vector.
 * * @param arr vector: need to sort.
 * @param ascending true: Sort (min -> max), false: Sort (max -> min)
 */
// Sorts array in-place. Returns pair{swap_count, was_already_sorted(false->needed sort)}
std::pair<int,bool> SortWithStats(std::vector<int>& arr, bool ascending = true) {
    int n = arr.size();

    if (n <= 1)
        return {0, true};
    
    int total_swaps = 0;
    bool any_swap = false;
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;                   // origin state
        for (int j = 0; j < n - i - 1; ++j) {
            bool should_swap;                   // save state
            if (ascending)
                should_swap = (arr[j] > arr[j+1]);
            else
                should_swap = (arr[j] < arr[j+1]);

            if (should_swap) {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
                ++total_swaps;
                any_swap = true;
            }
        }
        if (!swapped) break;
    }
    return {total_swaps, !any_swap};
}

void Max_to_Min(std::vector<int>& arr) {
    SortWithStats(arr, false);
}

void Min_to_Max(std::vector<int>& arr) {
    SortWithStats(arr, true);
}

int Count_Swap(const std::vector<int>& arr) {
    auto tmp = arr;
    return SortWithStats(tmp, true).first;
}

int main () {
    std::vector<int> array = {64, 34, 25, 12, 22, 11, 90};

    Min_to_Max(array);
    std::cout << "Sorted array in ascending order: \n";
    for (int val : array)
        std::cout << val << " ";
    std::cout << std::endl;

    // show number of swaps needed for original array
    std::vector<int> original = {64, 34, 25, 12, 22, 11, 90};
    int swaps = Count_Swap(original);
    std::cout << "Number of swaps to sort ascending: " << swaps << std::endl;

    Max_to_Min(array);
    std::cout << "Sorted array in descending order: \n";
    for (int val : array)
        std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}   
