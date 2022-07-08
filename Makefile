
NAME = ft_containers
CFILES = main.cpp
CVERSION = -std=c++11
CFLAGS = $(CVERSION) -Wall -c -g
CC = clang++
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)


%.o: %cpp
	$(CC) $(CFLAGS) -I. -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -lprofiler $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
