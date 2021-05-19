//
//  Noble.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Noble_h
#define Noble_h

#include <string>

namespace WarriorCraft {

    class Noble{
    public:
        Noble(const std::string& name, double strength = 0);
        virtual void defend() = 0;
        virtual double reduceStrength(double percent) = 0;
        virtual void battle(Noble& rhs);
        std::string getName() const;
        double getStrength() const;
        void setStrength(int aStrength);
        bool ifDead() const;
    private:
        std::string name;
        double strength;
        bool dead;
    };


}

#endif /* Noble_h */
