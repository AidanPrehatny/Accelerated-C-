#include <iostream>     // cout, endl
#include <vector>       // vector
#include <algorithm>    // copy
 
using std::vector;
using std::cout;
using std::endl;
 
int main()
{
  vector<int> u(10, 100);
 
  cout << "vector<int> u looks like this:" << endl;
  for (vector<int>::const_iterator i = u.begin(); i != u.end(); ++i)
    cout << (*i) << endl;
 
  vector<int> v;
  //copy(u.begin(), u.end(), v.begin());  // program crashes!
  copy(u.begin(), u.end(), std::back_inserter(v));  // fine

 
  cout << "vector<int> v looks like this:" << endl;
  for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
    cout << (*i) << endl;
 
  return 0;
}