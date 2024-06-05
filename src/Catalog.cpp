#include "../include/Catalog.h"

   //testing only//////   //testing only//////   //testing only//////
    //testing only//////   //testing only//////   //testing only//////
void Catalog::populatecatalog(){
    
}


Catalog::Catalog(){
    populatecatalog();
};

void Catalog::sortbyAuthor() {
    for (unsigned i = 0; i < catalog.size() - 1; ++i) {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < catalog.size(); ++j) {
            if (catalog[j].getAuthor() < catalog[minIndex].getAuthor()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(catalog[i], catalog[minIndex]);
        }
    }
}

void Catalog::sortbyISBN() {
    for (unsigned i = 0; i < catalog.size() - 1; ++i) {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < catalog.size(); ++j) {
            if (catalog[j].getISBN() < catalog[minIndex].getISBN()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(catalog[i], catalog[minIndex]);
        }
    }
}

void Catalog::sortbyTitle() {
    for (unsigned i = 0; i < catalog.size() - 1; ++i) {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < catalog.size(); ++j) {
            if (catalog[j].getTitle() < catalog[minIndex].getTitle()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(catalog[i], catalog[minIndex]);
        }
    }
}

void Catalog::sortbyLang() {
    for (unsigned i = 0; i < catalog.size() - 1; ++i) {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < catalog.size(); ++j) {
            if (catalog[j].getLanguage() < catalog[minIndex].getLanguage()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(catalog[i], catalog[minIndex]);
        }
    }
}

void Catalog::sortbySubj() {
    for (unsigned i = 0; i < catalog.size() - 1; ++i) {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < catalog.size(); ++j) {
            if (catalog[j].getSubject() < catalog[minIndex].getSubject()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(catalog[i], catalog[minIndex]);
        }
    }
}

void Catalog::sortbyGenre() {
    for (unsigned i = 0; i < catalog.size() - 1; ++i) {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < catalog.size(); ++j) {
            if (catalog[j].getGenre() < catalog[minIndex].getGenre()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(catalog[i], catalog[minIndex]);
        }
    }
}

void Catalog::sortbyDate() {
    for (unsigned i = 0; i < catalog.size() - 1; ++i) {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < catalog.size(); ++j) {
            if (catalog[j].getDate() < catalog[minIndex].getDate()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(catalog[i], catalog[minIndex]);
        }
    }
}


void Catalog::store(const std::string& filename) {
  std::ofstream outputFile(filename);

  if (outputFile.is_open()) {
    for (unsigned i = 0; i < catalog.size(); i++) {
      catalog.at(i).write(outputFile);
    }
    outputFile.close();
    std::cout << "Catalog information written to file: " << filename << std::endl;
  } else {
    std::cout << "Error opening file: " << filename << std::endl;
  }
}


void Catalog::addBook(string Title, string author, int isbn, string dataPublished, string genre, string language, string subject, int id){
    Book newBook(Title, author, isbn, dataPublished, "", genre, language, subject, false, id);
    catalog.push_back(newBook);
}

void Catalog::removeBook(int id){
    for(unsigned i = 0; i < catalog.size(); i++){
        if(catalog.at(i).getID() == id){ //change to get ID
            catalog.erase(catalog.begin() + i);
            return;
        }
    }
}

Book* Catalog::findBook(int id){
    for(unsigned i = 0; i < catalog.size(); i++){
        if(catalog.at(i).getID() == id){ //change to  get ID
            return &catalog.at(i);
        }
    }
    return nullptr;
}
/*
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
*/
void Catalog::testPrint(){
    for(unsigned i = 0; i < catalog.size(); i++){
        cout << catalog.at(i).getTitle() << endl;
    }
}
