//
//  Warrior.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Warrior_h
#define Warrior_h

#include <string>
#include "Protector.h"

namespace WarriorCraft {

    class Warrior : public Protector{
    public:
        Warrior(const std::string& name, double strength);
    };

}

#endif /* Warrior_h */
