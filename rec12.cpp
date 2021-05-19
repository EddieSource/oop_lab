// Eddie Zhu
// Doubly linked list
//  Test code

#include <cstdlib>
#include <iostream>
using namespace std;

class List {
    friend ostream& operator<< (ostream& os, const List& aList){
        for (Node* curr = aList.header->next; curr != aList.trailer; curr = curr->next) {
            os << curr->data << " ";
        }
        return os;
    }
public:
    struct Node {
        Node(int data = 0, Node* prior = nullptr, Node* next = nullptr) : data(data),prior(prior), next(next){}
        int data;
        Node* prior;
        Node* next;
    };
    
    class iterator {
        friend class List;
        //symmetry operator needs to be outside of class
        friend bool operator==(const iterator& lhs, const iterator& rhs) {
            return lhs.nodePtr == rhs.nodePtr;
        }
        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
            return !(lhs==rhs);
        }
    public:
        //constructor
        iterator (Node* p) : nodePtr(p) {}
        iterator& operator++ () {
            nodePtr = nodePtr->next;
            return *this;
        }
        iterator& operator-- () {
            nodePtr = nodePtr->prior;
            return *this;
        }
        int& operator*() { return nodePtr->data; }
    private:
        Node* nodePtr;
    };
    
    List(){
        theSize = 0;
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->prior = header;
    }
    void push_back(int data) {
        Node* original_lastNode = trailer->prior;
        Node* new_lastNode = new Node(data, original_lastNode, trailer);
        original_lastNode->next = new_lastNode;
        trailer->prior = new_lastNode;
        ++theSize;
    }
    void push_front(int data) {
        Node* original_frontNode = header->next;
        Node* new_frontNode = new Node(data, header, original_frontNode);
        original_frontNode->prior = new_frontNode;
        header->next = new_frontNode;
        ++theSize;
    }
    void pop_back() {
        if (theSize == 0) {
            return;
        }
        Node* original_lastNode = trailer->prior;
        Node* new_lastNode = original_lastNode->prior;
        new_lastNode->next = trailer;
        trailer->prior = new_lastNode;
        //        original_lastNode -> prior = nullptr;
        //        original_lastNode -> next = nullptr;
        delete original_lastNode;
        original_lastNode = nullptr;
        --theSize;
    }
    void pop_front() {
        if (theSize == 0) {
            return;
        }
        Node* original_frontNode = header->next;
        Node* new_frontNode = original_frontNode->next;
        new_frontNode->prior = header;
        header->next = new_frontNode;
//        original_frontNode -> prior = nullptr;
//        original_frontNode -> next = nullptr;
        delete original_frontNode;
        original_frontNode = nullptr;
        --theSize;
    }
    //const version
    int front() const {
        if (theSize == 0) return header->data;
        return header->next->data;
    }
    int back() const {
        if (theSize == 0) return trailer->data;
        return trailer->prior->data;
    }
    //non-const version
    int& front(){
        if (theSize == 0) return header->data;
        return header->next->data;
    }
    int& back(){
        if (theSize == 0) return trailer->data;
        return trailer->prior->data;
    }
    unsigned size() const {
        return theSize;
    }
    void clear() {
        Node* curr = header->next;
        while (curr != trailer) {
            Node* victim = curr;
            curr = curr->next;
            header->next = curr;
            curr->prior = header;
            delete victim;
            --theSize;
        }
    }
    int operator[](unsigned index) const {
        Node* curr = header;
        for (unsigned i = 0; i < index + 1; ++i) {
            curr = curr->next;
        }
        return curr->data;
    }
    int& operator[](size_t index) {
        if(theSize == 0 || index >= theSize){
            cerr << "non-exist";
        }
        Node* curr = header;
        for (size_t i = 0; i < index + 1; ++i) {
            curr = curr->next;
        }
        return curr->data;
    }
    iterator begin() {
        return iterator(header->next);
    }
    iterator end() {
        return iterator(trailer);
    }
    
    iterator insert(iterator it, int data) {
        Node* prior = it.nodePtr->prior;
        Node* next = it.nodePtr;
        Node* new_node = new Node (data, prior, next);
        prior->next = new_node;
        next->prior = new_node;
        ++theSize;
        return iterator(new_node);
    }
    
    iterator erase (iterator it) {
        Node* victim = it.nodePtr;
        Node* prior = victim->prior;
        Node* next = victim->next;
        prior->next = next;
        next->prior = prior;
        delete victim;
        --theSize;
        return iterator(next);
    }
    
