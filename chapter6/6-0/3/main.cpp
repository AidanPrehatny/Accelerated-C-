#include <iostream>  // cin, cout, endl
#include <string>  // string
#include <vector>  // vector
#include "vcout.h"  // vcout
#include "isPalindrome.h"   // isPalindrome
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
 
int main()
{
  string word;
  vector<string> words;
  vector<string> palindromes;
 
  // Populate vector
  while (cin >> word) {
    if (isPalindrome(word))
      palindromes.push_back(word);
  }
 
  // Print palindrome
  cout << "\nThese are the palindromes identified: " << endl;
  vcout(palindromes);
 
  return 0;
}