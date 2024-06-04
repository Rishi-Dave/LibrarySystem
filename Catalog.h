#ifndef CATALOG_H
#define CATALOG_H


#include "book.h"

#include <iostream>
#include <vector>

using namespace std;

class Catalog {
    private:
        vector<Book> catalog;
    public:
        void removeBook(int id);
        void addBook(string Title, string author, int isbn, string dataPublished, string genre, string language, string subject, int id);
        Book* findBook(int id);
        void testPrint();
};

#endif