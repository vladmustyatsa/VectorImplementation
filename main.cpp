#include <iostream>
#include "vector.h"
#include "mytests.h"
using namespace std;




int main() {
  check({
    {"operator[]", brackets_operator()},
    {"const operator[]", const_brackets_operator()},
    {"capacity", capacity()},
    {"operator<<", cout_operator()},
    {"assignment", assignment()},
    {"size", size()},
    {"empty", empty()},
    {"clear", clear()},
    {"reserve", reserve()}, 
    {"shrink_to_fit", shrink_to_fit()},
    {"push_back", push_back()},
    {"pop_back", pop_back()},
    {"default_constructor", default_constructor()},
    {"copy_constructor", copy_constructor()},
    {"constructor_with_n", constructor_with_n()},
    {"constructor_with_list", constructor_with_list()}
  });
  return 0;
}