containers: main.cpp vector.hpp
	clang++ -Wall -Werror -Wextra -std=c++11 -g main.cpp -o containers

clean:
	rm -rf containers

re: clean containers
