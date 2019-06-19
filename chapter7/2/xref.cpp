#include <iostream>   // std::cin, std::istream
#include <map>        // std::map
#include <string>     // std::string
#include <vector>     // std::vector
#include "split.h"    // split
 
using std::cin;
using std::map;
using std::string;
using std::vector;
using std::istream;
 
// Find all the lines that refer to each word in the input
// (S7.3/126)
map<string, vector<int> >
xref(istream& in, vector<string> find_words(const string&) = split)
{
  string line;
  int line_number = 0;
  map<string, vector<int> > ret;  // map string to vector<int>
 
  // Read the next line
  while (getline(in, line)) {
    ++line_number;
 
    // Break the input line into words
    vector<string> words = find_words(line);
 
    // remember that each word occurs on the current line
    for (vector<string>::const_iterator it = words.begin();
         it != words.end(); ++it)
      ret[*it].push_back(line_number);
  }
 
  return ret;
}