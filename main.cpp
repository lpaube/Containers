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
}
