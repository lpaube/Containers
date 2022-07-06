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

/*
#include <array>
#include <vector>
#include <map>
#include <iostream>
#include <list>
*/
#include <sstream>
#include "vector.hpp"
#include "stack.hpp"
#include "rb_tree.hpp"
#include "map.hpp"
#include "utils.hpp"
//#include "containers_test/srcs/map/common.hpp"
#include <list>
#include <iostream>
#include <string>
#include <map>
#include <iterator>

//#include "map_tests.hpp"
//#include "map_prelude.hpp"
//
#define MY_NAMESPACE ft


int main(void)
{
  MY_NAMESPACE::map<int, std::string> mp1;

  mp1.insert(MY_NAMESPACE::pair<int, std::string>(1, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(2, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(3, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(4, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(5, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(6, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(7, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(8, "one"));
  /*
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(9, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(10, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(11, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(12, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(13, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(14, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(15, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(16, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(17, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(18, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(19, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(20, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(21, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(22, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(23, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(24, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(25, "one"));
  mp1.insert(MY_NAMESPACE::pair<int, std::string>(26, "one"));

  */
  mp1.print_levels();
  mp1.print_map();


  MY_NAMESPACE::map<int, std::string>::iterator it = mp1.begin();
  std::advance(it, 1);

  std::cerr << "===ERASING===" << std::endl;
  mp1.erase(it, mp1.end());

  std::cerr << "===SIZE: " << mp1.size() << std::endl;
  mp1.print_levels();
  mp1.print_map();
}
