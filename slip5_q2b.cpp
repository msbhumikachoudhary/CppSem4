// Create a class Book containing Book_name, author and Price as a data member and write
// necessary member functions for the following (use function overloading).
// a. To Accept and display the Book Information.
// b. Display book details of a given author
// c. Display book details of specific price
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string book_name;
    string author;
    double price;

public:
    // Constructor
    Book(string book_name, string author, double price) {
        this->book_name = book_name;
        this->author = author;
        this->price = price;
    }

    // Function to display book information
    void display_book_info() {
        cout << "Book name: " << book_name << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }

    // Function to display books by a given author
    void display_books_by_author(string author_name) {
        if (author == author_name) {
            display_book_info();
        }
    }

    // Function to display books of a specific price
    void display_books_by_price(double price) {
        if (this->price == price) {
            display_book_info();
        }
    }
};
int main(void) {
    Book book1("Power of Subconscious Mind", "Joseph Murphy", 10.99);
    Book book2("Rich Dad Poor Dad", "Robert Kiyoski", 8.99);
    Book book3("A New Earth", "Eckhart Tolle", 12.99);
    book1.display_book_info();
    book2.display_books_by_author("Robert Kiyoski");
    book3.display_books_by_price(12.99);
}
