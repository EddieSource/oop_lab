//
//  Lord.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Lord_h
#define Lord_h

#include "Noble.h"
#include <string>
#include <vector>


namespace WarriorCraft{

    class Noble;
    class Protector;

    class Lord : public Noble{
    public:
        Lord(const std::string& name);
        void defend();
        double reduceStrength(double percent);
        bool hires(Protector& aProtector);
        //Find current Protector
        size_t findProtector(Protector& aProtector);
        bool fires(Protector& aProtector);
        size_t armySize();
    private:
        std::vector<Protector*> army;
    };

}


#endif /* Lord_h */
