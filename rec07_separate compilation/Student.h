//
//  Student.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/3/18.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly {
    class Course;

    class Student {
        friend std::ostream& operator<<(std::ostream& os, const Student& rhs);
    public:
        // Student methods needed by Registrar
        Student(const std::string& name);
        const std::string& getName() const;
        
        bool addCourse(Course* ptC);

        // Student method needed by Course
        void removedFromCourse(Course* ptC);

    private:
        std::string name;
        std::vector<Course*> courses;
    };
}




#endif /* Student_h */
