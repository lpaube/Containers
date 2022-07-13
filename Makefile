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
BENCHMARK_PATH = tests/benchmark

SRCS_FILES = main.cpp test_vector.cpp test_stack.cpp test_map.cpp \
						 benchmark_vector.cpp benchmark_map.cpp benchmark_stack.cpp

OBJS_FILES = $(SRCS_FILES:.cpp=.o)

FT_OBJS = $(addprefix $(FT_OBJS_PATH)/, $(OBJS_FILES))
STD_OBJS = $(addprefix $(STD_OBJS_PATH)/, $(OBJS_FILES))

all: $(FT_NAME) $(STD_NAME)

$(FT_NAME): $(FT_OBJS_PATH) $(FT_OBJS)
	@$(CC) -o $(FT_NAME) $(FT_OBJS) -I.
	@echo "Compiled ft_containers"

$(STD_NAME): $(STD_OBJS_PATH) $(STD_OBJS)
	@$(CC) -o $(STD_NAME) $(STD_OBJS) -I.
	@echo "Compiled std_containers"

$(FT_OBJS_PATH)/%.o: $(SRCS_PATH)/%.cpp
	@$(CC) $(CFLAGS) -D NAMESPACE_NUM=$(FT_NAMESPACE) -I$(INCL_PATH) -I. -c $< -o $@
	@echo "Generated ft object file"

$(STD_OBJS_PATH)/%.o: $(SRCS_PATH)/%.cpp
	@$(CC) $(CFLAGS) -D NAMESPACE_NUM=$(STD_NAMESPACE) -I$(INCL_PATH) -I. -c $< -o $@
	@echo "Generated std object file"

$(FT_OBJS_PATH):
	mkdir -p tests/obj/ft

$(STD_OBJS_PATH):
	mkdir -p tests/obj/std

$(OUTPUT_PATH):
	mkdir -p tests/log

$(BENCHMARK_PATH):
	mkdir -p tests/benchmark

tests: $(FT_NAME) $(STD_NAME) $(OUTPUT_PATH) $(BENCHMARK_PATH)
	@bash run_tests.sh

clean:
	@$(RM) $(FT_OBJS) $(STD_OBJS) $(OBJS_PATH)
	@echo "Removed object files"

fclean: clean
	@$(RM) $(FT_NAME) $(STD_NAME)
	@echo "Removed executables"

re: fclean all

.PHONY: all fclean re
