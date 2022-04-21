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
    std::vector<int> v1 = std::vector<int>(5);
    for (std::vector<int>::iterator ite = v1.begin(); ite < v1.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
}
