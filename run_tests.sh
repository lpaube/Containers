#!/bin/bash

echo "Running the benchmarking tests: please wait..."
./ft_containers
./std_containers

ft_tests="./tests/log/tests_ft.txt"
std_tests="./tests/log/tests_std.txt"

if cmp -s -- "$ft_tests" "$std_tests"; then
  echo "OK: The ft containers have the same output as the std containers."
  echo "See 'tests/benchmark' for the benchmarking results"
else
  echo "BAD: The output of the ft containers and the std containers do not match."
  echo "See 'tests/log' for the differences."
fi
