main: main.c
	gcc -o main main.c

clean:
	rm -vf main

check: main
	./main aabcccccaaa | grep '^a2b1c5a3$$' > /dev/null
	./main aaaaaaaaaaa | grep '^a11$$' > /dev/null
	./main abcdefghijk | grep '^abcdefghijk$$' > /dev/null
	./main aabbccddeeff | grep '^aabbccddeeff$$' > /dev/null
	./main aabbccddeee | grep '^a2b2c2d2e3$$' > /dev/null
	./main abcdefffffff | grep '^abcdefffffff$$' > /dev/null
	./main abcdeffffffff | grep '^a1b1c1d1e1f8$$' > /dev/null

.PHONY: clean check
