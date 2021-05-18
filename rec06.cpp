/*
  Recitation 06
  CS2124
 
  Focus: Dynamic arrays and copy control
 
    Eddie Zhu
 
 */


//heap is like an operator
//for now exam will tell us when to use heap. in the future we will tell them.

//default copy will do shallow copy, copy any attirbutes by value but atrtributes using heap
//deep copy we will copy the attributes using heap

#include <string>
#include <iostream>
using namespace std;

class Position {
    friend ostream& operator<<(ostream& os, const Position& rhs) {
        os << '[' << rhs.title << ',' << rhs.salary << ']';
        return os;
    }
public:
    Position(const string& aTitle, double aSalary)
        : title(aTitle), salary(aSalary) {}
    const string& getTitle() const { return title; }
    double getSalary() const { return salary; }
    void changeSalaryTo(double d) { salary = d; }
private:
    string title;
    double salary;
}; // class Position

class Entry {
    friend ostream& operator<<(ostream& os, const Entry& rhs) {
        os << rhs.name << ' ' << rhs.room
           << ' ' << rhs.phone << ", " << *rhs.pos;
        return os;
    }
public:
    Entry(const string& name, unsigned room, unsigned phone, Position& position)
        : name(name), room(room), phone(phone), pos(&position) {
    }
    const string& getName() const { return name; }
    unsigned getPhone() const { return phone; }
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry


class Directory {
    // Overload output operator
    friend ostream& operator<< (ostream& os, const Directory& aDirectory){
        for(size_t i = 0; i < aDirectory.size; ++i){
            os << *aDirectory.entries[i];
        }
        return os;
    }
public:
    // Of course the first function you need to write for this (or
    // any class is... //constructor
    Directory () {
        size = 0;
        capacity = 1;
        entries = new Entry* [capacity];
    }
    //copy control
    Directory(const Directory& yetAnotherDirectory) {
        size = yetAnotherDirectory.size;
        capacity = yetAnotherDirectory.capacity;
        entries = new Entry* [yetAnotherDirectory.capacity];
        for(size_t i = 0; i < size; ++i){
            entries[i] = new Entry(*yetAnotherDirectory.entries[i]);    //when to use a constructor? when there's no heap allocating in the class
        }
    }
    Directory& operator= (const Directory& rhs){
        //check self assignment
        if(this != &rhs){
            for(size_t i = 0; i < size; ++i){
                delete entries[i];
                entries[i] = nullptr;
            }
            delete []entries;   //what does delete do? will free out the entries of the delete
            entries = nullptr;
            
            size = rhs.size;
            capacity = rhs.capacity;
            entries = new Entry* [rhs.capacity];
            for(size_t i = 0; i < size; ++i){
                entries[i] = new Entry(*rhs.entries[i]);
            }
        }
        return *this;
    }
    
    ~Directory(){
        for(size_t i = 0; i < size; ++i){
            delete entries[i];
            entries[i] = nullptr;
        }
        delete []entries;   //what does delete entries mean?, what does clear mean? is entries ona heap?
        entries = nullptr;

    }
    
    unsigned operator[] (const string& name) const {
        for(size_t i = 0; i < size; ++i){
            if (entries[i]->getName() == name) {
                return entries[i]->getPhone();
            }
        }
        return 99999999;
    }
    
    // ???
    // ...
    
    
    // We'll get you started with the add method, but obviously you
    // have a lot of work to do here.
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if (size == capacity)    {
            // something is missing!!!  Add it!
            Entry** old_entries = entries;
            entries = new Entry* [2 * capacity];
            for (size_t i = 0; i < capacity; ++i) {
                entries[i] = old_entries[i];   //what about just entries?  //when there's no heap in an object just use default copy constructor
                //no need to use new becuase we are not gonna access to the old anymore, we will delete the old_entries
            }
            capacity *= 2;
            delete []old_entries;   //why delete this this is not something on the heap
            old_entries = nullptr;
        } // if
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    } // add
    
    
    

private:
    Entry** entries;
    size_t size;
    size_t capacity;
}; // class Directory

void doNothing(Directory dir) { cout << dir << endl; }

int main() {
    
    // Note that the Postion objects are NOT on the heap.
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
    
    // Create a Directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;

    Directory d2 = d;    // What function is being used??
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout << d << endl;

    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";

    Directory d3;
    d3 = d2;

    // Should display 1592
    cout << d2["Carmack"] << endl;
    
} // main
