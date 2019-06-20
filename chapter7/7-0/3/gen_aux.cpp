#include <string>            // std::string
#include <vector>            // std::vector
#include <stdexcept>         // logic_error
 
#include "read_grammar.h"    // Grammar, Rule, Rule_collection
#include "bracketed.h"       // bracketed
#include "nrand.h"           // nrand
 
using std::string;
using std::vector;
using std::logic_error;
 
// Look up the input Grammar, and expand
// (S7.4.3/132)
void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
  if (!bracketed(word)) {
    ret.push_back(word);
  } else {
    // locate the rule that corresponds to word
    Grammar::const_iterator it = g.find(word);
    if (it == g.end())
      throw logic_error("empty rule");
 
    // fetch the set of possible rules
    const Rule_collection& c = it->second;
 
    // from which we select one at random
    const Rule& r = c[nrand(c.size())];
 
    // recursively expand the selected rule
    for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
      gen_aux(g, *i, ret);
  }
}