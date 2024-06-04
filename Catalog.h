#pragma once
#include "book.h"
#include <vector>
using namespace std;

class Catalog{
    vector<Book> catalog;
    public:
        Catalog();
        void sortbyAuthor();
        void sortbyISBN();
        void sortbyTitle();
        void sortbyLang();
        void sortbySubj();
        void sortbyGenre();
        void sortbyDate();
        vector<Book>* vectorPointer(){return &catalog;};


        //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////
        //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////
        //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////   //testing only//////
        void populatecatalog();
};
