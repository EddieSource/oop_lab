//
//  main.cpp
//  cs2124-hw3
//
//  Created by Eddie Zhu on 2020/2/16.
//  Copyright © 2020 EddieZ. All rights reserved.
//

//  This is a game of medieval times. Our world is filled with warriors. Naturally what warriors like to do is fight. To the death. So we happily let them.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


class Warrior {
    friend ostream& operator<<(ostream& os, const Warrior& aWarrior);
public:
//    Warrior() {};
    Warrior(const string& aWarName, const string& aWeaName, int aWeaStrength):waName(aWarName),waWeapon(aWeaName, aWeaStrength) {};
    string getWaName() const{
        return waName;
    }
    string getWeName() const{
        //get the warrior's weapon's name
        return waWeapon.getName();
    }
    int getWeStrn() const{
        //get the warrior's weapon's strength
        return waWeapon.getStrn();
    }
    void setWeStrn(int aStrength) {
        //get the warrior's weapon's strength
        waWeapon.setStrng(aStrength);
    }
private:
    class Weapon {
        friend ostream& operator<<(ostream& os, const Warrior& aWarrior);
    public:
//        Weapon() {};
        Weapon(const string& aWeaName,int aWeaStrength):weName(aWeaName),WeStrn(aWeaStrength){};
        string getName() const{
            //get the weapon's name
            return weName;
        }
        int getStrn() const{
            //get the weapon's strength
            return WeStrn;
        }
        void setStrng(int aStrength) {
            //set the weapon's strength to aStrength
            WeStrn = aStrength;
        }
    private:
        string weName;
        int WeStrn;
    };
    string waName;
    Weapon waWeapon;
};


class Battle {
public:
//    Battle(){};
    Battle(Warrior& warrior1, Warrior& warrior2) : warr1(warrior1),warr2(warrior2){};
    void printResult(){
        cout << warr1.getWaName() << " battles "<< warr2.getWaName() << endl;

        //if both dead
        if(warr1.getWeStrn() == 0 && warr2.getWeStrn() == 0){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        //if one is dead
        else if(warr1.getWeStrn() > warr2.getWeStrn() && warr2.getWeStrn() == 0){
            cout << "He's dead, " << warr1.getWaName() << endl;
        }
        else if(warr1.getWeStrn() > warr2.getWeStrn()){
            warr1.setWeStrn(warr1.getWeStrn()-warr2.getWeStrn());
            warr2.setWeStrn(0);
            cout << warr1.getWaName() << " defeats " << warr2.getWaName() << endl;
        }
        //if the other one is dead
        else if(warr1.getWeStrn() < warr2.getWeStrn() && warr1.getWeStrn() == 0){
            cout << "He's dead, " << warr2.getWaName() << endl; ;
        }
        else if(warr1.getWeStrn() < warr2.getWeStrn()){
            warr2.setWeStrn(warr2.getWeStrn()-warr1.getWeStrn());
            warr1.setWeStrn(0);
            cout << warr2.getWaName()<< " defeats " << warr2.getWaName() << endl;
        }
        //if aWarrior.strength == bWarrior.strength
        else {
            warr1.setWeStrn(0);
            warr2.setWeStrn(0);
            cout << "Mutual Annihilation: Arthur and Lancelot die at each other's hands" << endl; ;
        }
    }
private:
    Warrior& warr1;
    Warrior& warr2;
};


class Status{
public:
    //create a new status
    Status(vector<Warrior>& somewarriors) : warriors(somewarriors){};
    void show() const {
        cout << "There are: " << warriors.size() << " warriors" << endl;
        for(const Warrior& aWarrior : warriors){
            cout << aWarrior << endl;
        }
    }
private:
    vector<Warrior>& warriors;
};


ostream& operator<<(ostream& os, const Warrior& aWarrior){
    os << "Warrior: " << aWarrior.waName;
    os << ", weapon: " << aWarrior.waWeapon.weName << ", " << aWarrior.waWeapon.WeStrn;
    return os;
}


Warrior& findWarr(vector<Warrior>& warriors, string& name){
    //find warriors by the name and return it
    for(Warrior& warrior : warriors){
        if(name == warrior.getWaName()){
            return warrior;
            break;
            }
        }
    cerr << "could not find any warriors";
    exit(1);
    }


void processCommand(ifstream& file){
    vector<Warrior> warriors;   //create a warrior vector to wait for the new warriors to add in
    string command; //file stream will first be read into this string
    string warrior_name;
    string weapon_name;
    int weapon_strength;
    string warrior1_name;
    string warrior2_name;
    
    while(file >> command){
        if(command == "Status"){
            //status command line
            Status new_status = Status(warriors);
            new_status.show();
        }
        else if(command == "Warrior"){
            //add warrior to the warriors vector
            file >> warrior_name;
            file >> weapon_name;
            file >> weapon_strength;
            Warrior aWarrior = Warrior(warrior_name, weapon_name, weapon_strength);
            warriors.push_back(aWarrior);
        }
        else if(command == "Battle"){
            //start a battle between two warriors
            file >> warrior1_name;
            file >> warrior2_name;
            Warrior& warrior1 = findWarr(warriors, warrior1_name);
            Warrior& warrior2 = findWarr(warriors, warrior2_name);
            Battle aBattle = Battle(warrior1, warrior2);
            aBattle.printResult();
        }
    }
    file.close();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream file("warriors2.0.txt");
    if (!file) {
        cerr << "could not open the file.\n";
        exit(1);
    }
    processCommand(file);
    return 0;
}

