// Write a C++ program to create a class which contains single dimensional integer array of
// given size. Define member function to display median of a given array. (Use Dynamic
// Constructor to allocate and Destructor to free memory of an object).
#include <iostream>
#include <algorithm> // for sorting array

using namespace std;

class Array {
private:
    int* arr;
    int size;

public:
    // Dynamic constructor
    Array(int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> arr[i];
        }
    }

    // Destructor
    ~Array() {
        delete[] arr;
    }

    // Member function to display median of array
    void displayMedian() {
        sort(arr, arr + size); // sort array in ascending order
        int mid = size / 2;
        if (size % 2 == 0) {
            cout << "Median is: " << (arr[mid - 1] + arr[mid]) / 2.0 << endl;
        } else {
            cout << "Median is: " << arr[mid] << endl;
        }
    }
};

int main(void) {
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    Array myArray(size);
    myArray.displayMedian();
}
