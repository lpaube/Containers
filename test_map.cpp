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

template <typename Key, typename Value>
void map_find(NAMESPACE::map<Key, Value>& mreal)
{
  std::cout << "find *it: " << (mreal.find(2))->second;
  std::cout << " | find *it: " << (mreal.find(10))->second;
  std::cout << " | find *it: " << (mreal.find(40))->second;
  std::cout << " | find end(): " << (mreal.find(9992) == mreal.end());
  std::cout << std::endl;
}

template <typename Key, typename Value>
void map_at(NAMESPACE::map<Key, Value>& mreal)
{
  std::cout << "at: " << mreal.at(2);
  std::cout << " | at: " << mreal.at(10);
  std::cout << " | at: " << mreal.at(40);
  std::cout << " | at: " << mreal.at(9993);
}

template <typename Key, typename Value>
void map_clear_size(NAMESPACE::map<Key, Value>& mreal)
{
  std::cout << "size: " << mreal.size() << std::endl;
  mreal.clear();

  print_map(mreal);
  std::cout << std::endl;
}

template <typename Key, typename Value>
void map_count(NAMESPACE::map<Key, Value>& mreal)
{
  std::cout << "count: " << mreal.count(20);
  std::cout << " | count: " << mreal.count(2);
  std::cout << " | count: " << mreal.count(9980);
  std::cout << " | count: " << mreal.count(0);
  std::cout << std::endl;
}

template <typename Key, typename Value>
void map_empty(NAMESPACE::map<Key, Value>& mreal)
{
  std::cout << "empty: " << mreal.empty() << std::endl;
  mreal.clear();
  std::cout << "empty: " << mreal.empty();
  std::cout << std::endl;
}

template <typename Key, typename Value>
void map_erase_pos(NAMESPACE::map<Key, Value>& mreal)
{
  mreal.erase(mreal.begin());
  mreal.erase(--(mreal.end()));
  mreal.erase(++(++(++(mreal.begin()))));

  print_map(mreal);
  std::cout << std::endl;
}

template <typename Key, typename Value>
void map_erase_range(NAMESPACE::map<Key, Value>& mreal)
{
  mreal.erase(mreal.begin(), (++(++(mreal.begin()))));
  mreal.erase(mreal.begin(), (++(++(mreal.begin()))));
  mreal.erase((--(--(--(mreal.end())))), (--(mreal.end())));

  print_map(mreal);
  std::cout << std::endl;
}

template <typename Key, typename Value>
void map_erase_key(NAMESPACE::map<Key, Value>& mreal)
{
  mreal.erase(2);
  mreal.erase(50);
  mreal.erase(150);

  print_map(mreal);
  std::cout << std::endl;
}

template <typename Key, typename Value>
void map_upper_lower_bound(NAMESPACE::map<Key, Value>& mreal)
{
  
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
  
  std::cout << "=== Testing map find (map_find) ===" << std::endl;
  map_find(m2);

  std::cout << "=== Testing map at (map_at) ===" << std::endl;
  try {
    map_at(m2);
  }
  catch (std::exception e) {
    std::cout << "There was an exception thrown" << std::endl;
  }

  std::cout << "=== Testing map clear and size (map_clear_size) ===" << std::endl;
  map_clear_size(m2);

  std::cout << "=== Testing map count (map_count) ===" << std::endl;
  m2 = m3;
  map_count(m2);

  std::cout << "=== Testing map empty (map_empty) ===" << std::endl;
  map_empty(m2);

  std::cout << "=== Testing map erase pos (map_erase_pos) ===" << std::endl;
  m2 = m3;
  map_erase_pos(m2);

  std::cout << "=== Testing map erase pos (map_erase_pos) ===" << std::endl;
  map_erase_range(m2);

  std::cout << "=== Testing map erase key (map_erase_key) ===" << std::endl;
  m2 = m3;
  map_erase_key(m2);

  std::cout << "=== Testing map upper and lower bound (map_upper_lower_bound) ===" << std::endl;


  /*
   * TODO:
   *  upper and lower bound
   *  equal range
   *  riterator
   *  swap
   *  comparisons (<, >, !=...)
   */
}
