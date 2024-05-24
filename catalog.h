#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include "Book.h"

class Catalog {
private:
    std::vector<Book> library;

public:
    // Methods to sort the catalog
    void sortbyAuthor();
    void sortbyISBN();
    void sortbyTitle();
    void sortbyLang();
    void sortbySubj();
    void sortbyGenre();
    void sortbyDate();

    // Methods to search for books
    Book* searchByTitle(const std::string &title);
    Book* searchByISBN(int isbn);
    void addBook(const Book &book);

    // Method to print the catalog
    void printCatalog() const;
};

#endif 