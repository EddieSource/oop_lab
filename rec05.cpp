//
//  main.cpp
//  cs2124-lab-5
//
//  Created by Eddie Zhu on 2020/2/28.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LabWorker;
class StudentRecord;
class Section;

class Section {
    friend ostream& operator << (ostream& os, const Section& aSec){
        os << "Section: " << aSec.name << aSec.time;
        if (aSec.records.size() == 0) {
            os << "None" << endl;
        }
        else {
            os << endl;
            for(size_t i = 0; i < aSec.records.size(); ++i){
                os << *(aSec.records[i]);
                os << endl;
            }
        }
        
        return os;
    }
public:
    Section(const string& name, const string& day, unsigned hour):
        name(name), time(day, hour){}
    
    Section(const Section& yetAnotherSection):
        name(yetAnotherSection.name), time(yetAnotherSection.time){  //should pass by reference
            for(size_t i = 0; i < yetAnotherSection.records.size(); ++i){
                records.push_back(new StudentRecord(*(yetAnotherSection.records[i])));
            }
    }
    
    void addStudent(const string& name){
        StudentRecord* pts = new StudentRecord(name);
        records.push_back(pts);
    }
    
    void setGrade(const string& studentName, int grade, int week){
        for(size_t i = 0; i < records.size(); ++i){
            if(records[i]->getName() == studentName){
                records[i]->setGrade(grade, week);
            }
        }
    }
    
    ~Section(){
        for(size_t i = 0; i < records.size(); ++i){
            delete records[i];
            records[i] = nullptr;
        }
    }
    
private:
    class StudentRecord {
        friend ostream& operator << (ostream& os, const StudentRecord& aRecord) {
            os << "Name: " << aRecord.name << ", ";
            for(size_t i = 0; i < aRecord.grades.size(); ++i){
                os << aRecord.grades[i] << " ";
            }
            return os;
        }
    public:
        StudentRecord(const string& name):name(name),grades(14, -1){}
        string getName() const {
            return name;
        }
        void setGrade(int grade, int week){
            for(int i = 0; i < 14; ++i){
                if(i == week - 1){
                    grades[i] = grade;
                }
            }
        }
    private:
        string name;
        vector<int> grades;
    };
    
    
    class TimeSlot{
        friend ostream& operator << (ostream& os, const TimeSlot& aTime){
            os << ", Time slot: [Day: "
            << aTime.day << ", Start time: ";
            if(aTime.hour < 12){
                os << aTime.hour << " am], " << "Students: ";
            }
            else if(aTime.hour > 12){
                os << (aTime.hour - 12) << " pm], " << "Students: ";
            }
            else {
                os << aTime.hour << " pm], " << "Students: ";
            }
            return os;
        }
    public:
        TimeSlot(const string& day, int hour) : day(day), hour(hour){}
        void setDay(const string& aDay){
            day = aDay;
        }
        void setHour(unsigned aHour){
            hour = aHour;
        }
    private:
        string day;
        unsigned hour;
    };
    vector<StudentRecord*> records;
    string name;
    TimeSlot time;
};


class LabWorker {
    friend ostream& operator << (ostream& os, const LabWorker& aLabWorker){
        if(aLabWorker.work == nullptr){
            os << aLabWorker.name << " does not have a section" << endl;
        }
        else {
            os << aLabWorker.name << " has " << *aLabWorker.work << endl;
        }
            
        return os;
    }
public:
    LabWorker(const string& name): name(name){}
    void addGrade(const string& studentName, int grade, int week){
        work->setGrade(studentName, grade, week);
    }
    void addSection(Section& aSection){
        work = &aSection;
    }


private:
    string name;
    Section* work;
};





// Test code
void doNothing(Section sec) {
    cout << sec << endl;;
}

int main() {

    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe("Moe");
    cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection(secA2);
    cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection(secB3);
    cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works properly, i.e. no memory leaks\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";

} // main
