containers: main.cpp my_vector.hpp
	clang++ -g main.cpp -o containers

clean:
	rm -rf containers
