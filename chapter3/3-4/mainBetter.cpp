#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<string> strings;
    string word;
 
    while (cin >> word){
        if (word == "q"){
            break;
        }
        strings.push_back(word);
    }

    auto itrs = minmax_element(
        strings.begin(),
        strings.end(),
        [](string const &s, string const &ss) { return s.length() > ss.length() ? false : true; }
    );
    
    cout << "shortest: " << itrs.first->c_str()

              << " , longest: " << itrs.second->c_str() << '\n';

    return 0;
}
