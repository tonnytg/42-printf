all: re

test:
	@make -C ..
	@cp ../*.h test.h
	@cp -a ../libft ./libft
	@gcc main.c ../*.a -o test
	./test

clean:
	@rm -f test test.h

fclean: clean
	@rm -rf libft
	@make fclean -C ..

re: fclean test
