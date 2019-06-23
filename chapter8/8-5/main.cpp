#include <map>
using std::map;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iterator>
using std::back_inserter;

#include <algorithm>
using std::copy;

#include <utility>
using std::pair;

#include <iostream>
using std::cout;

int main()
{
  map<int, string> m = { { 1, "hello" },{ 3, "bye" } };

  vector<pair<int, string>> x = { { 1, "thanks" },{ 3, "yo" } };

  // container that supports output iterator operations, push_back and that holds <int,string> pairs
  copy(m.begin(), m.end(), back_inserter(x));
    for (auto p : x) {
        cout << p.second;
    }
  // map doesn't support push_back so back_inserter is an invalid operation
  //copy(x.begin(), x.end(), back_inserter(m));

  return 0;
}