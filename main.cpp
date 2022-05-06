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

#define TESTED_NAMESPACE ft
#define TESTED_TYPE int

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

int main(void)
{
  std::cout << std::endl << "========Real test======" << std::endl;
  std::istringstream str1("1 2 3 4 5 6");
  std::istreambuf_iterator<char> real_it(str1), real_end;
  std::vector<char> real_vec1(45, 'A');
  real_vec1.insert(real_vec1.begin() + 20, real_it, real_end);
  print_vector(real_vec1);


  std::cout << std::endl << "======My test=======" << std::endl;

  std::istringstream str2("1 2 3 4 5 6");
  std::istreambuf_iterator<char> it(str2), end;
  ft::vector<char> my_vec1(4, 'A');
  std::cout << "*my_vec1.begin()" << *(my_vec1.begin()) << std::endl;
  print_vector(my_vec1);
  my_vec1.insert(my_vec1.begin() + 2, it, end);
}
