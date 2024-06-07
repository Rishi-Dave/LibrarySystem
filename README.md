# Library System
 > Authors: \<[Rishi Dave](https://github.com/Rishi-Dave)\>
>\<[Atharva Nevasekar](https://github.com/atharvanev)\>
> \<[Hanlin Liu](https://github.com/Diao2887)\>
> \<[Xuanyang Lai](https://github.com/sleepycreamcake)\>
## Project Description
 >Project Description:
> * It is interesting because we can develop a system that allows users to sign up for accounts, so that they can have a wallet for the library, display available books and borrow books.
> * We plan to use C++ and a Backend System such as SQL(still work in progress)
> * The input of the project will be user inputs. Before that, we as the administrator, can add/edit/remove books in order to build a basic storage of the program. The output of the project will be a list of books based on the user inputs.
> * The features that the project provides:
>     * Organized books that are sorted in different ways:
>         * Name
>         * Author
>         * Genres
>         * Rating
>         * Release Date
>     * Books will be shown on screen in selected sorting. User will be able to borrow the books they like.
>     * Users can deposit in their account. If they want to borrow books, there will be a charge based on the time they return the books.
>     * The library have a limited amount of books. Once a user borrows a book, the storage of the library will change. If a book is out of storage, it will be in a hiden file.
>     * User accounts can only manage their account, display books and borrow books. Only administrator can add/edit/remove books.

> 
### Navigation Diagram
> The Diagram belows shows the how a user would expect to move from page in the program with the starting point being the login page.
> ![Navigation Diagram Library Management]<img width="947" alt="image" src="https://github.com/cs100/final-project-rdave009-xlai015-hliu246-aneva018/assets/147217989/d8e5b2f9-6a2c-40a7-a90a-acc6d7d66a4d">


### Screen Layouts
> The document below shows the screen layout for all the different pages of the program from the starting page and shows how the terminal would look for each page. 
> https://docs.google.com/document/d/19pzhGZG7mlglxy0nlkBs0C4Lk1to9xdNGjIJQKOVodQ/edit

## Class Diagram
 > The UML digrams shows all the classes that are invovled in creating the Libarry system. It mainly consisting of two databases with a catalog that holds books and then a user database that holds users and admins. Users can checkout books, return, and pay fees while Admins can do everything mentioned previously and add remove, add, and edit books in the catalog.

<img width="1063" alt="image" src="https://github.com/cs100/final-project-rdave009-xlai015-hliu246-aneva018/assets/147217989/5db599db-6a2a-4bce-b129-95f4fc4b495a">

 > One of the first changes we made to apply to Solid Principals was to add separate Display classes for each class inorder to follow the Single Responsibility Principle. This Change allowed us to write better code since it became easier to edit the display versus the actual functionality of the program. It allowed for much easier and faster development. Additionally, we follow the open and closed principle since the code base is all open to expansion and creating new functions, but it is closed off from modification. We also follow the interface segregation principle with the book display class. The book display class is the only display class that doesn't take in input variables and the whole point of the Display Parent class is to help with input functionality. If the book display inherited from this class it would be a violation of the Interface segregation principle since those functions are useless for the class; thus, the book display class doesn't inherit like all the other display classes. It helped create better code since the bookDisplay class isn't needless inheriting functions and helps the code run faster.
 ## Final deliverable

 
 >## Screenshots
 > Screenshots of the input/output after running the application
> https://docs.google.com/document/d/1Lh5RrSasQVPTc1BOX3DUwyQmSp4ii3IoF_g9YN-R-nU/edit?usp=sharing
 ## Installation/Usage
Clone this repository to download the files required the program
 ```
git clone https://github.com/cs100/final-project-rdave009-xlai015-hliu246-aneva018.git
```
Make sure you have **Cmake installed** to run the program and type the following commands to run the program, Make sure ```storage/Catalog.txt``` and ```storage/Users.txt``` are empty/do not exists when you run the program for the first time to ensure that any invalid previous data does not mess up your experience.
```
cmake .
```
```
make
```
These command should generate a executable ``` ./bin/runMain``` and now whenever you want to acess the programm simply open the folder where the repo is cloned and run
```
./runMain
```
 ## Testing
> * How we test:
>    * The Project was validated using the google test suite and using a series of Unit Tests for each file to make sure they have proper behavior, accept input and output properly.
> * Our Approach:
>   * Our approach going into testing was to start with basic classes such as User and Book and then work our way into Display classes. With basic functions, we simply just called the function and see if its functionality works. To do this, we first tested the most basic methods and then used those methods to test the more complex methods(ex. using findBook() to test addBook() and addBook() to test removeBook(), etc.). Then, we moved on to the Display classes that outputted using cout to the terminal. After some research, we found std library functions to convert outputs into stringstreams which we could process as strings. We then compared that to what we want the output the be as a testing method. Another Feature we incorporated was "TEST_F" and using a SetUp() function to set up all of our testing variables before testing each function.
> * Who Made What Tests
>      * Rishi: BookDisplay.cpp, CatalogDisplay.cpp, ParentDisplay.cpp, AdminUser.cpp, User.cpp, Display.cpp
>      * Atharva: UserDisplay.cpp, UserDatabase.cpp, AdminDisplay.cpp
>      * Hanlin: Catalog.cpp
>     * Xuanyang: Book.cpp
