/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:08:44 by laube             #+#    #+#             */
/*   Updated: 2022/03/28 15:14:13 by laube            ###   ########.fr       */
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

	for (int i = 0; i < 5; i++) {
		std::cout << "i: " << i << " | my vec: " << mv1[i] << std::endl;
	}
}
