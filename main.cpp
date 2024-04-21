#include "mytests_templates.h"
#include "vector.h"
#include <iostream>
using namespace std;

int main() {
  cout << "INT:" << endl;
  check({{"operator[]", brackets_operator<int>()},
         {"const operator[]", const_brackets_operator<int>()},
         {"capacity", capacity<int>()},
         {"operator<<", cout_operator<int>()},
         {"assignment", assignment<int>()},
         {"size", size<int>()},
         {"empty", empty<int>()},
         {"clear", clear<int>()},
         {"reserve", reserve<int>()},
         {"shrink_to_fit", shrink_to_fit<int>()},
         {"push_back", push_back<int>()},
         {"pop_back", pop_back<int>()},
         {"default_constructor", default_constructor<int>()},
         {"copy_constructor", copy_constructor<int>()},
         {"constructor_with_n", constructor_with_n<int>()},
         {"constructor_with_list", constructor_with_list<int>()}});
  check({{"iterator_operator*", iterator_deref_operator<int>()},
         {"const_iterator_operator*", const_iterator_deref_operator<int>()},
         {"iterator_operator->", iterator_arrow_operator<int>()},
         {"const_iterator_operator->", const_iterator_arrow_operator<int>()},
         {"iterator_operator==", iterator_equals<int>()},
         {"const_iterator_operator==", const_iterator_equals<int>()},
         {"iterator_operator!=", iterator_not_equals<int>()},
         {"const_iterator_operator!=", const_iterator_not_equals<int>()},
         {"iterator_operator++", plus_plus_iterator<int>()},
         {"const_iterator_operator++", plus_plus_const_iterator<int>()},
         {"iterator_operator++(int)", iterator_plus_plus<int>()},
         {"const_iterator_operator++(int)", const_iterator_plus_plus<int>()},
         {"iterator_type_conversion", operator_const_iterator<int>()},
         {"insert", insert<int>()},
         {"erase", erase<int>()},
         {"iterator_constancy", iterator_constancy<int>()}

  });
  cout << "\n";

  cout << "DOUBLE:" << endl;
  check({{"operator[]", brackets_operator<double>()},
         {"const operator[]", const_brackets_operator<double>()},
         {"capacity", capacity<double>()},
         {"operator<<", cout_operator<double>()},
         {"assignment", assignment<double>()},
         {"size", size<double>()},
         {"empty", empty<double>()},
         {"clear", clear<double>()},
         {"reserve", reserve<double>()},
         {"shrink_to_fit", shrink_to_fit<double>()},
         {"push_back", push_back<double>()},
         {"pop_back", pop_back<double>()},
         {"default_constructor", default_constructor<double>()},
         {"copy_constructor", copy_constructor<double>()},
         {"constructor_with_n", constructor_with_n<double>()},
         {"constructor_with_list", constructor_with_list<double>()}});
  check({{"iterator_operator*", iterator_deref_operator<double>()},
         {"const_iterator_operator*", const_iterator_deref_operator<double>()},
         {"iterator_operator->", iterator_arrow_operator<double>()},
         {"const_iterator_operator->", const_iterator_arrow_operator<double>()},
         {"iterator_operator==", iterator_equals<double>()},
         {"const_iterator_operator==", const_iterator_equals<double>()},
         {"iterator_operator!=", iterator_not_equals<double>()},
         {"const_iterator_operator!=", const_iterator_not_equals<double>()},
         {"iterator_operator++", plus_plus_iterator<double>()},
         {"const_iterator_operator++", plus_plus_const_iterator<double>()},
         {"iterator_operator++(double)", iterator_plus_plus<double>()},
         {"const_iterator_operator++(double)",
          const_iterator_plus_plus<double>()},
         {"iterator_type_conversion", operator_const_iterator<double>()},
         {"insert", insert<double>()},
         {"erase", erase<double>()},
         {"iterator_constancy", iterator_constancy<double>()}

  });
  cout << "\n";

  cout << "CHAR:" << endl;
  check({ 
    {"operator[]", brackets_operator<char>()},
         {"const operator[]", const_brackets_operator<char>()},
         {"capacity", capacity<char>()},
         {"operator<<", cout_operator<char>()},
         {"assignment", assignment<char>()},
         {"size", size<char>()},
         {"empty", empty<char>()},
         {"clear", clear<char>()},
         {"reserve", reserve<char>()},
         {"shrink_to_fit", shrink_to_fit<char>()},
         {"push_back", push_back<char>()},
         {"pop_back", pop_back<char>()},
         {"default_constructor", default_constructor<char>()},
         {"copy_constructor", copy_constructor<char>()},
         {"constructor_with_n", constructor_with_n<char>()},
         {"constructor_with_list", constructor_with_list<char>()}
    }); 
  check({
    {"iterator_operator*", iterator_deref_operator<char>()},
    {"const_iterator_operator*", const_iterator_deref_operator<char>()},
    {"iterator_operator->", iterator_arrow_operator<char>()},
    {"const_iterator_operator->", const_iterator_arrow_operator<char>()},
    {"iterator_operator==", iterator_equals<char>()},
    {"const_iterator_operator==", const_iterator_equals<char>()},
    {"iterator_operator!=", iterator_not_equals<char>()},
    {"const_iterator_operator!=", const_iterator_not_equals<char>()},
    {"iterator_operator++", plus_plus_iterator<char>()},
    {"const_iterator_operator++", plus_plus_const_iterator<char>()},
    {"iterator_operator++(char)",iterator_plus_plus<char>()},
    {"const_iterator_operator++(char)", const_iterator_plus_plus<char>()},
    {"iterator_type_conversion", operator_const_iterator<char>()},
    {"insert", insert<char>()},
    {"erase", erase<char>()},
    {"iterator_constancy", iterator_constancy<char>()}

  });
  cout << "\n";

  check({{"templates", templates()}});
  /*
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

  });
  check({
    {"templates", templates()}
  });
  */
  return 0;
}