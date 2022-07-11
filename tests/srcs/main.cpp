#include <fstream>

#ifndef NAMESPACE_NUM
#define NAMESPACE_NUM 1
#endif

#include "tests.hpp"

int main()
{
  std::fstream test_file;

#if NAMESPACE_NUM == 1
  test_file.open("tests/log/tests_ft.txt", std::fstream::out | std::fstream::trunc);
#elif NAMESPACE_NUM == 2
  test_file.open("tests/log/tests_std.txt", std::fstream::out | std::fstream::trunc);
#endif

  test_vector(test_file);
  test_stack(test_file);
  test_map(test_file);
}
