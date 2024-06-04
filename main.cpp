#include "Catalog.h"
#include "CatalogDisplay.h"


int main(){
    Catalog cat;
    CatalogDisplay printer;
   // printer.print(cat);
   cat.store("Catalog.txt");
    cat.sortbyAuthor();
    cat.store("Catalog.txt");
}