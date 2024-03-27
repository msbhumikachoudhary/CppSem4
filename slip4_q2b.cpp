// Create a base class Flight containing protected data members as Flight_no, Flight_Name. Derive
// a class Route(Source, Destination) from class Flight. Also derive a class Reservation (no_seats,
// class, fare, travel_date) from Route. Write a C++ program to perform the following necessary
// functions.
// a. Enter details of n reservations.
// b. Display reservation details of Business class.
#include <iostream>
#include <string>

using namespace std;

class Flight {
protected:
    int Flight_no;
    string Flight_Name;
};

class Route : public Flight {
public:
    string Source, Destination;
};

class Reservation : public Route {
public:
    int no_seats;
    string Class;
    float fare;
    string travel_date;
};

int main(void) {
    int n;
    cout << "Enter the number of reservations: ";
    cin >> n;

    Reservation* reservations = new Reservation[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of reservation " << i + 1 << endl;
        cout << "Flight number: ";
        cin >> reservations[i].Flight_no;

        cout << "Flight name: ";
        cin >> reservations[i].Flight_Name;

        cout << "Source: ";
        cin >> reservations[i].Source;

        cout << "Destination: ";
        cin >> reservations[i].Destination;

        cout << "Number of seats: ";
        cin >> reservations[i].no_seats;

        cout << "Class: ";
        cin >> reservations[i].Class;

        cout << "Fare: ";
        cin >> reservations[i].fare;

        cout << "Travel date: ";
        cin >> reservations[i].travel_date;
    }

    cout << "\nReservation details of Business class:\n";
    for (int i = 0; i < n; i++) {
        if (reservations[i].Class == "Business") {
            cout << "Flight number: " << reservations[i].Flight_no << endl;
            cout << "Flight name: " << reservations[i].Flight_Name << endl;
            cout << "Source: " << reservations[i].Source << endl;
            cout << "Destination: " << reservations[i].Destination << endl;
            cout << "Number of seats: " << reservations[i].no_seats << endl;
            cout << "Class: " << reservations[i].Class << endl;
            cout << "Fare: " << reservations[i].fare << endl;
            cout << "Travel date: " << reservations[i].travel_date << endl;
            cout << endl;
        }
    }
    delete[] reservations;
}
