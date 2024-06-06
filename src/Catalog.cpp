#include "../include/Catalog.h"
#include <algorithm>
   //testing only//////   //testing only//////   //testing only//////
    //testing only//////   //testing only//////   //testing only//////
void Catalog::populatecatalog(){
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 9780743273565, "1925", "Fiction", "English", "20th Century Literature", false, 1);
    Book book2("To Kill a Mockingbird", "Harper Lee", 9780061120084, "1960", "Fiction", "English", "Civil Rights", false, 2);
    Book book3("1984", "George Orwell", 9780451524935, "1949", "Dystopian", "English", "Political Fiction", false, 3);
    Book book4("Pride and Prejudice", "Jane Austen", 9781503290563, "1813", "Romance", "English", "19th Century Literature", false, 4);
    Book book5("Moby-Dick", "Herman Melville", 9781503280786, "1851", "Adventure", "English", "Maritime Fiction", false, 5);
    Book book6("War and Peace", "Leo Tolstoy", 9781853260629, "1869", "Historical Fiction", "Russian", "Napoleonic Wars", false, 6);
    Book book7("The Catcher in the Rye", "J.D. Salinger", 9780316769488, "1951", "Fiction", "English", "Coming-of-Age", false, 7);
    catalog.push_back(book1);
    catalog.push_back(book2);
    catalog.push_back(book3);
    catalog.push_back(book4);
    catalog.push_back(book5);
    catalog.push_back(book6);
    catalog.push_back(book7);
}


Catalog::Catalog(){
    readBooksFromFile("storage/Catalog.txt");
    //populatecatalog();
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
    Book newBook(Title, author, isbn, dataPublished, genre, language, subject, false, id);
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

Book* Catalog::findBook(string title){
    for(unsigned i = 0; i < catalog.size(); i++){
        if(catalog.at(i).getTitle() == title){ //change to  get ID
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

void Catalog::testPrint(){
    for(unsigned i = 0; i < catalog.size(); i++){
        cout << catalog.at(i).getTitle() << endl;
    }
}
