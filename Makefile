CC = cc
CC_ARGS = -c -g3 -Wall -Werror -Wextra

NAME = libftprintf.a
SRC = src/ft_printf.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $^

%.o: %.c
	@$(CC) $(CC_ARGS) $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

.PHONY: all clean fclean
