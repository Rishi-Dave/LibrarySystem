#include "mockbook.h"
#include "user.h"
#include "userDisplay.h"

int main(){
    User user1("Atharva", "Nevasekar", "atharvanev",45.20,"password");
    userDisplay printer;
    printer.showAll(user1);
}