//
//  Archer.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Archer_h
#define Archer_h

#include "Warrior.h"
#include <string>

namespace WarriorCraft{

    class Archer : public Warrior{
    public:
        Archer(const std::string& name, double strength);
        void defend();
    };


}

#endif /* Archer_h */
