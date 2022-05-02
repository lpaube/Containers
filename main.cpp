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
#include <array>
#include <vector>
#include <map>
#include <iostream>
#include "vector.hpp"
#include "map.hpp"

int	main(void)
{
    std::cout << "--------REAL VECTOR: COUNT AND VALUE CONSTRUCTOR---------" << std::endl;
    std::vector<int> v1(5, 1);
    for (std::vector<int>::iterator ite = v1.begin(); ite < v1.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << "--------REAL VECTOR: CONSTRUCTOR BY ITERATORS---------" << std::endl;
    std::array<double, 5> a1{1.2, 1.6, 3.6, 88.88, 9};
    std::vector<int> v2(a1.begin() + 1, a1.end());
    for (std::vector<int>::iterator ite = v2.begin(); ite < v2.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }

    std::cout << "--------REAL VECTOR: CONSTRUCTOR BY COPY---------" << std::endl;
    std::vector<int> v3(v2);
    for (std::vector<int>::iterator ite = v3.begin(); ite < v3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }

    std::cout << "--------REAL VECTOR: CAPACITY & SIZE---------" << std::endl;
    std::cout << "v3.capacity(): " << v3.capacity() << std::endl;
    std::cout << "v3.size(): " << v3.size() << std::endl;
    std::cout << "v3.max_size(): " << v3.max_size() << std::endl;
    std::cout << "v2.max_size(): " << v2.max_size() << std::endl;
    std::cout << std::endl;

    std::cout << "--------REAL VECTOR: RESERVE 10---------" << std::endl;
    v3.reserve(10);
    std::cout << "v3.capacity(): " << v3.capacity() << std::endl;
    std::cout << "v3.size(): " << v3.size() << std::endl;
    for (std::vector<int>::iterator ite = v3.begin(); ite < v3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--------REAL VECTOR: INSERT POS 1, VALUE 36---------" << std::endl;
    v3.insert(v3.begin() + 1, 36);
    for (std::vector<int>::iterator ite = v3.begin(); ite < v3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--------REAL VECTOR: INSERT POS 1, 5 OF VALUE 99---------" << std::endl;
    v3.insert(v3.begin() + 1, 5, 99);
    for (std::vector<int>::iterator ite = v3.begin(); ite < v3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--------REAL VECTOR: ERASE POS 0---------" << std::endl;
    v3.erase(v3.begin());
    for (std::vector<int>::iterator ite = v3.begin(); ite < v3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------REAL VECTOR: SWAP V2 AND V3---------" << std::endl;
    v3.swap(v2);
    for (std::vector<int>::iterator ite = v3.begin(); ite < v3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << std::endl;


    // MY VECTOR
    std::cout << "---------MY VECTOR: COUNT AND VALUE CONSTRUCTOR---------" << std::endl;
    ft::vector<int> mv1(4, 5);
    for (ft::vector<int>::iterator ite = mv1.begin(); ite < mv1.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << "---------MY VECTOR: CONSTRUCTOR BY ITERATORS---------" << std::endl;
    std::array<double, 5> ma1{1.2, 1.6, 3.6, 88.88, 9};
    ft::vector<int> mv2(ma1.begin() + 1, ma1.end());
    for (ft::vector<int>::iterator ite = mv2.begin(); ite < mv2.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << "--------MY VECTOR: CONSTRUCTOR BY COPY---------" << std::endl;
    ft::vector<int> mv3(mv2);
    for (ft::vector<int>::iterator ite = mv3.begin(); ite < mv3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << "--------MY VECTOR: CAPACITY & SIZE---------" << std::endl;
    std::cout << "mv3.capacity(): " << mv3.capacity() << std::endl;
    std::cout << "mv3.size(): " << mv3.size() << std::endl;
    std::cout << "mv3.max_size(): " << mv3.max_size() << std::endl;
    std::cout << std::endl;

    std::cout << "--------MY VECTOR: RESERVE 10---------" << std::endl;
    mv3.reserve(10);
    std::cout << "mv3.capacity(): " << mv3.capacity() << std::endl;
    std::cout << "mv3.size(): " << mv3.size() << std::endl;
    for (ft::vector<int>::iterator ite = mv3.begin(); ite < mv3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--------MY VECTOR: INSERT POS 1, VALUE 36---------" << std::endl;
    mv3.insert(mv3.begin() + 1, 36);
    for (ft::vector<int>::iterator ite = mv3.begin(); ite < mv3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--------MY VECTOR: INSERT POS 1, 5 OF VALUE 99---------" << std::endl;
    mv3.insert(mv3.begin() + 1, 5, 99);
    for (ft::vector<int>::iterator ite = mv3.begin(); ite < mv3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--------MY VECTOR: ERASE POS 0---------" << std::endl;
    mv3.erase(mv3.begin());
    for (ft::vector<int>::iterator ite = mv3.begin(); ite < mv3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--------MY VECTOR: SWAP MV2 AND MV3---------" << std::endl;
    mv3.swap(mv2);
    for (ft::vector<int>::iterator ite = mv3.begin(); ite < mv3.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << std::endl;


    // REAL MAP
    std::cout << "----PLAYING WITH MY MAP------" << std::endl;
    ft::map<int, std::string> map;
    
    std::cout << "----PLAYING WITH REAL MAP------" << std::endl;
    std::map<int, std::string> rmap;
    rmap[2] = "test2";
    rmap[3] = "test3";
    std::map<int, std::string>::iterator ite = rmap.begin();
    std::cout << "*ite: " << ite->first << std::endl;
}
