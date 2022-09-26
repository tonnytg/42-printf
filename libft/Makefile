CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra -I . -c
NAME		= libft.a
FILES 		= $(wildcard *.c)
OBJS		= $(patsubst %.c,%.o, $(FILES))

all: $(NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) $< -o $@
	ar rsc $(NAME) $@\

$(NAME): $(OBJS)

clean:
	rm -rf *.o

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re