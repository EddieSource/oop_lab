//
//  main.cpp
//  cs2124-hw2
//
//  Created by Eddie Zhu on 2020/2/9.
//  Copyright © 2020 EddieZ. All rights reserved.
//

//  This is a game of medieval times. Our world is filled with warriors. Naturally what warriors like to do is fight. To the death. So we happily let them.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


struct Warrior {
    string name;
    int strength;
};


void addWarrior (vector<Warrior>& warriors, const string& word, int strength) {
    //add warriors to the warrior vector
    Warrior aWarrior {word, strength};
    warriors.push_back(aWarrior);
}


void battle(Warrior& aWarrior, Warrior& bWarrior){
    cout << aWarrior.name << " battles "<< bWarrior.name << endl;
    //if both dead
    if(aWarrior.strength == 0 && bWarrior.strength == 0){
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }
    //if one is dead
    else if(aWarrior.strength > bWarrior.strength && bWarrior.strength == 0){
        cout << "He's dead, " << aWarrior.name << endl;
    }
    else if(aWarrior.strength > bWarrior.strength){
        aWarrior.strength = aWarrior.strength - bWarrior.strength;
        bWarrior.strength = 0;
        cout << aWarrior.name << " defeats " << bWarrior.name << endl;
    }
    //if the other one is dead
    else if(aWarrior.strength < bWarrior.strength && aWarrior.strength == 0){
        cout << "He's dead, " << bWarrior.name << endl; ;
    }
    else if(aWarrior.strength < bWarrior.strength){
        bWarrior.strength = bWarrior.strength - aWarrior.strength;
        aWarrior.strength = 0;
        cout << bWarrior.name << " defeats " << aWarrior.name << endl;
    }
    //if aWarrior.strength = bWarrior.strength
    else {
        aWarrior.strength = 0;
        bWarrior.strength = 0;
        cout << "Mutual Annihilation: Arthur and Lancelot die at each other's hands" << endl; ;
    }
        
}


void status(const vector<Warrior>& warriors) {
    //tell the status of all warriors in the warriors vector
    cout << "There are: " << warriors.size() << " warriors" << endl;
    for(const Warrior& aWarrior : warriors){
        cout << "Warriors: " << aWarrior.name << ", strength: " << aWarrior.strength << endl;
    }
}


void processCommand(ifstream& file){
    vector<Warrior> warriors;   //create a warrior vector to wait for the new warriors to add in
    string command; //file stream will first be read into this string
    string warrior_name;
    int strength;
    string warrior1_name;
    string warrior2_name;
    
    while(file >> command){
        if(command == "Status"){
            //status command line
            status(warriors);
        }
        else if(command == "Warrior"){
            //add warrior to the warriors vector
            file >> warrior_name;
            file >> strength;
            addWarrior(warriors, warrior_name, strength);
        }
        else if(command == "Battle"){
            //start a battle between two warriors
            file >> warrior1_name;
            file >> warrior2_name;
            for(Warrior& aWarrior : warriors){
                if(warrior1_name == aWarrior.name){
                    for(Warrior& bWarrior : warriors){
                        if(warrior2_name == bWarrior.name){
                            battle(aWarrior, bWarrior);
                        }
                    }
                }
            }
        }
        
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    ifstream file("warriors.txt");
    
    if (!file) {
        cerr << "could not open the file.\n";
        exit(1);
    }
    
    processCommand(file);

    return 0;
}
