//
//  main.cpp
//  cs2124-rec14
//
//  Created by Eddie Zhu on 2020/5/8.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <iostream>
using namespace std;



bool func1 (int x) {
    if (x == 1) {
        return false;
    }
    if(x == 0) {
        return true;
    }
    else {
        bool b = func1(x/2);
        if (x % 2 == 0) {
            return b;
        }
        else {
            return !b;
        }
    }
}


struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};


Node* func2(Node* headPtr1, Node* headPtr2){
    if(headPtr1 == nullptr && headPtr2 == nullptr) {
        return nullptr;
    }
    else if(headPtr1 == nullptr){
        return new Node(headPtr2->data, func2(nullptr, headPtr2->next));
    }
    else if(headPtr2 == nullptr){
        return new Node(headPtr1->data, func2(headPtr1->next, nullptr));
    }
    else{
        Node* headPtr = new Node {headPtr1->data + headPtr2->data, func2(headPtr1->next, headPtr2->next)};
        return headPtr;
    }
}


struct TNode {
  TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};


int max(TNode* root) {
  // Provide this code
    if(root == nullptr){
        throw invalid_argument("the root is null and can not calculate the max");
    }
    if(root->left != nullptr && root->right != nullptr){
        int left_max = max(root->left);
        int right_max = max(root->right);
        int mid = root->data;
        int max = left_max;
        if( right_max > max) {
            max = right_max;
        }
        if(mid > max) {
            max = mid;
        }
        return max;
    }
    else if (root->left != nullptr){
        int mid = root->data;
        int left_max = max(root->left);
        if (mid < left_max) {
            return left_max;
        }
        else {
            return mid;
        }
    }
    else if (root->right != nullptr){
        int mid = root->data;
        int right_max = max(root->right);
        if (mid < right_max) {
            return right_max;
        }
        else {
            return mid;
        }
    }
    else {
        return root->data;
    }
}

bool palindrome(char c[], size_t length){
    if(length < 2){
        return true;
    }
    else {
        return palindrome(&c[1], length - 2) && c[0] == c[length - 1];
    }
}
      

int towers(int n, char a, char b, char c) {
    if(n == 1) return n;
    else {
        return 2*towers(n-1, a, b, c) + 1;
    }
}


void mystery(int n) {
   if (n > 1) {
      cout << 'a';
      mystery(n/2);
      cout << 'b';
      mystery(n/2);
   }
   cout << 'c';
}
/*
n = 7:a,n=3,b,n=3,c:aacbccbacbccc
n = 3:a,n=1,b,n=1,c:acbcc
n = 1:c
*/


int main() {
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    try {
        cout << max(&f) << endl;
        cout << max(nullptr) << endl; //can not go back if error detected

    }
    catch (const invalid_argument& ia){
        cerr << "Invalid argument: " << ia.what() << '\n';
    }
    
  mystery(7);

}
