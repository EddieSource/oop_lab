//
//  Polynomial.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/4/26.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h


#include <vector>
#include <string>
#include <iostream>

class Polynomial {
    friend std::ostream& operator<< (std::ostream& os, const Polynomial& aPolynomial);
    friend bool operator== (const Polynomial& lhs, const Polynomial& rhs);
    
public:
    struct Node;
    //default constructor
    Polynomial ();
    Polynomial (const std::vector<int>& aVector);
    //copy constructor
    Polynomial(const Polynomial& aPol);
    //destructor
    ~Polynomial();
    //assigning operator
    Polynomial& operator= (const Polynomial& aPol);
    Polynomial& operator+= (const Polynomial& aPol);
    int evaluate (int x);
    void cleanup_helper(Node* curr1, Node* curr2);
    void cleanup();
    void reverselyPrinting(std::ostream& os, Node* curr, int count) const;
private:
    Node* headPtr;
    int degree;
};

Polynomial operator+ (const Polynomial& rhs, const Polynomial& lhs);
bool operator!= (const Polynomial& lhs, const Polynomial& rhs); 



#endif /* Polynomial_h */
