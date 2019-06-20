#include <iostream>     // cin, cout, endl
#include <string>       // string
#include <vector>       // vector
#include <algorithm>    // copy
#include "vcout.h"      // vcout
 
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
 
int main()
{
  string word;               // a word
 
  vector<string> wordCollectionA;    // a collection of words
  cout << "Define vector<string> wordCollectionA below..." << endl;
  // Populate wordCollectionA.
  while (cin >> word)
    wordCollectionA.push_back(word);
  cin.clear();
 
  vector<string> wordCollectionB;    // another collection of words
  cout << "Define vector<string> wordCollectionB below..." << endl;
  // Populate wordCollectionB.
  while (cin >> word)
    wordCollectionB.push_back(word);
  cin.clear();
 
  // Test appending using the push_back method
  vector<string> baseForPushBack = wordCollectionA;
  for (vector<string>::const_iterator i = wordCollectionB.begin();
       i != wordCollectionB.end(); ++i)
    baseForPushBack.push_back(*i);
 
  // Test appending using the insert method
  vector<string> baseForInsert = wordCollectionA;
  baseForInsert.insert(baseForInsert.end(), wordCollectionB.begin(), wordCollectionB.end());
 
  // Test appending using the copy method
  vector<string> baseForCopy = wordCollectionA;
  copy(wordCollectionB.begin(), wordCollectionB.end(),
       back_inserter(baseForCopy) );
 
  // Display results
  cout << "Append wordCollectionB to wordCollectionA with push_back method..."
      << endl;
  vcout(baseForPushBack);
  cout << "Append wordCollectionB to wordCollectionA with insert method..."
      << endl;
  vcout(baseForInsert);
  cout << "Append wordCollectionB to wordCollectionA with copy method..."
      << endl;
  vcout(baseForCopy);
 
  return 0;
}