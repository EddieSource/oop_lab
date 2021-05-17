//
//  Noble.cpp
//  cs2124-hw7
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include "Noble.h"


using namespace std; 

namespace WarriorCraft{

    Noble::Noble(const string& name, double strength) : name(name), strength(strength), dead(false){}
    void Noble::battle(Noble& rhs){
        cout << name << " battles " << rhs.name << endl;
        defend();
        rhs.defend();
        if(dead && rhs.dead){
            cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
        }
        else if(dead) {
            cout << "He's dead, " << rhs.name << endl;
        }
        else if(rhs.dead){
            cout << "He's dead, " << name << endl;
        }
        else if(strength < rhs.strength){
            //set another Noble's strength
            rhs.reduceStrength(1 - strength/rhs.strength);
            
            //set the Noble's strength, the Noble is dead
            dead = true;
            reduceStrength(0);
            
            cout << rhs.name << " defeats " << name << endl;
        }
        else if(strength > rhs.strength){
            //set the Noble's strength
            strength = rhs.reduceStrength(1 - rhs.strength/strength);
            
            //set the Noble's strength, the Noble is dead
            rhs.dead = true;
            strength = rhs.reduceStrength(0);

            cout << name << " defeats " << rhs.name << endl;
        }
        else if(strength == rhs.strength){
            dead = true;
            strength = reduceStrength(0);
            rhs.dead = true;
            strength = rhs.reduceStrength(0);
            cout << "Mutual Annihilation: " << name << " and " << rhs.name << "die at each other's hands" << endl;
        }
        
    }
    string Noble::getName() const{
        return name;
    }
    double Noble::getStrength() const {
        return strength;
    }
    void Noble::setStrength(int aStrength){
        strength = aStrength;
    }
    bool Noble::ifDead() const{
        return dead;
    }


}

