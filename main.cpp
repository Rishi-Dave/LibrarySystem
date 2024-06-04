#include "book.h"
#include "user.h"
#include "userDisplay.h"
#include "BookDisplay.h"

int main(){
    User user1("Atharva", "Nevasekar", "atharvanev",45.20,"password");
    userDisplay printer;
    printer.showAll(user1);
    // user1.payFees(20);
    // printer.showbalance(user1);
}