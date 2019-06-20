#include <string>          // string, isalnum
#include <algorithm>       // find
 
using std::string;
 
bool not_url_char(char c)
{
  // characters, in addition to alphanumerics, that can appear in a URL
  static const string url_ch = "~;/?:@=&$-_.+!*'(),";
 
  // see whether c can appear in a URL and return the negative
  return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end() );
}