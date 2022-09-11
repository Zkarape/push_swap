NAME = push_swap

SRC = actions.c\
	  algorithm.c\
	  error_handling.c\
	  ft_split.c\
	  ft_strjoin\
	  indexing.c\
	  more_utils.c\
	  parsing.c\
	  sort.c\
	  utils.c\

OBJS = $(SRC:.c=.o)

GCC = cc
FLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) -o $(NAME) -I ./
all: $(NAME)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
