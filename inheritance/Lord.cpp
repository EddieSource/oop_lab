//
//  Lord.cpp
//  cs2124-hw7
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <stdio.h>
#include "Lord.h"
#include "Noble.h"
#include "Protector.h"
#include <string>
#include <vector>

using namespace std;

namespace WarriorCraft{

    Lord::Lord(const string& name) : Noble(name, 0){}
    void Lord::defend() {
        if(!ifDead()){
            for (size_t i = 0; i < army.size(); ++i) {
                army[i]->defend();
            }
        }
    }
    double Lord::reduceStrength(double percent) {
        if(ifDead()){
            //if noble is dead
            for(size_t i = 0; i < army.size(); ++i){
                if(army[i] != nullptr){
                    army[i]->setStrength(0);
                    army[i]->setDead(true);
                }
            }
        }
        else {
            //if noble wins
            for(size_t i = 0; i < army.size(); ++i){
                if(army[i] != nullptr){
                    army[i]->setStrength(percent * army[i]->getStrength());
                }
            }
        }
        return percent * getStrength();
    }

    bool Lord::hires(Protector& aProtector) {
        if(aProtector.getEmployer() != nullptr || ifDead() || aProtector.ifDead()){
            return false;
        }
        //update the employing status
        aProtector.setEmployer(this);
        //add the employer to the army
        army.push_back(&aProtector);
        setStrength(getStrength() + aProtector.getStrength());
        return true;
    }
        //Find current Protector
    size_t Lord::findProtector(Protector& aProtector){
        for(size_t i = 0; i < army.size(); ++i){
            if(army[i] == &aProtector){
                return i;
            }
        }
        return army.size();
    }
    bool Lord::fires(Protector& aProtector){
        size_t index = findProtector(aProtector);
        if(index == army.size()){
            return false;
        }
        //fire him
        army[index]->setEmployer(nullptr);
        army[index] = nullptr;
        return true;
        //update the employing
    }
    size_t Lord::armySize(){
        return army.size();
    }


}


