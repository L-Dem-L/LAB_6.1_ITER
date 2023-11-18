#include <iostream>
#include <cstdlib>
#include <ctime>

const int ARRAY_SIZE = 25;
const int LOWER_BOUND = 15;
const int UPPER_BOUND = 94;

void fillArray(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
    }
}

void printArray(const int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void processArray(int arr[], int& count, int& sum) {
    count = 0;
    sum = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (i % 2 != 0 && i % 13 != 0) {
            count++;
            sum += arr[i];
            arr[i] = 0;
        }
    }
}

int main() {
    std::srand(std::time(0));

    int myArray[ARRAY_SIZE];
    int count, sum;

    fillArray(myArray);
    std::cout << "Original Array: ";
    printArray(myArray);

    processArray(myArray, count, sum);
    std::cout << "Count of elements satisfying the criteria: " << count << std::endl;
    std::cout << "Sum of elements satisfying the criteria: " << sum << std::endl;
    std::cout << "Modified Array: ";
    printArray(myArray);

    return 0;
}
