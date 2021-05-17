//
//  Noble.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/3/21.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Noble_h
#define Noble_h

#include <iostream>
#include <vector>
#include <string>



namespace WarriorCraft {
    
    class Warrior;

    class Noble{
        friend std::ostream& operator << (std::ostream& os, const Noble& aNoble);
    public:
        Noble(const std::string& name);
        const std::string& get_name() const;
        double get_strength() const;
        void set_strength(double aStrength);
        bool hire(WarriorCraft::Warrior& aWarrior);
        bool delete_warrior(WarriorCraft::Warrior& aWarrior);
        bool fire(WarriorCraft::Warrior& aWarrior);
        void battle(Noble& aNoble);
        
    private:
        std::string name;
        std::vector<WarriorCraft::Warrior*> army;
        double strength;
        bool dead;
    };

}



#endif /* Noble_h */
