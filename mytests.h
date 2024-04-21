#ifndef MYTESTS_H
#define MYTESTS_H
#include "vector.h"
#include<map>
#include<exception>
#include<iostream>
#include<string>
using namespace std;


void check(map<string, bool> map) {
  for(auto& pair: map)
    cout << pair.first << ": " << (pair.second ? "Passed" : "FAILED") << endl;
  //cout << (flag ? "True" : "False") << endl;
}

bool default_constructor() {
  Vector<double> v;
  return (v.size() == 0 && v.capacity() == 0);
}

bool copy_constructor() {
  Vector<double> v1{1,2,3};
  Vector<double> v2{v1};
  v1[2] = 0;
  bool case1 = (v2.size() == v1.size()
   && v2.capacity() == v1.size() 
   && v1[2]!=v2[2]);

  Vector<double> v11;
  Vector<double> v22{v11};
  v22.push_back(1);
  bool case2 = (v22.size() != v11.size()
   && v22.capacity() != v11.size() 
   && v22[0] && v11.empty());
  
  return case1 && case2;
}

bool constructor_with_n() {
  Vector<double> v(2);
  bool case1 = (v.size() == 0 && v.capacity() == 2);
  Vector<double> v1(0);
  bool case2 = (v1.size() == 0 && v1.capacity() == 0);
  return case1 & case2;
}

bool constructor_with_list() {
  Vector<double> v1{1,2,3};
  bool case1 = (v1.size()==3 
                && v1.capacity()==3 
                && v1[0]==1 && v1[1]==2 
                && v1[2]==3);
  Vector<double> v2{};
  bool case2 = (v2.size()==0 && v2.capacity()==0);
  return case1 && case2;
}

bool assignment() {
  Vector<double> v1{1,2};
  Vector<double> v2 = v1;
  //v2 = v1;
  bool case1 = (v1.size()==v2.size() 
               && v1.capacity()==v2.capacity()
               && v1[0]==v2[0] && v1[0]&&v2[0]);
  return case1;
}

bool size() {
  Vector<double> v1, v2(0), v3{};
  bool case1 = (v1.size()==0 && v2.size()==0 
               && v3.size()==0);
  Vector<double> v4{1,2,3};
  bool case2 = (v4.size() == 3);
  return case1 && case2;
}

bool empty() {
  Vector<double> v1, v2(0), v3{};
  bool case1 = (v1.empty() && v2.empty()
               && v3.empty());
  Vector<double> v4{1,2,3};
  bool case2 = (!v4.empty());
  return case1 && case2;
}

bool clear() {
  Vector<double> v1, v2(0), v3{};
  v1.clear();v2.clear();v3.clear();
  bool case1 = (v1.empty() && v2.empty()
               && v3.empty());
  Vector<double> v4{1,2,3};
  v4.clear();
  bool case2 = (v4.empty());
  return case1 && case2;
}

bool reserve() {
  Vector<double> v1, v2(0), v3{};
  v1.reserve(2);v2.reserve(2);v3.reserve(0);
  bool case1 = (v1.capacity()==2 && v2.capacity()==2
               && v3.capacity()==0);
  Vector<double> v4{1,2,3}, v5{1};
  v4.reserve(4); v5.reserve(0);
  bool case2 = (v4.capacity()==4 && v5.capacity()==1);
  return case1 && case2;
}

bool shrink_to_fit() {
  Vector<double> v1, v2(0), v3(2), v4{1,2,3}, v5{};
  v1.shrink_to_fit(); v2.shrink_to_fit();
  v3.shrink_to_fit();
  v4.reserve(4);
  v4.shrink_to_fit();
  v5.reserve(2);
  v5.shrink_to_fit();
  bool case1 = (v1.capacity()==0 && v2.capacity()==0 
               && v3.capacity()==0 
               && v4.capacity()==3
               && v5.capacity()==0);
  return case1;
}
bool operator==(const Vector<double>& v1, const Vector<double>& v2) {
  bool flag1 = (v1.size()==v2.size());
  bool flag2 = (v1.capacity()==v2.capacity());
  if(flag1 && flag2)
    for(int i=0; i<v1.size(); ++i) 
      if (v1[i]!=v2[i])
        return false;
  return flag1 && flag2;
}
  
