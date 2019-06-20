#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

template <typename T>
using pair_map = map<typename T::first_type, typename T::second_type>;
typedef pair<string, vector<int>> fruit_type;

int main()
{
    pair_map<fruit_type> words;

    string line;
    int line_no = 0;

    while (getline(cin, line))
    {
        ++line_no;
        istringstream buffer(line);

        for_each(istream_iterator<string>(buffer), {},
                      [&](auto word) { words[word].push_back(line_no); });
    }

    map<int, bool> line_counter;
    for (auto const &it : words)
    {
        cout << "The key of: " << it.first << " appeared on line number: " << endl;
        for (auto const &i : it.second)
        {
            if (!line_counter[i]) {
                cout << i << endl;
                line_counter[i] = true;
            }
        }
    }

    return 0;
}