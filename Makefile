FT_NAME = ft_containers
STD_NAME = std_containers

FT_NAMESPACE = 1
STD_NAMESPACE = 2

CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

SRCS_PATH = tests/srcs
INCL_PATH = tests/includes
OBJS_PATH = tests/obj
FT_OBJS_PATH = tests/obj/ft
STD_OBJS_PATH = tests/obj/std
OUTPUT_PATH = tests/log

SRCS_FILES = main.cpp test_vector.cpp test_stack.cpp test_map.cpp \
						 benchmark_vector.cpp benchmark_map.cpp benchmark_stack.cpp
OBJS_FILES = $(SRCS_FILES:.cpp=.o)

FT_OBJS = $(addprefix $(FT_OBJS_PATH)/, $(OBJS_FILES))
STD_OBJS = $(addprefix $(STD_OBJS_PATH)/, $(OBJS_FILES))

all: $(FT_NAME) $(STD_NAME)

$(FT_NAME): $(FT_OBJS_PATH) $(FT_OBJS)
	$(CC) -o $(FT_NAME) $(FT_OBJS) -I.

$(STD_NAME): $(STD_OBJS_PATH) $(STD_OBJS)
	$(CC) -o $(STD_NAME) $(STD_OBJS) -I.

$(FT_OBJS_PATH)/%.o: $(SRCS_PATH)/%.cpp
	$(CC) $(CFLAGS) -D NAMESPACE_NUM=$(FT_NAMESPACE) -I$(INCL_PATH) -I. -c $< -o $@

$(STD_OBJS_PATH)/%.o: $(SRCS_PATH)/%.cpp
	$(CC) $(CFLAGS) -D NAMESPACE_NUM=$(STD_NAMESPACE) -I$(INCL_PATH) -I. -c $< -o $@

$(FT_OBJS_PATH):
	mkdir -p tests/obj/ft

$(STD_OBJS_PATH):
	mkdir -p tests/obj/std

clean:
	$(RM) $(FT_OBJS) $(STD_OBJS) $(OBJS_PATH)

fclean: clean
	$(RM) $(FT_NAME) $(STD_NAME)

re: fclean all

.PHONY: all fclean re
