//
//  Student.cpp
//  cs2124-rec-7
//
//  Created by Eddie Zhu on 2020/3/18.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

#include "Student.h"
#include "Course.h"

using namespace std;

namespace BrooklynPoly {
    ostream& operator<<(ostream& os, const Student& rhs){
        os << rhs.name << ": ";
        if(rhs.courses.size() == 0) {
            os << "No Courses";
        }
        else {
            for (size_t i = 0; i < rhs.courses.size(); ++i) {
                if(rhs.courses[i] != nullptr){
                    os << rhs.courses[i]->getName() << " ";
                }
            }
        }
        return os;
    }

    Student::Student(const string& name):name(name){}
    const string& Student::getName() const {return name; }
    bool Student::addCourse(Course* ptC) {
        courses.push_back(ptC);
        return true;
    }
        

    void Student::removedFromCourse(Course* ptC) {
        for (size_t i = 0; i < courses.size(); ++i){
            // set the course in the courses to nullptr
            if (courses[i] == ptC) {
                courses[i] = nullptr;
            }
        }
    }
        
}
