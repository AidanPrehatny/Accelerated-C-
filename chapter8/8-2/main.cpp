#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

template<class In1, class In2>
bool equalMine(In1 first, In1 last, In2 policy) {
    while (first != last) {
        if (!(*first == *policy)) {
            return false;
        }
        first++; policy++;
    }
    return true;
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
    vector<string>::iterator last = prev(words.end());
    vector<string>::iterator last1 = range.begin();

    if (equalMine(first, last, last1)) {
        cout << "found a match" << endl;
    } else {
        cout << "no match found" << endl;
    }

    return 0;
}