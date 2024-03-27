// Write a C++ program to create a class Shape with functions to find area of the shape and display
// the name of the shape and other essential components of the class. Create derived classes circle,
// rectangle and trapezoid each having overridden function area and display. Write a suitable
// program to illustrate Virtual Function.
#include <iostream>
#include <string>
using namespace std;

class Shape 
{
   protected:
    string name;
   public:
    Shape(string n) : name(n) {}
    virtual float area() 
    {
        return 0;
    }
    virtual void display() 
    {
        cout << "Shape: " << name << endl;
    }
};

class Circle : public Shape 
{
   private:
    float radius;
   public:
    Circle(string n, float r) : Shape(n), radius(r) {}
    float area() 
    {
        return 3.14 * radius * radius;
    }

    void display() 
    {
        cout << "Shape: " << name << ", Radius: " << radius << endl;
    }
};

class Rectangle : public Shape 
{
  private:
    float length, width;
  public:
    Rectangle(string n, float l, float w) : Shape(n), length(l), width(w) {}
    float area() 
    {
        return length * width;
    }
    void display() 
    {
        cout << "Shape: " << name << ", Length: " << length << ", Width: " << width << endl;
    }
};

class Trapezoid : public Shape 
{
   private:
    float a, b, height;
   public:
    Trapezoid(string n, float x, float y, float h) : Shape(n), a(x), b(y), height(h) {}
    float area() 
    {
        return (a + b) * height / 2;
    }
    void display() 
    {
      cout << "Shape: " << name << ", Side a: " << a << ", Side b: " << b << ", Height: " << height << endl;
    }
};

int main() 
{
    Shape *s;
    Circle c("Circle", 5);
    Rectangle r("Rectangle", 3, 4);
    Trapezoid t("Trapezoid", 2, 4, 5);

    s = &c;
    s->display();
    cout << "Area: " << s->area() << endl;

    s = &r;
    s->display();
    cout << "Area: " << s->area() << endl;

    s = &t;
    s->display();
    cout << "Area: " << s->area() << endl;

    return 0;
}
