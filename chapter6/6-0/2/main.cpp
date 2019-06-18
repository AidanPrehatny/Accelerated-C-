#include <string>
#include <vector>
#include <iostream>
#include "vcout.h"
#include "split.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string line;
    vector<string> words;
    while (getline(cin, line)) {
        vector<string> words = split(line);
        vcout(words);
    }
    return 0;
} 