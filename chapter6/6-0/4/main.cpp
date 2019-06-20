#include <iostream>  // cin, cout, endl
#include <string>  // string
#include <vector>  // vector
#include "find_urls.h"  // find_url
#include "vcout.h"  // vcout
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
 
int main()
{
    cout << "Enter a line. This program automatically find URLs..." << endl;
 
    // Read a line of input, then find and display URLs.
    string line;
    vector<string> urls;
    while (getline(cin, line)) {
      vector<string> urls = find_urls(line);
      vcout(urls);
    }
 
    return 0;
}