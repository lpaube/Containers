/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:08:44 by laube             #+#    #+#             */
/*   Updated: 2022/03/27 21:24:39 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "my_vector.hpp"
#include <vector>
#include <iostream>
#include "my_vector.hpp"

int	main(void)
{
	std::vector<int> v1;

	std::vector<int>* test = new std::vector<int>;

	for (int i = 1; i < 6; i++) {
		v1.push_back(i);
	}
	std::cout << "Output of begin and end: ";
	for (auto i = v1.begin(); i != v1.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << "\nOutput of cbegin and cend: ";
    for (auto i = v1.cbegin(); i != v1.cend(); ++i)
        std::cout << *i << " ";
  
    std::cout << "\nOutput of rbegin and rend: ";
    for (auto ir = v1.rbegin(); ir != v1.rend(); ++ir)
        std::cout << *ir << " ";
  
    std::cout << "\nOutput of crbegin and crend : ";
    for (auto ir = v1.crbegin(); ir != v1.crend(); ++ir)
        std::cout << *ir << " ";
}
