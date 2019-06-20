#ifndef GUARD_READ_GRAMMAR_H
#define GUARD_READ_GRAMMAR_H
 
// read_grammar.h
 
#include <vector>      // std::vector
#include <string>      // std::string
#include <map>         // std::map
#include <istream>     // std::istream
 
typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;
 
Grammar read_grammar(std::istream&);
 
#endif // GUARD_READ_GRAMMAR_H