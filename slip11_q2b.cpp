// Create a base class Conversion. Derive three different classes Weight (Gram, Kilogram),
// Volume (Milliliter, Liter), Currency (Rupees, Paise) from Conversion class. Write a program
// to perform read, convert and display operations. (Use Pure virtual function) 
#include <iostream>
#include <string>

using namespace std;

class Conversion {
    protected:
        double value;

    public:
        virtual void read() = 0;
        virtual double convert() = 0;
        virtual void display() = 0;
};

class Weight : public Conversion {
    private:
        string unit;

    public:
        void read() {
            cout << "Enter weight value: ";
            cin >> value;
            cout << "Enter weight unit (g/kg): ";
            cin >> unit;
        }

        double convert() {
            if (unit == "g") {
                return value / 1000.0;
            } else {
                return value;
            }
        }

        void display() {
            cout << "Weight: " << convert() << " kg" << endl;
        }
};

class Volume : public Conversion {
    private:
        string unit;

    public:
        void read() {
            cout << "Enter volume value: ";
            cin >> value;
            cout << "Enter volume unit (ml/l): ";
            cin >> unit;
        }

        double convert() {
            if (unit == "ml") {
                return value / 1000.0;
            } else {
                return value;
            }
        }

        void display() {
            cout << "Volume: " << convert() << " L" << endl;
        }
};

class Currency : public Conversion {
    private:
        string unit;

    public:
        void read() {
            cout << "Enter currency value: ";
            cin >> value;
            cout << "Enter currency unit (INR/PAISE): ";
            cin >> unit;
        }

        double convert() {
            if (unit == "PAISE") {
                return value / 100.0;
            } else {
                return value;
            }
        }

        void display() {
            cout << "Currency: " << convert() << " INR" << endl;
        }
};

int main() {
    Conversion* conv;
    int choice;

    do {
        cout << "\n1. Convert weight\n2. Convert volume\n3. Convert currency\n0. Exit\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                conv = new Weight();
                conv->read();
                conv->display();
                break;
            }

            case 2: {
                conv = new Volume();
                conv->read();
                conv->display();
                break;
            }

            case 3: {
                conv = new Currency();
                conv->read();
                conv->display();
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

        delete conv;
    } while (choice != 0);

    return 0;
}
