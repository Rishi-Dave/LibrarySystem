 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
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
> ![Navigation Diagram Library Management](https://github.com/cs100/final-project-rdave009-xlai015-hliu246-aneva018/assets/147217989/eb57d41b-30d5-48ac-8609-a91e235b5c7c)


### Screen Layouts
> The document below shows the screen layout for all the different pages of the program from the starting page and shows how the terminal would look for each page. 
> https://docs.google.com/document/d/19pzhGZG7mlglxy0nlkBs0C4Lk1to9xdNGjIJQKOVodQ/edit

## Class Diagram
 > The UML digrams shows all the classes that are invovled in creating the Libarry system. It mainly consisting of two databases with a catalog that holds books and then a user database that holds users and admins. Users can checkout books, return, and pay fees while Admins can do everything mentioned previously and add remove, add, and edit books in the catalog.


![image](https://github.com/cs100/final-project-rdave009-xlai015-hliu246-aneva018/assets/147217989/e375a896-bdc9-497a-87f1-7f2535f813a0)


 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
