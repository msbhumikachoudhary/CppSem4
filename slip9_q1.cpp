// Write a C++ program to create a class Item with data members Item_code, Item_name, Item_Price.
// Write member functions to accept and display item information and also display number of objects
// created for a class. (Use Static data member and Static member function) 
#include <iostream>
#include <cstring>
using namespace std;

class Item {
    int Item_code;
    string Item_name;
    float Item_Price;
    static int count;
public:
    Item() {
        Item_code = 0;
        Item_name = "";
        Item_Price = 0.0;
        count++;
    }
    void accept() {
        cout << "Enter Item code: ";
        cin >> Item_code;
        cout << "Enter Item name: ";
        cin >> Item_name;
        cout << "Enter Item price: ";
        cin >> Item_Price;
    }
    void display() {
        cout << "Item code: " << Item_code << endl;
        cout << "Item name: " << Item_name << endl;
        cout << "Item price: " << Item_Price << endl;
    }
    static void display_count() {
        cout << "Total number of items: " << count << endl;
    }
};

int Item::count = 0;

int main() {
    Item item1, item2, item3;
    item1.accept();
    item2.accept();
    item3.accept();
    cout << "Item 1 details:" << endl;
    item1.display();
    cout << "Item 2 details:" << endl;
    item2.display();
    cout << "Item 3 details:" << endl;
    item3.display();
    Item::display_count();
    return 0;
}