#include <iostream>    // cout, endl;
#include <vector>      // vector
#include <string>      // string
#include <numeric>     // accumulate
 
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::accumulate;
 
int main () {
    string s = "abc";
    vector<string>  vec (20, s);
    string sentence = accumulate( vec.begin(), vec.end(), string("") );
    cout << sentence << endl;
}