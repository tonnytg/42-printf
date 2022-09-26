NAME	=	libftprintf.a
CFLAGS	=	-Wall -Wextra -Werror
FILES	=	ft_printf.c core.c
HEADER	=	ft_printf.h
OBJ		=	$(FILES:.c=.o)

all: $(NAME)

$(OBJ): $(HEADER)
	cc $(CFLAGS) -c $(FILES)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a $(NAME)
	ar -rc $(NAME) $(OBJ)

clean:
	make clean -C libft
	rm	-f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
