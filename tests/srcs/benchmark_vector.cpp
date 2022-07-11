#include "vector.hpp"

#include <unistd.h>
#include <vector>
#include <fstream>

#include "timer.hpp"

#ifndef NAMESPACE_NUM
#define NAMESPACE_NUM 1
#endif

#if NAMESPACE_NUM == 1
#define NAMESPACE ft
#elif NAMESPACE_NUM == 2
#define NAMESPACE std
#endif

// TESTING INSERT
void vec_insert_basic(NAMESPACE::vector<int>& vreal)
{
  for (NAMESPACE::vector<int>::size_type i = 0; i < 200000; ++i)
  {
    vreal.insert(vreal.begin(), i);
  }
  vreal.clear();
  for (NAMESPACE::vector<int>::size_type i = 0; i < 200000; ++i)
  {
    vreal.insert(vreal.end(), i);
  }
}

    template <typename T>
void vec_insert_size(NAMESPACE::vector<T>& vreal)
{
  vreal.insert(vreal.begin(), 300000, 4);
  vreal.insert(vreal.end(), 300000, 5);
}

    template <typename T>
void vec_insert_range(NAMESPACE::vector<T>& vreal, NAMESPACE::vector<T>& vref)
{
  vreal.insert(vreal.begin(), vref.begin(), vref.end());
  vreal.clear();
  vreal.insert(vreal.end(), vref.begin(), vref.end());
}

// TESTING ASSIGN
template <typename T>
  void vec_assign_size(NAMESPACE::vector<T>& vreal)
{
  vreal.assign(200000, 5);
}

    template <typename T>
void vec_assign_range(NAMESPACE::vector<T>& vreal, NAMESPACE::vector<T>& vref)
{
  vreal.assign(vref.begin(), vref.end());
}

template <typename T>
void vec_erase_pos(NAMESPACE::vector<T>& vreal)
{
  vreal.assign(100000, 5);

  while (vreal.size())
    vreal.erase(vreal.begin());

  vreal.assign(100000, 5);

  while (vreal.size())
    vreal.erase(vreal.end() - 1);
}

template <typename T>
void vec_erase_range(NAMESPACE::vector<T>& vreal)
{
  vreal.erase(vreal.begin(), vreal.end());
}

template <typename T>
void vec_push_back(NAMESPACE::vector<T>& vreal)
{
  for (int i = 0; i < 100000; ++i)
    vreal.push_back(i);
}

template <typename T>
void vec_pop_back(NAMESPACE::vector<T>& vreal)
{
  while (vreal.size())
    vreal.pop_back();
}

template <typename T>
void vec_at(NAMESPACE::vector<T>& vreal)
{
  for (typename NAMESPACE::vector<T>::size_type i = 0
      ; i < vreal.size()
      ; ++i)
  {
    vreal.at(i);
  }
}

template <typename T>
void vec_reserve(NAMESPACE::vector<T>& vreal)
{
  (void)vreal;
}

template <typename T>
void vec_resize(NAMESPACE::vector<T>& vreal)
{
  vreal.resize(10000, 4);
  vreal.resize(100, 5);
  vreal.resize(100000, 6);
  vreal.resize(1, 6);
}

void benchmark_vector(std::fstream& benchmark_file)
{
  NAMESPACE::vector<int> v1;
  NAMESPACE::vector<int> v2;

  timer t1("insert_basic", benchmark_file);
  vec_insert_basic(v1);
  t1.stop();

  timer t2("insert_size", benchmark_file);
  vec_insert_size(v1);
  t2.stop();

  timer t3("insert_range", benchmark_file);
  vec_insert_range(v2, v1);
  t3.stop();

  timer t4("assign_size", benchmark_file);
  vec_assign_size(v2);
  t4.stop();

  timer t5("assign_range", benchmark_file);
  vec_assign_range(v2, v1);
  t5.stop();

  timer t6("erase_pos", benchmark_file);
  vec_erase_pos(v1);
  t6.stop();

  v2.insert(v2.begin(), 100000, 4);
  v1 = v2;
  timer t7("erase_range", benchmark_file);
  vec_erase_range(v1);
  t7.stop();

  v1.clear();
  timer t8("push_back", benchmark_file);
  vec_push_back(v1);
  t8.stop();

  timer t9("pop_back", benchmark_file);
  vec_pop_back(v2);
  t9.stop();

  v1 = v2;
  timer t10("at", benchmark_file);
  vec_at(v2);
  t10.stop();

  timer t11("resize", benchmark_file);
  vec_resize(v1);
  t11.stop();
}
