#include <iostream> // std::cin, std::cout, std::endl
#include <map>		// std::map
#include <string>   // std::string
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
	string s;
	map<string, int> counters; // store each word and an associated counter

	// read the input, keeping track of each word and how often we see it
	while (cin >> s)
		++counters[s];

	map<int, std::vector<string> > freq;

	// write the words and associated counts
	for (auto const& it : counters)
	{
		cout << it.first << "\t" << it.second << endl;
		freq[it.second].push_back(it.first);
	}

	// write frequency of word occurances
	for (auto const& it : freq) {
		cout << "Frequency of word occurance for freq: " << it.first << endl;
		for (auto const& it : it.second) {
			cout << it << endl;
		} 
	}

	return 0;
}