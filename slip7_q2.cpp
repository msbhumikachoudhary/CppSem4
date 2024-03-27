// Create a class College containing data members as College_Id, College_Name,
// Establishment_year, University_Name. Write a C++ program with following functions
// a. Accept n College details
// b. Display College details of specified University
// c. Display College details according to Establishment year (Use Array of Objects and
// Function Overloading).
#include <iostream>
#include <string>

using namespace std;

class College {
public:
    int Coll_id;
    string Coll_Name;
    int Est_year;
    string Uni_Name;
};

void acc_Det(College colleges[], int n) {
    for(int i=0; i<n; i++) {
        cout << "Enter details for college " << i+1 << ":" << endl;
        cout << "College Id: ";
        cin >> colleges[i].Coll_id;
        cout << "College Name: ";
        cin >> colleges[i].Coll_Name;
        cout << "Establishment Year: ";
        cin >> colleges[i].Est_year;
        cout << "University Name: ";
        cin >> colleges[i].Uni_Name;
    }
}

void displayByUniversity(College colleges[], int n, string universityName) {
    for(int i=0; i<n; i++) {
        if(colleges[i].Uni_Name == universityName) {
            cout << "College Id: " << colleges[i].Coll_id << endl;
            cout << "College Name: " << colleges[i].Coll_Name << endl;
            cout << "Establishment Year: " << colleges[i].Est_year << endl;
            cout << "University Name: " << colleges[i].Uni_Name << endl << endl;
        }
    }
}

void displayByEstYear(College colleges[], int n, int year) {
    for(int i=0; i<n; i++) {
        if(colleges[i].Est_year == year) {
            cout << "College Id: " << colleges[i].Coll_id << endl;
            cout << "College Name: " << colleges[i].Coll_Name << endl;
            cout << "Establishment Year: " << colleges[i].Est_year << endl;
            cout << "University Name: " << colleges[i].Uni_Name << endl << endl;
        }
    }
}

int main() {
    int n,year;
    cout << "Enter the number of colleges: ";
    cin >> n;
    College colleges[n];
    acc_Det(colleges, n);

    string universityName;
    cout << "Enter the name of the university to display college details: ";
    cin >> universityName;
    displayByUniversity(colleges, n, universityName);

    cout << "Enter the establishment year to display college details: ";
    cin >> year;
    displayByEstYear(colleges, n, year);
}
