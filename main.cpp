/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:08:44 by laube             #+#    #+#             */
/*   Updated: 2022/04/02 15:30:11 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "my_vector.hpp"
#include <vector>
#include <iostream>
#include "my_vector.hpp"

int	main(void)
{
	// Real Vector
	std::cout << "\n\n" << "-------REAL VECTOR---------" << std::endl;
	std::vector<int> v1;

	std::vector<int>* test = new std::vector<int>;

	for (int i = 1; i < 6; i++) {
		v1.push_back(i);
	}
	std::cout << "Output of begin and end: ";
	for (std::vector<int>::iterator i = v1.begin(); i != v1.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << "\nOutput of cbegin and cend: ";
	for (std::vector<int>::const_iterator i = v1.cbegin(); i != v1.cend(); ++i)
		std::cout << *i << " ";

	std::cout << "\nOutput of rbegin and rend: ";
	for (std::vector<int>::reverse_iterator ir = v1.rbegin(); ir != v1.rend(); ++ir)
		std::cout << *ir << " ";

	std::cout << "\nOutput of crbegin and crend : ";
	for (std::vector<int>::const_reverse_iterator ir = v1.crbegin(); ir != v1.crend(); ++ir)
		std::cout << *ir << " ";
	std::cout << "\n\n" << "--------MY VECTOR---------" << std::endl;

	// My vector
	ft::vector<int> mv1(5);

	mv1[2] = 3;
	for (int i = 0; i < 5; i++) {
		std::cout << "i: " << i << " | my vec: " << mv1[i] << std::endl;
	}
    std::vector<int>::iterator beg = v1.begin();
    std::cout << "begin iterator address: " << (void *)&(*beg) << std::endl;
    std::cout << "begin + 1 iterator address: " << (void *)&(*(beg + 1)) << std::endl;

    std::vector<int>::iterator mid1 = v1.begin() + 1;
    std::vector<int>::iterator mid2 = v1.begin() + 2;

    std::cout << "ite 2 - ite 1: " << mid1 - beg << std::endl;
}
