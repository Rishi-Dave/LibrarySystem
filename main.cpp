#include "user.h"
#include "userDisplay.h"
#include "book.h"
#include "UserDatabase.h"
int main(){
    User user1("Atharva", "Nevasekar", "atharvanev",45.20,"password");
    userDisplay printer;
    printer.showAll(user1);
    UserDatabase userDatabase;
    userDatabase.addUser(user1);
    userDatabase.writeFile();
}