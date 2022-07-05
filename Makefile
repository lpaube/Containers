
CFILES = main.cpp
#C_VERSION = -std=c++98
C_VERSION = -std=c++11

ft_containers: $(CFILES)
	clang++ -Wall -Wextra $(C_VERSION) -g main.cpp -o ft_containers

clean:
	rm -rf ft_containers

re: clean ft_containers
