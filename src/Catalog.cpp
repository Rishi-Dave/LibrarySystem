#include "../include/Catalog.h"
#include <algorithm>

Catalog::Catalog(){
    readBooksFromFile("storage/Catalog.txt");
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


void Catalog::store() {
  std::ofstream outputFile("storage/Catalog.txt");

  if (outputFile.is_open()) {
    for (unsigned i = 0; i < catalog.size(); i++) {
      catalog.at(i).write(outputFile);
    }
    outputFile.close();
  } else {
    std::cout << "Error opening file: " << std::endl;
  }
}


void Catalog::addBook(string Title, string author, int isbn, string dataPublished, string genre, string language, string subject, int id){
    Book newBook(Title, author, isbn, dataPublished, genre, language, subject, false, id);
    catalog.push_back(newBook);
}

void Catalog::removeBook(int id){
    for(unsigned i = 0; i < catalog.size(); i++){
        if(catalog.at(i).getID() == id){ 
            catalog.erase(catalog.begin() + i);
            return;
        }
    }
}

Book* Catalog::findBook(int id){
    for(unsigned i = 0; i < catalog.size(); i++){
        if(catalog.at(i).getID() == id){ 
            return &catalog.at(i);
        }
    }
    return nullptr;
}

Book* Catalog::findBook(string title){
    for(unsigned i = 0; i < catalog.size(); i++){
        if(catalog.at(i).getTitle() == title){ 
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

        istringstream ss(line);
        string title, author, genre, language, subject, year, isbn, id;
        
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, genre, '|');
        getline(ss, language, '|');
        getline(ss, subject, '|');
        getline(ss, year, '|');
        getline(ss, isbn, '|');
        if (isbn.empty() || !all_of(isbn.begin(), isbn.end(), ::isdigit)) {
            continue;
        }
        //int intIsbn = std::stoi(isbn);
        getline(ss, id, '|');
        int intId = std::stoi(id);
        int intIsbn = std::stoi(isbn);
        addBook(title, author, intIsbn, year, genre, language, subject, intId);
    }

    file.close();
}

