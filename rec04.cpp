//
//  rec04.cpp
//  cs2124-lab-4
//
//  Created by Eddie Zhu on 2020/2/21.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Complex {
   double real;
   double img;
};
class PlainOldClass {
public:
   PlainOldClass() : x(-72) {}
   int getX() const { return x; }
   void setX( int val )  { x = val; }
private:
   int x;
};


class PlainOldClassV2 {
    public:
       PlainOldClassV2() : x(-72) {}
       int getX() const { return x; }
//       void setX( int x )  { x = x; } // HMMMM???
        void setX( int x )  { this->x = x; }
    private:
       int x;
    };


class Colour {
public:
    Colour(const string& name, unsigned r, unsigned g, unsigned b)
        : name(name), r(r), g(g), b(b) {}
    void display() const {
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
    }
private:
    string name;      // what we call this colour
    unsigned r, g, b; // red/green/blue values for displaying
};


class SpeakerSystem {
   public:
   void vibrateSpeakerCones(unsigned signal) const {

      cout << "Playing: " << signal << "Hz sound..." << endl;
      cout << "Buzz, buzzy, buzzer, bzap!!!\n";
   }
};


class Amplifier {
public:
  void attachSpeakers(SpeakerSystem& spkrs)
   {
      if(attachedSpeakers)
         cout << "already have speakers attached!\n";
      else
         attachedSpeakers = &spkrs;
   }
  
   void detachSpeakers() { // should there be an "error" message if not attached?
      attachedSpeakers = nullptr;
   }
  
   void playMusic( ) const {
      if (attachedSpeakers)
         attachedSpeakers -> vibrateSpeakerCones(440);
      else
         cout << "No speakers attached\n";
   }
private:
   SpeakerSystem* attachedSpeakers = nullptr;
};


class Person {
public:
    Person(const string& name) : name(name) {}
    bool movesInWith(Person& newRoomate) {
        if(roomie == nullptr && newRoomate.roomie == nullptr && &newRoomate != this){
            roomie = &newRoomate;        // now I have a new roomie
            newRoomate.roomie = this;    // and now they do too
            return true;
        }
        else
        {
            cerr << "error" << endl;
            exit(1);
            return false;
            
        }
    }
    const string& getName() const { return name; }
    // Don't need to use getName() below, just there for you to use in debugging.
    const string& getRoomiesName() const { return roomie->getName(); }
private:
    Person* roomie;
    string name;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    //task1
    int x;
    x = 10;
    cout << "x= " << x << endl;
    
    //task8
    int* p; //pointer to int - this is the type
    p = &x; //points to x(to make p contain the address of x)
    cout << "p=" << p << endl;
//    p = 0x0012fed4;
    *p = -2763;
    cout << "p points to where " << *p << " is stored\n"; 
    cout << "*p now contains " << x << endl;
   
    //task 12
    int y(13);
    cout << "y contains " << y << endl;
    p = &y;
    cout << "p now points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "y now contains " << y << endl;
    
    //task 13
    int* q;
    q = p;
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q contains " << *q << endl;
    
    //task 14
    double d(33.44);
    double* pD(&d);
    *pD = *p; //int can be cast to double
    *pD = 73.2343;
    *p  = *pD; //double can be cast to int
    *q  = *p;
//    pD  = p;
//    p   = pD;
    
    //task 15
    int joe = 24;
    const int sal = 19;
    int*  pI;
      pI = &joe;
     *pI = 234;
//      pI = &sal;  //not-const pointertoint can not point to const int
//     *pI = 7623;

    const int* pcI; //the object in the address is constant, but address can change
      pcI = &joe;
    joe = 17;   //const pointer can not
//     *pcI = 234;    //const pointer's dereference can not change
    
      pcI = &sal;
    pcI = &joe;
//     *pcI = 7623;

//    int* const cpI;   //address const
    int* const cpI(&joe);   //address is constant but the object in the address can be changed
//    int* const cpI(&sal);
//      cpI = &joe;
     *cpI = 234;
    //  cpI = &sal;
    // *cpI = 7623;

//    const int* const cpcI;
//    const int* const cpcI(&joe);
//    const int* const cpcI(&sal); // cant show in the same line
    //  cpcI = &joe;  // *cpcI = 234;
//      cpcI = &sal;
//     *cpcI = 7623;
    
