// Write a C++ program to create a class Mobile which contains data members as Mobile_Id,
// Mobile_Name, Mobile_Price. Create and Initialize all values of Mobile object by using
// parameterized constructor. Display the values of Mobile object.
#include <iostream>
#include <cstring>
using namespace std;

class Mobile {
private:
    int Mobile_Id;
    string Mobile_Name;
    float Mobile_Price;

public:
    Mobile(int id, string name, float price) {
        Mobile_Id = id;
        Mobile_Name = name;
        Mobile_Price = price;
    }

    void display() {
        cout << "Mobile Id: " << Mobile_Id << endl;
        cout << "Mobile Name: " << Mobile_Name << endl;
        cout << "Mobile Price: " << Mobile_Price << endl;
    }
};

int main(void) {
    Mobile m(13, "Samsung Galaxy S23+", 98999.99);
    m.display();
}
