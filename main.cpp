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
#include <array>
#include <vector>
#include <map>
#include <iostream>
#include "vector.hpp"
#include "map.hpp"

template <typename T>
void print_vector(ft::vector<T> vec)
{
  for (typename ft::vector<T>::iterator ite = vec.begin(); ite != vec.end(); ++ite)
  {
    std::cout << "vec elem: " << *ite << std::endl;
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
}

int	main(void)
{
  test_real_vector();
  test_my_vector();
}
