#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
using pair_map = map<typename T::first_type, typename T::second_type>;
typedef pair<string, vector<int> > fruit_type;

istream& handleFruit(istream& in, pair_map<fruit_type> &map, int &lineNumber) {
    string line;
    getline(in, line);

    auto space = [] (char c) { return isspace(c); };
    auto noSpace = [] (char c) { return !isspace(c); };

    typedef string::iterator it;
    it start = line.begin();
    
    while (start != line.end()) {
        it wordStart = find_if(start, line.end(), noSpace);
        it wordEnd = find_if(wordStart, line.end(), space);

        map[string(wordStart, wordEnd)].push_back(lineNumber);
        start = wordEnd;
    }

    return in;
}

int main() {
    pair_map<fruit_type> words;

    int lineNumber = 0;

    while (handleFruit(cin, words, lineNumber)) {
        ++lineNumber;
    }

    for (auto const& it : words)
    {
        cout << "The key of: " << it.first << " has values:" << endl;
        for (auto const& i : it.second) {
            cout << i << endl;
        }
    }

    return 0;
}