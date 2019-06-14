#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

struct NumInfo
{
    double num;
    double squaredNum;
};

int squared(const int &num) {
    int sq = num * num;
    return sq;
}

std::istream& squareNum(std::istream& s, NumInfo& struc) {
    // read and store the number input with its squared value
    s >> struc.num;
    return s;
}

int main() {
    std::vector<NumInfo> numPairs;
    NumInfo numStruct;
    while (squareNum(std::cin, numStruct)) {
        double squaredNum = squared(numStruct.num);
        numStruct.squaredNum = squaredNum;
        numPairs.push_back(numStruct);
    }

    sort(
        numPairs.begin(),
        numPairs.end(),
        [](NumInfo s, NumInfo ss) {
            return s.num < ss.num;
        }
    );

    std::for_each(
        numPairs.begin(),
        numPairs.end(),
        [&](NumInfo struc) {
            std::cout << struc.num
                << std::setw(50)
            << struc.squaredNum << std::endl;
        }
    );
    
    return 0;
}