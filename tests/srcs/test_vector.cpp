#include "vector.hpp"

#include <vector>
#include <fstream>

#ifndef NAMESPACE_NUM
#define NAMESPACE_NUM 1
#endif

#if NAMESPACE_NUM == 1
#define NAMESPACE ft
#elif NAMESPACE_NUM == 2
#define NAMESPACE std
#endif

// PRINTING THE VECTOR
template <typename T>
void print_vector(std::fstream& test_file, NAMESPACE::vector<T>& v)
{
  test_file << "=== PRINTING VECTOR ===" << std::endl;
  test_file << "Size: " << v.size() << std::endl;
  for (int i = 0; v.begin() + i != v.end(); ++i)
  {
    test_file << "Elem " << i 
      << ": " << *(v.begin() + i)
      << " | ";
  }
  test_file << std::endl;
}

// TESTING ASSIGN
    template <typename T>
void vec_assign_range(std::fstream& test_file, NAMESPACE::vector<T>& vreal, NAMESPACE::vector<T>& vref)
{
  (void)test_file;
  vreal.assign(vref.begin(), vref.begin() + 3);
}

// TESTING INSERT
void vec_insert_basic_int(std::fstream& test_file, NAMESPACE::vector<int>& vreal)
{
  test_file << "Insert 1: ";
  for (NAMESPACE::vector<int>::size_type i = 0; i < 10; ++i)
  {
    test_file << "*It = " << *(vreal.insert(vreal.begin(), i)) << " | ";
  }
  test_file << std::endl;

  test_file << "Insert 2: ";
  for (NAMESPACE::vector<int>::size_type i = 10; i < 100; i += 10)
  {
    test_file << "*It = " << *(vreal.insert(vreal.end(), i)) << " | ";
  }
  test_file << std::endl;

  test_file << "Insert 3: ";
  for (NAMESPACE::vector<int>::size_type i = 100; i < 1000; i += 100)
  {
    test_file << "*It = " << *(vreal.insert(vreal.begin() + 5, i)) << " | ";
  }
  test_file << std::endl << std::endl;

  print_vector(test_file, vreal);
  test_file << std::endl;
}

    template <typename T>
void vec_insert_size(std::fstream& test_file, NAMESPACE::vector<T>& vreal)
{
  vreal.insert(vreal.end(), 0, 10);
  vreal.insert(vreal.end(), 0, 10);
  vreal.insert(vreal.end(), 5, 2);
  vreal.insert(vreal.end(), 0, 2);
  vreal.insert(vreal.begin(), 10, 5);
  vreal.insert(vreal.begin(), 0, 5);
  vreal.insert(vreal.begin() + 2, 3, 5);

  print_vector(test_file, vreal);
  test_file << std::endl;
}

    template <typename T>
void vec_insert_range(std::fstream& test_file, NAMESPACE::vector<T>& vreal, NAMESPACE::vector<T>& vref)
{
  vreal.insert(vreal.begin(), vref.begin(), vref.begin());
  vreal.insert(vreal.begin(), vref.end(), vref.end());
  vreal.insert(vreal.begin(), vref.begin(), vref.begin() + 2);
  vreal.insert(vreal.begin() + 2, vref.begin(), vref.begin() + 2);
  vreal.insert(vreal.end(), vref.begin() + 2, vref.begin() + 10);

  print_vector(test_file, vreal);
  test_file << std::endl;
}

// TESTING ASSIGN
template <typename T>
  void vec_assign_size_int(std::fstream& test_file, NAMESPACE::vector<T>& vreal)
{
  vreal.assign(0, 0);
  print_vector(test_file, vreal);
  test_file << std::endl;

  vreal.assign(3, 1337);
  print_vector(test_file, vreal);
  test_file << std::endl;

  vreal.assign(0, 1337);
  print_vector(test_file, vreal);
  test_file << std::endl;

  vreal.assign(1000, 1337);
  print_vector(test_file, vreal);
  test_file << std::endl;

  vreal.assign(100, 31337);
  print_vector(test_file, vreal);
  test_file << std::endl;
}

