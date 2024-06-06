#include "../include/Book.h"


// Constructors

Book::Book() : Title("dune"), Author(""), ISBN(0), DatePublished(""), Genre(""), Language(""), Subject(""), Status(false), ID(1){};

Book::Book(string title, string author, int isbn, string datePublished, string genre, string language, string subject, bool status, int id) 
        : Title(title), Author(author), ISBN(isbn), DatePublished(datePublished), Genre(genre), Language(language), Subject(subject), Status(status), ID(id){}

// Accessors
string Book::getTitle() const { return Title; }
string Book::getAuthor() const { return Author; }
string Book::getLanguage() const { return Language; }
string Book::getSubject() const { return Subject; }
string Book::getGenre() const { return Genre; }
string Book::getDate() const { return DatePublished; }
int Book::getISBN() const { return ISBN; }
bool Book::getStatus() const { return Status; }
int Book::getID() const { return ID; }

// Mutators
void Book::setTitle(const string &title) { 
    Title = title; 
}
void Book::setAuthor(const string &author) { 
    Author = author; 
}
void Book::setLanguage(const string &language) { 
    Language = language; 
}
void Book::setSubject(const string &subject) { 
    Subject = subject; 
}
void Book::setGenre(const string &genre) { 
    Genre = genre; 
}
void Book::setDate(const string &datePublished) { 
    DatePublished = datePublished; 
}
void Book::setISBN(int &isbn) { 
    ISBN = isbn;
}
void Book::setID(int &id) { 
    ID = id;
}
void Book::setStatus(bool status) { 
    Status = status;
}

void Book::write(std::ofstream& outputFile) {
  outputFile << Title << "|" << Author
            << "|" << Genre << "|" << Language 
            << "|" <<Subject << "|" << DatePublished 
            << "|" << ISBN << "|" << ID << std::endl;
  outputFile << std::endl;
}


