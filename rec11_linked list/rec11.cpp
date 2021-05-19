//
//  main.cpp
//  cs2124-rec11
//
//  Created by Eddie Zhu on 2020/4/17.
//  Copyright © 2020 EddieZ. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;

/*
  functions for use with CS2124 rec11
  -jbs
*/

// Node to be used a part of linked list
struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

// listAddHead: adds a data item to the beginning of a [possibly empty] list
void listAddHead(Node*& headPtr, int entry) {
    headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

// listBuild: constructs a list from a vector of data items. Note that
// you can use a curly-braced sequence.
// This may be useful for setting up test cases. Feel free to use it
// or not as you like.
// Example of using would be:
//    Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listAddHead(result, vals[index-1]);
    }
    return result;
}


void splice(Node* anotherList, Node* location){
    if(anotherList == nullptr || location == nullptr) {
        return;
    }
    Node* original_next = location->next;
    Node* curr = anotherList;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = original_next;
    location->next = anotherList;
}


void listDisplay(Node* headPtr) {
    //for (const Node* p = headPtr; p != nullptr; p = p->next) {
    for (Node* p = headPtr; p != nullptr; p = p->next) {
        cout << p->data << ' ';
    }
    cout << endl;
    //headPtr = nullptr;
}

Node* compare(Node* target_node, Node* list_node){
    if (target_node == nullptr && list_node == nullptr) {
        return nullptr;
    }
    Node* p1 = target_node;
    Node* p2 = list_node;
    while (p1 != nullptr && p2 != nullptr && p1->data == p2->data){
        p1 = p1->next;
        p2 = p2->next;
    }
    if (p1 == nullptr) {
        return list_node;
    }
    return nullptr;
}

Node* isSublist(Node* target, Node* list){
    // what are we comparing? data?
    cout << "Attempt match: ";
    listDisplay(target);
    Node* target_p = target;
    Node* curr = list;
    while (curr) {
        if (curr->data == target_p->data) {
            Node* result = compare(target_p, curr);
            if(result){
                listDisplay(result);
                return result;
            }
        }
        curr = curr->next;
    }
    cout << "Failed to match" << endl;
    return nullptr;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> aVecotr {5, 7, 9, 1};
    Node* list = listBuild(aVecotr);
    listDisplay(list);
    vector<int> another {6, 3, 2};
    Node* another_list = listBuild(another);
    listDisplay(another_list);
    splice(another_list, list->next);
    listDisplay(list);
    listDisplay(another_list);
    
    Node* result1 = isSublist(another_list, list);
    listDisplay(result1);
    vector<int> another2 {2};
    Node* another_list2 = listBuild(another2);
    Node* result2 = isSublist(another_list2, list);
    listDisplay(result2);
    
    vector<int> another3 {10};
    Node* another_list3 = listBuild(another3);
    Node* result3 = isSublist(another_list3, list);
    listDisplay(result3);
    
    vector<int> list2v {1,2,3,2,3,2,4,5,6};
    vector<int> match1v {1};
    vector<int> match2v {3, 9};
    vector<int> match3v {2,3,2,4};
    
    Node* list2 = listBuild(list2v);
    Node* match1 = listBuild(match1v);
    Node* match2 = listBuild(match2v);
    Node* match3 = listBuild(match3v);
    
    Node* resultmatch1 = isSublist(match1, list2);
    Node* resultmatch2 = isSublist(match2, list2);
    isSublist(match3, list2); 

    
    

    return 0;
}