template <typename T>
  void vec_assign_range_int(std::fstream& test_file, NAMESPACE::vector<T>& vreal, NAMESPACE::vector<T>& vref)
{
  vreal.assign(vref.begin(), vref.begin());
  print_vector(test_file, vreal);
  test_file << std::endl;

  vreal.assign(vref.end(), vref.end());
  print_vector(test_file, vreal);
  test_file << std::endl;

  vreal.assign(vref.begin(), vref.begin() + 2);
  print_vector(test_file, vreal);
  test_file << std::endl;

  vreal.assign(vref.begin() + 5, vref.begin() + 15);
  print_vector(test_file, vreal);
  test_file << std::endl;
}

// TESTING ERASE
template <typename T>
void vec_erase_pos(std::fstream& test_file, NAMESPACE::vector<T>& vreal)
{
  test_file << "Erase 1 it*: " << *(vreal.erase(vreal.begin()));
  test_file << " | Erase 2 it*: " << *(vreal.erase(vreal.begin() + 2));
  test_file << " | Erase 3 it*: " << *(vreal.erase(vreal.end() - 1));
  test_file << " | Erase 4 it*: " << *(vreal.erase(vreal.end() - 2));

  print_vector(test_file, vreal);
  test_file << std::endl;
}

template <typename T>
void vec_erase_range(std::fstream& test_file, NAMESPACE::vector<T>& vreal)
{
  test_file << "Erase 1 it*: " << *(vreal.erase(vreal.begin(), vreal.begin()));
  test_file << " | Erase 2 it*: " << *(vreal.erase(vreal.begin() + 2), vreal.begin() + 3);
  test_file << " | Erase 3 it*: " << *(vreal.erase(vreal.end() - 2, vreal.end()));
  test_file << " | Erase 4 it*: " << *(vreal.erase(vreal.end() - 2), vreal.end() - 2);

  print_vector(test_file, vreal);
  test_file << std::endl;
}

template <typename T>
void vec_push_back(std::fstream& test_file, NAMESPACE::vector<T>& vreal)
{
  vreal.push_back(2);
  vreal.push_back(2);
  vreal.push_back(2);
  vreal.push_back(2);
  vreal.push_back(2);
  vreal.push_back(2);
  
  print_vector(test_file, vreal);
  test_file << std::endl;

  vreal.clear();
  vreal.push_back(2);

  print_vector(test_file, vreal);
  test_file << std::endl;
}

template <typename T>
void vec_at(std::fstream& test_file, NAMESPACE::vector<T>& vreal)
{
  vreal.at(5) = 10;
  vreal.at(6) = 33;
  vreal.at(0) = 33;
  vreal.at(22) = 33;

  const T res = vreal.at(8);
  test_file << "at res: " << res << std::endl;

  print_vector(test_file, vreal);
  test_file << std::endl;
}

template <typename T>
void vec_pop_back(std::fstream& test_file, NAMESPACE::vector<T>& vreal)
{
  vreal.pop_back();
  vreal.pop_back();
  vreal.pop_back();

  print_vector(test_file, vreal);
  test_file << std::endl;
}

template <typename T>
void vec_front_back(std::fstream& test_file, NAMESPACE::vector<T>& vreal)
{
  test_file << "Back: " << vreal.back() << std::endl;
  vreal.back() = 999;
  test_file << "Back: " << vreal.back() << std::endl;


  test_file << "Front: " << vreal.front() << std::endl;
  vreal.front() = 999;
  test_file << "Front: " << vreal.front() << std::endl;

  print_vector(test_file, vreal);
  test_file << std::endl;
}

template <typename T>
void vec_empty(std::fstream& test_file, NAMESPACE::vector<T>& vreal)
{
  test_file << "Empty: " << vreal.empty() << std::endl;
  vreal.clear();
  test_file << "Empty: " << vreal.empty() << std::endl;

  print_vector(test_file, vreal);
  test_file << std::endl;
}

template <typename T>
void vec_reserve(std::fstream& test_file, NAMESPACE::vector<T>& vreal)
{
  test_file << "Capacity: " << vreal.capacity() << std::endl;
  vreal.reserve(1);
  test_file << "Capacity: " << vreal.capacity() << std::endl;
  vreal.reserve(100);
  test_file << "Capacity: " << vreal.capacity() << std::endl;
  vreal.reserve(10000);
  test_file << "Capacity: " << vreal.capacity() << std::endl;
  test_file << "Size: " << vreal.size() << std::endl;
}

