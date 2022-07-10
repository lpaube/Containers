#include "vector.hpp"
#include <vector>

#define NAMESPACE std

// PRINTING THE VECTOR
template <typename T>
void print_vector(NAMESPACE::vector<T>& v)
{
  std::cout << "=== PRINTING VECTOR ===" << std::endl;
  std::cout << "Size: " << v.size() << std::endl;
  for (int i = 0; v.begin() + i != v.end(); ++i)
  {
    std::cout << "Elem " << i 
      << ": " << *(v.begin() + i)
      << " | ";
  }
  std::cout << std::endl;
}

// TESTING ASSIGN
    template <typename T>
void vec_assign_range(NAMESPACE::vector<T>& vreal, NAMESPACE::vector<T>& vref)
{
  vreal.assign(vref.begin(), vref.begin() + 3);
}

// TESTING INSERT
void vec_insert_basic_int(NAMESPACE::vector<int>& vreal)
{
  std::cout << "Insert 1: ";
  for (NAMESPACE::vector<int>::size_type i = 0; i < 10; ++i)
  {
    std::cout << "*It = " << *(vreal.insert(vreal.begin(), i)) << " | ";
  }
  std::cout << std::endl;

  std::cout << "Insert 2: ";
  for (NAMESPACE::vector<int>::size_type i = 10; i < 100; i += 10)
  {
    std::cout << "*It = " << *(vreal.insert(vreal.end(), i)) << " | ";
  }
  std::cout << std::endl;

  std::cout << "Insert 3: ";
  for (NAMESPACE::vector<int>::size_type i = 100; i < 1000; i += 100)
  {
    std::cout << "*It = " << *(vreal.insert(vreal.begin() + 5, i)) << " | ";
  }
  std::cout << std::endl << std::endl;

  print_vector(vreal);
  std::cout << std::endl;
}

    template <typename T>
void vec_insert_size(NAMESPACE::vector<T>& vreal)
{
  vreal.insert(vreal.end(), 0, 10);
  vreal.insert(vreal.end(), 0, 10);
  vreal.insert(vreal.end(), 5, 2);
  vreal.insert(vreal.end(), 0, 2);
  vreal.insert(vreal.begin(), 10, 5);
  vreal.insert(vreal.begin(), 0, 5);
  vreal.insert(vreal.begin() + 2, 3, 5);

  print_vector(vreal);
  std::cout << std::endl;
}

    template <typename T>
void vec_insert_range(NAMESPACE::vector<T>& vreal, NAMESPACE::vector<T>& vref)
{
  vreal.insert(vreal.begin(), vref.begin(), vref.begin());
  vreal.insert(vreal.begin(), vref.end(), vref.end());
  vreal.insert(vreal.begin(), vref.begin(), vref.begin() + 2);
  vreal.insert(vreal.begin() + 2, vref.begin(), vref.begin() + 2);
  vreal.insert(vreal.end(), vref.begin() + 2, vref.begin() + 10);

  print_vector(vreal);
  std::cout << std::endl;
}

// TESTING ASSIGN
template <typename T>
  void vec_assign_size_int(NAMESPACE::vector<T>& vreal)
{
  vreal.assign(0, 0);
  print_vector(vreal);
  std::cout << std::endl;

  vreal.assign(3, 1337);
  print_vector(vreal);
  std::cout << std::endl;

  vreal.assign(0, 1337);
  print_vector(vreal);
  std::cout << std::endl;

  vreal.assign(1000, 1337);
  print_vector(vreal);
  std::cout << std::endl;

  vreal.assign(100, 31337);
  print_vector(vreal);
  std::cout << std::endl;
}

template <typename T>
  void vec_assign_range_int(NAMESPACE::vector<T>& vreal, NAMESPACE::vector<T>& vref)
{
  vreal.assign(vref.begin(), vref.begin());
  print_vector(vreal);
  std::cout << std::endl;

  vreal.assign(vref.end(), vref.end());
  print_vector(vreal);
  std::cout << std::endl;

  vreal.assign(vref.begin(), vref.begin() + 2);
  print_vector(vreal);
  std::cout << std::endl;

  vreal.assign(vref.begin() + 5, vref.begin() + 15);
  print_vector(vreal);
  std::cout << std::endl;
}

// TESTING ERASE
template <typename T>
void vec_erase_pos(NAMESPACE::vector<T>& vreal)
{
  std::cout << "Erase 1 it*: " << *(vreal.erase(vreal.begin()));
  std::cout << " | Erase 2 it*: " << *(vreal.erase(vreal.begin() + 2));
  std::cout << " | Erase 3 it*: " << *(vreal.erase(vreal.end() - 1));
  std::cout << " | Erase 4 it*: " << *(vreal.erase(vreal.end() - 2));

  print_vector(vreal);
  std::cout << std::endl;
}

template <typename T>
void vec_erase_range(NAMESPACE::vector<T>& vreal)
{
  std::cout << "Erase 1 it*: " << *(vreal.erase(vreal.begin(), vreal.begin()));
  std::cout << " | Erase 2 it*: " << *(vreal.erase(vreal.begin() + 2), vreal.begin() + 3);
  std::cout << " | Erase 3 it*: " << *(vreal.erase(vreal.end() - 2, vreal.end()));
  std::cout << " | Erase 4 it*: " << *(vreal.erase(vreal.end() - 2), vreal.end() - 2);

  print_vector(vreal);
  std::cout << std::endl;
}

