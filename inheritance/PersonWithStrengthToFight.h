//
//  PersonWithStrengthToFight.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef PersonWithStrengthToFight_h
#define PersonWithStrengthToFight_h

#include <string>
#include "Noble.h"

namespace WarriorCraft {



class Noble;

    class PersonWithStrengthToFight : public Noble{
    public:
        PersonWithStrengthToFight(const std::string& name, double strength);
        void defend();
        double reduceStrength(double percent);
    };

}




#endif /* PersonWithStrengthToFight_h */
