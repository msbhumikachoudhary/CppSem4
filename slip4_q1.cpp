// Write a C++ program to print area of circle, square and rectangle using inline function
#include <iostream>
using namespace std;

inline float area(float r) {
    return 3.14 * r * r;
}

inline float area(double s1, double s2) {
    return s1 * s2;
}

inline float area(float l, float b) {
    return l * b;
}

int main(void) {
    float radius, length, breadth;
    double side;
    cout<<"Enter the radius of circle : ";
    cin>>radius;
    cout<<"Enter the side of square : ";
    cin>>side;
    cout<<"Enter the length and breadth of rectangle : ";
    cin>>length>>breadth;

    cout << "Area of circle with radius " << radius << " is " << area(radius) << endl;
    cout << "Area of square with side " << side << " is " << area(side, side) << endl;
    cout << "Area of rectangle with length " << length << " and breadth " << breadth << " is " << area(length, breadth) << endl;
}
