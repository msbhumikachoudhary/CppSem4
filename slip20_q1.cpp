// Write a C++ program to sort integer and float array elements in ascending order by using
// function overloading 
#include <iostream>
using namespace std;

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(void) {
    int int_arr[] = { 5, 1, 9, 3, 7 };
    float float_arr[] = { 5.5, 1.1, 9.9, 3.3, 7.7 };

    int int_n = sizeof(int_arr) / sizeof(int);
    int float_n = sizeof(float_arr) / sizeof(float);

    sort(int_arr, int_n);
    sort(float_arr, float_n);

    cout << "Sorted integer array:" << endl;
    for (int i = 0; i < int_n; i++) {
        cout << int_arr[i] << " ";
    }
    cout << endl;

    cout << "Sorted float array:" << endl;
    for (int i = 0; i < float_n; i++) {
        cout << float_arr[i] << " ";
    }
    cout << endl;
}
