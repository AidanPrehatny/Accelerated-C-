#include <string>  // string, isalpha
#include <algorithm>  // search
#include "not_url_char.h"  // not_url_char
 
using std::string;
 
string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e)
{
  static const string sep = "://";
  typedef string::const_iterator iter;
 
  // i marks where the separator was found
  iter i = b;
 
  while ((i = search(i, e, sep.begin(), sep.end() )) != e) {
 
    // make sure the separator isn't at the beginning or end of the line
    if (i != b && i + sep.size() != e) {
 
      // beg marks the beginning of the protocol-name
      iter beg = i;
      while (beg != b && isalpha(beg[-1]))
        --beg;
 
      // is there at least one appropriate character before and after the separator?
      if (beg != i && !not_url_char(i[sep.size()]))
        return beg;
    }
 
    // the separator we found wasn't part of a URL; advance i past this separator
    i += sep.size();
  }
  return e;
}