template <typename T>
void vec_resize(std::fstream& test_file, NAMESPACE::vector<T>& vreal)
{
  test_file << "Size: " << vreal.size() << std::endl;

  vreal.resize(150);

  print_vector(test_file, vreal);
  test_file << std::endl;

  vreal.resize(2);

  print_vector(test_file, vreal);
  test_file << std::endl;
}

template <typename T>
void vec_rev_iterator(std::fstream& test_file, NAMESPACE::vector<T>& vreal)
{
  test_file << "*rit: " << (*vreal.rbegin());
  test_file << " | *rit: " << (*vreal.rbegin() + 3);
  test_file << " | *rit: " << (*vreal.rend() - 5);
  test_file << " | *rit: " << (*vreal.rend() - 1);
  *(vreal.rend() - 5) = 3;

  print_vector(test_file, vreal);
  test_file << std::endl;
}

template <typename T>
void vec_comparison(std::fstream& test_file, NAMESPACE::vector<T>& vreal, NAMESPACE::vector<T>& vref)
{
  test_file << "gt: " << (vreal > vref) << std::endl;
  test_file << "lt: " << (vreal < vref) << std::endl;
  test_file << "gteq: " << (vreal >= vref) << std::endl;
  test_file << "lteq: " << (vreal <= vref) << std::endl;
  test_file << "eq: " << (vreal == vref) << std::endl;
  test_file << "neq: " << (vreal != vref) << std::endl;
}

void test_vector(std::fstream& test_file)
{
  NAMESPACE::vector<int> v1;
  NAMESPACE::vector<int> v2;

  test_file << "=== Testing basic insert (vec_insert_basic_int) ===" << std::endl;
  vec_insert_basic_int(test_file, v1);

  test_file << "=== Testing insert size (vec_insert_size) ===" << std::endl;
  vec_insert_size(test_file, v2);

  test_file << "=== Testing insert range (vec_insert_range) ===" << std::endl;
  vec_insert_range(test_file, v2, v1);

  test_file << "=== Testing copy constructor ===" << std::endl;
  NAMESPACE::vector<int> v3(v2);
  print_vector(test_file, v3);
  test_file << std::endl;

  test_file << "=== Testing clear ===" << std::endl;
  v2.clear();
  v2.clear();
  print_vector(test_file, v2);
  test_file << std::endl;

  test_file << "=== Testing assign size (vec_assign_size_int) ===" << std::endl;
  v2 = v3;
  vec_assign_size_int(test_file, v2);

  test_file << "=== Testing assign range (vec_assign_range_int) ===" << std::endl;
  vec_assign_range_int(test_file, v2, v1);

  test_file << "=== Testing erase position (vec_erase_pos) ===" << std::endl;
  v1 = v3;
  vec_erase_pos(test_file, v1);

  test_file << "=== Testing erase range (vec_erase_range) ===" << std::endl;
  vec_erase_range(test_file, v1);

  test_file << "=== Testing push_back (vec_push_back) ===" << std::endl;
  vec_push_back(test_file, v1);

  test_file << "=== Testing pop_back (vec_pop_back) ===" << std::endl;
  vec_pop_back(test_file, v2);

  test_file << "=== Testing at (vec_at) ===" << std::endl;
  v2 = v3;
  vec_at(test_file, v2);

  test_file << "=== Testing front and back (vec_front_back) ===" << std::endl;
  vec_front_back(test_file, v2);

  test_file << "=== Testing empty (vec_empty) ===" << std::endl;
  vec_empty(test_file, v2);

  test_file << "=== Testing max_size ===" << std::endl;
  test_file << "Max size: " << v2.max_size() << std::endl << std::endl;

  test_file << "=== Testing reserve (vec_reserve) ===" << std::endl;
  NAMESPACE::vector<int> v4;
  vec_reserve(test_file, v4);

  test_file << "=== Testing resize (vec_resize) ===" << std::endl;
  v2 = v3;
  vec_resize(test_file, v2);

  test_file << "=== Testing reverse iterators (vec_rev_iterator) ===" << std::endl;
  v2 = v3;
  vec_rev_iterator(test_file, v2);

  test_file << "=== Testing swap ===" << std::endl;
  v2.swap(v1);
  print_vector(test_file, v2);
  test_file << std::endl;

  test_file << "=== Testing comparisons (vec_comparison) ===" << std::endl;
  vec_comparison(test_file, v2, v1);

  test_file << std::endl;
}
