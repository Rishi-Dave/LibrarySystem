#include "../include/UserDatabase.h"
#include "../include/Catalog.h"
#include "../include/UserDisplay.h"
#include "../include/CatalogDisplay.h"
#include "../include/AdminDisplay.h"
#include "../include/Display.h"

int main() {
   
    Catalog catalog;
     UserDatabase database(&catalog);
    UserDisplay userdisplay;
    CatalogDisplay catDisplay;
    AdminDisplay adminDisplay;
    Display dispay;
    User user1("Atharva", "Nevasekar", "aneva", 123, "password", &catalog);
    AdminUser him("Rishi", "Dave", "rdave", 1234, "password", &catalog);
    database.addUser(&user1);
    // database.writeFile();
    // userdisplay.checkout(&user1);
    // database.writeFile();
    // userdisplay.returnBook(&user1);
    // database.writeFile();
    
    dispay.printWelcomeMessage(database);


}