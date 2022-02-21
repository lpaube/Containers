/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:08:44 by laube             #+#    #+#             */
/*   Updated: 2022/02/21 13:27:21 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "my_vector.hpp"
#include <vector>

int	main(void)
{
	std::test_vec<std::string> vector;
	test_vec.push_back("This");
	test_vec.push_back("is");
	test_vec.push_back("my vector.");

	for (int i = test_vec.begin(); i != test_vec.end(); i++)
		std::cout << *i << std::endl;
	return 0;
}
