#ifndef GUARD_GEN_AUX_H
#define GUARD_GEN_AUX_H
 
// gen_aux.h
 
#include <string>             // std::string
#include <vector>             // std::vector
#include "read_grammar.h"     // Grammar
 
void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&);
 
#endif // GUARD_GEN_AUX_H