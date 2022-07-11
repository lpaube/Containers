#include <map>
#include <fstream>

#include "map.hpp"
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
  template <typename Key, typename Value>
void map_insert(NAMESPACE::map<Key, Value>& mreal)
{
  for (int i = 0; i < 200000; ++i)
    mreal.insert(NAMESPACE::pair<int, int>(i, i + 2));
}

  template <typename Key, typename Value>
void map_hint_insert(NAMESPACE::map<Key, Value>& mreal)
{
  for (int i = 200000; i < 400000; ++i)
  {
    mreal.insert(mreal.begin(), NAMESPACE::pair<int, int>(i, i));
  }
}

  template <typename Key, typename Value>
void map_range_insert(NAMESPACE::map<Key, Value>& mreal, NAMESPACE::map<Key, Value>& mref)
{
  mreal.insert(mref.begin(), mref.end());
}

  template <typename Key, typename Value>
void map_find(NAMESPACE::map<Key, Value>& mreal)
{
  for (int i = 0; i < 200000; ++i)
  {
    mreal.find(i);
  }
}

  template <typename Key, typename Value>
void map_at(NAMESPACE::map<Key, Value>& mreal)
{
  try{
    for (int i = 0; i < 200000; ++i)
    {
      mreal.at(i);
    }
  }
  catch (std::exception e)
  {

  }
}

  template <typename Key, typename Value>
void map_erase_pos(NAMESPACE::map<Key, Value>& mreal)
{
  while (mreal.size())
  {
    mreal.erase(mreal.begin());
  }
}

  template <typename Key, typename Value>
void map_erase_range(NAMESPACE::map<Key, Value>& mreal)
{
  mreal.erase(mreal.begin(), mreal.end());
}

  template <typename Key, typename Value>
void map_erase_key(NAMESPACE::map<Key, Value>& mreal)
{
  for (int i = 0; i < 200000; ++i)
  {
    mreal.erase(i);
  }
}

void benchmark_map(std::fstream& benchmark_file)
{
  NAMESPACE::map<int, int> m1;

  timer t1("insert_basic", benchmark_file);
  map_insert(m1);
  t1.stop();

  m1.clear();
  timer t2("insert_hint", benchmark_file);
  map_hint_insert(m1);
  t2.stop();

  NAMESPACE::map<int, int> m2;
  timer t3("insert_range", benchmark_file);
  map_range_insert(m2, m1);
  t3.stop();

  timer t4("find", benchmark_file);
  map_find(m2);
  t4.stop();

  timer t5("at", benchmark_file);
  map_at(m2);
  t5.stop();

  timer t6("erase_pos", benchmark_file);
  map_erase_pos(m2);
  t6.stop();

  m2 = m1;
  timer t7("erase_range", benchmark_file);
  map_erase_range(m2);
  t7.stop();

  m2 = m1;
  timer t8("erase_key", benchmark_file);
  map_erase_key(m2);
  t8.stop();

}
