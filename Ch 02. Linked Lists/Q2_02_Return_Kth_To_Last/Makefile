all: main

main: main.c
	gcc -o main main.c

clean:
	rm -fv main

check: main
	./main 1 Foo | grep '^Foo$$' > /dev/null
	./main 1 Foo Bar | grep '^Bar$$' > /dev/null
	./main 2 Foo Bar | grep '^Foo$$' > /dev/null
	./main 1 Foo Bar Baz | grep '^Baz$$' > /dev/null
	./main 2 Foo Bar Baz | grep '^Bar$$' > /dev/null
	./main 3 Foo Bar Baz | grep '^Foo$$' > /dev/null

.PHONY: all clean check
