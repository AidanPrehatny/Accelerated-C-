#include <iostream>
#include <string>    // string
#include <vector>    // vector
 
using std::cout;
using std::endl;
using std::string;
using std::vector;
 
int vcout(const vector<string>& v)
{
  for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i)
    cout << (*i) << endl;
 
  return 0;
}