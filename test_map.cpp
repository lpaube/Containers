#include "map.hpp"
#include <map>

#define NAMESPACE std

// PRINTING THE MAP
  template <typename Key, typename Value>
void print_map(const NAMESPACE::map<Key, Value>& mreal)
{
  std::cout << "=== PRINTING MAP ===" << " size: " << mreal.size() << std::endl;
  for (typename NAMESPACE::map<Key, Value>::const_iterator it = mreal.begin()
      ; it != mreal.end()
      ; ++it)
  {
    std::cout << " | Key: " << it->first << " ,Value: " << it->second;
  }
  std::cout << std::endl;
}

// TESTING INSERT
template <typename Key, typename Value>
void map_insert(NAMESPACE::map<Key, Value>& mreal)
{
  for (int i = 0; i < 25; ++i)
  {
    std::cout << "ret->first: " << (*((mreal.insert(NAMESPACE::pair<int, int>(i * 2, i * 4))).first)).first;
  }
  std::cout << std::endl;
  std::cout << "ret->second: " << mreal.insert(NAMESPACE::pair<int, int>(0, 0)).second;
  std::cout << std::endl;

  print_map(mreal);
  std::cout << std::endl;
}

template <typename Key, typename Value>
void map_hint_insert(NAMESPACE::map<Key, Value>& mreal)
{
  std::cout << "it->first: " << (mreal.insert(++(++(++(mreal.begin()))), NAMESPACE::pair<int, int>(3, 3)))->first;
  std::cout << "it->first: " << (mreal.insert(--(--(--(mreal.end()))), NAMESPACE::pair<int, int>(14, 14)))->first;

  print_map(mreal);
  std::cout << std::endl;
}

template <typename Key, typename Value>
void map_range_insert(NAMESPACE::map<Key, Value>& mreal, NAMESPACE::map<Key, Value>& mref)
{
  mreal.insert(mref.begin(), mref.begin());
  print_map(mreal);
  std::cout << std::endl;

  mreal.insert(mref.begin(), ++(++(++mref.begin())));
  print_map(mreal);
  std::cout << std::endl;

  mreal.insert(mref.begin(), (mref.end()--)--);
  print_map(mreal);
  std::cout << std::endl;
}

template <typename Key, typename Value>
void map_iterators(NAMESPACE::map<Key, Value>& mreal)
{
  std::cout << "it->first: " << (mreal.begin())->first << std::endl;
  std::cout << "it->first: " << ((++(mreal.begin()))->first) << std::endl;
  std::cout << "it->second: " << (--(mreal.end()))->second << std::endl;
  std::cout << std::endl;
}


void test_map()
{
  NAMESPACE::map<int, int> m1;
  NAMESPACE::map<int, int> m2;

  std::cout << "=== Testing map basic insert (map_insert) ===" << std::endl;
  map_insert(m1);

  std::cout << "=== Testing map assignment operator ===" << std::endl;
  const NAMESPACE::map<int, int> m3 = m1;
  print_map(m3);
  std::cout << std::endl;

  std::cout << "=== Testing map iterators (map_iterators) ===" << std::endl;
  map_iterators(m1);

  std::cout << "=== Testing map hint insert (map_hint_insert) ===" << std::endl;
  map_hint_insert(m1);

  std::cout << "=== Testing map range insert (map_range_insert) ===" << std::endl;
  map_range_insert(m2, m1);
}
