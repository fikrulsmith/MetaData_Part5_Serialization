#pragma once

#include "Vector.h"
#include "enumconv.h"

enum class Test
{
	test1,
	test2
};
template<> char const* enumStrings<Test>::data[] = { "Test1", "Test2"};

enum class Test2
{
	test21,
	test22
};
template<> char const* enumStrings<Test2>::data[] = { "Test     1", "Test         2" };

inline std::ostream& operator<<(std::ostream& out, Test& day)
{
	out << lexical_cast_toStr<Test>(day);
    return out;
}

struct Object
{
public:
  Object( int id );
  ~Object( );

  META_DATA( Object );

private:
  int ID;
  bool active;
  float fire{ 15.0f };
  double x;
  Test test{ Test::test1 };
  int fool{ 5 };
  ECVec3 vec{0.f,0.f,0.f};
};
