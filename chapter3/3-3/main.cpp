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
 
    sort(words.begin(), words.end());
 
    int wordCount = 1;
 
    for (int i = 0; i != sizeOwords; i++){
        // make sure we're in bounds of the vector
        if (i + 1 < sizeOwords){
            // increment wordCount
            if (words[i] == words[i + 1]){
                wordCount++;
            } else {
                // once two words no longer match, we spit out the counts
                // and reset wordcount
                cout << words[i] << " count: " << wordCount << endl;
                wordCount = 1;
            }
        } else {
            // same as above, but for the last element of the vector
            cout << words[i] << " count: " << wordCount << endl;
            wordCount = 1;
        }
    }
    return 0;
}