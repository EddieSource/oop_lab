//
//  Protector.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/4/15.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Protector_h
#define Protector_h

#include <string>
#include <vector>
#include <iostream>



namespace WarriorCraft {

    class Lord;

    class Protector {
    public:
        Protector(const std::string& name, double strength);
        virtual void defend() = 0;
        
        bool quit();
        
        std::string getName() const;
        double getStrength() const;
        void setStrength(int aStrength);
        Lord* getEmployer () const;
        void setEmployer(Lord* aEmployer);
        bool ifDead() const;
        void setDead(bool ifDead);
                         
    private:
        std::string name;
        double strength;
        Lord* employer;
        bool dead;
    };

}


#endif /* Protector_h */
