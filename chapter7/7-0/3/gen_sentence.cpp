#include <vector>             // std::vector
#include <string>             // std::string
#include "read_grammar.h"     // Grammar
#include "gen_aux.h"          // gen_aux
 
using std::vector;
using std::string;
 
// Generate a sentence based on a Grammer object
// (S7.4.3/132)
vector<string> gen_sentence(const Grammar& g)
{
  vector<string> ret;
  gen_aux(g, "<sentence>", ret);
  return ret;
}