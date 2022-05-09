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

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_0(vct.rbegin());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_1(vct.rend());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_mid;

	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_0 = vct.rbegin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_1;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_mid;

	for (int i = size; it_0 != it_1; --i)
		*it_0++ = i;
	printSize(vct, 1);
	it_0 = vct.rbegin();
	cit_1 = vct.rend();
	it_mid = it_0 + 3;
	cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

	std::cout << std::boolalpha;
	std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

	std::cout << "\t\tft_eq_ope:" << std::endl;
	// regular it
	ft_eq_ope(it_0 + 3, it_mid);
	ft_eq_ope(it_0, it_1);
	ft_eq_ope(it_1 - 3, it_mid);
	// const it
	ft_eq_ope(cit_0 + 3, cit_mid);
	ft_eq_ope(cit_0, cit_1);
	ft_eq_ope(cit_1 - 3, cit_mid);
	// both it
	ft_eq_ope(it_0 + 3, cit_mid);
	ft_eq_ope(it_mid, cit_0 + 3);
	ft_eq_ope(it_0, cit_1);
	ft_eq_ope(it_1, cit_0);
	ft_eq_ope(it_1 - 3, cit_mid);
	ft_eq_ope(it_mid, cit_1 - 3);

	return (0);
}
