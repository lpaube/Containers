containers: main.cpp my_vector.hpp
	clang++ -std=c++11 -g main.cpp -o containers

clean:
	rm -rf containers
