#include <string>  // string
#include <vector>  // vector
#include <algorithm>  // find_if
#include "not_url_char.h"  // not_url_char
 
using std::string;
 
string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
  return find_if(b, e, not_url_char);
}