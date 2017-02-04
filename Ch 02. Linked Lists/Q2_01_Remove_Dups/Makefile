main: main.c
	gcc -o main main.c

clean:
	rm -vf main

check: main
	./main a | grep '^a$$' > /dev/null
	./main a a | grep '^a$$' > /dev/null
	./main a a a a a a a a | grep '^a$$' > /dev/null
	./main a a a a a a a b | grep '^a b$$' > /dev/null
	./main a b b b b b b b | grep '^a b$$' > /dev/null
	./main a b b b b b b a | grep '^a b$$' > /dev/null
	./main a b a b a b a b | grep '^a b$$' > /dev/null
	./main a a b b a a b b | grep '^a b$$' > /dev/null
	./main a a a a b b b b | grep '^a b$$' > /dev/null
	./main a b c | grep '^a b c$$' > /dev/null
	./main a a a a a a b c | grep '^a b c$$' > /dev/null
	./main a a a a a b c a | grep '^a b c$$' > /dev/null
	./main a b b b b b b c | grep '^a b c$$' > /dev/null
	./main a b c c c c c c | grep '^a b c$$' > /dev/null
	./main a a b b a a c c | grep '^a b c$$' > /dev/null
	./main a b c a b c a b | grep '^a b c$$' > /dev/null

.PHONY: clean check
