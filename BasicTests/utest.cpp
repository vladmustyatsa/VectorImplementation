#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../vector.h"
#include "../vector.h" // check include guards
#include "doctest.h"
#include <sstream>

TEST_CASE("Vector<double>Test, DefaultConstructorEmpty") {
  Vector<double> v;
  CHECK(v.size() == 0);
  CHECK(v.empty() == true);
}

TEST_CASE("Vector<double>Test, PushBack") {
  Vector<double> v(0);
  CHECK(v.size() == 0);
  CHECK(v.empty() == true);

  for(int i=0; i < 20; ++i) v.push_back(i);

  CHECK(v.size() == 20);
  CHECK(v.empty() == false);
}

TEST_CASE("Vector<double>Test, CopyConstructor") {
  const Vector<double> v({0,1,2,3,4,5,6,7,8,9});
  Vector<double> other{v};

  CHECK( other.size() == 10 );
  CHECK( other.empty() == false );

  for (size_t i=0;i<other.size();i++) {
    CHECK(v[i] == other[i]);
  }

  other.pop_back();

  CHECK( v.size() == other.size() + 1 );
  // Just for memory stuff....
  for(double i{0};i<200;i+=1){
    other.push_back(i);
  }
}

TEST_CASE("Vector<double>Test, PopBack") {
  Vector<double> v({0,1,2,3,4,5,6,7,8,9});
  CHECK(v.size() == 10);
  CHECK(v.empty() == false);

  for(int i=10; i > 0; --i) {
    v.pop_back();
    CHECK(v.size() == i-1);
  }

  CHECK_THROWS_AS(v.pop_back(), std::exception);
}

TEST_CASE("Vector<double>Test, Assignment") {
  const Vector<double> a({0.,1,2,3,4,5,6,7,8,9});
  Vector<double> b(0);
  b = a;
  // Just for memory stuff....
  for(double i{0};i<200;i+=1){
    b.push_back(i);
  }

  for(size_t i=0; i < a.size(); ++i)
    CHECK(a[i] == b[i]);

  CHECK(a.size() == 10);
  CHECK(b.size() == 210);

  b.pop_back();

  CHECK(b.size() ==  209);
  CHECK(a.size() == 10);
  // Just for memory stuff....
  Vector<double> nca{a};
  nca = b;
  for(double i{0};i<200;i+=1){
    nca.push_back(i);
  }
}

TEST_CASE("Vector<double>Test, Clear") {
  Vector<double> v({0,1,2,3,4,5,6,7,8,9});
  CHECK(v.size() == 10);
  v.clear();
  CHECK(v.size() ==  0);
}

TEST_CASE("Vector<double>Test, Capacity") {
  Vector<double> v({0,1,2,3,4,5,6,7,8,9});
  v.reserve(50);
  CHECK(v.capacity() == 50);
  v.clear();
  CHECK(v.capacity() == 50);
}

TEST_CASE("Vector<double>Test, Reserve") {
  Vector<double> v;
  v.reserve(0); // noop
  for(int i=0; i < 20; ++i) v.push_back(i);
  v.reserve(50);
  CHECK(v.capacity() == 50);

  CHECK(v.size() == 20);
  v.reserve(10); // noop
  CHECK(v.size() == 20);
  CHECK(v.capacity() == 50);
}

TEST_CASE("Vector<double>Test, ShrinkToFit") {
  Vector<double> v({0,1,2,3,4,5,6,7,8,9});
  v.reserve(20);
  v.shrink_to_fit();
  for(int i=0; i < 10; ++i) CHECK(v[i] == i);
  CHECK(v.size() == 10);
  CHECK(v.capacity() == 10);
}

TEST_CASE("Vector<double>Test, BracketOperator") {
  Vector<double> v({0,1,2,3,4,5,6,7,8,9});
  CHECK(v[9] == 9);
  CHECK_THROWS_AS(v[10], std::exception);
  CHECK_THROWS_AS(v[-1], std::exception);
}

TEST_CASE("Vector<double>Test, const_bracket_operator") {
  const Vector<double> v({0,1,2,3,4,5,6,7,8,9});
  CHECK(v[9] == 9);
  CHECK_THROWS_AS(v[10], std::exception);
  CHECK_THROWS_AS(v[-1], std::exception);
}
