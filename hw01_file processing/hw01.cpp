//
//  hw01.cpp
//  cs2124-hw1
//
//  purpose: Decrypt Text
//
//  Created by Eddie Zhu on 2020/1/29.
//  Copyright © 2020 EddieZ. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


//takes an encrypted character and returns the corresponding decrypted character
char decrypt_char(char ch, int step){
    if (isupper(ch) || !isalpha(ch)) {
        return ch;
    }
    else {
        if (ch - step < 'a') {
            return char('z' - 'a' + 1 + ch - step);
        }
        else {
            return ch - step;
        }
    }
}


//modify an encrypted string changing it into its unencrypted form
void decrypt_string(string& s, int step) {
    //decrypt one line of strings
    for (size_t i = 0; i < s.size(); ++i) {
        s[i] = decrypt_char(s[i], step);
    }
}


int main() {
    // insert code here...
    ifstream code("encrypted.txt");
    
    if (!code) {
        cerr << "Could not open the file. \n";
        exit(1);
    }
    
    int step;
    code >> step;
    
    string line;
    vector<string> para(0);

    while (getline(code, line)) {
        decrypt_string(line, step);
        para.push_back(line);
    }
    code.close();
    for (size_t i = para.size(); i > 0; --i) {
        cout << para[i - 1] << endl;
    }

    
}
