/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:08:44 by laube             #+#    #+#             */
/*   Updated: 2022/04/21 20:21:09 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "my_vector.hpp"
#include <sstream>
#include <iterator>
#include <array>
#include <vector>
#include <map>
#include <iostream>
#include <list>
#include "vector.hpp"
//#include "map.hpp"
#include "containers_test/srcs/vector/common.hpp"
#include "ft_containers_tester/tests/prelude.hpp"

#define TESTED_NAMESPACE ft
#define TESTED_TYPE foo<int>

template <typename T>
void print_vector(ft::vector<T> vec)
{
  int i = 0;

  for (typename ft::vector<T>::iterator ite = vec.begin(); ite != vec.end(); ++ite, ++i)
  {
    std::cout << "Vec elem " << i << ": " << *ite << std::endl;
  }
}

template <typename T>
void print_vector(std::vector<T> vec)
{
  for (typename std::vector<T>::iterator ite = vec.begin(); ite != vec.end(); ++ite)
  {
    std::cout << "vec elem: " << *ite << std::endl;
  }
}

void test_real_vector()
{
  std::cout << "\033[1;40;32m=====REAL VECTOR=====\033[0m" << std::endl;
  std::cout << std::endl;
  std::cout << "=====CREATING VECTOR AND INSERTING VALUES: ======" << std::endl;
  std::vector<int> vec1;
  for (int i = 0; i < 10; ++i)
  {
    vec1.push_back(i * 11);
  }
  print_vector(vec1);
  
  std::cout << std::endl;

  std::cout << "=====REVERSE ITERATOR: =====" << std::endl;
  std::vector<int>::reverse_iterator r_ite = vec1.rbegin();
  for (int i = 0; r_ite + i != vec1.rend(); ++i)
  {
    std::cout << "vec elem (rev ite): " << *(r_ite + i) << std::endl;
  }
  std::cout << std::endl;

  std::cout << "=====EMPTY VECTOR: =====" << std::endl;
  std::vector<int> vec2;
  std::cout << "Is empty? (should be 1): " << vec2.empty() << std::endl;
  std::cout << "Is empty? (should be 0): " << vec1.empty() << std::endl;
  std::cout << std::endl;

  std::cout << "=====INSERT VEC1: =====" << std::endl;
  std::cout << "-----PRE INSERT: ------" << std::endl;
  print_vector(vec1);
  
  std::vector<int>::iterator ite = vec1.insert(vec1.begin() + 1, 99);
  std::cout << std::endl << "*ite after insert: " << *ite << std::endl;
  std::cout << std::endl;

  vec1.insert(vec1.begin(), 1111);
  vec1.insert(vec1.end() - 1, 21);
  vec1.insert(vec1.end(), 42);
  std::cout << "-----POST INSERT: ------" << std::endl;
  print_vector(vec1);
  std::cout << std::endl;
}

void test_my_vector()
{
  std::cout << "\033[1;40;32m=====MY VECTOR=====\033[0m" << std::endl;
  std::cout << std::endl;
  std::cout << "=====CREATING VECTOR AND INSERTING VALUES: ======" << std::endl;
  ft::vector<int> vec1;
  for (int i = 0; i < 10; ++i)
  {
    vec1.push_back(i * 11);
  }
  print_vector(vec1);
  
  std::cout << std::endl;

  std::cout << "=====REVERSE ITERATOR: =====" << std::endl;
  ft::vector<int>::reverse_iterator r_ite = vec1.rbegin();
  for (int i = 0; r_ite + i != vec1.rend(); ++i)
  {
    std::cout << "vec elem (rev ite): " << *(r_ite + i) << std::endl;
  }
  std::cout << std::endl;

  std::cout << "=====EMPTY VECTOR: =====" << std::endl;
  std::vector<int> vec2;
  std::cout << "Is empty? (should be 1): " << vec2.empty() << std::endl;
  std::cout << "Is empty? (should be 0): " << vec1.empty() << std::endl;
  std::cout << std::endl;

  std::cout << "=====INSERT VEC1: =====" << std::endl;
  std::cout << "-----PRE INSERT: ------" << std::endl;
  print_vector(vec1);
  
  ft::vector<int>::iterator ite = vec1.insert(vec1.begin() + 1, 99);
  std::cout << std::endl << "*ite after insert: " << *ite << std::endl;
  std::cout << std::endl;

  vec1.insert(vec1.begin(), 1111);
  vec1.insert(vec1.end() - 1, 21);
  vec1.insert(vec1.end(), 42);
  std::cout << "-----POST INSERT: ------" << std::endl;
  print_vector(vec1);
  std::cout << std::endl;
}

void vec_test_ctor_copy()
{
    {
        ft::vector<double, leak_allocator<double> > v(128, -345783);
        ft::vector<double, leak_allocator<double> > v_copy(v);

        PRINT_ALL(v_copy);

        if (v.data() == v_copy.data()) {
            std::cout << "Copy ctor doesn't do a deep copy!";
            PRINT_FILE_LINE();
        }

        if (!std::equal(v.begin(), v.end(), v_copy.begin())) {
            std::cout << "Copy ctor error";
            PRINT_FILE_LINE();
        }

        ft::vector<double, leak_allocator<double> > v1;
        ft::vector<double, leak_allocator<double> > v_copy1(v1);

        PRINT_ALL(v_copy1);

        if (v1.data() != v_copy1.data()) {
            std::cout << "Non-null pointer in vector of size 0";
            PRINT_FILE_LINE();
        }

        if (!std::equal(v1.begin(), v1.end(), v_copy1.begin())) {
            std::cout << "Copy ctor error.";
            PRINT_FILE_LINE();
        }
    }
    {
        ft::vector<ctor_dtor_checker<int>, leak_allocator<ctor_dtor_checker<int> > > v1(512);
        ft::vector<ctor_dtor_checker<int>, leak_allocator<ctor_dtor_checker<int> > > v2(v1);

        PRINT_SIZE_CAP(v1);
        PRINT_SIZE_CAP(v2);

        CHECK_DTOR(int);
    }
}

int main()
{
    vec_test_ctor_copy();
    CHECK_LEAKS(double);
    CHECK_LEAKS(ctor_dtor_checker<int>);
    CHECK_DTOR(int);
}
