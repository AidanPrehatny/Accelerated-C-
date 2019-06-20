#include "read_Grammar.h"    // Grammar, Rule
#include <istream>           // std::istream
#include <string>            // std::string
#include <vector>            // std::vector
#include "split.h"           // split
 
using std::istream;
using std::string;
using std::vector;
using std::map;
 
// Read a Grammar from a given input stream
// (S7.4.1/131)
Grammar read_grammar(istream& in)
{
  Grammar ret;
  string line;
 
  // read the input
  while (getline(in, line)) {
 
    // split the input into words
    vector<string> entry = split(line);
 
    if (!entry.empty())
      // use the category to store the associated rule
      ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
 
  }
  return ret;
}