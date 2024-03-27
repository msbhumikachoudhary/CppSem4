// A book (ISBN) and CD (data capacity) are both types of media (id, title) objects. A person buys
// 10 media items each of which can be either book or CD. Display the list of all books and CD’s
// bought. Define the classes and appropriate member functions to accept and display data. Use
// pointers and concept of polymorphism (Virtual Function) 
#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    int id;
    string title;

public:
    Media(int id, string title) {
        this->id = id;
        this->title = title;
    }

    virtual void display() = 0;
};

class Book : public Media {
private:
    string isbn;

public:
    Book(int id, string title, string isbn) : Media(id, title) {
        this->isbn = isbn;
    }

    void display() {
        cout << "Book ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "ISBN: " << isbn << endl;
    }
};

class CD : public Media {
private:
    double data_capacity;

public:
    CD(int id, string title, double data_capacity) : Media(id, title) {
        this->data_capacity = data_capacity;
    }

    void display() {
        cout << "CD ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Data Capacity: " << data_capacity << endl;
    }
};

int main(void) {
    Media *mediaList[3];

    for (int i = 0; i < 3; i++) {
        int id;
        string title;
        int choice;

        cout << "Enter the ID for media item #" << i+1 << ": ";
        cin >> id;
        cout << "Enter the title for media item #" << i+1 << ": ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter the type of media item (1 for Book, 2 for CD): ";
        cin >> choice;

        if (choice == 1) {
            string isbn;
            cout << "Enter the ISBN for the book: ";
            cin >> isbn;

            mediaList[i] = new Book(id, title, isbn);
        } else {
            double data_capacity;
            cout << "Enter the data capacity for the CD: ";
            cin >> data_capacity;

            mediaList[i] = new CD(id, title, data_capacity);
        }
    }

    cout << endl << "List of Books:" << endl;
    for (int i = 0; i < 3; i++) {
        if (dynamic_cast<Book*>(mediaList[i])) {
            mediaList[i]->display();
        }
    }

    cout << endl << "List of CDs:" << endl;
    for (int i = 0; i < 3; i++) {
        if (dynamic_cast<CD*>(mediaList[i])) {
            mediaList[i]->display();
        }
    }
}


#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // filestream variables
    fstream f1;
    fstream f2;

    string inputFile, outputFile, ch;

    // prompt the user to enter the file path for input file
    cout << "Enter the file path for input file: ";
    getline(cin, inputFile);

    // prompt the user to enter the file path for output file
    cout << "Enter the file path for output file: ";
    getline(cin, outputFile);

    // opening first file to read the content
    f1.open(inputFile, ios::in);

    // opening second file to write the content copied from first file
    f2.open(outputFile, ios::out);

    if (!f1.is_open()) {
        cout << "Error opening input file!";
        return 0;
    }

    if (!f2.is_open()) {
        cout << "Error opening output file!";
        return 0;
    }

    while (getline(f1, ch)) {
        // writing content to second file line by line
        f2 << ch << endl;
    }

    // closing the files
    f1.close();
    f2.close();

    // opening second file to read the content
    f2.open(outputFile, ios::in);

    if (!f2.is_open()) {
        cout << "Error opening output file for reading!";
        return 0;
    }

    while (getline(f2, ch)) {
        // displaying content
        cout << ch << endl;
    }

    // closing file
    f2.close();

    return 0;
}
