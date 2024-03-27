// Write a C++ program to interchange values of two integer numbers (use call by reference)
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main(void) {
    int x, y;
    cout<<"Enter the value of x : ";
    cin>>x;
    cout<<"Enter the value of y : ";
    cin>>y;
    cout << "Before swapping: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "After swapping: x = " << x << ", y = " << y << endl;
}