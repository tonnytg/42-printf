CC = cc
CC_FLAGS = -Wall -Werror -Wall

SRC = src

NAME = "libftprintf.a"
LIBFT = "libft.a"

OBJ = $(SRC:.c=.o)

all: copile run

copile:
	$(CC) $(CC_FLAGS) main.c $(SRC)/ft_printf.c

run:
	./a.out

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

test:
	@echo "testing"

clean:
	rm -f a.out
	rm -f $(OBJS) $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
