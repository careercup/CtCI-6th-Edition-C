main: main.c
	gcc -o main main.c

clean:
	rm -vf main

check: main
	./main abc aabc | grep 'True' > /dev/null
	./main aabc abc | grep 'True' > /dev/null
	./main abc abbc | grep 'True' > /dev/null
	./main abbc abc | grep 'True' > /dev/null
	./main abc abcc | grep 'True' > /dev/null
	./main abcc abc | grep 'True' > /dev/null
	./main abc xbc | grep 'True' > /dev/null
	./main xbc abc | grep 'True' > /dev/null
	./main axc abc | grep 'True' > /dev/null
	./main abc axc | grep 'True' > /dev/null
	./main abc abx | grep 'True' > /dev/null
	./main abx abc | grep 'True' > /dev/null
	./main abc abc | grep 'False' > /dev/null
	./main a a | grep 'False' > /dev/null
	./main abc abccc | grep 'False' > /dev/null
	./main abccc abc | grep 'False' > /dev/null

.PHONY: clean check
