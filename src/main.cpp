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
    AdminUser admin("Admin", "User", "admin", "complexpassword", &catalog);
    
    database.addAdmin(&admin);
    
    while(true){
        if(database.getAdminUser()){
            bool stop = display.displayAdmin(adminDisplay, database, catDisplay, catalog);
            if(stop){
                break;
            }
        }
        else if(!database.getCurUser()){
            bool stop = display.printWelcomeMessage(database, catalog);
            if(stop){
                break;
            }
        }
        else{
            bool stop = display.displayInputPrompt(userDisplay, database, catDisplay, catalog);
            if(stop){
                break;
            }
        }
    }
    
}
