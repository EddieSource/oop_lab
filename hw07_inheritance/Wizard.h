//
//  Wizard.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Wizard_h
#define Wizard_h

#include "Protector.h"
#include <string>

namespace WarriorCraft{

    class Wizard : public Protector{
    public:
        Wizard(const std::string& name, double strength);
        void defend();
    };


}


#endif /* Wizard_h */
