// Write a C++ program to create two classes Rectangle1 and Rectangle2. Compare area of both the
// rectangles using friend function.
#include <iostream>
using namespace std;

class Rectangle2;
class Rectangle1 {
private:
    float length;
    float breadth;

public:
    Rectangle1(float l, float b) {
        length = l;
        breadth = b;
    }

    float getArea() {
        return length * breadth;
    }

    friend float compareArea(Rectangle1 r1, Rectangle2 r2);
};

class Rectangle2 {
private:
    float length;
    float breadth;

public:
    Rectangle2(float l, float b) {
        length = l;
        breadth = b;
    }

    float getArea() {
        return length * breadth;
    }

    friend float compareArea(Rectangle1 r1, Rectangle2 r2);
};

float compareArea(Rectangle1 r1, Rectangle2 r2) {
    float area1 = r1.getArea();
    float area2 = r2.getArea();

    if (area1 > area2)
        return area1;
    else 
        return area2;
}

int main(void) {
    Rectangle1 r1(8, 10);
    Rectangle2 r2(7, 5);

    cout << "Area of rectangle 1 is: " << r1.getArea() << endl;
    cout << "Area of rectangle 2 is: " << r2.getArea() << endl;
    cout << "The rectangle with the greater area is: " << compareArea(r1, r2) << endl;
}
