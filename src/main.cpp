#include "../include/UserDatabase.h"
#include "../include/Catalog.h"

int main() {
    User user1("Atharva", "Nevasekar", "aneva", 123, "password");
    UserDatabase database;
    Catalog catalog;
    database.addUser(user1);
    database.writeFile();
}