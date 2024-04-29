#ifndef CATALOG_H
#define CATALOG_H

#include "Book.h"
#include <vector>

class Catalog {
public:
    void addBook(const Book& book);
    bool deleteBook(const string& isbn);

    bool checkoutBook(const string& isbn);
    bool returnBook(const string& isbn);


    <Book*> findBooksByTitle(const string& title);
    vector<Book*> findBooksByAuthor(const string& author);
    vector<Book*> findBooksByISBN(const string& isbn);



private:
    vector<Book> Totalbooklib;
};

#endif // CATALOG_H