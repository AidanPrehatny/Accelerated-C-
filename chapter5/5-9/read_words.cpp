#include <iostream>
#include <string>
#include "read_words.h"

std::istream& readWords(std::istream& cin, std::string& word) {
    std::cin >> word;
    return std::cin;
}