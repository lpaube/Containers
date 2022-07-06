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
#include "containers_test/srcs/map/common.hpp"
#include <list>
#include <iostream>
#include <string>

#include "map_tests.hpp"
#include "map_prelude.hpp"

int main(void)
{

  ft::map<int, std::string> mp1;
  ft::map<int, std::string>::size_type size;

  mp1.erase(mp1.begin(), mp1.end());

  mp1.insert(ft::make_pair(23, "23n"));
  mp1.insert(ft::make_pair(25, "asdasdfsdfsafdsf"));
  mp1.insert(ft::make_pair(1, "asdssdfdfdffffff"));
  mp1.insert(ft::make_pair(2, "dsfdffffdfdfdsdfdffa"));
  mp1.insert(ft::make_pair(3, "sssdfs"));
  mp1.insert(ft::make_pair(75, "dfse"));
  mp1.insert(ft::make_pair(30, "sefsadfasdfasdfsadfasdfsf"));
  mp1.insert(ft::make_pair(-22, "dfhkihgbnfbcx5reterjhd"));
  mp1.insert(ft::make_pair(-23, "sdffgdfgrefet34thfgheewt"));
  mp1.insert(ft::make_pair(0, "98y4rtuohwidsjusdossefsse"));

  mp1.erase(64);
  mp1.erase(0);
  mp1.erase(75);
  mp1.erase(1);
  mp1.erase(2);
  mp1.erase(3);
  mp1.erase(23);
  mp1.erase(23);
  mp1.erase(30);

  std::cerr << "Size before: " << mp1.size() << std::endl;
  mp1.print_levels();
  // This one below
  mp1.erase(-22);
  std::cerr << "Size After: " << mp1.size() << std::endl;
  mp1.print_levels();

  mp1.erase(-23);
  mp1.erase(-23);
}
