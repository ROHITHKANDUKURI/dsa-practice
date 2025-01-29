#include <iostream>
#include <vector>
#include <sstream>

void selectionSort(std::vector<int> &arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            std::swap(arr[i], arr[min]);
        }
    }
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::vector<int> arr;
    std::stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    selectionSort(arr);
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
