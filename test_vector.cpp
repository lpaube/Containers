#include "vector.hpp"
#include <vector>

#define NAMESPACE ft

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
  std::cout << "Erase 2 it*: " << *(vreal.erase(vreal.begin() + 2));
  std::cout << "Erase 3 it*: " << *(vreal.erase(vreal.end()));
  std::cout << "Erase 4 it*: " << *(vreal.erase(vreal.end() - 2));

  print_vector(vreal);
  std::cout << std::endl;
}

template <typename T>
void vec_erase_range(NAMESPACE::vector<T>& vreal)
{
  std::cout << "Erase 1 it*: " << *(vreal.erase(vreal.begin(), vreal.begin()));
  std::cout << "Erase 2 it*: " << *(vreal.erase(vreal.begin() + 2), vreal.begin() + 3);
  std::cout << "Erase 3 it*: " << *(vreal.erase(vreal.end() - 2, vreal.end()));
  std::cout << "Erase 4 it*: " << *(vreal.erase(vreal.end() - 2), vreal.end() - 2);

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
  v3.clear();
  v3.clear();
  print_vector(v3);
  std::cout << std::endl;

  std::cout << "=== Testing assign size (vec_assign_size_int) ===" << std::endl;
  vec_assign_size_int(v2);

  std::cout << "=== Testing assign range (vec_assign_range_int) ===" << std::endl;
  vec_assign_range_int(v2, v1);

  std::cout << "=== Testing erase position (vec_erase_pos) ===" << std::endl;
  vec_erase_pos(v1);

  std::cout << "=== Testing erase range (vec_erase_range) ===" << std::endl;
  vec_erase_range(v1);
}
