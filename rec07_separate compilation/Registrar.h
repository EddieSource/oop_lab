//
//  Registrar.h
//  cs2124
//
//  Created by Eddie Zhu on 2020/3/18.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#ifndef Registrar_h
#define Registrar_h

#include <iostream>
#include <string>
#include <vector>


namespace BrooklynPoly {
    class Registrar {
        friend std::ostream& operator<<(std::ostream& os, const Registrar& rhs);
    public:
        Registrar();
        bool addCourse(const std::string& courseName);
        bool addStudent(const std::string& studentName);
        bool enrollStudentInCourse(const std::string& studentName,
                                   const std::string& courseName);
        bool cancelCourse(const std::string& courseName);
        void purge();

    private:
        size_t findStudent(const std::string& studentName) const;
        size_t findCourse(const std::string& courseName) const;

        std::vector<Course*> courses;
        std::vector<Student*> students;
    };
}


#endif /* Registrar_h */
