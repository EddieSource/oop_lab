//
//  Polynomial.cpp
//  hw8
//
//  Created by Eddie Zhu on 2020/4/26.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <stdio.h>
#include "polynomial.h"

using namespace std;


struct Polynomial::Node {
    Node(int coef = 0, Node* next = nullptr) : coef(coef), next(next) {}
    int coef;
    Node* next;
};


//default constructor
Polynomial::Polynomial () : degree(0) {
    headPtr = new Node();
    headPtr->next = new Node (0, headPtr->next);
}


Polynomial::Polynomial (const vector<int>& aVector) : degree(-1) {
    headPtr = new Node();
    for (size_t i = 0; i < aVector.size(); ++i) {
        degree += 1;
        headPtr->next = new Node(aVector[i], headPtr->next);
    }
    cleanup();
}


//copy constructor
Polynomial::Polynomial(const Polynomial& aPol){
    headPtr = new Node();
    degree = aPol.degree;
    
    
    Node* pointer1 = headPtr;
    Node* pointer2 = aPol.headPtr->next;
    while(pointer2){
        pointer1->next = new Node(pointer2->coef, nullptr);
        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
    }
    
}


//destructor
Polynomial::~Polynomial(){
    Node* curr = headPtr->next;
    while (curr) {
        Node* victim = curr;
        headPtr->next = curr->next;
        curr = curr->next;
        delete victim;
        victim = nullptr;
    }
}


//assigning operator
Polynomial& Polynomial::operator= (const Polynomial& aPol) {
    Node* curr = headPtr->next;
    while (curr) {
        Node* victim = curr;
        headPtr->next = curr->next;
        curr = curr->next;
        delete victim;
        victim = nullptr;
    }
    degree = aPol.degree;
    Node* pointer1 = headPtr;
    Node* pointer2 = aPol.headPtr->next;
    while(pointer2){
        pointer1->next = new Node(pointer2->coef, nullptr);
        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
    }
    return *this;
}


Polynomial& Polynomial::operator+= (const Polynomial& aPol) {
    Node* pre_pointer1 = headPtr;
    Node* pointer1 = headPtr->next;
    Node* pointer2 = aPol.headPtr->next;
    while (pointer1 && pointer2) {
        pointer1->coef = pointer1->coef + pointer2->coef;
        pre_pointer1 = pre_pointer1->next;
        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
    }
    if (pointer1 == nullptr) {
        while (pointer2) {
            pre_pointer1->next = new Node(pointer2->coef, nullptr);
            pre_pointer1 = pre_pointer1->next;
            pointer2 = pointer2->next;
            degree += 1;
        }
    }
    cleanup();
    return *this;
}


int Polynomial::evaluate (int x) {
    int result = 0;
    int count = 0;
    Node* curr = headPtr->next;
    while(curr) {
        if (count == 0) {
            result += curr->coef * 1;
        }
        else if (count == 1) {
            result += curr->coef * x;
        }
        else {
            for (int i = 0; i < count - 1; ++i) {
                x = x * x;
            }
            result += curr->coef * x;
        }
        count += 1;
        curr = curr->next;
    }
    return result;
}


void Polynomial::cleanup_helper(Node* curr1, Node* curr2){
    while(curr2->next != nullptr) {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if (curr2->coef == 0 && degree >= 1) {
        degree -= 1;
        delete curr2;
        curr2 = nullptr;
        curr1->next = nullptr;
        curr1 = headPtr;
        curr2 = headPtr->next;
        cleanup_helper(curr1, curr2);
    }
    else {
        return;
    }
}


void Polynomial::cleanup(){
    cleanup_helper(headPtr, headPtr->next);
}


void Polynomial::reverselyPrinting(ostream& os, Node* curr, int count) const {
    if(curr == nullptr){
        return;
    }
    else {
        reverselyPrinting(os, curr->next, count + 1);
        if (curr->coef == 0) return;
        //deal with +;
        if (count != degree) os << " + ";
        //deal with the most special case
        if (curr->coef == 1 &&  count == 0) os << "1";
        //other cases
        else {
            //deal with coef
            if (curr->coef != 1) os << curr->coef;
            //deal with x
            if (count == 0) {}
            else if (count == 1) os << "x";
            else os << "x^" << count;
        }
    }
}


ostream& operator<< (ostream& os, const Polynomial& aPolynomial) {
    if (aPolynomial.degree == 0 && aPolynomial.headPtr->next->coef == 0) {
        os << "0";
        return os;
    }
    aPolynomial.reverselyPrinting(os, aPolynomial.headPtr->next, 0);
    return os;
}


bool operator== (const Polynomial& lhs, const Polynomial& rhs) {
    Polynomial::Node* pointer1 = lhs.headPtr->next;
    Polynomial::Node* pointer2 = rhs.headPtr->next;
    while (pointer1 && pointer2) {
        if (pointer1->coef != pointer2->coef) {
            return false;
        }
        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
    }
    if (pointer1 || pointer2) {
        return false;
    }
    return true;
}
  

Polynomial operator+ (const Polynomial& rhs, const Polynomial& lhs) {
    Polynomial result(rhs);
    result += lhs;
    return result;
}


bool operator!= (const Polynomial& lhs, const Polynomial& rhs) {
    return !(lhs == rhs);
}
        

