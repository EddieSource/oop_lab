//
//  Swordsman.cpp
//  cs2124-hw7
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Swordsman.h"
#include "Lord.h"

using namespace std;

namespace WarriorCraft{

    Swordsman::Swordsman(const string& name, double strength) : Warrior(name, strength){}
    void Swordsman::defend() {
        if(!ifDead()){
            cout << "CLANG!  " << getName() << " says: Take that in the name of my lord, " << getEmployer()->getName() << endl;
        }
    }

}

