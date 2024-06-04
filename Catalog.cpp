#include "Catalog.h"

void Catalog::addBook(string Title, string author, int isbn, string dataPublished, string genre, string language, string subject, int id){
    Book newBook(Title, author, isbn, dataPublished, "", genre, language, subject, false);
    catalog.push_back(newBook);
    cout << catalog.at(0).getTitle() << endl;;
}

void Catalog::removeBook(int id){
    for(unsigned i = 0; i < catalog.size(); i++){
        if(catalog.at(i).getISBN() == id){
            catalog.erase(catalog.begin() + i);
            cout << id << endl;
            return;
        }
    }
}