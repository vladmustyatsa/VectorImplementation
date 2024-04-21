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
template<typename T>
bool default_constructor() {
  Vector<T> v;
  return (v.size() == 0 && v.capacity() == 0);
}

template<typename T>
bool copy_constructor() {
  Vector<T> v1{1,2,3};
  Vector<T> v2{v1};
  v1[2] = 0;
  bool case1 = (v2.size() == v1.size()
   && v2.capacity() == v1.size() 
   && v1[2]!=v2[2]);

  Vector<T> v11;
  Vector<T> v22{v11};
  v22.push_back(1);
  bool case2 = (v22.size() != v11.size()
   && v22.capacity() != v11.size() 
   && v22[0] && v11.empty());
  
  return case1 && case2;
}

template<typename T>
bool constructor_with_n() {
  Vector<T> v(2);
  bool case1 = (v.size() == 0 && v.capacity() == 2);
  Vector<T> v1(0);
  bool case2 = (v1.size() == 0 && v1.capacity() == 0);
  return case1 & case2;
}

template<typename T>
bool constructor_with_list() {
  Vector<T> v1{1,2,3};
  bool case1 = (v1.size()==3 
                && v1.capacity()==3 
                && v1[0]==1 && v1[1]==2 
                && v1[2]==3);
  Vector<T> v2{};
  bool case2 = (v2.size()==0 && v2.capacity()==0);
  return case1 && case2;
}

template<typename T>
bool assignment() {
  Vector<T> v1{1,2};
  Vector<T> v2 = v1;
  //v2 = v1;
  bool case1 = (v1.size()==v2.size() 
               && v1.capacity()==v2.capacity()
               && v1[0]==v2[0] && v1[0]&&v2[0]);
  return case1;
}

template<typename T>
bool size() {
  Vector<T> v1, v2(0), v3{};
  bool case1 = (v1.size()==0 && v2.size()==0 
               && v3.size()==0);
  Vector<T> v4{1,2,3};
  bool case2 = (v4.size() == 3);
  return case1 && case2;
}

template<typename T>
bool empty() {
  Vector<T> v1, v2(0), v3{};
  bool case1 = (v1.empty() && v2.empty()
               && v3.empty());
  Vector<T> v4{1,2,3};
  bool case2 = (!v4.empty());
  return case1 && case2;
}

template<typename T>
bool clear() {
  Vector<T> v1, v2(0), v3{};
  v1.clear();v2.clear();v3.clear();
  bool case1 = (v1.empty() && v2.empty()
               && v3.empty());
  Vector<T> v4{1,2,3};
  v4.clear();
  bool case2 = (v4.empty());
  return case1 && case2;
}

template<typename T>
bool reserve() {
  Vector<T> v1, v2(0), v3{};
  v1.reserve(2);v2.reserve(2);v3.reserve(0);
  bool case1 = (v1.capacity()==2 && v2.capacity()==2
               && v3.capacity()==0);
  Vector<T> v4{1,2,3}, v5{1};
  v4.reserve(4); v5.reserve(0);
  bool case2 = (v4.capacity()==4 && v5.capacity()==1);
  return case1 && case2;
}

