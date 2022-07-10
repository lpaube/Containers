NAME = ft_containers

SRCS = main.cpp test_vector.cpp test_map.cpp
CC = clang++
VERSION = -std=c++98
CFLAGS = -g $(VERSION)

$(NAME) : $(SCRS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re
