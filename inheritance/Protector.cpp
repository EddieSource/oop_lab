//
//  Protector.cpp
//  cs2124-hw7
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <stdio.h>
#include "Protector.h"
#include "Lord.h"

using namespace std;



namespace WarriorCraft {


    Protector::Protector(const string& name, double strength): name(name), strength(strength), employer(nullptr), dead(false){}

    bool Protector::quit(){
        return employer->fires(*this);
    }

    string Protector::getName() const{
        return name;
    }
    double Protector::getStrength() const{
        return strength;
    }
    void Protector::setStrength(int aStrength){
        strength = aStrength;
    }
    Lord* Protector::getEmployer () const{
        return employer;
    }
    void Protector::setEmployer(Lord* aEmployer){
        employer = aEmployer;
    }
    bool Protector::ifDead() const{
        return dead;
    }
    void Protector::setDead(bool ifDead){
        dead = ifDead;
    }



}
