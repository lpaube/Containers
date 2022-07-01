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

#include <sstream>
#include <iterator>
/*
#include <array>
#include <vector>
#include <map>
#include <iostream>
#include <list>
*/
#include "vector.hpp"
#include "stack.hpp"
#include "rb_tree.hpp"
#include "map.hpp"
#include "utils.hpp"

int main(void)
{
  ft::map<int, std::string> map_test;
  map_test.insert(ft::pair<int, std::string>(1, "this is one"));
  map_test.insert(ft::pair<int, std::string>(4, "wowow"));
  map_test.insert(ft::pair<int, std::string>(6, "this is sicks (6)"));
  map_test.insert(ft::pair<int, std::string>(8, "this is eight"));
  map_test.insert(ft::pair<int, std::string>(41, "forty-one"));
  map_test.insert(ft::pair<int, std::string>(-2, "minus 2"));
  map_test.insert(ft::pair<int, std::string>(10, "ten"));
  map_test.insert(ft::pair<int, std::string>(32, "thirty-two"));
  map_test.insert(ft::pair<int, std::string>(42, "forty-two"));
  map_test.insert(ft::pair<int, std::string>(2, "two"));
  map_test.insert(ft::pair<int, std::string>(1000, "thousand"));
  map_test.insert(ft::pair<int, std::string>(999, "nine-nine-nine"));
  

  std::cout << "======PRINTING LEVELS MAP 1======" << std::endl;
  map_test.print_levels();
  map_test.print_map();

  /*
  // Copy constructor
  ft::map<int, std::string> map_test2(map_test.begin(), map_test.end());

  std::cout << "===This is map_test2===" << std::endl;
  map_test2.print_map();
  std::cout << "===== End of printing test_map2 =====" << std::endl;
  */
}
