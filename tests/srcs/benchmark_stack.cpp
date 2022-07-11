#include <stack>
#include <vector>
#include <fstream>

#include "stack.hpp"
#include "vector.hpp"
#include "timer.hpp"

#ifndef NAMESPACE_NUM
#define NAMESPACE_NUM 1
#endif

#if NAMESPACE_NUM == 1
#define NAMESPACE ft
#elif NAMESPACE_NUM == 2
#define NAMESPACE std
#endif

template <typename T>
void stack_push(NAMESPACE::stack<T, NAMESPACE::vector<T> >& sreal)
{
  for (int i = 0; i < 500000; ++i)
  {
    sreal.push(i);
  }
}

template <typename T>
void stack_pop(NAMESPACE::stack<T, NAMESPACE::vector<T> >& sreal)
{
  while (sreal.size())
  {
    sreal.pop();
  }
}

void benchmark_stack(std::fstream& benchmark_file)
{
  NAMESPACE::stack<int, NAMESPACE::vector<int> > s1;

  timer t1("push", benchmark_file);
  stack_push(s1);
  t1.stop();

  timer t2("pop", benchmark_file);
  stack_pop(s1);
  t2.stop();

}
