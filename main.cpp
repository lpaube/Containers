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

#include "containers_test/srcs/map/common.hpp"
#include <list>

#define T1 char
#define T2 int
typedef _pair<const T1, T2> T3;

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3('a' + i, (i + 1) * 7));

	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	TESTED_NAMESPACE::map<T1, T2>::iterator it_ = mp.begin();
	TESTED_NAMESPACE::map<T1, T2>::reverse_iterator it(it_), ite;
	printSize(mp);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == dec(it, 3).base()) << std::endl;

	printPair(it.base());
	printPair(inc(it.base(), 1));

	std::cout << "TEST OFFSET" << std::endl;
	--it;
	printPair(it);
	printPair(it.base());

	it = mp.rbegin(); ite = mp.rend();
	while (it != ite)
		std::cout << "[rev] " << printPair(it++, false) << std::endl;
	printReverse(mp);

	return (0);
}
