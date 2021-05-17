//
//  Warrior.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/3/21.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Warrior_h
#define Warrior_h

#include <iostream>
#include <string>

namespace WarriorCraft {
    class Noble;
    
    class Warrior{
        
        friend std::ostream& operator << (std::ostream& os, const Warrior& aWarrior);
        
        //Warriors start out with a specified name and strength.
    public:
        Warrior(const std::string& name, double strength);
        
        double get_strength() const;
        
        void set_strength(double aStrength);
        
        const std::string& get_name() const;
        
        void set_employer(WarriorCraft::Noble& aNoble);
        void detach_employer();
        WarriorCraft::Noble* get_employer() const;
        
        void runaway();
        
    private:
        std::string name;
        double strength;
        WarriorCraft::Noble* employer;
        bool dead;
        };
}


#endif /* Warrior_h */
