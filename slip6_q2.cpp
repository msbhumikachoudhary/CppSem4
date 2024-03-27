// Write a C++ program to design a class complex to represent complex number. The complex class
// uses an external function (as a friend function) to add two complex number. The function should
// return an object of type complex representing the sum of two complex Numbers. 
#include <iostream>
using namespace std;

class complex {
private:
    float real;
    float imaginary;

public:
    complex(float r = 0, float i = 0) {
        real = r;
        imaginary = i;
    }

    friend complex add(complex c1, complex c2);

    void display() {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

complex add(complex c1, complex c2) {
    complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

int main(void) {
    complex c1(14, 14);
    complex c2(15, 10);

    complex sum = add(c1, c2);

    cout << "Complex Number #1 = ";
    c1.display();
    cout << "Complex Number #2 = ";
    c2.display();
    cout << "Sum = ";
    sum.display();
}
