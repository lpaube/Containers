#include <map>
#include <fstream>

#include "map.hpp"

#ifndef NAMESPACE_NUM
#define NAMESPACE_NUM 1
#endif

#if NAMESPACE_NUM == 1
#define NAMESPACE ft
#elif NAMESPACE_NUM == 2
#define NAMESPACE std
#endif

// PRINTING THE MAP
  template <typename Key, typename Value>
void print_map(std::fstream& test_file, const NAMESPACE::map<Key, Value>& mreal)
{
  test_file << "=== PRINTING MAP ===" << " size: " << mreal.size() << std::endl;
  for (typename NAMESPACE::map<Key, Value>::const_iterator it = mreal.begin()
      ; it != mreal.end()
      ; ++it)
  {
    test_file << " | Key: " << it->first << " ,Value: " << it->second;
  }
  test_file << std::endl;
}

// TESTING INSERT
template <typename Key, typename Value>
void map_insert(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  for (int i = 0; i < 25; ++i)
  {
    test_file << "ret->first: " << (*((mreal.insert(NAMESPACE::pair<int, int>(i * 2, i * 4))).first)).first;
  }
  test_file << std::endl;
  test_file << "ret->second: " << mreal.insert(NAMESPACE::pair<int, int>(0, 0)).second;
  test_file << std::endl;

  print_map(test_file, mreal);
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_hint_insert(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  test_file << "it->first: " << (mreal.insert(++(++(++(mreal.begin()))), NAMESPACE::pair<int, int>(3, 3)))->first;
  test_file << "it->first: " << (mreal.insert(--(--(--(mreal.end()))), NAMESPACE::pair<int, int>(14, 14)))->first;

  print_map(test_file, mreal);
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_range_insert(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal, NAMESPACE::map<Key, Value>& mref)
{
  mreal.insert(mref.begin(), mref.begin());
  print_map(test_file, mreal);
  test_file << std::endl;

  mreal.insert(mref.begin(), ++(++(++mref.begin())));
  print_map(test_file, mreal);
  test_file << std::endl;

  mreal.insert(mref.begin(), (mref.end()--)--);
  print_map(test_file, mreal);
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_iterators(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  test_file << "it->first: " << (mreal.begin())->first << std::endl;
  test_file << "it->first: " << ((++(mreal.begin()))->first) << std::endl;
  test_file << "it->second: " << (--(mreal.end()))->second << std::endl;
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_find(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  test_file << "find *it: " << (mreal.find(2))->second;
  test_file << " | find *it: " << (mreal.find(10))->second;
  test_file << " | find *it: " << (mreal.find(40))->second;
  test_file << " | find end(): " << (mreal.find(9992) == mreal.end());
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_at(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  test_file << "at: " << mreal.at(2);
  test_file << " | at: " << mreal.at(10);
  test_file << " | at: " << mreal.at(40);
  test_file << " | at: " << mreal.at(9993);
}

template <typename Key, typename Value>
void map_clear_size(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  test_file << "size: " << mreal.size() << std::endl;
  mreal.clear();

  print_map(test_file, mreal);
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_count(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  test_file << "count: " << mreal.count(20);
  test_file << " | count: " << mreal.count(2);
  test_file << " | count: " << mreal.count(9980);
  test_file << " | count: " << mreal.count(0);
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_empty(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  test_file << "empty: " << mreal.empty() << std::endl;
  mreal.clear();
  test_file << "empty: " << mreal.empty();
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_erase_pos(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  mreal.erase(mreal.begin());
  mreal.erase(--(mreal.end()));
  mreal.erase(++(++(++(mreal.begin()))));

  print_map(test_file, mreal);
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_erase_range(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  mreal.erase(mreal.begin(), (++(++(mreal.begin()))));
  mreal.erase(mreal.begin(), (++(++(mreal.begin()))));
  mreal.erase((--(--(--(mreal.end())))), (--(mreal.end())));

  print_map(test_file, mreal);
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_erase_key(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  mreal.erase(2);
  mreal.erase(50);
  mreal.erase(150);

  print_map(test_file, mreal);
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_upper_lower_bound(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  typename NAMESPACE::map<Key, Value>::iterator it;

  it = mreal.lower_bound(20);
  test_file << "lower_bound: " << it->first;
  it = mreal.upper_bound(20);
  test_file << " | upper_bound: " << it->first << std::endl;
  it = mreal.lower_bound(5);
  test_file << "lower_bound: " << it->first;
  it = mreal.upper_bound(5);
  test_file << " | upper_bound: " << it->first << std::endl;
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_equal_range(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  typedef typename NAMESPACE::map<Key, Value>::iterator it_type;
  NAMESPACE::pair<it_type, it_type> it_pair;

  it_pair = mreal.equal_range(20);
  for (; it_pair.first != it_pair.second; ++it_pair.first)
    test_file << " | " << it_pair.first->first;
  
  it_pair = mreal.equal_range(5);
  for (; it_pair.first != it_pair.second; ++it_pair.first)
    test_file << " | " << it_pair.first->first;
  test_file << std::endl;

  it_pair = mreal.equal_range(0);
  for (; it_pair.first != it_pair.second; ++it_pair.first)
    test_file << " | " << it_pair.first->first;
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_reverse_it(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal)
{
  test_file << "*rit: " << (mreal.rbegin())->first;
  test_file << " | *rit: " << (++(++(++(mreal.rbegin()))))->first;
  test_file << " | *rit: " << (--(--(--(--(--(mreal.rend()))))))->first;
  test_file << " | *rit: " << (--(mreal.rend()))->first;
}

template <typename Key, typename Value>
void map_swap(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal, NAMESPACE::map<Key, Value>& mref)
{
  mref.erase(mref.begin());
  mreal.swap(mref);

  print_map(test_file, mreal);
  test_file << std::endl;

  mref.erase(mref.begin());
  mreal.swap(mref);

  print_map(test_file, mreal);
  test_file << std::endl;
}

template <typename Key, typename Value>
void map_comparison(std::fstream& test_file, NAMESPACE::map<Key, Value>& mreal, NAMESPACE::map<Key, Value>& mref)
{
  test_file << "gt: " << (mreal > mref) << std::endl;
  test_file << "lt: " << (mreal < mref) << std::endl;
  test_file << "gteq: " << (mreal >= mref) << std::endl;
  test_file << "lteq: " << (mreal <= mref) << std::endl;
  test_file << "eq: " << (mreal == mref) << std::endl;
  test_file << "neq: " << (mreal != mref) << std::endl;
}

void test_map(std::fstream& test_file)
{
  NAMESPACE::map<int, int> m1;
  NAMESPACE::map<int, int> m2;

  test_file << "=== Testing map basic insert (map_insert) ===" << std::endl;
  map_insert(test_file, m1);

  test_file << "=== Testing map assignment operator ===" << std::endl;
  const NAMESPACE::map<int, int> m3 = m1;
  print_map(test_file, m3);
  test_file << std::endl;

  test_file << "=== Testing map iterators (map_iterators) ===" << std::endl;
  map_iterators(test_file, m1);

  test_file << "=== Testing map hint insert (map_hint_insert) ===" << std::endl;
  map_hint_insert(test_file, m1);

  test_file << "=== Testing map range insert (map_range_insert) ===" << std::endl;
  map_range_insert(test_file, m2, m1);
  
  test_file << "=== Testing map find (map_find) ===" << std::endl;
  map_find(test_file, m2);

  test_file << "=== Testing map at (map_at) ===" << std::endl;
  try {
    map_at(test_file, m2);
  }
  catch (std::exception e) {
    test_file << "There was an exception thrown" << std::endl;
  }

  test_file << "=== Testing map clear and size (map_clear_size) ===" << std::endl;
  map_clear_size(test_file, m2);

  test_file << "=== Testing map count (map_count) ===" << std::endl;
  m2 = m3;
  map_count(test_file, m2);

  test_file << "=== Testing map empty (map_empty) ===" << std::endl;
  map_empty(test_file, m2);

  test_file << "=== Testing map erase pos (map_erase_pos) ===" << std::endl;
  m2 = m3;
  map_erase_pos(test_file, m2);

  test_file << "=== Testing map erase pos (map_erase_pos) ===" << std::endl;
  map_erase_range(test_file, m2);

  test_file << "=== Testing map erase key (map_erase_key) ===" << std::endl;
  m2 = m3;
  map_erase_key(test_file, m2);

  test_file << "=== Testing map upper and lower bound (map_upper_lower_bound) ===" << std::endl;
  m2 = m3;
  map_upper_lower_bound(test_file, m2);

  test_file << "=== Testing map equal range (map_equal_range) ===" << std::endl;
  map_equal_range(test_file, m2);

  test_file << "=== Testing map reverse iterator (map_reverse_it) ===" << std::endl;
  map_reverse_it(test_file, m2);

  test_file << "=== Testing map swap (map_swap) ===" << std::endl;
  map_swap(test_file, m2, m1);

  test_file << "=== Testing map comparisons (map_comparison) ===" << std::endl;
  m2 = m3;
  map_comparison(test_file, m2, m1);

  test_file << std::endl;
}
