#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    vector<string> words;
    string word;
 
    while (cin >> word){
        if (word == "q"){
            break;
        }
        words.push_back(word);
    }
 
    typedef vector<double>::size_type vec_sz;
    vec_sz sizeOwords = words.size();
 
    string shortestWord;
    string longestWord;

    for (vector<string>::iterator word = words.begin(); word != words.end(); ++word) {
        int index = distance(words.begin(), word);
        if (index == 0) {
            shortestWord = words[index];
            longestWord = words[index];
        } else {
            if (words[index].length() < shortestWord.length()) {
                shortestWord = words[index];
            }
            if (words[index].length() > longestWord.length()) {
                longestWord = words[index];
            }
        }
    }
    cout << "shortest: " << shortestWord << "\n";
    cout << "longest: " << longestWord << "\n";
    return 0;
}