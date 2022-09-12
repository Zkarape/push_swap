NAME = push_swap

SRC = $(wildcard *.c)

OBJS = $(SRC:.c=.o)

GCC = cc
FLAGS = -Wall -fsanitize=address -Werror -Wextra -g -ggdb3

$(NAME): $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) -o $(NAME) -I ./

all: $(NAME)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
