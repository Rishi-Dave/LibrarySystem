#include "CatalogDisplay.h"
#include "BookDisplay.h"

void CatalogDisplay::print(Catalog cat){
    BookDisplay printer;
    vector<Book> vect = *(cat.vectorPointer());
    for(unsigned i; i<vect.size();i++){
        printer.printBook(vect.at(i));
    }
}

void CatalogDisplay::printbyAuthor(Catalog cat){
    cat.sortbyAuthor();
    print(cat);
}

void CatalogDisplay::printbyTitle(Catalog cat){
    cat.sortbyTitle();
    print(cat);
}

void CatalogDisplay::printbyLang(Catalog cat){
    cat.sortbyLang();
    print(cat);
}

void CatalogDisplay::printbySubj(Catalog cat){
    cat.sortbySubj();
    print(cat);
}

void CatalogDisplay::printbyGenre(Catalog cat){
    cat.sortbyGenre();
    print(cat);
}

void CatalogDisplay::printbyDate(Catalog cat){
    cat.sortbyDate();
    print(cat);
}