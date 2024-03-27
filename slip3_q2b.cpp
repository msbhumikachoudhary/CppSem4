// Create a class String which contains a character pointer (Use new and delete operator)
// Write a C++ program to overload following operators
// a. ! To reverse the case of each alphabet from given string.
// b. [ ] To print a character present at specified index
#include <iostream>
#include <cstring>
using namespace std;

class String {
public:
    String(const char* str) {
        int length = strlen(str) + 1;
        data = new char[length];
        strncpy(data, str, length);
    }

    ~String() {
        delete[] data;
    }

    char& operator[](int index) {
        return data[index];
    }

    String operator!() {
        int length = strlen(data);
        char* newData = new char[length + 1];
        for (int i = 0; i < length; i++) {
            if (isupper(data[i])) {
                newData[i] = tolower(data[i]);
            }
            else if (islower(data[i])) {
                newData[i] = toupper(data[i]);
            }
            else {
                newData[i] = data[i];
            }
        }
        newData[length] = '\0';
        return String(newData);
    }

    friend ostream& operator<<(ostream& out, const String& str) {
        out << str.data;
        return out;
    }

private:
    char* data;
};

int main(void) {
    String str("VS Code is best !");

    // Print original string
    cout << "Original: " << str << endl;

    // Test [] operator
    cout << "Character at index 4: " << str[4] << endl;

    // Test ! operator
    cout << "Reversed case: " << !str << endl;
}
