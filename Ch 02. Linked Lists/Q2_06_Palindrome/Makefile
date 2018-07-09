all: main

main: main.c
	gcc -o main main.c

check: main
	./main a | grep '^True$$' > /dev/null
	./main a a | grep '^True$$' > /dev/null
	./main a a a | grep '^True$$' > /dev/null
	./main a b | grep '^False$$' > /dev/null
	./main a b c | grep '^False$$' > /dev/null
	./main a b a | grep '^True$$' > /dev/null
	./main a b c d c b a | grep '^True$$' > /dev/null

clean:
	rm -vf main

.PHONY: all check clean
