//
//  Registrar.cpp
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
#include "Registrar.h"
using namespace std;


namespace BrooklynPoly {
    ostream& operator<<(ostream& os, const Registrar& rhs) {
        os << "Registrar's Report" << endl;
        os << "Courses: " << endl;
        //print courses
        for (size_t i = 0; i < rhs.courses.size(); ++i){
            if(rhs.courses[i] != nullptr){
                os << *rhs.courses[i] << endl;
            }
        }
        //print students
        os << "Students: " << endl;
        for (size_t i = 0; i < rhs.students.size(); ++i){
            if(rhs.students[i] != nullptr) {
                os << *rhs.students[i] << endl;
            }
        }
        return os;
    }

    Registrar::Registrar(){};

    bool Registrar::addCourse(const string& courseName) {
        Course* ptC = new Course(courseName);
        courses.push_back(ptC);
        return true;
    }
    bool Registrar::addStudent(const string& studentName){
        Student* ptS = new Student(studentName);
        students.push_back(ptS);
        return true;
    }
    bool Registrar::enrollStudentInCourse(const string& studentName,
                                const string& courseName) {
        size_t courseInd = findCourse(courseName);
        size_t studentInd = findStudent(studentName);
        if (courseInd != -1 && studentInd != -1) {
            courses[courseInd]->addStudent(students[studentInd]);   //include student to course
            students[studentInd]->addCourse(courses[courseInd]);    //include course to student
            return true;
        }
        else {
        //an error occured when neither one of the courses nor students exists
    //        cerr << "non-exist error" << endl;
            return false;
        }
    }
        

    bool Registrar::cancelCourse(const string& courseName) {
        size_t courseInd = findCourse(courseName);
        if (courseInd != -1) {
            courses[courseInd]->removeStudentsFromCourse();
            for (size_t i = 0; i < students.size(); ++i) {
                students[i]->removedFromCourse(courses[courseInd]);
            }
            //set the courses in the course to null ptr
            courses[courseInd] = nullptr;
            return true;
        }
        else {
            //the course does not exist
            return false;
        }
    }
        
        
    //private method
    size_t Registrar::findStudent(const string& studentName) const {
        for(size_t i = 0; i < students.size(); ++i){
            if(students[i] != nullptr && students[i]->getName() == studentName){
                return i;
            }
        }
        return -1;
    }
    size_t Registrar::findCourse(const string& courseName) const {
        for(size_t i = 0; i < courses.size(); ++i){
            if(courses[i] != nullptr && courses[i]->getName() == courseName){
                return i;
            }
        }
        return -1;
    }
        
    void Registrar::purge() {
        courses.clear();
        students.clear();
    }


}


