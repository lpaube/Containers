containers: main.cpp my_vector.hpp
	clang++ main.cpp -o containers

clean:
	rm -rf containers
