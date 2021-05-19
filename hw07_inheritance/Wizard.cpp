//
//  Wizard.cpp
//  cs2124-hw7
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Wizard.h"

using namespace std;

namespace WarriorCraft {

    Wizard::Wizard(const string& name, double strength) : Protector(name, strength){}
    void Wizard::defend() {
        //when defend, says poof
        if(!ifDead()){
            cout << "POOF!" << endl;
        }
    }

}
