#!/bin/bash

echo "Running the benchmarking tests: please wait..."
./ft_containers
./std_containers

ft_tests="./tests/log/tests_ft.txt"
std_tests="./tests/log/tests_std.txt"

if cmp -s -- "$ft_tests" "$std_tests"; then
  printf "\033[0;32mOK: The ft containers have the same output as the std containers.\033[0m\n"
  printf "See 'tests/benchmark' for the benchmarking results\n"
else
  printf "\033[0;31mBAD: The output of the ft containers and the std containers do not match.\033[0m\n"
  printf "See 'tests/log' for the differences.\n"
fi
