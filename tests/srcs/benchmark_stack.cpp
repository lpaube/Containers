#include <stack>
#include <vector>
#include <fstream>

#include "stack.hpp"
#include "vector.hpp"

#ifndef NAMESPACE_NUM
#define NAMESPACE_NUM 1
#endif

#if NAMESPACE_NUM == 1
#define NAMESPACE ft
#elif NAMESPACE_NUM == 2
#define NAMESPACE std
#endif

template <typename T>
void stack_push(std::fstream& test_file, NAMESPACE::stack<T, NAMESPACE::vector<T> >& sreal)
{
  (void)test_file;
  for (int i = 0; i < 100; i += 2)
  {
    sreal.push(i);
  }
}

template <typename T>
void stack_comparison(std::fstream& test_file, NAMESPACE::stack<T, NAMESPACE::vector<T> >& sreal
    , NAMESPACE::stack<T, NAMESPACE::vector<T> >& sref)
{
  test_file << "gt: " << (sreal > sref) << std::endl;
  test_file << "lt: " << (sreal < sref) << std::endl;
  test_file << "gteq: " << (sreal >= sref) << std::endl;
  test_file << "lteq: " << (sreal <= sref) << std::endl;
  test_file << "eq: " << (sreal == sref) << std::endl;
  test_file << "neq: " << (sreal != sref) << std::endl;
}

void test_stack(std::fstream& test_file)
{
  NAMESPACE::stack<int, NAMESPACE::vector<int> > s1;

  test_file << "=== Testing stack push (stack_push) ===" << std::endl;
  stack_push(test_file, s1);
  test_file << "GOOD: push did not crash" << std::endl;

  test_file << "=== Testing stack copy constructor ===" << std::endl;
  NAMESPACE::stack<int, NAMESPACE::vector<int> > s2 = s1;
  test_file << "GOOD: copy constructor did not crash" << std::endl;

  test_file << "=== Testing stack pop ===" << std::endl;
  s2.pop();
  s2.pop();
  s2.pop();
  test_file << "GOOD: pop did not crash" << std::endl;

  test_file << "=== Testing stack comparisons (stack_comparison) ===" << std::endl;
  stack_comparison(test_file, s1, s2);

  test_file << std::endl;
}
