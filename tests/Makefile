all: re

test:
	@make -C ..
	@cp ../src/*.h test.h
	@gcc main.c ../*.a -o test
	./test

clean:
	@rm -f test test.h

fclean: clean
	@make fclean -C ..

re: fclean test
