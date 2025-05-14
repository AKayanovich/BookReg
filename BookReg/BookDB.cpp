#include "BookDB.h"
#include <cstring>

namespace bookregistry {
    BookDB::BookDB(int amount) : bookCount(amount) {
        books = new Book[amount];
    }

    BookDB::~BookDB() {
        delete[] books;
    }

    void BookDB::addBook(const std::string& title, const std::string& author, const std::string& genre, int quantity) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title && books[i].getAuthor() == author) {
                for (int j = 0; j < quantity; j++) {
                    books[i].addBook();
                }
                return;
            }
        }

        Book* newBooks = new Book[bookCount + 1];

        for (int i = 0; i < bookCount; i++) {
            newBooks[i] = books[i];
        }

        newBooks[bookCount] = Book(title, author, genre, quantity);

        delete[] books;
        books = newBooks;
        bookCount++;
    }

    Book* BookDB::findBookByTitle(const std::string& title, int& count) {
        count = 0;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title) {
                count++;
            }
        }

        if (count == 0) {
            return nullptr;
        }

        Book* titleBooks = new Book[count];
        int index = 0;

        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title) {
                titleBooks[index++] = books[i];
            }
        }

        return titleBooks;
    }

    Book* BookDB::findBooksByAuthor(const std::string& author, int& count) {
        count = 0;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getAuthor() == author) {
                count++;
            }
        }

        if (count == 0) {
            return nullptr;
        }

        Book* authorBooks = new Book[count];
        int index = 0;

        for (int i = 0; i < bookCount; i++) {
            if (books[i].getAuthor() == author) {
                authorBooks[index++] = books[i];
            }
        }

        return authorBooks;
    }

    void BookDB::orderBook(const std::string& title) {
        int count = 0;
        Book* titleBooks = findBookByTitle(title, count);
        if (titleBooks != nullptr) {
            for (int i = 0; i < count; i++) {
                if (titleBooks[i].getQuantity() > 0) {
                    for (int j = 0; j < bookCount; j++) {
                        if (books[j].getTitle() == title && books[j].getAuthor() == titleBooks[i].getAuthor()) {
                            books[j].orderBook();
                            delete[] titleBooks;
                            return;
                        }
                    }
                }
            }
            delete[] titleBooks;
            throw "Book out of stock";
        }
        else {
            throw "Book not found";
        }
    }

    void BookDB::displayAll() const {
        for (int i = 0; i < bookCount; i++) {
            std::cout << books[i];
        }
    }

    int BookDB::getBookCount() const {
        return bookCount;
    }

    Book* BookDB::getBooks() const {
        return books;
    }
}