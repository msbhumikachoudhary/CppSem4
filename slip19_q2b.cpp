// Write a C++ program to create a text file which stores employee information as emp_id,
// emp_name, emp_sal). Write a menu driven program with the options
// a. Append
// b. Modify
// c. Display
// d. Exit
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee {
    int emp_id;
    string emp_name;
    double emp_sal;
};

void appendToFile() {
    Employee emp;
    ofstream outfile("employee.txt", ios::app);

    cout << "Enter employee ID: ";
    cin >> emp.emp_id;
    cout << "Enter employee name: ";
    cin.ignore();
    getline(cin, emp.emp_name);
    cout << "Enter employee salary: ";
    cin >> emp.emp_sal;

    outfile << emp.emp_id << " " << emp.emp_name << " " << emp.emp_sal << endl;
    outfile.close();
    cout << "Employee record appended to file successfully." << endl;
}

void modifyFile() {
    int emp_id;
    bool found = false;
    Employee emp;
    fstream file("employee.txt", ios::in | ios::out);

    cout << "Enter employee ID to modify: ";
    cin >> emp_id;

    while (file >> emp.emp_id >> emp.emp_name >> emp.emp_sal) {
        if (emp.emp_id == emp_id) {
            cout << "Enter new employee name: ";
            cin.ignore();
            getline(cin, emp.emp_name);
            cout << "Enter new employee salary: ";
            cin >> emp.emp_sal;

            file.seekp(-1 * sizeof(emp), ios::cur);
            file << emp.emp_id << " " << emp.emp_name << " " << emp.emp_sal;
            found = true;
            break;
        }
    }
    file.close();

    if (found) {
        cout << "Employee record modified successfully." << endl;
    } else {
        cout << "Employee record not found." << endl;
    }
}

void displayFile() {
    Employee emp;
    ifstream infile("employee.txt");

    cout << "Employee ID\tEmployee Name\tEmployee Salary" << endl;
    while (infile >> emp.emp_id >> emp.emp_name >> emp.emp_sal) {
        cout << emp.emp_id << "\t\t" << emp.emp_name << "\t\t" << emp.emp_sal << endl;
    }
    infile.close();
}

int main(void) {
    char choice;

    do {
        cout << "Choose an option:" << endl;
        cout << "a. Append" << endl;
        cout << "b. Modify" << endl;
        cout << "c. Display" << endl;
        cout << "d. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 'a':
                appendToFile();
                break;
            case 'b':
                modifyFile();
                break;
            case 'c':
                displayFile();
                break;
            case 'd':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 'd');
}
