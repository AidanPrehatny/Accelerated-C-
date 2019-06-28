// 10-1 rewrite the student grading program from 9.6/166 to generate letter grades
// 10-2 rewrite the median function from 8.1.1/140 so that we can call it wit either a vector or a build in array. the function should allow containers of any arithmetic type
// 10-3 write a test program to verify that the median function operates correctly. Ensure that calling median does not change the order of the elements in the container.
// 10-4 write a class that implements a list that holds strings
// 10-5 write a bidirectional iterator for your String_list class
// 10-6 test the class by rewriting the split function to put its output into a String_list

#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

char* duplicate_chars(const char* p) {
    size_t length = strlen(p) + 1;
    char* result = new char[length];

    std::copy(p, p + length, result);
    return result;
}

int* pointer_to_dynamic() {
    return new int(0);
}

std::string letter_grade(double grade) {
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };
    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };

    static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
    for (size_t i = 0; i < ngrades; ++i) {
        if (grade >= numbers[i]) {
            return letters[i];
        }
    }
    return "?\?\?";
}

int main(int argc, char ** argv) {
    int fail_count =0;

    for (int i = 1; i < argc; ++i) {
        std::ifstream in(argv[i]);
        if (in) {
            std::string s;
            while (getline(in, s)) {
                std::cout << s << std::endl;
            }
        } else {
            std::cerr << "cannot open file " << argv[i] << std::endl;
            ++fail_count;
        }
    }
    std::string grade = letter_grade(85.0);
    std::cout << grade << std::endl;
    return fail_count;
}
