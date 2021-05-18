//
//  Rational.cpp
//  cs2124-lec-8
//
//  Created by Eddie Zhu on 2020/3/28.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <stdio.h>
#include "Rational.h"
#include <string>
#include <sstream>

using namespace std;

namespace CS2124 {
    int Rational::greatestCommonDivisor(int x, int y) {
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }

    ostream& operator<< (ostream& os, const Rational& aRational){
        os << aRational.numerator << "/" << aRational.denominator;
        return os;
    }
        
    istream& operator>> (istream& is, Rational& aRational){
        string input;
        is >> input;
        size_t ind = input.find('/');
        string a = input.substr(0, ind);
        string b = input.substr(ind + 1);
        stringstream sa(a);
        stringstream sb(b);
        int aNum = 0;
        int bNum = 0;
        sa >> aNum;
        sb >> bNum;
        int d = aRational.greatestCommonDivisor(aNum, bNum);
        aRational.numerator = aNum/d;
        aRational.denominator = bNum/d;
        
        return is;
    }
        
    Rational::Rational(int num, int den):numerator(num), denominator(den){
        int d = greatestCommonDivisor(num, den);
        numerator = num/d;
        denominator = den/d;
    }

    Rational& Rational::operator+= (const Rational& rhs) {
        numerator = numerator * rhs.denominator + rhs.numerator * denominator;
        denominator = denominator * rhs.denominator;
        int d = greatestCommonDivisor(numerator, denominator);
        numerator /= d;
        denominator /= d;
        return *this;
    }

    //not a friend
    Rational operator+ (const Rational& lhs, const Rational& rhs) {
        Rational result(lhs);
        result += rhs;
        return result;
    }
        
    bool operator== (const Rational& lhs, const Rational& rhs){
        return (lhs.numerator == rhs.numerator) && (lhs.denominator == rhs.denominator);
    }
        
    bool operator!= (const Rational& lhs, const Rational& rhs){
        return !(lhs == rhs);
    }
    //non member
        
    //pre-fix
    Rational& Rational::operator++ () {
        numerator += denominator;
        return *this;
    }

    //post-fix
    Rational Rational::operator++(int dummy){
        Rational original(*this);
        numerator += denominator;
        return original;
    }

        
    Rational& operator--(Rational& aRational){
        aRational = aRational - 1;
        return aRational;
    }
        
    Rational operator--(Rational& aRational, int dummy){
        Rational original(aRational);
        aRational = aRational - 1;
        return original;
    }
        
    bool operator< (const Rational& lhs, const Rational& rhs){
        return lhs.numerator/lhs.denominator < rhs.numerator/rhs.denominator;
    }

    bool operator<= (const Rational& lhs, const Rational& rhs){
        return lhs == rhs || lhs < rhs;
    }

    bool operator> (const Rational& lhs, const Rational& rhs){
        return !(lhs <= rhs);
    }

    bool operator>= (const Rational& lhs, const Rational& rhs){
        return(lhs > rhs || lhs == rhs);
    }
        
    Rational::operator bool() const {
        return denominator != 0;
    }
}






