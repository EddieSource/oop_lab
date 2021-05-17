//
//  PersonWithStrengthToFight.cpp
//  cs2124-hw7
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <stdio.h>
#include "PersonWithStrengthToFight.h"
#include <string>
#include <iostream>
#include "Noble.h"

using namespace std;


namespace WarriorCraft {

    PersonWithStrengthToFight::PersonWithStrengthToFight(const string& name, double strength) : Noble(name, strength){}
    void PersonWithStrengthToFight::defend() {
        if(!ifDead()){
            cout << "Ugh!" << endl;
        }
    }
    double PersonWithStrengthToFight::reduceStrength(double percent) {
        return percent * getStrength();
    }

}



