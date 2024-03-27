// Write a C++ program to check minimum and maximum of two integer number (use inline
// function and conditional operator)
#include <iostream>
using namespace std;

inline int min(int a, int b) {
    return (a < b) ? a : b;
}

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {
    int num1, num2;
    cout << "Enter two integer numbers: ";
    cin >> num1 >> num2;

    cout << "Minimum of " << num1 << " and " << num2 << " is " << min(num1, num2) <<endl;
    cout << "Maximum of " << num1 << " and " << num2 << " is " << max(num1, num2) <<endl;
}