template<typename T>
bool shrink_to_fit() {
  Vector<T> v1, v2(0), v3(2), v4{1,2,3}, v5{};
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
template<typename T>
bool operator==(const Vector<T>& v1, const Vector<T>& v2) {
  bool flag1 = (v1.size()==v2.size());
  bool flag2 = (v1.capacity()==v2.capacity());
  if(flag1 && flag2)
    for(int i=0; i<v1.size(); ++i) 
      if (v1[i]!=v2[i])
        return false;
  return flag1 && flag2;
}

template<typename T>
bool push_back() {
  Vector<T> v1, v2(0), v3{}, v4{1,2,3};
  v1.push_back(1);
  v2.push_back(1);
  v3.push_back(1);
  v4.push_back(1);
  Vector<T> v11{1}, v22{1}, v33{1}, v44{1,2,3,1};
  bool case1 = (v1==v11 && v2==v22 && v3==v33 & v4==v44);
  return case1;
}

template<typename T>
bool pop_back() {
  Vector<T> v1, v2(0), v3{}, v4{1,2,3};
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
  Vector<T> v44{1,2};
  v44.reserve(3);
  bool case4 = (v4==v44);
  
  return case1 && case2 && case3 && case4;
}

template<typename T>
bool brackets_operator() {
  Vector<T> v1, v2(0), v3{}, v4{1,2,3};
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

template<typename T>
bool const_brackets_operator() {
  const Vector<T> v1, v2(0), v3{}, v4{1,2,3};
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

template<typename T>
bool capacity() {
  Vector<T> v1, v2(0), v3{}, v4{1,2,3};
  bool case1 = (v1.capacity()==0 && v2.capacity()==0                   && v3.capacity()==0 
                && v4.capacity()==3);
  v1.reserve(1);v2.reserve(1);v3.reserve(1);
  v4.reserve(4);
  bool case2= (v1.capacity()==1 && v2.capacity()==1                   && v3.capacity()==1
               && v4.capacity()==4);
  return case1 && case2;
}

template<typename T>
bool cout_operator() {
  
  Vector<T> v1, v2(0), v3{}, v4{50,51,52};
  cout << v1 << endl << v2 << endl 
    << v3 << endl << v4 << endl;
  
  return true;
}

template<typename T>
bool iterator_deref_operator() {
  typename Vector<T>::iterator it1;
  bool case1 = false;
  try {
    *it1;
  } catch (runtime_error& e) {
    case1 = true;
  }
  Vector<T> v;
  typename Vector<T>::iterator it2 {v.begin()};
  bool case2 = false;
  try {
    *it2;
  } catch (runtime_error& e) {
    case2 = true;
  }

  Vector<T> vv {1,2};
  typename Vector<T>::iterator it3 {vv.begin()};
  bool case3 = (*it3 == 1);

  return (case1 && case2 && case3);
}

template<typename T>
bool const_iterator_deref_operator() {
  typename Vector<T>::const_iterator it1;
  bool case1 = false;
  try {
    *it1;
  } catch (runtime_error& e) {
    case1 = true;
  }
  Vector<T> v;
  typename Vector<T>::const_iterator it2 {v.begin()};
  bool case2 = false;
  try {
    *it2;
  } catch (runtime_error& e) {
    case2 = true;
  }

  Vector<T> vv {1,2};
  typename Vector<T>::const_iterator it3 {vv.begin()};
  bool case3 = (*it3 == 1);

  return (case1 && case2 && case3);
}

template<typename T>
bool iterator_arrow_operator() {
  typename Vector<T>::iterator it1;
  bool case1 = false;
  try {
    it1.operator->();
  } catch (runtime_error& e) {
    case1 = true;
  }
  Vector<T> v;
  typename Vector<T>::iterator it2 {v.begin()};
  bool case2 = false;
  try {
    it2.operator->();
  } catch (runtime_error& e) {
    case2 = true;
  }

  Vector<T> vv {1,2};
  typename Vector<T>::iterator it3 {vv.begin()};
  bool case3 = (it3.operator->() == &vv[0]);

  return (case1 && case2 && case3);
}

template<typename T>
bool const_iterator_arrow_operator() {
  typename Vector<T>::const_iterator it1;
  bool case1 = false;
  try {
    it1.operator->();
  } catch (runtime_error& e) {
    case1 = true;
  }
  Vector<T> v;
  typename Vector<T>::const_iterator it2 {v.begin()};
  bool case2 = false;
  try {
    it2.operator->();
  } catch (runtime_error& e) {
    case2 = true;
  }

  Vector<T> vv {1,2};
  typename Vector<T>::const_iterator it3 {vv.begin()};
  bool case3 = (it3.operator->() == &vv[0]);

  return (case1 && case2 && case3);
}

template<typename T>
bool iterator_equals() {
  typename Vector<T>::iterator it1;
  typename Vector<T>::iterator it2;
  bool case1 = (it1 == it2);
  
  Vector<T> v;
  typename Vector<T>::iterator it3 {v.begin()};
  typename Vector<T>::iterator it4 {v.end()};
  bool case2 = (it3 == it4);
  
  Vector<T> vv {1,2};
  typename Vector<T>::iterator it5 {vv.begin()};
  typename Vector<T>::iterator it6 {it5};
  bool case3 = (it5 == it6);

  return (case1 && case2 && case3);
}

template<typename T>
bool const_iterator_equals() {
  typename Vector<T>::const_iterator it1;
  typename Vector<T>::const_iterator it2;
  bool case1 = (it1 == it2);

  Vector<T> v;
  typename Vector<T>::const_iterator it3 {v.begin()};
  typename Vector<T>::const_iterator it4 {v.end()};
  bool case2 = (it3 == it4);

  Vector<T> vv {1,2};
  typename Vector<T>::const_iterator it5 {vv.begin()};
  typename Vector<T>::const_iterator it6 {it5};
  bool case3 = (it5 == it6);

  return (case1 && case2 && case3);
}

template<typename T>
bool iterator_not_equals() {
  typename Vector<T>::iterator it1;
  typename Vector<T>::iterator it2;
  bool case1 = !(it1 != it2);

  Vector<T> v;
  typename Vector<T>::iterator it3 {v.begin()};
  typename Vector<T>::iterator it4 {v.end()};
  bool case2 = !(it3 != it4);

  Vector<T> vv {1,2};
  typename Vector<T>::iterator it5 {vv.begin()};
  typename Vector<T>::iterator it6 {vv.end()};
  bool case3 = (it5 != it6);

  return (case1 && case2 && case3);
}

template<typename T>
bool const_iterator_not_equals() {
  typename Vector<T>::const_iterator it1;
  typename Vector<T>::const_iterator it2;
  bool case1 = !(it1 != it2);

  Vector<T> v;
  typename Vector<T>::const_iterator it3 {v.begin()};
  typename Vector<T>::const_iterator it4 {v.end()};
  bool case2 = !(it3 != it4);

  Vector<T> vv {1,2};
  typename Vector<T>::const_iterator it5 {vv.begin()};
  typename Vector<T>::const_iterator it6 {vv.end()};
  bool case3 = (it5 != it6);

  return (case1 && case2 && case3);
}

template<typename T>
bool plus_plus_iterator() {
  typename Vector<T>::iterator it1;
  typename Vector<T>::iterator it2 = it1;
  ++it1;
  bool case1 = (it1 == it2);

  Vector<T> v;
  typename Vector<T>::iterator it3 {v.begin()};
  typename Vector<T>::iterator it4 {v.end()};
  ++it3;
  bool case2 = (it3 == it4);
  
  Vector<T> vv {1,2};
  typename Vector<T>::iterator it5 {vv.begin()};
  typename Vector<T>::iterator it6 {vv.end()};
  ++it5;
  bool case3 = (++it5 == it6);
  
  return (case1 && case2 && case3);
}

template<typename T>
bool plus_plus_const_iterator() {
  typename Vector<T>::const_iterator it1;
  typename Vector<T>::const_iterator it2 = it1;
  ++it1;
  bool case1 = (it1 == it2);

  Vector<T> v;
  typename Vector<T>::const_iterator it3 {v.begin()};
  typename Vector<T>::const_iterator it4 {v.end()};
  ++it3;
  bool case2 = (it3 == it4);

  Vector<T> vv {1,2};
  typename Vector<T>::const_iterator it5 {vv.begin()};
  typename Vector<T>::const_iterator it6 {vv.end()};
  ++it5;
  bool case3 = (++it5 == it6);

  return (case1 && case2 && case3);
}  

template<typename T>
bool iterator_plus_plus() {
  typename Vector<T>::iterator it1;
  typename Vector<T>::iterator it2 = it1;
  it1++;
  bool case1 = (it1 == it2);

  Vector<T> v;
  typename Vector<T>::iterator it3 {v.begin()};
  typename Vector<T>::iterator it4 {v.end()};
  it3++;
  bool case2 = (it3 == it4);

  Vector<T> vv {1,2};
  typename Vector<T>::iterator it5 {vv.begin()};
  typename Vector<T>::iterator it6 {vv.begin()};
  bool case31 = (it5++ == it6);
  it5++;
  bool case32 = (it5 == vv.end()); 
  

  return (case1 && case2 && case31 && case32);
}

template<typename T>
bool const_iterator_plus_plus() {
  typename Vector<T>::const_iterator it1;
  typename Vector<T>::const_iterator it2 = it1;
  it1++;
  bool case1 = (it1 == it2);

  Vector<T> v;
  typename Vector<T>::const_iterator it3 {v.begin()};
  typename Vector<T>::const_iterator it4 {v.end()};
  it3++;
  bool case2 = (it3 == it4);

  Vector<T> vv {1,2};
  typename Vector<T>::const_iterator it5 {vv.begin()};
  typename Vector<T>::const_iterator it6 {vv.begin()};
  bool case31 = (it5++ == it6);
  it5++;
  bool case32 = (it5 == vv.end()); 


  return (case1 && case2 && case31 && case32);
}

template<typename T>
bool operator_const_iterator() {
  typename Vector<T>::iterator it1;
  typename Vector<T>::const_iterator it2 = it1;
  bool case1 = (it1 == it2);

  Vector<T> v;
  typename Vector<T>::iterator it3 {v.begin()};
  typename Vector<T>::const_iterator it4 = it3;

  bool case2 = (it3 == it4);

  Vector<T> vv {1,2};
  typename Vector<T>::iterator it5 {vv.begin()};
  typename Vector<T>::const_iterator it6 = it5;
  bool case3 = (it5 == it6);

  return (case1 && case2 && case3);
}

template<typename T>
bool insert() {
  Vector<T> v1(1);
  v1.insert(v1.begin(), 2);
  Vector<T> v2 {2};
  bool case1 = (v1 == v2);


  Vector<T> v3 {1,2,3};
  v3.insert(v3.end(), 4);
  Vector<T> v4 {1,2,3,4};
  bool case2 = true;
  for (typename Vector<T>::size_type i=0; i < v3.size(); ++i)
    if (v3[i] != v4[i]) {
      case2 = false;
      break;
    }
  
  return (case1 && case2);
}

template<typename T>
bool erase() {
  Vector<T> v1 {1,2,3};
  v1.erase(v1.begin());
  Vector<T> v2 {2,3};
  bool case1 = true;
  for (typename Vector<T>::size_type i=0; i < v1.size(); ++i)
    if (v1[i] != v2[i]) {
      case1 = false;
      break;
    }
  return case1;
}

template<typename T>
bool iterator_constancy() {
  const Vector<T> v{1,2,3};
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