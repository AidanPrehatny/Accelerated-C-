#include <string>
 
using std::string;
 
bool isPalindrome(const string& s)
{
  return equal(s.begin(), s.end(), s.rbegin() );
}