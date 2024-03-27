// Create a class Fraction that contains two data members as numerator and denominator.
// Write a C++ program to overload following operators
// a. ++ Unary (pre and post both)
// b. << and >> Overload as friend functions 
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {}
    friend Fraction& operator++(Fraction& f); // pre-increment
    friend Fraction operator++(Fraction& f, int); // post-increment
    friend istream& operator>>(istream& in, Fraction& f);
    friend ostream& operator<<(ostream& out, const Fraction& f);
};

Fraction& operator++(Fraction& f) {
    f.numerator += f.denominator;
    return f;
}

Fraction operator++(Fraction& f, int) {
    Fraction temp(f);
    f.numerator += f.denominator;
    return temp;
}

istream& operator>>(istream& in, Fraction& f) {
    char slash;
    in >> f.numerator >> slash >> f.denominator;
    return in;
}

ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.numerator << "/" << f.denominator;
    return out;
}

int main() {
    Fraction f1(1, 2);
    cout << "f1 = " << f1 << endl;
    ++f1;
    cout << "++f1 = " << f1 << endl;
    f1++;
    cout << "f1++ = " << f1 << endl;
    Fraction f2;
    cout << "Enter a fraction (numerator/denominator): ";
    cin >> f2;
    cout << "f2 = " << f2 << endl;
    return 0;
}
