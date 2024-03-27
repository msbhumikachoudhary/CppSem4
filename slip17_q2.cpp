// Create a base class Media. Derive two different classes Book (Book_id, Book_name,
// Publication, Author, Book_price) and CD (CD_title, CD_price) from Media. Write a program
// to accept and display information of both Book and CD. (Use pure virtual function) 
#include <iostream>
#include <string>

using namespace std;

class Media {
public:
    virtual void accept() = 0;
    virtual void display() = 0;
};

class Book : public Media {
private:
    int book_id;
    string book_name;
    string publication;
    string author;
    double book_price;
public:
    void accept() {
        cout << "Enter Book ID: ";
        cin >> book_id;
        cout << "Enter Book Name: ";
        cin >> book_name;
        cout << "Enter Publication: ";
        cin >> publication;
        cout << "Enter Author: ";
        cin >> author;
        cout << "Enter Book Price: ";
        cin >> book_price;
    }
    void display() {
        cout << "Book ID: " << book_id << endl;
        cout << "Book Name: " << book_name << endl;
        cout << "Publication: " << publication << endl;
        cout << "Author: " << author << endl;
        cout << "Book Price: " << book_price << endl;
    }
};

class CD : public Media {
private:
    string cd_title;
    double cd_price;
public:
    void accept() {
        cout << "Enter CD Title: ";
        cin >> cd_title;
        cout << "Enter CD Price: ";
        cin >> cd_price;
    }
    void display() {
        cout << "CD Title: " << cd_title << endl;
        cout << "CD Price: " << cd_price << endl;
    }
};

int main() {
    Media *m[2];
    m[0] = new Book();
    m[1] = new CD();
    for (int i = 0; i < 2; i++) {
        m[i]->accept();
        m[i]->display();
    }
    return 0;
}
