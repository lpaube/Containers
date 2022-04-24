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

//#include "my_vector.hpp"
#include <vector>
#include <iostream>
#include "my_vector.hpp"

int	main(void)
{
    std::cout << "--------REAL VECTOR: COUNT AND VALUE CONSTRUCTOR---------" << std::endl;
    std::vector<int> v1 = std::vector<int>(5, 1);
    for (std::vector<int>::iterator ite = v1.begin(); ite < v1.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << "--------REAL VECTOR: CONSTRUCTOR BY ITERATORS---------" << std::endl;
    std::array<double, 5> a1{1.2, 1.6, 3.6, 88.88, 9};
    std::vector<int> v2 = std::vector<int>(a1.begin() + 1, a1.end());
    for (std::vector<int>::iterator ite = v2.begin(); ite < v2.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }

    std::cout << "--------REAL VECTOR: CONSTRUCTOR BY COPY---------" << std::endl;
    std::vector<int> v3 = std::vector<int>(v2);
    for (std::vector<int>::iterator ite = v3.begin(); ite < v3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }

    std::cout << "---------MY VECTOR: COUNT AND VALUE CONSTRUCTOR---------" << std::endl;
    ft::vector<int> mv1 = ft::vector<int>(4, 5);
    for (ft::vector<int>::iterator ite = mv1.begin(); ite < mv1.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << "---------MY VECTOR: CONSTRUCTOR BY ITERATORS---------" << std::endl;
    std::array<double, 5> ma1{1.2, 1.6, 3.6, 88.88, 9};
    ft::vector<int> mv2 = ft::vector<int>(ma1.begin() + 1, ma1.end());
    for (ft::vector<int>::iterator ite = mv2.begin(); ite < mv2.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << "--------MY VECTOR: CONSTRUCTOR BY COPY---------" << std::endl;
    ft::vector<int> mv3 = ft::vector<int>(mv2);
    for (ft::vector<int>::iterator ite = mv3.begin(); ite < mv3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
}
