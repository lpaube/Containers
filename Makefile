
CFILES = main.cpp
#C_VERSION = -std=c++98
C_VERSION = -std=c++11

INCL1 = ft_containers-terminator/tests/tests/map
INCL2 = ft_containers-terminator/tests/tests
INCL3 = ft_containers-terminator/tests
INCL4 = .

ft_containers: $(CFILES)
	clang++ -Wall -Wextra $(C_VERSION) -g \
		-I$(INCL1) -I$(INCL2) -I$(INCL3) -I$(INCL4)\
		main.cpp -o ft_containers

clean:
	rm -rf ft_containers

re: clean ft_containers