private:
    unsigned theSize;
    Node* header;
    Node* trailer;
};

// Task 1
void printListInfo(const List& myList) {
        cout << "size: " << myList.size()
             << ", front: " << myList.front()
             << ", back(): " << myList.back()
             << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList){
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList){
    theList.front() = 17;
    theList.back() = 42;
}

// Task 4
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.size(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}
//
//// Task 8
//void doNothing(List aList) {
//    cout << "In doNothing\n";
//    printListInfo(aList);
//    cout << endl;
//    cout << "Leaving doNothing\n";
//}


int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
//    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
//    for (int i = 0; i < 10; ++i) {
//        cout << "myList.push_back(" << i*i << ");\n";
//        myList.push_back(i*i);
//        printListInfo(myList);
//    }
//    cout << "===================\n";
//
//    cout << "Modify the first and last items, and display the results\n";
//    changeFrontAndBack(myList);
//    printListInfo(myList);
//    cout << "===================\n";
//
//    cout << "Remove the items with pop_back\n";
//    while (myList.size()) {
//        printListInfo(myList);
//        myList.pop_back();
//    }
//    cout << "===================\n";

//    // Task 2
//    cout << "\n------Task Two------\n";
//    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
//    for (int i = 0; i < 10; ++i) {
//        cout << "myList2.push_front(" << i*i << ");\n";
//        myList.push_front(i*i);
//        printListInfo(myList);
//    }
//    cout << "===================\n";
//    cout << "Remove the items with pop_front\n";
//    while (myList.size()) {
//        printListInfo(myList);
//        myList.pop_front();
//    }
//    cout << "===================\n";

//    // Task 3
//    cout << "\n------Task Three------\n";
//    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
//    for (int i = 0; i < 10; ++i) {
//        myList.push_back(i*i);
//    }
//    printListInfo(myList);
//    cout << "Now clear\n";
//    myList.clear();
//    cout << "Size: " << myList.size() << ", list: " << myList << endl;
//    cout << "===================\n";

//    // Task 4
//    cout << "\n------Task Four------\n";
//    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
//    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
//    cout << "Display elements with op[]\n";
//    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
//    cout << endl;
//    cout << "Add one to each element with op[]\n";
//    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
//    cout << "And print it out again with op[]\n";
//    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
//    cout << endl;
//    cout << "Now calling a function, printListSlow, to do the same thing\n";
//    printListSlow(myList);
//    cout << "Finally, for this task, using the index operator to modify\n"
//         << "the data in the third item in the list\n"
//         << "and then using printListSlow to display it again\n";
//    myList[2] = 42;
//    printListSlow(myList);
//
//
    // Task 5
//    cout << "\n------Task Five------\n";
//    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
//    myList.clear();
//    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
//    printListInfo(myList);
//    cout << "Now display the elements in a ranged for\n";
//    for (int x : myList) cout << x << ' ';
//    cout << endl;
//    cout << "And again using the iterator type directly:\n";
//    // Note you can choose to nest the iterator class or not, your choice.
//    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
//    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
//        cout << *iter << ' ';
//    }
//    cout << endl;
//    cout << "WOW!!! (I thought it was cool.)\n";
//
    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";
//
//    // Task 8
//    cout << "\n------Task Eight------\n";
//    cout << "Copy control\n";
//    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
//    myList.clear();
//    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
//    printListInfo(myList);
//    cout << "Calling doNothing(myList)\n";
//    doNothing(myList);
//    cout << "Back from doNothing(myList)\n";
//    printListInfo(myList);
//
//    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
//    List listTwo;
//    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
//    printListInfo(listTwo);
//    cout << "listTwo = myList\n";
//    listTwo = myList;
//    cout << "myList: ";
//    printListInfo(myList);
//    cout << "listTwo: ";
//    printListInfo(listTwo);
//    cout << "===================\n";
}