bool push_back() {
  Vector<double> v1, v2(0), v3{}, v4{1,2,3};
  v1.push_back(1);
  v2.push_back(1);
  v3.push_back(1);
  v4.push_back(1);
  Vector<double> v11{1}, v22{1}, v33{1}, v44{1,2,3,1};
  bool case1 = (v1==v11 && v2==v22 && v3==v33 & v4==v44);
  return case1;
}

bool pop_back() {
  Vector<double> v1, v2(0), v3{}, v4{1,2,3};
  bool case1 = false;
  try{
    v1.pop_back();
  } catch (runtime_error& e){
    case1 = true;
  }
  bool case2 = false;
  try{
    v2.pop_back();
  } catch (runtime_error& e){
    case2 = true;
  }
  bool case3 = false;
  try{
    v3.pop_back();
  } catch (runtime_error& e){
    case3 = true;
  }
  v4.pop_back();
  Vector<double> v44{1,2};
  v44.reserve(3);
  bool case4 = (v4==v44);
  
  return case1 && case2 && case3 && case4;
}

bool brackets_operator() {
  Vector<double> v1, v2(0), v3{}, v4{1,2,3};
  bool case1 = false;
  try{
    v1[0];
  } catch (runtime_error& e) {
    case1 = true;
  }
  bool case2 = false;
  try{
    v2[0];
  } catch (runtime_error& e) {
    case2 = true;
  }
  bool case3 = false;
  try{
    v3[0];
  } catch (runtime_error& e) {
    case3 = true;
  }
  bool case4 = false;
  try{
    v4[3];
  } catch (runtime_error& e) {
    case4 = true;
  }
  bool case5 = (v4[2]==3);
  v4[0] = 0;
  bool case6 = (v4[0]==0);
  return case1 && case2 && case3 
         && case4 && case5 & case6;
}

bool const_brackets_operator() {
  const Vector<double> v1, v2(0), v3{}, v4{1,2,3};
  bool case1 = false;
  try{
    v1[0];
  } catch (runtime_error& e) {
    case1 = true;
  }
  bool case2 = false;
  try{
    v2[0];
  } catch (runtime_error& e) {
    case2 = true;
  }
  bool case3 = false;
  try{
    v3[0];
  } catch (runtime_error& e) {
    case3 = true;
  }
  bool case4 = false;
  try{
    v4[3];
  } catch (runtime_error& e) {
    case4 = true;
  }
  
  bool case5 = (v4[2]==3);
  
  return case1 && case2 && case3 
         && case4 && case5;
}

bool capacity() {
  Vector<double> v1, v2(0), v3{}, v4{1,2,3};
  bool case1 = (v1.capacity()==0 && v2.capacity()==0                   && v3.capacity()==0 
                && v4.capacity()==3);
  v1.reserve(1);v2.reserve(1);v3.reserve(1);
  v4.reserve(4);
  bool case2= (v1.capacity()==1 && v2.capacity()==1                   && v3.capacity()==1
               && v4.capacity()==4);
  return case1 && case2;
}

bool cout_operator() {
  
  Vector<double> v1, v2(0), v3{}, v4{1,2,3};
  cout << v1 << endl << v2 << endl 
    << v3 << endl << v4 << endl;
  
  return true;
}

bool iterator_deref_operator() {
  Vector<double>::iterator it1;
  bool case1 = false;
  try {
    *it1;
  } catch (runtime_error& e) {
    case1 = true;
  }
  Vector<double> v;
  Vector<double>::iterator it2 {v.begin()};
  bool case2 = false;
  try {
    *it2;
  } catch (runtime_error& e) {
    case2 = true;
  }

  Vector<double> vv {1,2};
  Vector<double>::iterator it3 {vv.begin()};
  bool case3 = (*it3 == 1);

  return (case1 && case2 && case3);
}

bool const_iterator_deref_operator() {
  Vector<double>::const_iterator it1;
  bool case1 = false;
  try {
    *it1;
  } catch (runtime_error& e) {
    case1 = true;
  }
  Vector<double> v;
  Vector<double>::const_iterator it2 {v.begin()};
  bool case2 = false;
  try {
    *it2;
  } catch (runtime_error& e) {
    case2 = true;
  }

  Vector<double> vv {1,2};
  Vector<double>::const_iterator it3 {vv.begin()};
  bool case3 = (*it3 == 1);

  return (case1 && case2 && case3);
}

