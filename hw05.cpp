//
//  main.cpp
//  hw5
//
//  Created by Eddie Zhu on 2020/2/28.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Noble;    //clarifying it without defining it can be used as only reference or pointers
class Warrior;

class Warrior{
    friend ostream& operator << (ostream& os, const Warrior& aWarrior);
    //Warriors start out with a specified name and strength.
public:
    Warrior(const string& name, double strength) : name(name), strength(strength), employer(nullptr), dead(false){}
    
    double get_strength() const{
        return strength;
    }
    
    void set_strength(double aStrength){
        strength = aStrength;
    }
    
    string get_name() const {
        return name;
    }
    
    void set_employer(Noble& aNoble){
        employer = &aNoble;
    }
    
    void detach_employer(){
        //detach_employer prevents the potential issue of pointer to pointer
        employer = nullptr;
    }
    
    bool has_no_employer() const{
        if (employer == nullptr) {
            return true;
        }
        return false;
    }
    
private:
    string name;
    double strength;
    Noble* employer;
    bool dead;
    };


class Noble{
    friend ostream& operator << (ostream& os, const Noble& aNoble);
public:
    Noble(const string& name) : name(name){
        strength = 0;
        dead = false;
    }
    
    bool hire(Warrior& aWarrior){
        if(aWarrior.has_no_employer() && dead == false){
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
            cerr << "Error: noble " << name << " is attempting to hire warrior " << aWarrior.get_name() << " who is already employed. " << endl;
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
     
    string get_name() const {
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
    double strength;
    bool dead;
};


ostream& operator << (ostream& os, const Noble& aNoble){
    os << aNoble.name << " has an army of " << aNoble.army.size() << endl;
    for(size_t i = 0; i < aNoble.army.size(); ++i){
        os << "     " << aNoble.army[i]->get_name() << ": " << aNoble.army[i]->get_strength() << endl;
    }
    return os;
}


ostream& operator << (ostream& os, const Warrior& aWarrior){
    os << aWarrior.name << " " << aWarrior.strength << endl;
    return os;
}


Noble* findNoble(const vector<Noble*>& pstNoble, const string& nobleName){
    for(size_t i = 0; i < pstNoble.size(); ++i){
        if(pstNoble[i]->get_name()==nobleName){
            return pstNoble[i];
        }
    }
    return nullptr;
}

Warrior* findWarrior(const vector<Warrior*>& pstWarrior, const string& warriorName){
    for(size_t i = 0; i < pstWarrior.size(); ++i){
        if(pstWarrior[i]->get_name()==warriorName){
            return pstWarrior[i];
        }
    }
    return nullptr;
}



void processFile(ifstream& file){
    string command;
    int warriorStrength;
    string nobleName;
    string warriorName;
    
    vector<Noble*> pstNoble;
    vector<Warrior*> pstWarrior;
    
    string noble1;
    string noble2;
    
    while(file >> command){
        if(command == "Noble"){
            file >> nobleName;
            Noble* aNoble = findNoble(pstNoble, nobleName);
            if(aNoble == nullptr){
                //create a new noble on heap
                Noble* aptN = new Noble(nobleName);
                pstNoble.push_back(aptN);
            }
            else {
                //catch error when a Noble with a given name already exists.
                cerr << aNoble->get_name() << " already exists" << endl;
                aNoble = nullptr;
            }
        }
        else if(command == "Warrior"){
            file >> warriorName;
            file >> warriorStrength;
            Warrior* aWarrior = findWarrior(pstWarrior, warriorName);
            if(aWarrior == nullptr){
                // create a new warrior on heap
                Warrior* aptW = new Warrior(warriorName, warriorStrength);
                pstWarrior.push_back(aptW);
            }
            else {
                //catch error when a Warrior with a given name already exists.
                cerr << aWarrior->get_name()<< " already exists" << endl;
                aWarrior = nullptr;
            }
        }
        else if(command == "Hire"){
            file >> nobleName;
            file >> warriorName;
            
            Noble* aNoble = findNoble(pstNoble, nobleName);
            Warrior* aWarrior = findWarrior(pstWarrior, warriorName);
            
            //check if both does not exist
            if(aNoble == nullptr && aWarrior == nullptr){
                cerr << "Both Noble " << nobleName << " and Warrior" << warriorName << " do not exist";
            }
            //check if one does not exist
            else if (aNoble == nullptr) {
                cerr << "Noble " << nobleName << " does not exist";
            }
            //check if one does not exist
            else if (aWarrior == nullptr) {
                cerr << "Error: noble " << aNoble->get_name() << " is attempting to hire warrior " << warriorName << " who is already employed. " << endl;
            }
            else {
                aNoble->hire(*aWarrior);
            }
        }
        else if(command == "Fire"){
            file >> nobleName;
            file >> warriorName;
            Noble* aNoble = findNoble(pstNoble, nobleName);
            Warrior* aWarrior = findWarrior(pstWarrior, warriorName);
            // check if noble does not exist
            if(aNoble == nullptr){
                cerr << nobleName << "does not exist";
                aNoble = nullptr;
            }
            else{
                aNoble->fire(*aWarrior);
            }
        }
        else if(command == "Status"){
            cout << "Status\n"
                 << "=====\n";
            cout << "Nobles: " << endl;
            if(pstNoble[0] == nullptr || pstNoble.size() == 0){
                cout << "NONE" << endl;
            }
            else{
                for(size_t i = 0; i < pstNoble.size(); ++i){
                    cout << *pstNoble[i];
                }
            }
            
            cout << "Unemployed Warriors: " << endl;
            if(pstWarrior[0] == nullptr || pstWarrior.size() == 0){
                cout << "NONE" << endl;
            }
            else{
                bool no_warrior = true;
                for(size_t i = 0; i < pstWarrior.size(); ++i){
                    if(pstWarrior[i]->has_no_employer()){
                        cout << *pstWarrior[i];
                        no_warrior = false;
                    }
                }
                if(no_warrior){
                    cout << "NONE" << endl;
                }
            }
        }
        else if(command == "Battle"){
            file >> noble1;
            file >> noble2;
            Noble* Noble1 = findNoble(pstNoble, noble1);
            Noble* Noble2 = findNoble(pstNoble, noble2);
            //check if both two does not exist
            if(Noble1 == nullptr || Noble2 == nullptr){
                cerr << "Both" << noble1 << "and" << noble2 << "does not exist" << endl;
            }
            //check if one does not exist
            else if(Noble1 == nullptr){
                cerr << noble1 << "does not exist" << endl;
            }
            //check if the other one does not exist
            else if(Noble2 == nullptr){
                cerr << noble2 << "does not exist" << endl;
            }
            else{
                Noble1->battle(*Noble2);
            }
        }
        else if(command == "Clear"){
            for(size_t i = 0; i < pstWarrior.size(); ++i){
                //delete Warrior on the heap and set the pointer to nullptr
                delete pstWarrior[i];
                pstWarrior[i] = nullptr;
            }
            for(size_t i = 0; i < pstNoble.size(); ++i){
                //delete Warrior on the heap and set the pointer to nullptr
                delete pstNoble[i];
                pstNoble[i] = nullptr;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    ifstream file("nobleWarriors-20S.txt");
    if(!file){
        cerr << "could not open the file" << endl;
        exit(1);
    }
    processFile(file);
    file.close();
    return 0;
}
