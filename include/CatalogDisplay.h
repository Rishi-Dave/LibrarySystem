#pragma once

#include "Catalog.h"
#include "ParentDisplay.h"

class CatalogDisplay : private ParentDisplay{
    public:
        void printbyAuthor(Catalog cat);
        void printbyISBN(Catalog cat);
        void printbyTitle(Catalog cat);
        void printbyLang(Catalog cat);
        void printbySubj(Catalog cat);
        void printbyGenre(Catalog cat);
        void printbyDate(Catalog cat);
        void print(Catalog cat);
        void viewCatalog(Catalog* catalog);

};