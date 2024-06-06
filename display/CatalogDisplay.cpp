#include "../include/CatalogDisplay.h"
#include "../include/BookDisplay.h"

void CatalogDisplay::print(Catalog cat){
    BookDisplay printer;
    vector<Book> books = *(cat.vectorPointer());
    for(unsigned i; i<books.size();i++){
        printer.printBook(books.at(i));
    }
}

void CatalogDisplay::printbyAuthor(Catalog cat){
    cat.sortbyAuthor();
    print(cat);
}

void CatalogDisplay::printbyTitle(Catalog cat){
    cat.sortbyTitle();
    print(cat);
}

void CatalogDisplay::printbyLang(Catalog cat){
    cat.sortbyLang();
    print(cat);
}

void CatalogDisplay::printbySubj(Catalog cat){
    cat.sortbySubj();
    print(cat);
}

void CatalogDisplay::printbyGenre(Catalog cat){
    cat.sortbyGenre();
    print(cat);
}

void CatalogDisplay::printbyDate(Catalog cat){
    cat.sortbyDate();
    print(cat);
}

void CatalogDisplay::printbyISBN(Catalog cat){
    cat.sortbyISBN();
    print(cat);
}





void CatalogDisplay::viewCatalog(Catalog* catalog){
    printPageBreak();
    cout<< "Book Catalog:"<<endl<<endl;
    print(*catalog);
    cout<<endl<<endl;
    cout << "Press Enter to continue.";
    cin.get();
    while(true){
        printPageBreak();
        cout<<"Sort Catalog by Categories"<<endl;
        cout<<"     ISBN (I)"<<endl;
        cout<<"     Title (T)"<<endl;
        cout<<"     Language (L)"<<endl;
        cout<<"     Subject (S)"<<endl;
        cout<<"     Genre (G)"<<endl;
        cout<<"     Date Published (D)"<<endl;
        cout<<"     Go back home (E)"<<endl;
        string input = getInput("Enter Choice: ");
        cout << endl << "Book Catalog ";
        if(input == "i" || input== "I"){
            cout << "Sorted by ISBN:" << endl << endl;
            printbyISBN(*catalog);
        }
        else if(input == "t" || input== "T"){
            cout << "Sorted by Title:" << endl << endl;
            printbyTitle(*catalog);
        }
        else if(input == "l" || input== "L"){
            cout << "Sorted by Language:" << endl << endl;
            printbyLang(*catalog);
        }
        else if(input == "s" || input== "S"){
            cout << "Sorted by Subject:" << endl << endl;
            printbySubj(*catalog);
        }
        else if(input == "g" || input== "G"){
            cout << "Sorted by Genre:" << endl << endl;
            printbyGenre(*catalog);
        }
        else if(input == "d" || input== "D"){
            cout << "Sorted by Date Published:" << endl << endl;
            printbyDate(*catalog);
        }
        else if(input == "e" || input== "E"){
            return;
        }
        else{
            cout<<endl;
            cout<<"Invalid input please try again"<<endl;
            cout<<endl;
            continue;
        }
        cout << "Press Enter to continue.";
        cin.get();
    }  
 }