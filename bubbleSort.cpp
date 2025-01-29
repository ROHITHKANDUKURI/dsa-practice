#include <iostream>
#include <vector>
#include <sstream>

void bubbleSort(std::vector<int>& arr) {
    int size = arr.size();
    for(int i = size - 1;i > 0;i--) {
        for(int j = 0; j < i;j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
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
    bubbleSort(arr);
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
