all: main

main: main.c
	gcc -o main main.c

clean:
	rm -fv main

check: main
	./main 7 1 6 + 5 9 2 | grep '^2 1 9$$' > /dev/null
	./main 0 0 1 + 0 1 0 | grep '^0 1 1$$' > /dev/null
	./main 1 + 1 | grep '^2$$' > /dev/null
	./main 1 2 + 1 | grep '^2 2$$' > /dev/null
	./main 1 2 3 + 1 | grep '^2 2 3$$' > /dev/null
	./main 1 + 1 2 | grep '^2 2$$' > /dev/null
	./main 1 + 1 2 3 | grep '^2 2 3$$' > /dev/null
	./main 9 9 9 + 1 | grep '^0 0 0 1$$' > /dev/null
	./main 9 9 9 + 9 9 9 | grep '^8 9 9 1$$' > /dev/null

.PHONY: all clean check
