FLAGS=-Wall -Wextra -Werror -std=c11 
LFLAGS=-lcheck -lm

ifeq ($(shell uname), Linux)
	LFLAGS=-lcheck -lm -lsubunit
endif

quadratic_equation.a:
	gcc -c $(FLAGS) quadratic_equation.c
	ar rc quadratic_equation.a quadratic_equation.o
	ranlib quadratic_equation.a

all: quadratic_equation.a

check: quadratic_equation.a
	gcc $(FLAGS) -c tests.c 
	gcc $(FLAGS) tests.o -L. quadratic_equation.a $(LFLAGS) -o tests
	./tests

rebuild: clean all

clean:
	rm -rf quadratic_equation.a tests *.o 