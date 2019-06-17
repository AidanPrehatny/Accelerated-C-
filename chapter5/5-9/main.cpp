#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <algorithm>
#include <functional>
#include "read_words.h"

void processCharacters(
    std::list<std::string>& words,
    std::function<bool(const char c)> predicate,
    std::list<std::string>& valueTypes
) {
    std::list<std::string>::iterator iter = words.begin();
    while (iter != words.end()) {
        std::string it = *iter;
        bool valueToCheck = std::any_of(it.begin(), it.end(), predicate);
        if (valueToCheck) {
            valueTypes.push_back(it);
            iter = words.erase(iter);
        } else {
            ++iter;
        }
    }
}

int main() {

    std::list<std::string> words;
    std::string word;

    while(readWords(std::cin, word)) {
        words.push_back(word);
    }

    std::list<std::string> uppercases;

    processCharacters(words, [](const char c) { return std::islower(c) == 0; }, uppercases);
    for (auto i : uppercases) {
        std::cout << i << " upper case " << "\n";
    }
    for (auto w : words) {
        std::cout << w << " lower case " << "\n";
    }

    return 0;
}