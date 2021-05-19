// rec13_test.cpp
// Eddie Zhu

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

void printList(const list<int>& l) {
//    for (list<int>::iterator i = l.begin(); i != l.end(); ++i) {
//        cout << *i;
//    }
    for (list<int>::const_iterator i = l.begin(); i != l.end(); ++i) {
        cout << ' ' << *i;
    }
    cout << endl;
}

void printList2(const list<int>& l) {
//    for (list<int>::iterator i = l.begin(); i != l.end(); ++i) {
//        cout << *i;
//    }
    for (int num : l) {
        cout << ' ' << num;
    }
    cout << endl;
}

void printList3(const list<int>& l) {
    for (auto i = l.begin(); i != l.end(); ++++i) {
        cout << ' ' << *i;
    }
    cout << endl;
}

//task 12
list<int>::const_iterator myfind(const list<int>& l, int target) {
    for (list<int>::const_iterator i = l.begin(); i != l.end(); ++i) {
        if (*i == target) return i;
    }
    return l.end();
}
//task 13
auto myfind2(const list<int>& l, int target) {
    for (auto i = l.begin(); i != l.end(); ++i) {
        if (*i == target) return i;
    }
    return l.end();
}

//task 15
bool isEven(int n){
    return n % 2 == 0;
}



//task 16
class IsEven{
public:
    bool operator() (int n) const {return n % 2 == 0; }
};


//task 19
list<int>::const_iterator ourFind2(list<int>::const_iterator i1, list<int>::const_iterator i2, int target) {
    cout << "Our Find: " << endl;
    for (list<int>::const_iterator i = i1; i != i2; ++i) {
        if (*i == target) return i;
    }
    return i2;
}



//task 20
template<typename T, typename U>
auto ourFind(T i1, T i2, U target) {
    cout << "Our Find: " << endl;
    for (auto i = i1; i != i2; ++i) {
        if (*i == target) return i;
    }
    return i2;
}

/*
template<typename T>
bool existinv(const vector<T>& v, T target) {
    for (auto i = v.begin(); i != v.end(); ++i) {
        if (*i == target) return true;
    }
    return false;
}*/



int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> v { 2, 1, 3, 4 };
    for(const int& elem : v){
        cout << ' ' << elem;
    }

    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";

    list<int> l(v.begin(), v.end());

    for (list<int>::iterator i = l.begin(); i != l.end(); ++i){
        cout << ' ' << *i;
    }
    
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(v.begin(), v.end());
    for(const int& elem : v){
        cout << ' ' << elem;
    }
    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    
    for (size_t i = 0; i < v.size(); ++i) {
        cout << ' ' << v[i];
    }

    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    
//    for (size_t i = 0; i < l.size(); ++i) {
//        cout << ' ' << l[i];
//    }
    
//    Why didn't they provide op[] for list? Easy to write, right? (In fact you've done it.) They omitted it just so we wouldn't try to use it in a loop like this. (How did you write it? Each call to op[] required walking from the front of the list. To loop over N items this way would take approximately N2 / 2 steps. Ouch!)

    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    
    
    //random access ability of vector's iterators?
    //bumped the iterator by 2?
    for (vector<int>::iterator i = v.begin(); i != v.end(); i += 2) {
        cout << ' ' << *i;
    }

    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    
    //can't use +=2
    for (list<int>::iterator i = l.begin(); i != l.end(); ++++i){
        cout << ' ' << *i;
    }
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    l.sort();
    for (list<int>::iterator i = l.begin(); i != l.end(); ++i){
           cout << ' ' << *i;
       }
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    printList(l);
    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    printList2(l);
    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    printList3(l);
    cout << "=======\n";

    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    list<int>::const_iterator i = myfind(l, 1);
    if (i == l.end()) cerr << "can't find it" << endl;
    else {
        cout << *i << endl;
    }
    
    
    list<int>::const_iterator j = myfind(l, 6);
    if (j == l.end()) cerr << "can't find it" << endl;
    else {
        cout << *j << endl;
    }
    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    
    auto m = myfind2(l, 1);
    if (m == l.end()) cerr << "can't find it" << endl;
    else {
        cout << *m << endl;
    }

    auto n = myfind2(l, 6);
    
    if (n == l.end()) cerr << "can't find it" << endl;
    else {
        cout << *n << endl;
    }


    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    list<int>::iterator o = find(l.begin(), l.end(), 1);
    if (o == l.end()) cerr << "can't find it" << endl;
    else {
        cout << *o << endl;
    }

    list<int>::iterator p = find(l.begin(), l.end(), 6);
    if (p == l.end()) cerr << "can't find it" << endl;
    else {
        cout << *p << endl;
    }

    
    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    list<int>::iterator loc1 = find_if(l.begin(), l.end(), isEven);
    cout << *loc1 << endl;
    cout << "=======\n";

    // 16. Functor
    cout << "Task 16:\n";
    list<int>::iterator loc2 = find_if(l.begin(), l.end(), IsEven());
    cout << *loc2 << endl;
    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    list<int>::iterator loc3 = find_if(l.begin(), l.end(), [] (int n) { return n % 2 == 0;});
    cout << *loc3 << endl;
    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int* arr = new int[l.size()];
    copy(l.begin(), l.end(), arr);
    
    for (size_t i = 0; i < l.size(); ++i) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    auto loc4 = ourFind2(l.begin(), l.end(), 3);
    cout << *loc4 << endl;
    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    auto loc5 = ourFind(l.begin(), l.end(), 3);
    cout << *loc5 << endl;
    cout << "=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    ifstream file("pooh-nopunc.txt");
    if(!file){
        cerr << "can't open the file";
        exit(1);
    }
    string word;
    vector<string> vec;
    while(file >> word) {
        if(vec.end() == find(vec.begin(), vec.end(), word)){
            vec.push_back(word);
        }
    }
    file.close();
    cout << "size: " << vec.size() << endl;
    for(const string& s : vec){
        cout <<  " " << s;
    }
    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    ifstream file2("pooh-nopunc.txt");
    if(!file2){
        cerr << "can't open the file";
        exit(1);
    }
    string word2;
    set<string> aset;
    while(file2 >> word2) {
            aset.insert(word2);
    }
    file2.close();
    cout << "size: " << aset.size() << endl;
    for(const string& s : aset){
        cout <<  " " << s;
    }
    cout << "=======\n";

    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    map<string, vector<int>> wordMap;
    ifstream file3("pooh-nopunc.txt");
    if(!file3){
        cerr << "can't open the file";
        exit(1);
    }
    string word3;
    int count = 0;
    while(file3 >> word3) {
        wordMap[word3].push_back(count);
        count += 1;
    }
    file3.close();
    
    for(const auto& pair : wordMap){
        cout << pair.first << ": ";
        for (int i : pair.second){
            cout << " " << i;
        }
        cout << endl;
    }
    
    cout << "=======\n";
}