bool iterator_arrow_operator() {
  Vector<double>::iterator it1;
  bool case1 = false;
  try {
    it1.operator->();
  } catch (runtime_error& e) {
    case1 = true;
  }
  Vector<double> v;
  Vector<double>::iterator it2 {v.begin()};
  bool case2 = false;
  try {
    it2.operator->();
  } catch (runtime_error& e) {
    case2 = true;
  }

  Vector<double> vv {1,2};
  Vector<double>::iterator it3 {vv.begin()};
  bool case3 = (it3.operator->() == &vv[0]);

  return (case1 && case2 && case3);
}

bool const_iterator_arrow_operator() {
  Vector<double>::const_iterator it1;
  bool case1 = false;
  try {
    it1.operator->();
  } catch (runtime_error& e) {
    case1 = true;
  }
  Vector<double> v;
  Vector<double>::const_iterator it2 {v.begin()};
  bool case2 = false;
  try {
    it2.operator->();
  } catch (runtime_error& e) {
    case2 = true;
  }

  Vector<double> vv {1,2};
  Vector<double>::const_iterator it3 {vv.begin()};
  bool case3 = (it3.operator->() == &vv[0]);

  return (case1 && case2 && case3);
}

bool iterator_equals() {
  Vector<double>::iterator it1;
  Vector<double>::iterator it2;
  bool case1 = (it1 == it2);
  
  Vector<double> v;
  Vector<double>::iterator it3 {v.begin()};
  Vector<double>::iterator it4 {v.end()};
  bool case2 = (it3 == it4);
  
  Vector<double> vv {1,2};
  Vector<double>::iterator it5 {vv.begin()};
  Vector<double>::iterator it6 {it5};
  bool case3 = (it5 == it6);

  return (case1 && case2 && case3);
}

bool const_iterator_equals() {
  Vector<double>::const_iterator it1;
  Vector<double>::const_iterator it2;
  bool case1 = (it1 == it2);

  Vector<double> v;
  Vector<double>::const_iterator it3 {v.begin()};
  Vector<double>::const_iterator it4 {v.end()};
  bool case2 = (it3 == it4);

  Vector<double> vv {1,2};
  Vector<double>::const_iterator it5 {vv.begin()};
  Vector<double>::const_iterator it6 {it5};
  bool case3 = (it5 == it6);

  return (case1 && case2 && case3);
}

bool iterator_not_equals() {
  Vector<double>::iterator it1;
  Vector<double>::iterator it2;
  bool case1 = !(it1 != it2);

  Vector<double> v;
  Vector<double>::iterator it3 {v.begin()};
  Vector<double>::iterator it4 {v.end()};
  bool case2 = !(it3 != it4);

  Vector<double> vv {1,2};
  Vector<double>::iterator it5 {vv.begin()};
  Vector<double>::iterator it6 {vv.end()};
  bool case3 = (it5 != it6);

  return (case1 && case2 && case3);
}

bool const_iterator_not_equals() {
  Vector<double>::const_iterator it1;
  Vector<double>::const_iterator it2;
  bool case1 = !(it1 != it2);

  Vector<double> v;
  Vector<double>::const_iterator it3 {v.begin()};
  Vector<double>::const_iterator it4 {v.end()};
  bool case2 = !(it3 != it4);

  Vector<double> vv {1,2};
  Vector<double>::const_iterator it5 {vv.begin()};
  Vector<double>::const_iterator it6 {vv.end()};
  bool case3 = (it5 != it6);

  return (case1 && case2 && case3);
}

bool plus_plus_iterator() {
  Vector<double>::iterator it1;
  Vector<double>::iterator it2 = it1;
  ++it1;
  bool case1 = (it1 == it2);

  Vector<double> v;
  Vector<double>::iterator it3 {v.begin()};
  Vector<double>::iterator it4 {v.end()};
  ++it3;
  bool case2 = (it3 == it4);
  
  Vector<double> vv {1,2};
  Vector<double>::iterator it5 {vv.begin()};
  Vector<double>::iterator it6 {vv.end()};
  ++it5;
  bool case3 = (++it5 == it6);
  
  return (case1 && case2 && case3);
}

