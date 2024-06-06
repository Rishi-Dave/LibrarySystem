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

    UserDisplay userDisplay;
    AdminUser him("Rishi", "Dave", "rdave", 1234, "password", &catalog);
    catDisplay.print(catalog);
    database.readFile(&catalog);
    /*
    
    database.writeFile();
    display.checkout(&user1);
    database.writeFile();
    display.returnBook(&user1);
    database.writeFile();
    */    
   database.printAllInfo();
   database.login("aneva", "password");
   userDisplay.showAll(*database.getCurUser());

}