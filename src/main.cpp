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
    Display display;
    AdminUser him("Rishi", "Dave", "rdave", 1234, "password", &catalog);
    while(true){
        if(!database.getCurUser()){
            display.printWelcomeMessage(database, catalog);
        }
        else{
            display.displayInputPrompt(userDisplay, database, catDisplay, catalog);
        }
    }
    
}