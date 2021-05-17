//
//  Warrior.cpp
//  cs2124-hw6
//
//  Created by Eddie Zhu on 2020/3/21.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <stdio.h>
#include "Warrior.h"
#include "Noble.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace WarriorCraft;

namespace WarriorCraft{
    
    ostream& operator << (ostream& os, const Warrior& aWarrior){
        os << "     " << aWarrior.name << ": " << aWarrior.strength;
        return os;
    }
        
    Warrior::Warrior(const string& name, double strength) : name(name), strength(strength), dead(false){};

    double Warrior::get_strength() const{
        return strength;
    }

    void Warrior::set_strength(double aStrength){
        strength = aStrength;
    }

    const string& Warrior::get_name() const{
        return name;
    }

    void Warrior::set_employer(Noble& aNoble){
        employer = &aNoble;
    }

    void Warrior::detach_employer(){
        //detach_employer prevents the potential issue of pointer to pointer
        employer = nullptr;
    }

    Noble* Warrior::get_employer() const{
        return employer;
    }

    void Warrior::runaway() {
        employer->delete_warrior(*this);
        cout << name << " flees in terror, abandoning his lord, " << employer->get_name() << endl;
        this->detach_employer();
    }
        
}


