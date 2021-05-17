//
//  Archer.cpp
//  cs2124-hw7
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Archer.h"
#include "Lord.h"

using namespace std;

namespace WarriorCraft {
    
    Archer::Archer(const string& name, double strength) : Warrior(name, strength){}
    void Archer::defend() {
        if(!ifDead()){
            cout << "TWANG!  " << getName() << " says: Take that in the name of my lord, " << getEmployer()->getName() << endl;
        }
    }

}


