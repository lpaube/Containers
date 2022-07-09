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

#include "vector.hpp"
#include "stack.hpp"
#include "rb_tree.hpp"
#include "map.hpp"
#include "utils.hpp"
#include "Timer.hpp"

#include <sstream>
#include <list>
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>

#define NAMESPACE ft

// GOAL: < 1000ms
// Try 01: ft_insert_basic: 34859ms | std_insert_basic: 58ms (30000 elems)
// Try 02: ft_insert_basic: 22833ms | std_insert_basic: 58ms (30000 elems)
// Try 03: ft_insert_basic: 12302ms | std_insert_basic: 58ms (30000 elems)
// Try 04: ft_insert_basic: 876ms | std_insert_basic: 58ms (30000 elems) | USED POINTERS INSTEAD OF ITERATORS

// GOAL: < 12ms
// Try 01: ft_assign_range 1080ms | std_insert_basic: 0.641ms (30000 elems)
// Try 02: ft_assign_range 0.009ms | std_insert_basic: 0.641ms (30000 elems) | Inserted all at once instead of individual insert calls

void print_vector(NAMESPACE::vector<std::string>& v)
{
  std::cout << "===PRINTING VECTOR===" << std::endl;
  for (int i = 0; v.begin() + i != v.end(); ++i)
  {
    std::cout << "Elem " << i 
      << ": " << *(v.begin() + i)
      << std::endl;
  }
  std::cout << std::endl;
}

void assign_range(NAMESPACE::vector<int>& vreal, NAMESPACE::vector<int>& vref)
{
  vreal.assign(vref.begin(), vref.begin() + 3);
}

void insert_range(NAMESPACE::vector<int>& vreal, NAMESPACE::vector<int>& vref)
{
  vreal.insert(vreal.begin(), vref.begin(), vref.begin() + 5);
}

void insert_basic(NAMESPACE::vector<int>& vreal)
{
  for (NAMESPACE::vector<int>::size_type i = 0; i < 50; ++i)
  {
    vreal.insert(vreal.begin(), i);
  }
}

