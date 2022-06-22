
CFILES = main.cpp map.hpp vector.hpp rb_tree.hpp

ft_containers: $(CFILES)
	clang++ -Wall -Wextra -std=c++98 -g main.cpp -o ft_containers

clean:
	rm -rf ft_containers

re: clean ft_containers
