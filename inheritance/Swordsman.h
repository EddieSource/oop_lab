//
//  Swordsman.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Swordsman_h
#define Swordsman_h

#include "Warrior.h"
#include <string>

namespace WarriorCraft {
    
    class Swordsman : public Warrior{
    public:
        Swordsman(const std::string& name, double strength);
        void defend();
    };

}


#endif /* Swordsman_h */
