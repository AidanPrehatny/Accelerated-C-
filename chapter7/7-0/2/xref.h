#ifndef GUARD_XREF_H
#define GUARD_XREF_H
 
// xref.h
 
#include <iostream>   // std::istream
#include <map>        // std::map
#include <string>     // std::string
#include <vector>     // std::vector
#include "split.h"      // split
 
std::map<std::string, std::vector<int> >
xref(std::istream&,
     std::vector<std::string> find_words(const std::string&) = split);
 
#endif // GUARD_XREF_H