int main(void)
{
  using std::chrono::high_resolution_clock;
  using std::chrono::duration_cast;
  using std::chrono::duration;
  using std::chrono::milliseconds;

    std::size_t s_size = 32;                                                                       \
    std::size_t b_size = 64;                                                                       \

    std::string s_string[32] = {                                                                   \
        "QExoqp0nICr0sXsHqty2", "naax9QcpJhvaL7DezsNQ", "25ZTtB6wbptfbxM8AvHB",                    \
        "tShYNtc0MkdjqLrOatgz", "7Z3kf1Qec0NnsLSEpbOt", "WhkSNrKJC966fvjZ2Or1",                    \
        "8vlxlFRRgW7yYj4GO7dt", "5sq1aoT8zP0HaHj3nFOK", "61Dv31GYZhkgjKCErpng",                    \
        "l0IIcWWHhOcPzoxEamQM", "bE1RYclskwXlhCm46YFs", "kXeoi5qz94JYPqSDTs79",                    \
        "TFsQP1dz8VVos9KzUpY0", "b3wYQR7An193gjgYuRj3", "xSmyNsnSJ47jLqrvbpyr",                    \
        "guAIP2Wq43Gf8VhHsyu5", "yT6c2loPebHovnq9BQog", "3qvU1xcVm2g1DKFDlqh4",                    \
        "L0q8RR9P41VD4sVjdnWl", "YdjESsIZM4b1oGQPjpBe", "l1ZVQbWKw7brHUSimJgq",                    \
        "xdn0cf4vqRzpfXWtl10G", "lYnZvpqaV0s8DowMZwzV", "8P1cyKrwJNLoJyvLjYqO",                    \
        "4MhOXNbAX23CEijO5cRT", "tHe3miAwCOVQbuoLaEP2", "l6uNLsc8fiLl3eWoG6j6",                    \
        "477xt6l0lph9ALQdr4HX", "D9UJNe4s8YF02LhrwOdl", "dLCisBNOdE8yugntu6cj",                    \
        "YvY4aQFHgAuagn4dFLO1", "eGR6Dtv7LW75qlV5Fkik"                                             \
    };                                                                                             \
    std::string b_string[64] = {                                                                   \
        "uvg6KqtcgduR31n3ajsv", "wbiAcjgojb9JOagZwyMn", "ATZKCzaPOqgkhPjwuGlf",                    \
        "MOhaJs56yjOw8f6nLPRA", "0gyB2Tr42v6awMw2nK7J", "e6GsiLFUuoDpVFEhJKZ1",                    \
        "z0jXAhiV9keBsaLOY0Xf", "P68p2ZAosHJdmoZh1C7N", "Pu3EuZVeY0TCO3ojdK0t",                    \
        "z7jCHMooHCS73M8GygKB", "uT4KoK83JrZxZjkul7ty", "g8gfrZoY5XwfzRusvHvv",                    \
        "7PGmkM0OSRnYREt9mFIP", "q1od7mBIpPEsCtpF9kdw", "XQo0LWId5TdZnLnpUNOb",                    \
        "U0m1R0kFFhAFyS6hmHHw", "K0lPKfxJxIOnE8QB90xn", "cZ5xyQifMJhrKxqBK9A7",                    \
        "cFBiwjfYw7Js6qEGy5Kt", "1tW0KWfXxeFO69tByqcE", "3Fvq9NxBrhPXHe0IlIVx",                    \
        "MSRDjdFRvHAhFGhiMtDe", "zGm2joMh71jQkYzg5L4V", "Mq4RRaeLvSAO0z2ibp8Q",                    \
        "WnLFYnQKP8TNJkqVVbUg", "E98UphbbVSzrW5Mzurmg", "F8HRxeEcaTZDkFPkioij",                    \
        "jmUVl4Q8X5BwVNzXN219", "n7Xp4w4FwzGKit7AI4SO", "4MxXYr6rKOcXLt9UkVd2",                    \
        "4RVTDsADtRyboaai9d29", "XaSqsrrtdhAfFoJIc5KK", "9Z9jdVCrTT09bg348ceb",                    \
        "I6uqLG9dO5mfNdSMwOYm", "UwMTzJPlbnhgwbHpDi6w", "DebjMP9afncYE6GhhO00",                    \
        "YGPuscYDiGfAjY1UWST0", "K6gbvgGjVZgEFUDlkdSk", "8xCBPI0w6TpC0RA62c2W",                    \
        "fYMxkNwmKg3moP8KvD9v", "QpPdhwhEYjIugg3OPcPH", "qQBXjSn43I3EMP54SyxZ",                    \
        "7qvdKwoW1CQEZTWPvuSC", "rCT212rdYO0zTGHXesKg", "dBHvlHsBwcR9MkkenYYG",                    \
        "NQiSlergqR8fVbOeivLj", "xYVqsV147UIe7jVBVwXo", "tcxayO4DdEJ885TbqUMy",                    \
        "9TGSMTD8U8ksRpHqq0cL", "TIJ16jCv9BSUiWvhbF9T", "BM9GL2ig1hePkA6lM6Ck",                    \
        "TfJTYB9JQMU6CGcYg20Q", "Fg6e5YT2FQbpTZNTDqdo", "LI5q6ml40MeE9H1dPb93",                    \
        "OaxJUSm3nYN9Y8Ela7sS", "BgBeODAwXz7xJo50Rwqd", "xdkgKj1dEoJ6zuVhkvvo",                    \
        "olIewtUEvXJgs1lB9bCn", "dTsPDS0x2uXtcgOIJHb8", "DYvJ2phLppGNZKboTBrd",                    \
        "DjNFMtt9PxkzqvWBHI6j", "1Z3YkeTFlPniKnzFhzgu", "76XqQg6hqMf5IXxKPOEs",                    \
        "gzaapTWW7i9EZjjzLeK6"                                                                     \
    };                                                                                             \

  ft::vector<std::string> v;

  v.insert(v.begin(), s_string, s_string + s_size);

  print_vector(v);

  v.insert(v.begin(), b_string, b_string + 10);

  print_vector(v);

  /*
  NAMESPACE::vector<int> v1;
  NAMESPACE::vector<int> v2;
  NAMESPACE::vector<int> v3;

  for (int i = 1000; i < 10000; i += 1000)
    v3.insert(v3.end(), i);


  Timer t1("insert_basic");
  insert_basic(v1);
  t1.Stop();

  Timer t2("assign_range");
  assign_range(v2, v1);
  t2.Stop();

  std::cout << "v1size: " << v1.size() << std::endl;

  for (auto i: v1)
    std::cout << "v1prei: " << i << std::endl;
  std::cout << std::endl;

  for (auto i: v3)
    std::cout << "v3i: " << i << std::endl;
  std::cout << std::endl;

  Timer t3("insert_range");
  insert_range(v1, v3);
  t3.Stop();


  std::cout << "v1size: " << v1.size() << std::endl;

  for (auto i: v1)
    std::cout << "v1posti: " << i << std::endl;
  std::cout << std::endl;


  return 0;
  */
}
