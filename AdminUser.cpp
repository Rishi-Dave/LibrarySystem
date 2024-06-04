#include "AdminUser.h"
AdminUser::AdminUser(string first, string last, string uname, double balance, string key, Catalog &theCatalog)
    : User{first, last, uname, balance, key}
    {
        catalog = &theCatalog;
    }
void AdminUser::addBook(string Title, string author, int isbn, string dataPublished, string genre, string language, string subject, int id){
    catalog->addBook(Title,  author,  isbn,  dataPublished,  genre,  language,  subject, id);
}

void AdminUser::removeBook(int id){
    catalog->removeBook(id);
}

Book* AdminUser::findBook(int id){
    return catalog->findBook(id);
}
