// Create a class Time containing members as:
// - hours
// - minutes
// - seconds
// Write a C++ program for overloading operators >> and << to accept and display a Time
// also write a member function to display time in total seconds.
#include<iostream>
using namespace std;

class Time{
    private:
        int hours, minutes, seconds;

    public:
        Time(){
            hours = 0;
            minutes = 0;
            seconds = 0;
        }

        friend istream& operator>>(istream& input, Time& T){
            cout<<"Enter hours: ";
            input>>T.hours;
            cout<<"Enter minutes: ";
            input>>T.minutes;
            cout<<"Enter seconds: ";
            input>>T.seconds;
            return input;
        }

        friend ostream& operator<<(ostream& output, const Time& T){
            output<<T.hours<<":"<<T.minutes<<":"<<T.seconds;
            return output;
        }

        int getTotalSeconds(){
            return (hours*3600) + (minutes*60) + seconds;
        }
};

int main(void){
    Time t;
    cin>>t;
    cout<<"Time entered: "<<t<<endl;
    cout<<"Total seconds: "<<t.getTotalSeconds()<<endl;
}
