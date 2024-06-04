#include "Catalog.h"

void Catalog::addBook(string Title, string author, int isbn, string dataPublished, string genre, string language, string subject, int id){
    Book newBook(Title, author, isbn, dataPublished, "", genre, language, subject, false);
    catalog.push_back(newBook);
}

void Catalog::removeBook(int id){
    for(unsigned i = 0; i < catalog.size(); i++){
        if(catalog.at(i).getISBN() == id){ //change to get ID
            catalog.erase(catalog.begin() + i);
            return;
        }
    }
}

Book* Catalog::findBook(int id){
    for(unsigned i = 0; i < catalog.size(); i++){
        if(catalog.at(i).getISBN() == id){ //change to  get ID
            return &catalog.at(i);
        }
    }
    return nullptr;
}

void Catalog::readBooksFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Unable to open file " << filename << endl;
        return;
    }

    string line;

    while (getline(file, line)) {

        istringstream INFS(line);
        string title, author, genre, language, subject;
        int year, isbn, id;
        
        INFS >> quoted(title) >> quoted(author) >> quoted(genre) >> quoted(language) 
            >> quoted(subject) >> year >> isbn >> id;
        
        Book book(title, author, genre, language, subject, year, isbn, id);

        addBook(book);
    }

    file.close();
}

void Catalog::testPrint(){
    for(unsigned i = 0; i < catalog.size(); i++){
        cout << catalog.at(i).getTitle() << endl;
    }
}
