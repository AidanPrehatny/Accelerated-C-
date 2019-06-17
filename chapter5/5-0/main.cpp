#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include "grade.h"
#include "Student_info.h"
#include "extract_fails.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::list;
 
int main() {
    list<Student_info> students;
    Student_info record;
 
    // read and store all the student's data.
    while (read(cin, record))
        students.push_back(record);
 
    // Extract the failed students
    list<Student_info> students_failed = extract_fails(students);
 
    // sort lists
    students.sort(compare);
    students_failed.sort(compare);
 
    // Report passing students
    cout << "These students have passed." << endl;
    for (list<Student_info>::const_iterator i = students.begin();
         i != students.end(); ++i)
        cout << i->name << endl;
 
    // Report failing students
    cout << "These students have failed." << endl;
    for (list<Student_info>::const_iterator i = students_failed.begin();
         i != students_failed.end(); ++i)
        cout << i->name << endl;
 
    return 0;
}
