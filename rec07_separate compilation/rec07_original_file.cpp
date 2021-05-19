/*
  rec07
  Starter Code for required functionality
  Yes, you may add other methods.
 
  Eddie Zhu
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;

class Course {
    friend ostream& operator<<(ostream& os, const Course& rhs);
public:
    // Course methods needed by Registrar
    Course(const string& courseName);
    const string& getName() const;
    bool addStudent(Student* ptS);
    //disconnect all the students from the to-be-canceled course
    void removeStudentsFromCourse();
private:
    string name;
    vector<Student*> students;
};

class Student {
    friend ostream& operator<<(ostream& os, const Student& rhs);
public:
    // Student methods needed by Registrar
    Student(const string& name);
    const string& getName() const;
    
    bool addCourse(Course* ptC);

    // Student method needed by Course
    void removedFromCourse(Course* ptC);

private:
    string name;
    vector<Course*> courses;
};

class Registrar {
    friend ostream& operator<<(ostream& os, const Registrar& rhs);
public:
    Registrar();
    bool addCourse(const string& courseName);
    bool addStudent(const string& studentName);
    bool enrollStudentInCourse(const string& studentName,
                               const string& courseName);
    bool cancelCourse(const string& courseName);
    void purge();

private:
    size_t findStudent(const string& studentName) const;
    size_t findCourse(const string& courseName) const;

    vector<Course*> courses;
    vector<Student*> students;
};


int main() {

    Registrar registrar;

    cout << "No courses or students added yet\n";
    cout << registrar << endl;
     
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    cout << registrar << endl;

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    cout << registrar << endl;

    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout << "Should fail, i.e. do nothing, "
         << "since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    cout << registrar << endl;

    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    cout << registrar << endl;
   
    /*
    // [OPTIONAL - do later if time]
    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
    registrar.changeStudentName("FritzTheCat", "MightyMouse");
    cout << registrar << endl;

    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
    cout << registrar << endl;

    cout << "RemoveStudent FritzTheCat\n";
    registrar.removeStudent("FritzTheCat");
    cout << registrar << endl;
    */

    cout << "Purge for start of next semester\n";
    registrar.purge();
    cout << registrar << endl;
}

        
//course:
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
    
    
//student:
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
    

//registrar:
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

    

        
  
