#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

namespace bookregistry {
    class Book {
    private:
        std::string title;
        std::string author;
        std::string genre;
        int quantity;

        static std::string generateTitle();
        static std::string generateAuthor();
        static std::string generateGenre();
        static int generateQuantity();

    public:
        Book();
        Book(const std::string& title, const std::string& author, const std::string& genre, int quantity);

        friend std::ostream& operator<<(std::ostream& os, const Book& book);

        const std::string& getTitle() const;
        const std::string& getAuthor() const;
        const std::string& getGenre() const;
        int getQuantity() const;

        void orderBook();
        void addBook();
    };
}

#endif