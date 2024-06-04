#include "Catalog.h"

   //testing only//////   //testing only//////   //testing only//////
    //testing only//////   //testing only//////   //testing only//////
void Catalog::populatecatalog(){
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 9780743273565, 1, "1925", "", "Fiction", "English", "20th Century Literature", false);
    Book book2("To Kill a Mockingbird", "Harper Lee", 9780061120084, 2, "1960", "", "Fiction", "English", "Civil Rights", false);
    Book book3("1984", "George Orwell", 9780451524935, 3, "1949", "", "Dystopian", "English", "Political Fiction", false);
    Book book4("Pride and Prejudice", "Jane Austen", 9781503290563, 4, "1813", "", "Romance", "English", "19th Century Literature", false);
    Book book5("Moby-Dick", "Herman Melville", 9781503280786, 5, "1851", "", "Adventure", "English", "Maritime Fiction", false);
    Book book6("War and Peace", "Leo Tolstoy", 9781853260629, 6, "1869", "", "Historical Fiction", "Russian", "Napoleonic Wars", false);
    Book book7("The Catcher in the Rye", "J.D. Salinger", 9780316769488, 7, "1951", "", "Fiction", "English", "Coming-of-Age", false);
    catalog.push_back(book1);
    catalog.push_back(book2);
    catalog.push_back(book3);
    catalog.push_back(book4);
    catalog.push_back(book5);
    catalog.push_back(book6);
    catalog.push_back(book7);
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