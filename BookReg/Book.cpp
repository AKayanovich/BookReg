#include "Book.h"
#include <ctime>

namespace bookregistry {
    Book::Book() :
        title(generateTitle()),
        author(generateAuthor()),
        genre(generateGenre()),
        quantity(generateQuantity())
    {}

    Book::Book(const std::string& title, const std::string& author, const std::string& genre, int quantity) :
        title(title),
        author(author),
        genre(genre),
        quantity(quantity)
    {}

    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "Name: " << book.title << "\n"
            << "Author: " << book.author << "\n"
            << "Genre: " << book.genre << "\n"
            << "Amount: " << book.quantity << "\n\n";
        return os;
    }

    const std::string& Book::getTitle() const {
        return title;
    }

    const std::string& Book::getAuthor() const {
        return author;
    }

    const std::string& Book::getGenre() const {
        return genre;
    }

    int Book::getQuantity() const {
        return quantity;
    }

    void Book::orderBook() {
        if (quantity > 0) {
            quantity--;
        }
        else {
            throw "Book out of stock";
        }
    }

    void Book::addBook() {
        quantity++;
    }

    std::string Book::generateTitle() {
        static int counter = 0;
        counter++;

        std::string firstParts[] = { "Lord", "Color", "Mystery", "Secret", "War", "Code", "Chronicles" };
        std::string secondParts[] = { "Rings", "Magic", "Hole", "Castle", "Worlds", "Access", "Narnia" };

        std::string harryPotterSecondParts[] = { "Philosopher's Stone", "Chamber of Secrets", "Thesis Defense",
                                              "Goblet of Fire", "Order of the Phoenix", "Half-Blood Prince", "Deathly Hallows" };

        if (counter % 2 == 0) {
            return firstParts[rand() % 7] + " " + secondParts[rand() % 7];
        }
        else {
            return "Harry Potter and " + harryPotterSecondParts[rand() % 7];
        }
    }

    std::string Book::generateAuthor() {
        std::string firstInitials[] = { "A.", "B.", "V.", "G.", "D.", "E.", "J." };
        std::string secondInitials[] = { "A.", "B.", "V.", "G.", "D.", "K.", "R." };
        std::string lastNames[] = { "Pushkin", "Tolstoy", "Dostoevsky", "Bulgakov", "Rowling", "King", "Martin" };

        std::string author = firstInitials[rand() % 7] + " " + secondInitials[rand() % 7] + " " + lastNames[rand() % 7];

        return author;
    }

    std::string Book::generateGenre() {
        std::string genres[] = { "Fantasy", "Detective", "Novel", "Science Fiction", "Thriller", "Comedy", "Drama" };
        return genres[rand() % 7];
    }

    int Book::generateQuantity() {
        return rand() % 10 + 1;
    }
}