//
//  main.cpp
//  cs2124-rec-9
//
//  Created by Eddie Zhu on 2020/4/4.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numOfPages(numPages){}
    virtual void displayNumPages() const = 0;
//    void displayNumPages(ostream& os) const { os << numOfPages; }
    
//    virtual void nonConstMethodDeclar( ) = 0; // the normal way
//    virtual void constMethodDeclar( ) const = 0; // the normal way
//    void nonConstMethodWithBody( ) = 0 {} // INCORRECT! Even though your compiler may accept it.
//    void constMethodWithBody( ) const = 0 {} // INCORRECT! Even though your compiler may accept it.
    
protected:
private:
    unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const {
    cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages){}
    void displayNumPages() const
         {
             cout << "Pages: ";
             PrintedMaterial::displayNumPages();
         }
protected:
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages) : PrintedMaterial(numPages){}
    void displayNumPages() const
         {
             cout << "Pages: ";
             PrintedMaterial::displayNumPages();
         }
protected:
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned indexPg) : Book(numPages), numOfIndexPages(indexPg){}
    void displayNumPages() const
        {
            cout << "Pages: ";
            PrintedMaterial::displayNumPages();
            cout << "IndexPages: ";
            cout << numOfIndexPages << endl;
        }
protected:
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned numPages) : Book(numPages){}
    void displayNumPages() const
         {
             cout << "Pages: ";
             PrintedMaterial::displayNumPages();
         }
protected:
private:
};
//
//ostream& operator<< (ostream& os, PrintedMaterial& a){
//    a.displayNumPages(os);
//    return os;
//}

void displayNumberOfPages( const PrintedMaterial& anyPM )
{
    anyPM.displayNumPages();
}


// tester/modeler code
int main()
{
    TextBook t(5430, 6);    //Why did TextBook not have a compilation problem? (It -did- override the pure virtual method.)
    t.displayNumPages();
//    cout << t;
    Novel n(213);
    n.displayNumPages();
//    cout << n;
    Magazine m(6);
    m.displayNumPages();
//    cout << m;
    
//    cout << "\nA PrintedMaterial material object!\n";
//    PrintedMaterial pm(2345);
//    pm.displayNumPages();
//
//    cout << "\nA PrintedMaterial variable containing a TextBook value\n";
//    pm = t; // like putting a t into a vector of PrintedMaterials
//    pm.displayNumPages();
    
    cout << endl;
    
    PrintedMaterial* ptPM = &t;
    ptPM->displayNumPages(); //We were not getting a TextBook object when we dereferenced a PrintedMaterial* value.
    //However, When you dereference a pointer to an base class which has a virtual method in an inheritance hierarchy which holds the address of an object of a type that was publicly derived from the base class, you get the DERIVED class
    
    //now the virtual method is invoked
    //Recall that the virtual mechanism works with either pointers to base class or reference to base class.
    
    // print some stuff by calling a generic function
    cout << "\nUse a generic functino for printing\n";
    displayNumberOfPages(m);
    displayNumberOfPages(n);
    displayNumberOfPages(t);
    
    //But if we don't want to allow PrintedMaterial things, don't we still want to make sure that any object that derived from PrintedMaterial MUST have a displayNumPages()method?
    
    vector<PrintedMaterial*> aVector;
    aVector.push_back(&m);
    aVector.push_back(&n);
    aVector.push_back(&t);
    
    for(size_t i = 0; i < aVector.size(); ++i){
        aVector[i]->displayNumPages();
        cout << endl;
    }
    
    
}
