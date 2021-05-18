//
//  main.cpp
//  cs2124-lab-3
//
//  Created by Eddie Zhu on 2020/2/14.
//  Copyright © 2020 EddieZ. All rights reserved.
//

/*
  rec03.cpp
 */

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//
// Task 1: The Account struct. Call it AccountS
//

struct AccountS {
    string accountName;
    int accountNumber;
};


//
// Task 2: The Account class. Call it AccountC
//
class AccountC {
    
    friend ostream& operator<<(ostream&os, const AccountC& someAccount);
    
public:
    //AccountC () {};
    AccountC (const string& name, int num) : accountName(name), accountNumber(num) {};
    
    string get_accountName() const{
        return accountName;
    }
    
    int get_accountNumber() const{
        return accountNumber;
    }
    
    void deposit(int money) {
        balance += money;
        history.push_back(Transaction(true, money));
    }
    void withdrawl(int money) {
        if(balance-money < 0){
            cerr << "insufficient balance" << endl;
        }
        else {
            balance -= money;
            history.push_back(Transaction(false, money));
        }
    }
    
private:
        class Transaction {
            friend ostream& operator<<(ostream& os, const AccountC& someAccount);
        public:
            //Transaction () {};
            Transaction (bool ifDeposit, int howmuch) : ifDeposit(ifDeposit), howmuch(howmuch) {};
        private:
            bool ifDeposit;
            int howmuch;
        };
    
    string accountName;
    int accountNumber;

    vector<Transaction> history;
    int balance = 0;
};


// 2.b: AccountC output operator, not a friend.
//ostream& operator<<(ostream&os, const AccountC& someAccount){
//    os << someAccount.get_accountName() << ":" << someAccount.get_accountNumber();
//    return os;
//}

// 2.2: AccountC output operator, reimplemented as a friend.
ostream& operator<<(ostream& os, const AccountC& someAccount){
    os << someAccount.accountName << ":" << someAccount.accountNumber << endl;
    os << "Transaction History:" << endl;
    for(const AccountC::Transaction& aTransaction: someAccount.history){
        os << aTransaction.ifDeposit << " " << aTransaction.howmuch << endl; ;
    }
    return os;
}


//
// Task 3
//
// Transaction class definition


// Account class definition


//
// Task 4
//
// Transaction class definition with embedded Account class



int main() {

    //
    // Task 1: account as struct
    //
    //      1a. Fill vector of account structs from file

    cout << "Task1a:\n";
    cout << "Filling vector of struct objects, define a local struct instance "
         << " and set fields explicitly:\n";
    
    ifstream ifs("accounts.txt");
    vector<AccountS> vectorOfAccountS;
    string name;
    int num;
    if(!ifs){
        cerr << "Could not open the file" << endl;
        exit(1);
    }
    
    while(ifs >> name >> num) {
        AccountS aAccountS;
        aAccountS.accountName = name;
        aAccountS.accountNumber = num;
        vectorOfAccountS.push_back(aAccountS);
    }
    
    ifs.close();
    for(const AccountS& aAccountS : vectorOfAccountS){
        cout << aAccountS.accountName << ": " << aAccountS.accountNumber << endl;
    }
    cout << endl;
    
    
    

    //      1b
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";
    
    vectorOfAccountS.clear();   //to clear the file
    ifs.open("accounts.txt");
    if(!ifs){
        cerr << "Could not open the file" << endl;
        exit(1);
    }
    
    while(ifs >> name >> num) {
        AccountS aAccountS {name, num};
        vectorOfAccountS.push_back(aAccountS);
    }
    
    ifs.close();
    for(const AccountS& aAccountS : vectorOfAccountS){
        cout << aAccountS.accountName << ": " << aAccountS.accountNumber << endl;
    }
    cout << endl;
    
    
    
    
    //==================================
    //
    // Task 2: account as class
    //

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";
    
    vector<AccountC> vectorOfAccountC;
    ifs.open("accounts.txt");
    while(ifs >> name >> num){
        AccountC someAccount = AccountC(name, num);
        vectorOfAccountC.push_back(someAccount);
    }
    ifs.close();
    
    
    cout << "---\n";
    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";
    for(const AccountC& someAccount : vectorOfAccountC){
        cout << someAccount << endl;
    }

    
    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";
    // Note code here will be same as above.
    for(const AccountC& someAccount : vectorOfAccountC){
        cout << someAccount << endl;
    }


    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";
    vectorOfAccountC.clear();
    ifs.open("accounts.txt");
    while(ifs >> name >> num){
        vectorOfAccountC.push_back(AccountC(name, num));
    }
    ifs.close();
    for(const AccountC& someAccount : vectorOfAccountC){
        cout << someAccount << endl;
    }


    
    cout << "\nTask2e:\n";
    cout << "\nFilling vector of class objects, using emplace_back:\n";
    vectorOfAccountC.clear();
    ifs.open("accounts.txt");
    while(ifs >> name >> num){
        vectorOfAccountC.emplace_back(name, num);
    }
    ifs.close();
    for(const AccountC& someAccount : vectorOfAccountC){
        cout << someAccount << endl;
    }
    

    
    // Task 3
    cout << "==============\n";
    cout << "\nTask 3:\n\nAccounts and Transaction:\n";
//    class Transaction {
//    public:
//        Transaction () {};
//        Transaction (bool ifDeposit, int howmuch) : ifDeposit(ifDeposit), howmuch(howmuch) {};
//    private:
//        bool ifDeposit;
//        int howmuch;
//    };


    // Task 4
    cout << "==============\n";
    cout << "\nTask 4:\n\nAccounts and Transaction:\n"
         << "Account class is nested inside Transaction class.\n";
    
    
    ifs.open("transactions.txt");
    if (!ifs) {
        cerr << "could not open the file";
        exit(1);
    }
    string command;
    string aname;
    int anum;
    int money;
    while(ifs >> command){
        if(command == "Account"){
            ifs >> aname;
            ifs >> anum;
        }
        else if(command == "Withdraw"){
            ifs >> anum;
            for(AccountC& someAccountC : vectorOfAccountC){
                if(someAccountC.get_accountNumber()==anum){
                    ifs >> money;
                    someAccountC.withdrawl(money);
                    break;
                }
            }
        }
        else if(command == "Deposit"){
            ifs >> anum; 
            for(AccountC& someAccountC : vectorOfAccountC){
                if(someAccountC.get_accountNumber()==anum){
                    ifs >> money;
                    someAccountC.deposit(money);
                    break;
                }
            }
        }
    }
    ifs.close();
    
    
    for(const AccountC& someAccount : vectorOfAccountC){
        cout << someAccount << endl;
    }

}



