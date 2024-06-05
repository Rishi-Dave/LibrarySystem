#pragma once

#include "Book.h"


class Catalog {
    private:
        vector<Book> catalog;
    public:
        void readBooksFromFile(const string& filename);
        void removeBook(int id);
        void addBook(string Title, string author, int isbn, string dataPublished, string genre, string language, string subject, int id);
        Book* findBook(int id);
        void testPrint();
        Catalog();
        void sortbyAuthor();
        void sortbyISBN();
        void sortbyTitle();
        void sortbyLang();
        void sortbySubj();
        void sortbyGenre();
        void sortbyDate();
        vector<Book>* vectorPointer(){return &catalog;};

        void store(const std::string& filename);
        //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////
        //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////
        //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////
        void populatecatalog();
};
