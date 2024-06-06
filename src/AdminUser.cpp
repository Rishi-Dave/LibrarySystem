#include "../include/AdminUser.h"

AdminUser::AdminUser(string first, string last, string uname, string key, Catalog* theCatalog)
    : User{first, last, uname, key, theCatalog}
{}

void AdminUser::addBook(string Title, string author, int isbn, string dataPublished, string genre, string language, string subject, int id){
    catalog->addBook(Title,  author,  isbn,  dataPublished,  genre,  language,  subject, id);
}

void AdminUser::removeBook(int id){
    catalog->removeBook(id);
}

Book* AdminUser::findBook(int id){
    return catalog->findBook(id);
}

Book* AdminUser::findBook(string title){
    return catalog->findBook(title);
}
