// Write a C++ program to implement a class printdata to overload print function as follows:
// void print(int) - outputs value followed by the value of the integer.
// Eg. print(10) outputs - value 10
// void print(char *) – outputs value followed by the string in double quotes.
// Eg. print(“hi”) outputs value “hi” 
#include <iostream>
#include <cstring>

using namespace std;

class printdata {
public:
    void print(int value) {
        cout << "Integer Value : " << value << endl;
    }

    void print(char *value) {
        cout << "Character Value : \"" << value << "\"" << endl;
    }
};

int main(void) {
    printdata p;
    int num = 33;
    char str[] = "GOLD";
    p.print(num);
    p.print(str);
}