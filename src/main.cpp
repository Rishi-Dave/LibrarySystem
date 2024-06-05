#include "../include/UserDatabase.h"
#include "../include/Catalog.h"
#include "../include/UserDisplay.h"
#include "../include/CatalogDisplay.h"
#include "../include/AdminDisplay.h"

int main() {
    UserDatabase database;
    Catalog catalog;
    UserDisplay display;
    CatalogDisplay catDisplay;
    AdminDisplay adminDisplay;
    User user1("Atharva", "Nevasekar", "aneva", 123, "password", &catalog);
    AdminUser him("Rishi", "Dave", "rdave", 1234, "password", &catalog);
    database.addUser(&user1);
    database.writeFile();
    display.checkout(&user1);
    database.writeFile();
    display.returnBook(&user1);
    database.writeFile();

}