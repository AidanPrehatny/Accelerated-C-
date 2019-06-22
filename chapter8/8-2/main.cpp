#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

template<class In1, class In2>
bool equalMine(In1 first, In1 last, In2 policy) {
    while (first != prev(last) || !(*first == *policy)) {
        cout << *first;
        if (!(*first == *policy)) {
            return false;
        }
         first++; policy++;
    }
    return true;
}

template<class It, class ToFind>
bool findMine(It first, It const last, ToFind const &toFind) {
    while (first != last || *first == toFind) {
        if (*first == toFind) {
            return true;
        }
        first++;
    }
    return false;
}

template<class It, class CopyTo>
CopyTo copyMine(It first, It const last, CopyTo copyTo) {
    while (first != last) {
        *copyTo++ = *first++;
    }
    return copyTo;
}

int main() {

    vector<string> words;
    vector<string> range{"gucci", "prada", "louie"};
    string line;

    while (getline(cin, line)) {
        istringstream buffer(line);
        
        for_each(istream_iterator<string>(buffer), {},
                    [&](auto word) {words.push_back(word); });
    };
    vector<string>::iterator first = words.begin();
    vector<string>::iterator last = words.end();
    
    // for equal
    vector<string>::iterator last1 = range.begin();
    // for find
    // string last1 = "gucci";

    // for copy
    copyMine(first, last, back_inserter(range));
    for (auto const &word : range) {
        cout << word << endl;
    }

    // if (equalMine(first, last, last1)) {
    //     cout << "found a match" << endl;
    // } else {
    //     cout << "no match found" << endl;
    // }

    return 0;
}