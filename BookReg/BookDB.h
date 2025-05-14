#pragma once
#ifndef BOOK_DATABASE_H
#define BOOK_DATABASE_H

#include "Book.h"

namespace bookregistry {
    class BookDB {
    private:
        Book* books;
        int bookCount;

    public:
        BookDB(int amount = 10);
        ~BookDB();

        void addBook(const std::string& title, const std::string& author, const std::string& genre, int quantity = 1);
        Book* findBookByTitle(const std::string& title, int& count);
        Book* findBooksByAuthor(const std::string& author, int& count);
        void orderBook(const std::string& title);
        void displayAll() const;

        int getBookCount() const;
        Book* getBooks() const;
    };
}

#endif