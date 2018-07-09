all: main

main: main.c
	gcc -o main main.c

clean:
	rm -fv main

check: main
	./main 0 3 5 8 5 10 2 1 | grep '^1 2 10 5 8 5 3$$' > /dev/null
	./main 1 3 5 8 5 10 2 1 | grep '^1 2 10 5 8 5 3$$' > /dev/null
	./main 2 3 5 8 5 10 2 1 | grep '^1 2 10 5 8 5 3$$' > /dev/null
	./main 3 3 5 8 5 10 2 1 | grep '^1 2 10 5 8 5 3$$' > /dev/null
	./main 4 3 5 8 5 10 2 1 | grep '^1 2 3 10 5 8 5$$' > /dev/null
	./main 5 3 5 8 5 10 2 1 | grep '^1 2 3 10 5 8 5$$' > /dev/null
	./main 6 3 5 8 5 10 2 1 | grep '^1 2 5 5 3 10 8$$' > /dev/null
	./main 8 3 5 8 5 10 2 1 | grep '^1 2 5 5 3 10 8$$' > /dev/null
	./main 10 3 5 8 5 10 2 1 | grep '^1 2 5 8 5 3 10$$' > /dev/null
	./main 11 3 5 8 5 10 2 1 | grep '^1 2 10 5 8 5 3$$' > /dev/null

.PHONY: all clean check
