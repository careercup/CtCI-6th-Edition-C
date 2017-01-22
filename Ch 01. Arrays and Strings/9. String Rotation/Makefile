main: main.c
	gcc -o main main.c

clean:
	rm -vf main

check: main
	./main waterbottle waterbottle | grep 'False' > /dev/null
	./main waterbottle aterbottlew | grep 'True' > /dev/null
	./main waterbottle terbottlewa | grep 'True' > /dev/null
	./main waterbottle erbottlewat | grep 'True' > /dev/null
	./main waterbottle rbottlewate | grep 'True' > /dev/null
	./main waterbottle bottlewater | grep 'True' > /dev/null
	./main waterbottle ottlewaterb | grep 'True' > /dev/null
	./main waterbottle ttlewaterbo | grep 'True' > /dev/null
	./main waterbottle tlewaterbot | grep 'True' > /dev/null
	./main waterbottle lewaterbott | grep 'True' > /dev/null
	./main waterbottle ewaterbottl | grep 'True' > /dev/null
	./main waterbottle aterbottlem | grep 'False' > /dev/null
	./main waterbottle ATERBOTTLEW | grep 'False' > /dev/null
	./main waterbottle aterbottlewa | grep 'False' > /dev/null
	./main waterbottle waterbottlewaterbottle | grep 'False' > /dev/null
	./main a a | grep 'False' > /dev/null
	./main a aa | grep 'False' > /dev/null
	./main aa aa | grep 'False' > /dev/null
	./main aa aaa | grep 'False' > /dev/null
	./main ab ba | grep 'True' > /dev/null

.PHONY: clean check