template <typename T>
void vec_push_back(NAMESPACE::vector<T>& vreal)
{
  vreal.push_back(2);
  vreal.push_back(2);
  vreal.push_back(2);
  vreal.push_back(2);
  vreal.push_back(2);
  vreal.push_back(2);
  
  print_vector(vreal);
  std::cout << std::endl;

  vreal.clear();
  vreal.push_back(2);

  print_vector(vreal);
  std::cout << std::endl;
}

template <typename T>
void vec_at(NAMESPACE::vector<T>& vreal)
{
  vreal.at(5) = 10;
  vreal.at(6) = 33;
  vreal.at(0) = 33;
  vreal.at(22) = 33;

  const T res = vreal.at(8);
  std::cout << "at res: " << res << std::endl;

  print_vector(vreal);
  std::cout << std::endl;
}

template <typename T>
void vec_pop_back(NAMESPACE::vector<T>& vreal)
{
  vreal.pop_back();
  vreal.pop_back();
  vreal.pop_back();

  print_vector(vreal);
  std::cout << std::endl;
}

template <typename T>
void vec_front_back(NAMESPACE::vector<T>& vreal)
{
  std::cout << "Back: " << vreal.back() << std::endl;
  vreal.back() = 999;
  std::cout << "Back: " << vreal.back() << std::endl;


  std::cout << "Front: " << vreal.front() << std::endl;
  vreal.front() = 999;
  std::cout << "Front: " << vreal.front() << std::endl;

  print_vector(vreal);
  std::cout << std::endl;
}

template <typename T>
void vec_empty(NAMESPACE::vector<T>& vreal)
{
  std::cout << "Empty: " << vreal.empty() << std::endl;
  vreal.clear();
  std::cout << "Empty: " << vreal.empty() << std::endl;

  print_vector(vreal);
  std::cout << std::endl;
}

template <typename T>
void vec_reserve(NAMESPACE::vector<T>& vreal)
{
  std::cout << "Capacity: " << vreal.capacity() << std::endl;
  vreal.reserve(1);
  std::cout << "Capacity: " << vreal.capacity() << std::endl;
  vreal.reserve(100);
  std::cout << "Capacity: " << vreal.capacity() << std::endl;
  vreal.reserve(10000);
  std::cout << "Capacity: " << vreal.capacity() << std::endl;
  std::cout << "Size: " << vreal.size() << std::endl;
}

template <typename T>
void vec_resize(NAMESPACE::vector<T>& vreal)
{
  std::cout << "Size: " << vreal.size() << std::endl;

  vreal.resize(150);

  print_vector(vreal);
  std::cout << std::endl;

  vreal.resize(2);

  print_vector(vreal);
  std::cout << std::endl;
}

template <typename T>
void vec_rev_iterator(NAMESPACE::vector<T>& vreal)
{
  std::cout << "*rit: " << (*vreal.rbegin());
  std::cout << " | *rit: " << (*vreal.rbegin() + 3);
  std::cout << " | *rit: " << (*vreal.rend() - 5);
  std::cout << " | *rit: " << (*vreal.rend() - 1);
  *(vreal.rend() - 5) = 3;

  print_vector(vreal);
  std::cout << std::endl;
}

void test_vector()
{
  NAMESPACE::vector<int> v1;
  NAMESPACE::vector<int> v2;

  std::cout << "=== Testing basic insert (vec_insert_basic_int) ===" << std::endl;
  vec_insert_basic_int(v1);

  std::cout << "=== Testing insert size (vec_insert_size) ===" << std::endl;
  vec_insert_size(v2);

  std::cout << "=== Testing insert range (vec_insert_range) ===" << std::endl;
  vec_insert_range(v2, v1);

  std::cout << "=== Testing copy constructor ===" << std::endl;
  NAMESPACE::vector<int> v3(v2);
  print_vector(v3);
  std::cout << std::endl;

  std::cout << "=== Testing clear ===" << std::endl;
  v2.clear();
  v2.clear();
  print_vector(v2);
  std::cout << std::endl;

  std::cout << "=== Testing assign size (vec_assign_size_int) ===" << std::endl;
  v2 = v3;
  vec_assign_size_int(v2);

  std::cout << "=== Testing assign range (vec_assign_range_int) ===" << std::endl;
  vec_assign_range_int(v2, v1);

  std::cout << "=== Testing erase position (vec_erase_pos) ===" << std::endl;
  v1 = v3;
  vec_erase_pos(v1);

  std::cout << "=== Testing erase range (vec_erase_range) ===" << std::endl;
  vec_erase_range(v1);

  std::cout << "=== Testing push_back (vec_push_back) ===" << std::endl;
  vec_push_back(v1);

  std::cout << "=== Testing pop_back (vec_pop_back) ===" << std::endl;
  vec_pop_back(v2);

  std::cout << "=== Testing at (vec_at) ===" << std::endl;
  v2 = v3;
  vec_at(v2);

  std::cout << "=== Testing front and back (vec_front_back) ===" << std::endl;
  vec_front_back(v2);

  std::cout << "=== Testing empty (vec_empty) ===" << std::endl;
  vec_empty(v2);

  std::cout << "=== Testing max_size ===" << std::endl;
  std::cout << "Max size: " << v2.max_size() << std::endl << std::endl;

  std::cout << "=== Testing reserve (vec_reserve) ===" << std::endl;
  NAMESPACE::vector<int> v4;
  vec_reserve(v4);

  std::cout << "=== Testing resize (vec_resize) ===" << std::endl;
  v2 = v3;
  vec_resize(v2);

  std::cout << "=== Testing reverse iterators (vec_rev_iterator) ===" << std::endl;
  v2 = v3;
  vec_rev_iterator(v2);

  std::cout << "=== Testing swap ===" << std::endl;
  v2.swap(v1);
  print_vector(v2);
  std::cout << std::endl;
}
