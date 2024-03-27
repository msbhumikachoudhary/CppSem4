// Write a C++ program to subtract two integer numbers of two different classes using friend function.
#include <iostream>
using namespace std;

class Number2;

class Number1 {
    int num1;

public:
    Number1(int n1) {
        num1 = n1;
    }

    friend int subtract(Number1 n1, Number2 n2);
};

class Number2 {
    int num2;

public:
    Number2(int n2) {
        num2 = n2;
    }

    friend int subtract(Number1 n1, Number2 n2);
};

int subtract(Number1 n1, Number2 n2) {
    return n1.num1 - n2.num2;
}

int main(void) {
    int num1, num2, result;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    Number1 n1(num1);
    Number2 n2(num2);

    result = subtract(n1, n2);
    cout << "Result of subtraction: " << result << endl;
}