bool plus_plus_const_iterator() {
  Vector<double>::const_iterator it1;
  Vector<double>::const_iterator it2 = it1;
  ++it1;
  bool case1 = (it1 == it2);

  Vector<double> v;
  Vector<double>::const_iterator it3 {v.begin()};
  Vector<double>::const_iterator it4 {v.end()};
  ++it3;
  bool case2 = (it3 == it4);

  Vector<double> vv {1,2};
  Vector<double>::const_iterator it5 {vv.begin()};
  Vector<double>::const_iterator it6 {vv.end()};
  ++it5;
  bool case3 = (++it5 == it6);

  return (case1 && case2 && case3);
}  

bool iterator_plus_plus() {
  Vector<double>::iterator it1;
  Vector<double>::iterator it2 = it1;
  it1++;
  bool case1 = (it1 == it2);

  Vector<double> v;
  Vector<double>::iterator it3 {v.begin()};
  Vector<double>::iterator it4 {v.end()};
  it3++;
  bool case2 = (it3 == it4);

  Vector<double> vv {1,2};
  Vector<double>::iterator it5 {vv.begin()};
  Vector<double>::iterator it6 {vv.begin()};
  bool case31 = (it5++ == it6);
  it5++;
  bool case32 = (it5 == vv.end()); 
  

  return (case1 && case2 && case31 && case32);
}

bool const_iterator_plus_plus() {
  Vector<double>::const_iterator it1;
  Vector<double>::const_iterator it2 = it1;
  it1++;
  bool case1 = (it1 == it2);

  Vector<double> v;
  Vector<double>::const_iterator it3 {v.begin()};
  Vector<double>::const_iterator it4 {v.end()};
  it3++;
  bool case2 = (it3 == it4);

  Vector<double> vv {1,2};
  Vector<double>::const_iterator it5 {vv.begin()};
  Vector<double>::const_iterator it6 {vv.begin()};
  bool case31 = (it5++ == it6);
  it5++;
  bool case32 = (it5 == vv.end()); 


  return (case1 && case2 && case31 && case32);
}

bool operator_const_iterator() {
  Vector<double>::iterator it1;
  Vector<double>::const_iterator it2 = it1;
  bool case1 = (it1 == it2);

  Vector<double> v;
  Vector<double>::iterator it3 {v.begin()};
  Vector<double>::const_iterator it4 = it3;

  bool case2 = (it3 == it4);

  Vector<double> vv {1,2};
  Vector<double>::iterator it5 {vv.begin()};
  Vector<double>::const_iterator it6 = it5;
  bool case3 = (it5 == it6);

  return (case1 && case2 && case3);
}

bool insert() {
  Vector<double> v1(1);
  v1.insert(v1.begin(), 2);
  Vector<double> v2 {2};
  bool case1 = (v1 == v2);


  Vector<double> v3 {1,2,3};
  v3.insert(v3.end(), 4);
  Vector<double> v4 {1,2,3,4};
  bool case2 = true;
  for (Vector<double>::size_type i=0; i < v3.size(); ++i)
    if (v3[i] != v4[i]) {
      case2 = false;
      break;
    }
  
  return (case1 && case2);
}

bool erase() {
  Vector<double> v1 {1,2,3};
  v1.erase(v1.begin());
  Vector<double> v2 {2,3};
  bool case1 = true;
  for (Vector<double>::size_type i=0; i < v1.size(); ++i)
    if (v1[i] != v2[i]) {
      case1 = false;
      break;
    }
  return case1;
}

bool iterator_constancy() {
  const Vector<double> v{1,2,3};
  auto it = v.begin();
  //*it = 1; //check "constancy" by uncommenting it
  return true;
}

bool templates() {
  Vector<int> v1 {1,2,3};
  Vector<char> v2 {'a', 'b', 'c'};
  v2.push_back('a');
  Vector<string> v3 {"asd","123", "qwe"};
  v3.push_back("oiu");
  Vector<int*> v4;
  v4.push_back(&v1[0]);
  *v4[0] = 0;
  bool case1 = (v1[0] == 0);
  return case1;
}
#endif