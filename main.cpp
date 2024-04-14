#include "mytests.h"
#include "vector.h"
#include<algorithm>
#include<numeric>
#include <iostream>
#include "TemplatesTests/miniatur.h"
using namespace std;


int main() {
  Vector<int> tmp;
  {
    const Vector<int> v {1,2,3,4,5};
    const Vector<int> cpy{v};
    tmp = cpy;
  }
  const Vector<int> vi{tmp}; 
  cout<<accumulate(vi.begin(), vi.end(), 0, [] (int sum, int elem) {return sum+elem;})<<'\n';
    {
      Vector<string> vss(0);
      for(size_t i{0};i<20;++i)
        vss.push_back("a");
    }
    {
      Vector<string> vss{}; 
      for(size_t i{0};i<20;++i)
        vss.push_back("a");
    }

    Vector<string> vs {"a","bb","ccc"};
    vs.erase(find(vs.begin(), vs.end(), "bb"));
    for (auto& s : vs) s+="z";
    for (const auto& s : vs) cout<<s<<' ';
    cout<<'\n';

    Spezial_Miniatur sp{"Genestealer",Fraktion::Tyraniden,395};
    //Vector<Spezial_Miniatur> vsm {Spezial_Miniatur{"Genestealer",Fraktion::Tyraniden,395}, Spezial_Miniatur{"Burna Boy",Fraktion::Orks,240}, Spezial_Miniatur{"Tankbusta",Fraktion::Orks,252}, Spezial_Miniatur{"Inceptors", Fraktion::SM,403},Spezial_Miniatur(),Spezial_Miniatur{"Kabalite Warrior",Fraktion::Drukhari,324}};
    
  /*check({ 
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
  check({
    {"iterator_operator*", iterator_deref_operator()},
    {"const_iterator_operator*", const_iterator_deref_operator()},
    {"iterator_operator->", iterator_arrow_operator()},
    {"const_iterator_operator->", const_iterator_arrow_operator()},
    {"iterator_operator==", iterator_equals()},
    {"const_iterator_operator==", const_iterator_equals()},
    {"iterator_operator!=", iterator_not_equals()},
    {"const_iterator_operator!=", const_iterator_not_equals()},
    {"iterator_operator++", plus_plus_iterator()},
    {"const_iterator_operator++", plus_plus_const_iterator()},
    {"iterator_operator++(int)",iterator_plus_plus()},
    {"const_iterator_operator++(int)", const_iterator_plus_plus()},
    {"iterator_type_conversion", operator_const_iterator()},
    {"insert", insert()},
    {"erase", erase()},
    {"iterator_constancy", iterator_constancy()}
    
  });*/
  return 0;
}