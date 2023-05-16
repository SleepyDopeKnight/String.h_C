.PHONY: all check clean rebuild
CC = gcc -std=c11
FLAGS = -Wall -Wextra -Werror
OS = $(shell uname -s)

all: test check gcov_report

s21_string.a:
	gcc $(FLAGS) -c s21_string.c
	ar rc s21_string.a s21_string.o
	ranlib s21_string.a

test: s21_string.a
	$(CC) $(FLAGS) -lcheck s21_tests.c s21_string.a -o s21_tests
	./s21_tests

gcov_report: s21_string.a
	$(CC) $(FLAGS) --coverage -lcheck s21_tests.c s21_string.c -o gcov_report
	./gcov_report
	lcov -t "./gcov_report" -o gcov_report.info -c -d .
	genhtml -o report gcov_report.info
ifeq ($(OS), Darwin)
	open ./report/index.html
else
	xdg-open ./report/index.html
endif

check:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	rm *.cfg
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./s21_tests
else
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./s21_tests
endif

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf gcov_report
	rm -rf report
	rm -rf s21_tests

rebuild: clean all