// Write a C++ programto create a class Distance which contains data members as kilometer, meter.
// Write a program to perform the following functions
// a.To accept distance
// b.To display distance
// c.To overload > operator to compare two distance
#include <iostream>
using namespace std;

class Distance {
    private:
        int kilometer;
        int meter;
    public:
        void accept_distance() {
            cout << "Enter distance in kilometers: ";
            cin >> kilometer;
            cout << "Enter distance in meters: ";
            cin >> meter;
        }

        void display_distance() {
            cout << "Distance: " << kilometer << " kilometers and " << meter << " meters" << endl;
        }

        bool operator > (Distance d) {
            int this_distance = (kilometer * 1000) + meter;
            int other_distance = (d.kilometer * 1000) + d.meter;
            return (this_distance > other_distance);
        }
};

int main() {
    Distance d1, d2;
    cout << "----- DISTANCE #1 -----:\n";
    d1.accept_distance();
    cout << "----- DISTANCE #2 -----:\n";
    d2.accept_distance();

    cout << "\nDistance 1:\n";
    d1.display_distance();
    cout << "\nDistance 2:\n";
    d2.display_distance();

    if(d1 > d2) {
        cout << "\nDistance 1 is greater than Distance 2" << endl;
    }
    else {
        cout << "\nDistance 2 is greater than Distance 1" << endl;
    }
    return 0;
}
