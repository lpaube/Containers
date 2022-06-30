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
  map_test.insert(ft::pair<int, std::string>(4, "wowow"));
  map_test.insert(ft::pair<int, std::string>(6, "this is sicks (6)"));
  map_test.insert(ft::pair<int, std::string>(1, "this is one"));
  map_test.insert(ft::pair<int, std::string>(8, "this is eight"));
  std::cout << "===== Printing test_map =====" << std::endl;
  map_test.print_map();
  std::cout << "===== End of printing test_map =====" << std::endl;


  /*
  std::cout << "===== Printing begin() iterator ++ =====" << std::endl;
  ft::map<int, std::string>::iterator it = map_test.begin();
  std::cout << "ite begin: " << it->first << std::endl;
  ++it;
  std::cout << "++it begin: " << it->first << std::endl;
  ++it;
  std::cout << "++it begin: " << it->first << std::endl;
  ++it;
  std::cout << "++it begin: " << it->first << std::endl;

  std::cout << "===== Printing end() iterator -- =====" << std::endl;
  ft::map<int, std::string>::iterator ite = map_test.end();
  --ite;
  std::cout << "ite end --: " << ite->first << std::endl;
  --ite;
  std::cout << "--ite begin: " << ite->first << std::endl;
  --ite;
  std::cout << "--ite begin: " << ite->first << std::endl;
  --ite;
  std::cout << "--ite begin: " << ite->first << std::endl;
  std::cout << std::endl;

  std::cout << "This is find key: "
    << (map_test.find(6))->first
    << " | this is the value: " << (map_test.find(6))->second
    << std::endl;
  std::cout << std::endl;

  */
  std::cout << "max_size(): " << map_test.max_size() << std::endl;
  std::cout << "size(): " << map_test.size() << std::endl;
  std::cout << std::endl;

  // Copy constructor
  ft::map<int, std::string> map_test2(map_test.begin(), map_test.end());

  std::cout << "===This is map_test2===" << std::endl;
  map_test2.print_map();
  std::cout << "===== End of printing test_map2 =====" << std::endl;

  /*
  map_test2.erase(++(map_test2.begin()));

  std::cout << "===This is map_test2 after erase===" << std::endl;
  map_test2.print_map();
  std::cout << "===== End of printing test_map2 =====" << std::endl;
  */
}
