//
//  main.cpp
//  cs2124-hw4
//
//  Created by Eddie Zhu on 2020/2/22.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Noble;    //clarifying it without defining it can be used as only reference or pointers
class Warrior;

class Warrior{
    //Warriors start out with a specified name and strength.
public:
    Warrior(const string& name, double strength) : name(name), strength(strength){};
    
    double get_strength() const{
        return strength;
    }
    
    void set_strength(double aStrength){
        strength = aStrength;
    }
    
    const string& get_name() const{
        return name;
    }
    
    void set_employer(Noble& aNoble){
        employer = &aNoble;
    }
    
    void detach_employer(){
        //detach_employer prevents the potential issue of pointer to pointer
        employer = nullptr;
    }
    
    Noble* get_employer() const{
        return employer;
    }
    
private:
    string name;
    double strength;
    Noble* employer;
    bool dead = false;
    };


class Noble{
    friend ostream& operator << (ostream& os, const Noble& aNoble);
public:
    Noble(const string& name) : name(name){};
    
    bool hire(Warrior& aWarrior){
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
    
    bool fire(Warrior& aWarrior){
        if (dead == false){
            size_t i = 0;
            while(i < army.size()){
                if(aWarrior.get_name()==army[i]->get_name()){
                    cout << "You don't work for me anymore "<< aWarrior.get_name() <<"! -- " << name <<"." << endl;
                    //remove the warrior strength from the Warrior
                    strength -= army[i]->get_strength();
                    //set the warrior's employer to nullptr;
                    army[i]->detach_employer();
                    //remove the warrior from the army
                    while(i < army.size() - 1){
                        army[i] = &(*(army[i+1]));
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
     
    
    const string& get_name() const{
        return name;
    }
    
    double get_strength() const{
        return strength;
    }
    
    void set_strength(double aStrength){
        strength = aStrength;
    }
    
    
    
    void battle(Noble& aNoble){
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
    
private:
    string name;
    vector<Warrior*> army;
    double strength = 0;
    bool dead = false;
};


ostream& operator << (ostream& os, const Noble& aNoble){
    os << aNoble.name << " has an army of " << aNoble.army.size() << endl;
    for(size_t i = 0; i < aNoble.army.size(); ++i){
        os << "     " << aNoble.army[i]->get_name() << ": " << aNoble.army[i]->get_strength() << endl;
    }
    return os;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);

    cout << "==========\n"
         << "Status before all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";

    art.fire(cheetah);
    cout << art << endl;

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "==========\n"
         << "Status after all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";
    
    
    return 0;
}
