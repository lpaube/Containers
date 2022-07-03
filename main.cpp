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
  map_test.insert(ft::pair<int, std::string>(15, "this is one"));
  map_test.insert(ft::pair<int, std::string>(30, "wowow"));
  map_test.insert(ft::pair<int, std::string>(35, "this is sicks (6)"));
  /*
  map_test.insert(ft::pair<int, std::string>(50, "this is eight"));
  map_test.insert(ft::pair<int, std::string>(65, "forty-one"));
  map_test.insert(ft::pair<int, std::string>(55, "minus 2"));
  map_test.insert(ft::pair<int, std::string>(70, "ten"));
  map_test.insert(ft::pair<int, std::string>(68, "thirty-two"));
  map_test.insert(ft::pair<int, std::string>(80, "forty-two"));
  map_test.insert(ft::pair<int, std::string>(90, "two"));
  */
  
  std::cout << "======PRINTING LEVELS MAP 1======" << std::endl;
  map_test.print_levels();

  map_test.erase(map_test.find(150));
  std::cout << "ERASE 150" << std::endl;
  map_test.print_levels();
}
