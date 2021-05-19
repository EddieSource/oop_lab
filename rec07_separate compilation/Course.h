//
//  Course.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/3/18.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Course_h
#define Course_h

#include <iostream>
#include <string>
#include <vector>


namespace BrooklynPoly {

    class Student;

    class Course {
        friend std::ostream& operator<<(std::ostream& os, const Course& rhs);
    public:
        // Course methods needed by Registrar
        Course(const std::string& courseName);
        const std::string& getName() const;
        bool addStudent(Student* ptS);
        //disconnect all the students from the to-be-canceled course
        void removeStudentsFromCourse();
    private:
        std::string name;
        std::vector<Student*> students;
    };

}


#endif /* Course_h */
