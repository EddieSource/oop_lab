//
//  main.cpp
//  cs2124-rec10
//
//  Created by Eddie Zhu on 2020/4/10.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Instrument {
    // pure virtual
    
    //default private? yes
public:
    virtual void makeSound() = 0;
    virtual void playSound() = 0;
    
};

void Instrument::makeSound(){
        cout << "To make a sound... ";
}

//why need to write public?
//difference version public inherence

class Brass : public Instrument{
public:
    Brass(unsigned size) : size(size){}
    void makeSound() {
        Instrument::makeSound();
        cout << "blow on a mouthpiece of size " << size << endl;
    }
private:
    unsigned size;
};

class Trombone : public Brass{
public:
    Trombone(unsigned size) : Brass(size){}
    void playSound(){
        cout << "Blat";
    }
};

class Trumpet : public Brass{
public:
    Trumpet(unsigned size) : Brass(size){}
    void playSound(){
        cout << "Toot";
    }
};


class String : public Instrument{
public:
    String(unsigned pitch) : pitch(pitch){};
    void makeSound(){
        Instrument::makeSound();
        cout << "bow a string with pitch " << pitch << endl;
    }
private:
    unsigned pitch;
};

class Cello : public String{
public:
    Cello(unsigned pitch) : String(pitch){}
    void playSound(){
        cout << "Squawk";
    }
};

class Violin : public String{
public:
    Violin(unsigned pitch) : String(pitch){}
    void playSound(){
        cout << "Screech";
    }
};



class Percussion: public Instrument{
public:
    Percussion(){}
    void makeSound(){
        Instrument::makeSound();
        cout << "hit me!" << endl;
    }
};

class Drum : public Percussion{
public:
    Drum() : Percussion(){}
    void playSound(){
        cout << "Boom";
    }
};
class Cymbal : public Percussion{
public:
    Cymbal() : Percussion(){}
    void playSound(){
        cout << "Crash";
    }
};


class Musician {
public:
    Musician() : instr(nullptr) {}

    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }

    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << "have no instr\n";
    }
    
    void Play() const {
        if (instr) instr->playSound();
    }

private:
    Instrument* instr;
};


class MILL{
public:
    MILL(){}
    void receiveInstr(Instrument& aInstrument){
        aInstrument.makeSound();
        for (size_t i = 0; i < inventory.size(); ++i){
            if (inventory[i] == nullptr) {
                inventory[i] = &aInstrument;
                return;
            }
        }
        inventory.push_back(&aInstrument);
        return;
    }
    void dailyTestPlay(){
        for (size_t i = 0; i < inventory.size(); ++i){
            if (inventory[i] != nullptr) {
                inventory[i]->makeSound();
            }
        }
    }
    Instrument* loanOut(){
        for (size_t i = 0; i < inventory.size(); ++i){
            if (inventory[i] != nullptr) {
                Instrument* p(inventory[i]);
                inventory[i] = nullptr;
                return p;
            }
        }
        return nullptr;
    }
private:
    vector<Instrument*> inventory;
};


class Orch {
public:
    Orch(){}
    void addPlayer(Musician& aMusician){
        group.push_back(&aMusician);
    }
    void play(){
        for (size_t i = 0; i < group.size(); ++i) {
            group[i]->Play();
        }
        cout << endl;
    }
private:
    vector<Musician*> group;
};




int main(int argc, const char * argv[]) {
//      cout << "Define some instruments ------------------------------------\n";
//       Drum drum;
//       Cello cello(673);
//       Cymbal cymbal;
//       Trombone tbone(4);
//       Trumpet trpt(12) ;
//       Violin violin(567) ;
//
//       // use the debugger to look at the mill
//       cout << "Define the MILL --------------------------------------------\n";
//       MILL mill;
//
//       cout << "Put the instruments into the MILL --------------------------\n";
//       mill.receiveInstr(trpt);
//       mill.receiveInstr(violin);
//       mill.receiveInstr(tbone);
//       mill.receiveInstr(drum);
//       mill.receiveInstr(cello);
//       mill.receiveInstr(cymbal);
//
//       cout << "Daily test -------------------------------------------------\n";
//       cout << endl;
//       cout << "dailyTestPlay()" << endl;
//       mill.dailyTestPlay();
//       cout << endl;
//
//       cout << "Define some Musicians---------------------------------------\n";
//       Musician harpo;
//       Musician groucho;
//
//       cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
//       groucho.testPlay();
//       cout << endl;
//       groucho.acceptInstr(mill.loanOut());
//       cout << endl;
//       groucho.testPlay();
//       cout << endl;
//       cout << "dailyTestPlay()" << endl;
//       mill.dailyTestPlay();
//
//       cout << endl << endl;
//
//       groucho.testPlay();
//       cout << endl;
//       mill.receiveInstr(*groucho.giveBackInstr());
//       harpo.acceptInstr(mill.loanOut());
//       groucho.acceptInstr(mill.loanOut());
//       cout << endl;
//       groucho.testPlay();
//       cout << endl;
//       harpo.testPlay();
//       cout << endl;
//       cout << "dailyTestPlay()" << endl;
//       mill.dailyTestPlay();
//
//       cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
//
//       // fifth
//       mill.receiveInstr(*groucho.giveBackInstr());
//       cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
//       mill.receiveInstr(*harpo.giveBackInstr());
//
//
//       cout << endl;
//       cout << "dailyTestPlay()" << endl;
//       mill.dailyTestPlay();
//       cout << endl;
//
//       cout << endl;
    // The initialization phase

    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);

    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);

    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    return 0;
}