    //task 16
    
    Complex c = {11.23,45.67};
    Complex* pC(&c);
    
//    cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;
    cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl;
    cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;
    
    //task 17
    
    

    PlainOldClass poc;
    PlainOldClass* ppoc( &poc );
    cout << ppoc->getX() << endl;
    ppoc->setX( 2837 );
    cout << ppoc->getX() << endl;
    
    //task 18
    
    PlainOldClassV2 poc2;
    PlainOldClassV2* ppoc2( &poc2 );
    cout << ppoc2->getX() << endl;
    ppoc2->setX( 2837 );
    cout << ppoc2->getX() << endl;
    
    
    int* pDyn = new int(3); // p points to an int initialized to 3 on the heap, thats why we use "()"
    *pDyn = 17;
    cout << "The " << *pDyn
    << " is stored at address " << pDyn;
    
    cout << pDyn << endl;
    delete pDyn;
//    pDyn = nullptr;

    //some ide does not change the program
    cout << pDyn << endl;
    
    cout << "The 17 might STILL be stored at address " << pDyn<< " even though we deleted pDyn\n";
    cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
    
    
    //Task 22
    double* pDouble = nullptr;
    cout << "Can we dereference nullptr?  " << *pDyn << endl;
//    cout << "Can we dereference nullptr?  " << *pDouble << endl;  //we can t dereference nullptr
    
    
    //Task 23
    //"this" can never be nullptr
    
    //Task 24
    double* pTest = new double(12);
    delete pTest;
    pTest = nullptr;
    delete pTest; // safe
    
    //Task 25
    short* pShrt = new short(5);
    delete pShrt;
//    delete pShrt; //can not be delete twice
    
    //task 26
    long jumper = 12238743;
//    delete jumper;    //delete can only be used in heap
    long* ptrTolong = &jumper;
//    delete ptrTolong;
    Complex cmplx;
//    delete cmplx; //we give it back to the memory
    
    
    
//task 27
    vector<Complex*> complV; // can hold pointers to Complex objects
    Complex* tmpPCmplx;      // space for a Complex pointer
    for (size_t ndx = 0; ndx < 3; ++ndx) {
       tmpPCmplx = new Complex; // create a new Complex object on the heap
       tmpPCmplx->real = ndx;   // set real and img to be the
       tmpPCmplx->img  = ndx;   // value of the current ndx
       complV.push_back(tmpPCmplx); // store the ADDRESS of the object in a vector or pointer to Complex
    }
    // display the objects using the pointers stored in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        cout << complV[ ndx ]->real << endl;
        cout << complV[ ndx ]->img  << endl;
    }
    // release the heap space pointed at by the pointers in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        delete complV[ndx];
        //complV[ndx] = nullptr //do we need this?
    }
    // clear the vector
    complV.clear();     //Note carefully that .clear() does NOT issue a delete on the things inside the vector.
    
    
    
    

    vector<Colour*> colours;
    string inputName;
    unsigned inputR, inputG, inputB;

    // fill vector with Colours from the file
    // this could be from an actual file but here we are using the keyboard instead of a file
    // (so we don't have to create an actual file)
    // Do you remember the keystroke combination to indicate "end of file" at the keyboard?
    // somehow the while's test has to fail - from keyboard input
    
//    while (cin >> inputName >> inputR >> inputG >> inputB) {
//        colours.push_back(new Colour(inputName, inputR, inputG, inputB));
//    }

    // display all the Colours in the vector:
    for (size_t ndx = 0; ndx < colours.size(); ++ndx) {
        colours[ndx]->display();
        cout << endl;
    }
    
    
    //task 29

    
    Amplifier a;
    SpeakerSystem s;
    a.attachSpeakers(s);
    a.playMusic();
    a.playMusic();
    
    
    


    // write code to model two people in this world
    Person joeBob("Joe Bob"), billyJane("Billy Jane");

    // now model these two becoming roommates
    joeBob.movesInWith(joeBob);
    joeBob.movesInWith(billyJane);

    // did this work out?
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
    
    
    return 0;
}
