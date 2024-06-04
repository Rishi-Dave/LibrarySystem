#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include "Book.h"

class Catalog {
private:
    std::vector<Book> library;

public:
    // sort the catalog
    void sortbyAuthor();
    void sortbyISBN();
    void sortbyTitle();
    void sortbyLang();
    void sortbySubj();
    void sortbyGenre();
    void sortbyDate();

    void displayCatalog() const;

    // read books from a file
    void readBooksFromFile(const std::string& filename);

    
    // search for books
    Book* searchByTitle(const std::string &title);
    Book* searchByISBN(int isbn);
    void addBook(const Book &book);

    void printCatalog() const;
};

#endif
