#include <algorithm>
#include <string>
#include "Student_info.h"

using std::max;

int main() {
    size_t maxlen = 3;
    Student_info s;
    // both parameters must be of the same type
    max(s.name.size(), maxlen);
    std::cout << maxlen << std::endl;
    return 0;
}