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

#include "vector.hpp"
#include "stack.hpp"
#include "rb_tree.hpp"
#include "map.hpp"
#include "utils.hpp"

#include <sstream>
#include <list>
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>

#include <chrono>

#define NAMESPACE ft

// GOAL: < 1000ms
// Try 01: ft_insert_basic: 34859ms | std_insert_basic: 58ms (30000 elems)
// Try 02: ft_insert_basic: 22833ms | std_insert_basic: 58ms (30000 elems)

void insert_basic(NAMESPACE::vector<int>& vref)
{
  for (NAMESPACE::vector<int>::size_type i = 0; i < 30000; ++i)
  {
    vref.insert(vref.begin(), i);
  }
}

int main(void)
{
  using std::chrono::high_resolution_clock;
  using std::chrono::duration_cast;
  using std::chrono::duration;
  using std::chrono::milliseconds;

  NAMESPACE::vector<int> v1;

  auto t1 = high_resolution_clock::now();
  insert_basic(v1);
  auto t2 = high_resolution_clock::now();

  auto ms_int = duration_cast<milliseconds>(t2 - t1);
  std::cout << "insert_basic time: " << ms_int.count() << "ms"
    << " | size: " << v1.size()
    << std::endl;

  return 0;
}
