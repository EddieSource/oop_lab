//
//  rec01.cpp
//  cs2124-lab-1
//
//  Created by Eddie Zhu on 2020/1/31.
//  Copyright © 2020 EddieZ. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;


//pr13
void displayVector(const vector<int>& v) {
    for (int elem : v) {
        cout << elem << ' ';
    }
    cout << endl;
}


//pr14
void doubleVector(vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = 2 * v[i];
    }
}


//pr15
void doubleVector2(vector<int>& v) {
    for (int& num : v) {
        num = 2 * num;
    }
}


int main(int argc, const char * argv[]) {
    // pr1
    std::cout << "Hello, World!\n";
    
    // pr2
    cout << "Hello, World!\n";
    
    //pr3
    int x;
    cout << x << endl;
    
    //pr4
    int y = 17;
    int z = 2000000017;
    double pie = 3.14159;
    cout << sizeof(x) << endl;
    cout << sizeof(y) << endl;
    cout << sizeof(z) << endl;
    cout << sizeof(pie) << endl;
    
    //pr5
//    x = "felix"; //compilation error: incompatible type
    
    //pr6
    cout << (y < 20 && y > 10) << endl; //1 means true, 0 means false
    
    //pr7
    for (int i = 10; i < 21; ++i) {
        cout << i << " ";
    }
    cout << endl;
    
    int i = 10;
    while (i < 21) {
        cout << i << " ";
        ++i;
    }
    cout << endl;
    
    int j = 10;
    do{
        cout << j;
        ++j;
    } while(j < 21);
    cout << endl;
    
    
    //pr8
    bool right_name = false;
    ifstream file;
    while (right_name == false) {
        string file_name;
        cin >> file_name;
        file.open(file_name);
        if (file) {
            right_name = true;
        }
    }
    
    
    //pr9
    string word;
    while (file >> word) {
        cout << word << endl;
    }
    file.close();
    
    
    //pr10
    vector<int> vectorofInts;
    for (int i = 10; i < 101; ++i) {
        if (i % 2 == 0) {
            vectorofInts.push_back(i);
        }

    }
    
    
    //pr11
    for(size_t i = 0; i < vectorofInts.size(); ++i) {
        cout << vectorofInts[i] << " ";
    }
    cout << endl;
    
    for(int integers : vectorofInts) {
        cout << integers << " ";
    }
    cout << endl;
    
    for(size_t i = vectorofInts.size(); i > 0; --i) {
        cout << vectorofInts[i - 1] << " ";
    }
    cout << endl;
    
    
    //pr12
    vector<int> vectorofPrimes{2, 3, 5, 7, 11, 13, 17, 19};
    
    
    //pr13
    displayVector(vectorofPrimes);
    
    //pr14
    doubleVector(vectorofPrimes);
    displayVector(vectorofPrimes);
    
    //pr15
    doubleVector2(vectorofPrimes);
    displayVector(vectorofPrimes);
    
}


