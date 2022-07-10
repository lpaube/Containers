#include "stack.hpp"
#include <stack>
#include <vector>
#include "vector.hpp"

#ifndef NAMESPACE
#define NAMESPACE std
#endif

template <typename T>
void stack_push(NAMESPACE::stack<T, NAMESPACE::vector<T> >& sreal)
{
  for (int i = 0; i < 100; i += 2)
  {
    sreal.push(i);
  }
}

template <typename T>
void stack_comparison(NAMESPACE::stack<T, NAMESPACE::vector<T> >& sreal
    , NAMESPACE::stack<T, NAMESPACE::vector<T> >& sref)
{
  std::cout << "gt: " << (sreal > sref) << std::endl;
  std::cout << "lt: " << (sreal < sref) << std::endl;
  std::cout << "gteq: " << (sreal >= sref) << std::endl;
  std::cout << "lteq: " << (sreal <= sref) << std::endl;
  std::cout << "eq: " << (sreal == sref) << std::endl;
  std::cout << "neq: " << (sreal != sref) << std::endl;
}

void test_stack()
{
  NAMESPACE::stack<int, NAMESPACE::vector<int> > s1;

  std::cout << "=== Testing stack push (stack_push) ===" << std::endl;
  stack_push(s1);
  std::cout << "GOOD: push did not crash" << std::endl;

  std::cout << "=== Testing stack copy constructor ===" << std::endl;
  NAMESPACE::stack<int, NAMESPACE::vector<int> > s2 = s1;
  std::cout << "GOOD: copy constructor did not crash" << std::endl;

  std::cout << "=== Testing stack pop ===" << std::endl;
  s2.pop();
  s2.pop();
  s2.pop();
  std::cout << "GOOD: pop did not crash" << std::endl;

  std::cout << "=== Testing stack comparisons (stack_comparison) ===" << std::endl;
  stack_comparison(s1, s2);

  std::cout << std::endl;
}
