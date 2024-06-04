#include "user.h"
#include "userDisplay.h"
#include "AdminDisplay.h"
#include "AdminUser.h"

int main(){
    Catalog catalog;
    AdminUser user1("Atharva", "Nevasekar", "atharvanev",45.20,"password", catalog);
    AdminDisplay adminDisplay;
    adminDisplay.addBook(&user1);
}