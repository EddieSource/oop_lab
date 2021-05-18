//
//  Rational.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/3/28.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Rational_h
#define Rational_h

#include <iostream>
#include <string>


namespace CS2124{
    class Rational;

    Rational operator+ (const Rational& lhs, const Rational& rhs);    //not a friend
    bool operator!= (const Rational& lhs, const Rational& rhs); //non friend
    //Rational& operator-- ();
    //Rational operator-- (int dummy);
    bool operator<= (const Rational& lfs, const Rational& rhs);
    bool operator> (const Rational& lfs, const Rational& rhs);
    bool operator>= (const Rational& lfs, const Rational& rhs);
    Rational& operator--(Rational& aRational);
    Rational operator--(Rational& aRational, int dummy);

    class Rational {
        friend std::ostream& operator<< (std::ostream& os, const Rational& aRational);
        friend std::istream& operator>> (std::istream& is, Rational& aRational);
        friend bool operator== (const Rational& lfs, const Rational& rhs);
        friend bool operator< (const Rational& lfs, const Rational& rhs);

    public:
        
        Rational (int num = 0, int den = 1);
        
        Rational& operator+= (const Rational& rhs);
        
        //pre-fix
        Rational& operator++ ();
        
        //post-fix
        Rational operator++ (int dummy);
        
        operator bool() const;
        
    private:
        int greatestCommonDivisor(int x, int y);
        int numerator;
        int denominator;
    };
}


#endif /* Rational_h */
