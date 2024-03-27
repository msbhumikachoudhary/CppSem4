// Write a C++ program to create a class Person that contains data members as Person_Name, City,
// Mob_No. Write a C++ program to perform following functions:
// a. To accept and display Person information
// b. To search the Person details of a given mobile number
// c. To search the Person details of a given city.
// (Use Function Overloading)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
    private:
        string Person_Name;
        string City;
        string Mob_No;

    public:
        Person() {}
        Person(string name, string city, string mob) {
            Person_Name = name;
            City = city;
            Mob_No = mob;
        }

        void accept_info() {
            cout << "Enter Person name: ";
            cin >> Person_Name;
            cout << "Enter City: ";
            cin >> City;
            cout << "Enter Mobile number: ";
            cin >> Mob_No;
        }

        void display_info() {
            cout << "Name: " << Person_Name << endl;
            cout << "City: " << City << endl;
            cout << "Mobile number: " << Mob_No << endl;
        }

        bool search_by_mobile(string mob) {
            return Mob_No == mob;
        }

        bool search_by_city(string city) {
            return City == city;
        }
};

int main() {
    vector<Person> people;
    int choice;

    do {
        cout << "\n1. Add Person information\n2. Display all Person information\n3. Search by mobile number\n4. Search by city\n0. Exit\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Person p;
                p.accept_info();
                people.push_back(p);
                break;
            }

            case 2: {
                if (people.empty()) {
                    cout << "No Person information available." << endl;
                    break;
                }

                for (int i = 0; i < people.size(); i++) {
                    people[i].display_info();
                    cout << endl;
                }
                break;
            }

            case 3: {
                if (people.empty()) {
                    cout << "No Person information available." << endl;
                    break;
                }

                string mob;
                cout << "Enter the mobile number to search: ";
                cin >> mob;

                bool found = false;
                for (int i = 0; i < people.size(); i++) {
                    if (people[i].search_by_mobile(mob)) {
                        people[i].display_info();
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Person with the given mobile number not found." << endl;
                }

                break;
            }

            case 4: {
                if (people.empty()) {
                    cout << "No Person information available." << endl;
                    break;
                }

                string city;
                cout << "Enter the city to search: ";
                cin >> city;

                bool found = false;
                for (int i = 0; i < people.size(); i++) {
                    if (people[i].search_by_city(city)) {
                        people[i].display_info();
                        found = true;
                    }
                }

                if (!found) {
                    cout << "No Person from the given city found." << endl;
                }

                break;
            }

            case 0: {
                cout << "Exiting program." << endl;
                break;
            }

            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}
