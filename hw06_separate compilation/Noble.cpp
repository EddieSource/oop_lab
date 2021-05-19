//
//  Noble.cpp
//  cs2124-hw6
//
//  Created by Eddie Zhu on 2020/3/21.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <stdio.h>
#include "Noble.h"
#include "Warrior.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace WarriorCraft; 

namespace WarriorCraft {
    ostream& operator << (ostream& os, const Noble& aNoble){
        os << aNoble.name << " has an army of " << aNoble.army.size() << endl;
        for(size_t i = 0; i < aNoble.army.size(); ++i){
            os << *aNoble.army[i] << endl;
        }
        return os;
    }
        
    Noble::Noble(const string& name) : name(name), strength(0), dead(false){};

    bool Noble::hire(Warrior& aWarrior){
        if(aWarrior.get_employer()==nullptr && dead == false){
            //set the warrior's employer to this
            aWarrior.set_employer(*this);
            //add the warrior to the employer's army
            Warrior* pW = &aWarrior;
            army.push_back(pW);
            strength += pW->get_strength();
            return true;
        }
        else if(dead == false){
            // the warrior already has a employer
            cerr << aWarrior.get_name() << " already has a employer. " << endl;
            return false;
        }
        else{
            // the noble is dead
            cerr << name << " is dead, so he can not hire any one" << endl;
            return false;
        }
    }


    bool Noble::fire(Warrior& aWarrior){
        if (dead == false){
            size_t i = 0;
            while(i < army.size()){
                if(army[i] == &aWarrior){
                    cout << "You don't work for me anymore "<< aWarrior.get_name() <<"! -- " << name <<"." << endl;
                    //remove the warrior strength from the Warrior
                    strength -= army[i]->get_strength();
                    //set the warrior's employer to nullptr;
                    army[i]->detach_employer();
                    //remove the warrior from the army
                    while(i < army.size() - 1){
                        army[i] = army[i+1];
                    }
                    army.pop_back();
                    return true;
                }
                ++i;
            }
            cerr << "Could not find Warrior" << endl;
            return false;
        }
        else {
            cerr << "He is already dead" << endl;
            return false;
        }
        
    }
     

    const string& Noble::get_name() const{
        return name;
    }

    double Noble::get_strength() const{
        return strength;
    }

    void Noble::set_strength(double aStrength){
        strength = aStrength;
    }


    bool Noble::delete_warrior(Warrior& aWarrior){
        size_t i = 0;
        while(i < army.size()){
            if(army[i] == &aWarrior){
                //remove the warrior strength from the Warrior
                strength -= army[i]->get_strength();
                //remove the warrior from the army
                while(i < army.size() - 1){
                    army[i] = army[i+1];
                }
                army.pop_back();
                return true;
            }
            ++i;
        }
        cerr << "Could not find Warrior" << endl;
        return false;
    }


    void Noble::battle(Noble& aNoble){
        cout << name << " battles "<< aNoble.name << endl;
        
        //if both dead
        if(strength == 0 && aNoble.strength == 0){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        //if one is dead
        else if(strength > aNoble.strength && aNoble.strength == 0){
            cout << "He's dead, " << name << endl;
        }
        else if(strength > aNoble.strength){
            double portion = aNoble.strength/strength;
            //set strength for the winner
            strength = 0;
            for(size_t i = 0; i < army.size(); ++i){
                army[i]->set_strength((1 - portion) * army[i]->get_strength());
                strength += army[i]->get_strength();
            }
            
            //set strength for the loser
            aNoble.strength = 0;
            for(size_t i = 0; i < aNoble.army.size(); ++i){
                aNoble.army[i]->set_strength(0);
            }
            aNoble.dead = true;
            
            cout << name << " defeats " << aNoble.name << endl;
        
        }
        //if the other one is dead
        else if(strength < aNoble.get_strength() && strength == 0){
            cout << "He's dead, " << aNoble.name << endl; ;
        }
        else if(strength < aNoble.get_strength()){
            double portion = strength/aNoble.strength;
            //set strength for the winner
            aNoble.strength = 0;
            for(size_t i = 0; i < aNoble.army.size(); ++i){
                aNoble.army[i]->set_strength((1 - portion) * aNoble.army[i]->get_strength());
                aNoble.strength += aNoble.army[i]->get_strength();
            }
            //set strength for the loser
            strength = 0;
            for(size_t i = 0; i < army.size(); ++i){
                army[i]->set_strength(0);
            }
            dead = true;
            cout << strength << " defeats " << aNoble.name << endl;
        }
        
        //if aWarrior.strength = bWarrior.strength
        else {
            //set strength for both to zero
            for(size_t i = 0; i < aNoble.army.size(); ++i){
                aNoble.army[i]->set_strength(0);
            }
            aNoble.strength = 0;
            aNoble.dead = true;
            //set strength for the loser
            for(size_t i = 0; i < army.size(); ++i){
                army[i]->set_strength(0);
            }
            strength = 0;
            dead = true;
            cout << "Mutual Annihilation: Arthur and Lancelot die at each other's hands" << endl; ;
        }
    }
}
        
        
        


