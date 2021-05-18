//
//  Course.cpp
//  cs2124-rec-7
//
//  Created by Eddie Zhu on 2020/3/18.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

#include "Course.h"
#include "Student.h"

using namespace std;

namespace BrooklynPoly {
    ostream& operator<<(ostream& os, const Course& rhs) {
    os << rhs.name << ": ";
    if(rhs.students.size() == 0){
        os << "No Students";
    }
    else{
        for (size_t i = 0; i < rhs.students.size(); ++i) {
            if (rhs.students[i] != nullptr) {
                os << rhs.students[i]->getName() << " ";
            }
        }
    }
    return os;
    }

    Course::Course(const string& courseName) : name(courseName){}
    const string& Course::getName() const {return name; }
    bool Course::addStudent(Student* ptS) {
            students.push_back(ptS);
            return true;
    }
        
    void Course::removeStudentsFromCourse() {
        for (size_t i = 0; i < students.size(); ++i) {
            students[i] = nullptr;
        }
    }
}


