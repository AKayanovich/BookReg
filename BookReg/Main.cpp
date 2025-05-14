#include <iostream>
#include <ctime>
#include <clocale>
#include <string>
#include "BookDB.h"

using namespace bookregistry;
using namespace std;

void displayMenu() {
    cout << "===== Book Registry =====\n";
    cout << "1. Show all books\n";
    cout << "2. Search book by title\n";
    cout << "3. Search books by author\n";
    cout << "4. Order book\n";
    cout << "5. Add book\n";
    cout << "6. Exit\n";
    cout << "Choose an action: ";
}

int main() {
    setlocale(LC_ALL, "English");
    srand((time(NULL)));

    BookDB database(15);

    database.addBook("Harry Potter and the Philosopher's Stone", "J.K. Rowling", "Fantasy", 3);
    database.addBook("Harry Potter and the Chamber of Secrets", "J.K. Rowling", "Fantasy", 2);
    database.addBook("Harry Potter and the Deathly Hallows", "J.K. Rowling", "Fantasy", 5);

    int choice;
    string title, author, genre;
    int quantity;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "\n===== All books in registry =====\n";
            database.displayAll();
            break;

        case 2: {
            cout << "Enter book title: ";
            getline(cin, title);

            int count = 0;
            Book* book = database.findBookByTitle(title, count);
            if (book) {
                cout << "\n===== Found book =====\n";
                cout << *book;
            }
            else {
                cout << "Book not found\n";
            }
            break;
        }

        case 3: {
            cout << "Enter author: ";
            getline(cin, author);

            int count = 0;
            Book* authorBooks = database.findBooksByAuthor(author, count);

            if (authorBooks) {
                cout << "\n===== Books by " << author << " =====\n";
                for (int i = 0; i < count; i++) {
                    cout << authorBooks[i];
                }
                delete[] authorBooks;
            }
            else {
                cout << "No books by this author found\n";
            }
            break;
        }

        case 4: {
            cout << "Enter book title to order: ";
            getline(cin, title);

            try {
                database.orderBook(title);
                cout << "Book \"" << title << "\" successfully ordered\n";
            }
            catch (const char* error) {
                cout << "Error: " << error << "\n";
            }
            break;
        }

        case 5: {
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter genre: ";
            getline(cin, genre);
            cout << "Enter quantity: ";
            cin >> quantity;
            cin.ignore();

            database.addBook(title, author, genre, quantity);
            cout << "Book successfully added to registry\n";
            break;
        }

        case 6:
            cout << "Exiting program\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

        cout << "\n";
    } while (choice != 6);

    return 0;
}