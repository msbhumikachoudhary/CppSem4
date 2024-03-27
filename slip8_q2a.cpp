// Create a class String which contains a character pointer (Use new and delete operator).
// Write a C++ program to overload following operators:
// a. ! To reverse the case of each alphabet from given string
// b. == To check equality of two strings
#include <iostream>
#include <cstring>
using namespace std;

class String {
    char* str;

public:
    String() {
        str = new char[1];
        str[0] = '\0';
    }

    String(const char* s) {
        int len = strlen(s) + 1;
        str = new char[len];
        strcpy(str, s);
    }

    ~String() {
        delete[] str;
    }

    void display() {
        cout << str << endl;
    }

    String operator!() {
        String result(*this);
        for (int i = 0; result.str[i]; i++) {
            if (islower(result.str[i])) {
                result.str[i] = toupper(result.str[i]);
            } else if (isupper(result.str[i])) {
                result.str[i] = tolower(result.str[i]);
            }
        }
        return result;
    }

    bool operator==(const String& s2) {
        return strcmp(str, s2.str) == 0;
    }
};

int main(void) {
    String s1("GOLD");
    String s2("GOLDEN");

    cout << "s1 = ";
    s1.display();
    cout << "s2 = ";
    s2.display();

    if (s1 == s2) {
        cout << "s1 and s2 are equal.\n";
    } else {
        cout << "s1 and s2 are not equal.\n";
    }

    s1 = !s1;
    s2 = !s2;

    cout << "s1 = ";
    s1.display();
    cout << "s2 = ";
    s2.display();

    if (s1 == s2) {
        cout << "s1 and s2 are equal.\n";
    } else {
        cout << "s1 and s2 are not equal.\n";
    }
}
