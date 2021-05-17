//
//  main.cpp
//  cs2124-hw7
//
//  Created by Eddie Zhu on 2020/4/4.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Noble.h"
#include "Lord.h"
#include "PersonWithStrengthToFight.h"
#include "Protector.h"
#include "Wizard.h"
#include "Warrior.h"
#include "Archer.h"
#include "Swordsman.h"


using namespace std;
using namespace WarriorCraft; 

int main(int argc, const char * argv[]) {
    // insert code here...
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    PersonWithStrengthToFight randy("Randolf the Elder", 250);
    //line1
    joe.battle(randy);
    //line2
    joe.battle(sam);
    Lord janet("Janet");
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);
    janet.hires(stout);
    PersonWithStrengthToFight barclay("Barclay the Bold", 300);
    //line3
    janet.battle(barclay);
    
    janet.hires(samantha);
    Archer pethora("Pethora", 50);
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    //line4
    janet.battle(barclay);
    //line5
    sam.battle(barclay);
    //line6
    joe.battle(barclay);
    
    return 0;
}
