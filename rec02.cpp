//
//  main.cpp
//  cs2124-lab-2
//
//  Created by Eddie Zhu on 2020/2/7.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Molecular_formula {
    vector<string> names;
    int carbon_atoms;
    int hydrogen_atoms;
};

void selection_sort (vector<Molecular_formula>& formulas);
void display (const vector<Molecular_formula>& aVector);
size_t findFormula (const vector<Molecular_formula>& formulas, int c_num, int h_num);
void insertFormula (vector<Molecular_formula>& formulas, const string& name, int c_num, int h_num);
void openStream(ifstream& file);
void fillVector (vector<Molecular_formula>& aVector, ifstream& file);


int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream file;
    vector<Molecular_formula> formula_group;
    
    //open the stream
    openStream(file);
    
    fillVector(formula_group, file);
    
    selection_sort(formula_group);
    display(formula_group);
    
    return 0;

}




void selection_sort (vector<Molecular_formula>& formulas) {
    for (size_t i = 0; i < formulas.size() - 1; i++){
        size_t min_index = i;
        for (size_t j = i + 1; j < formulas.size(); j++) {
            if (formulas[j].carbon_atoms < formulas[min_index].carbon_atoms) {
                min_index = j;
            }
            else if (formulas[j].carbon_atoms == formulas[min_index].carbon_atoms) {
                if (formulas[j].hydrogen_atoms < formulas[min_index].hydrogen_atoms) {
                    min_index = j;
                }
            }
        }
        Molecular_formula temp = formulas[i];
        formulas[i] = formulas[min_index];
        formulas[min_index] = temp;
    }
}


void display (const vector<Molecular_formula>& aVector) {
    for (size_t i = 0; i < aVector.size(); i++) {
        cout << 'c' << aVector[i].carbon_atoms << 'h' << aVector[i].hydrogen_atoms << ' ';
        for (const string& name : aVector[i].names) {
            cout << name << ' ';
        }
        cout << endl;
    }
}


size_t findFormula (const vector<Molecular_formula>& formulas, int c_num, int h_num) {
    for (size_t i = 0; i < formulas.size();i++) {
        if (c_num == formulas[i].carbon_atoms && h_num == formulas[i].hydrogen_atoms){
            return i;   //find the location of a formula object that matches h and c num in a new entry in formulas vector
        }
    }
    return formulas.size(); //no formula entry in the formulas vector
}


//insert the formula
void insertFormula (vector<Molecular_formula>& formulas, const string& name, int c_num, int h_num) {
    size_t loc = findFormula(formulas, c_num, h_num);
    //update the formula when it was in the formulas vector
    if (loc < formulas.size()) {
        formulas[loc].names.push_back(name);
    }
    //insert the formula when it was not in
    else {
        vector<string> names;
        names.push_back(name);
        Molecular_formula newFormula {names, c_num, h_num};
        formulas.push_back(newFormula);
    }
   
}


void openStream(ifstream& file){
    //ask users to enter correct file_name
    do{
        file.clear();
        string file_name;
        cout << "Please enter a new file name: ";
        cin >> file_name;
        file.open(file_name);
    } while(!file);
}


void fillVector (vector<Molecular_formula>& aVector, ifstream& file) {
    string name;
    char ch;
    int c_num, h_num;
    
    while (file >> name >> ch >> c_num >> ch >> h_num) {
        insertFormula(aVector, name, c_num, h_num);
    }
    file.close();
}


