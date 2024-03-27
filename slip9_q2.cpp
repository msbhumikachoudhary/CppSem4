// Create a class Time which contains data members as: Hours, Minutes and Seconds. Write a
// C++ program to perform following necessary member functions:
// a. To read time
// b. To display time in format like: hh:mm:ss
// c. To add two different times (Use Objects as argument) 
#include <iostream>
using namespace std;

class Time {
    int hours, minutes, seconds;
public:
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    void read_time() {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;
    }
    void display_time() {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
    Time add_time(Time t2) {
        Time result;
        result.seconds = seconds + t2.seconds;
        result.minutes = minutes + t2.minutes + result.seconds / 60;
        result.hours = hours + t2.hours + result.minutes / 60;
        result.minutes %= 60;
        result.seconds %= 60;
        return result;
    }
};

int main() {
    Time t1, t2, sum;
    cout << "Enter time 1:" << endl;
    t1.read_time();
    cout << "Enter time 2:" << endl;
    t2.read_time();
    sum = t1.add_time(t2);
    cout << "Time 1: ";
    t1.display_time();
    cout << "Time 2: ";
    t2.display_time();
    cout << "Sum: ";
    sum.display_time();
    return 0;
}
