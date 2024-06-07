#include "googletest/googletest/include/gtest/gtest.h"
#include  "../include/UserDatabase.h"
#include "../include/User.h"
#include "../include/Book.h"
#include "../include/Catalog.h"
#include <gtest/gtest.h>


TEST(userDatabaseTest,constructor){
    Catalog catalog;
    UserDatabase database(&catalog);
    EXPECT_FALSE(database.getCurUser());
    EXPECT_FALSE(database.getAdminUser());
    EXPECT_FALSE(database.getLogStatus());
}

TEST(userDatabaseTest,addUser){
    Catalog catalog;
    UserDatabase database(&catalog);
    User* user1 = new User("Lebron","James","theKing","password", &catalog);

    database.addUser(user1);

    EXPECT_TRUE(database.checkforUser("theKing"));
}

TEST(userDatabaseTest,addadmin){
    Catalog catalog;
    UserDatabase database(&catalog);
    AdminUser admin("Admin", "User", "admin", "complexpassword", &catalog);

    database.addAdmin(&admin);


    vector<AdminUser*> list = *(database.adminvectorPointer());

    EXPECT_TRUE(list.size()==1);
}

TEST(userDatabaseTest,checkforUser){
    Catalog catalog;
    UserDatabase database(&catalog);
    User* user1 = new User("Lebron","James","theKing","password", &catalog);

    database.addUser(user1);

    EXPECT_TRUE(database.checkforUser("theKing"));
}

TEST(userDatabaseTest,login){
    Catalog catalog;
    UserDatabase database(&catalog);
    User* user1 = new User("Lebron","James","theKing","password", &catalog);
    database.addUser(user1);
    

    EXPECT_TRUE(database.login("theKing","password"));
}

TEST(userDatabaseTest,signup){
    Catalog catalog;
    UserDatabase database(&catalog);
    database.signup("lebron","james","theKing","password");

    EXPECT_TRUE(database.login("theKing","password"));
}

TEST(userDatabaseTest,logOut){
    Catalog catalog;
    UserDatabase database(&catalog);
    database.signup("lebron","james","theKing","password");
    database.login("theKing","password");
    database.logout();    

    EXPECT_FALSE(database.getLogStatus());
}

