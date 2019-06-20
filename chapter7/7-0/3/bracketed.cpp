#include <string>     // std::string
 
using std::string;
 
// Determine whether a string is surrounded by brackets <>
// (S7.4.3/132)
bool bracketed(const string& s)
{
  return s.size() > 1 &&
         s[0] == '<' &&
         s[s.size() - 1] == '>';
}