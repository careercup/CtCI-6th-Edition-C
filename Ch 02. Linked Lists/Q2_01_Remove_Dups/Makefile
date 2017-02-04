all: dedup dedup-ms

dedup: main.c
	gcc -o dedup main.c

dedup-ms: main.c
	gcc -o dedup-ms -DMERGE_SORT main.c

clean:
	rm -vf dedup dedup-ms

check: all
	./dedup a | grep '^a$$' > /dev/null
	./dedup a a | grep '^a$$' > /dev/null
	./dedup a a a a a a a a | grep '^a$$' > /dev/null
	./dedup a a a a a a a b | grep '^a b$$' > /dev/null
	./dedup a b b b b b b b | grep '^a b$$' > /dev/null
	./dedup a b b b b b b a | grep '^a b$$' > /dev/null
	./dedup a b a b a b a b | grep '^a b$$' > /dev/null
	./dedup a a b b a a b b | grep '^a b$$' > /dev/null
	./dedup a a a a b b b b | grep '^a b$$' > /dev/null
	./dedup a b c | grep '^a b c$$' > /dev/null
	./dedup a a a a a a b c | grep '^a b c$$' > /dev/null
	./dedup a a a a a b c a | grep '^a b c$$' > /dev/null
	./dedup a b b b b b b c | grep '^a b c$$' > /dev/null
	./dedup a b c c c c c c | grep '^a b c$$' > /dev/null
	./dedup a a b b a a c c | grep '^a b c$$' > /dev/null
	./dedup a b c a b c a b | grep '^a b c$$' > /dev/null
	./dedup-ms a | grep '^a$$' > /dev/null
	./dedup-ms a a | grep '^a$$' > /dev/null
	./dedup-ms a a a a a a a a | grep '^a$$' > /dev/null
	./dedup-ms a a a a a a a b | grep '^a b$$' > /dev/null
	./dedup-ms a b b b b b b b | grep '^a b$$' > /dev/null
	./dedup-ms a b b b b b b a | grep '^a b$$' > /dev/null
	./dedup-ms a b a b a b a b | grep '^a b$$' > /dev/null
	./dedup-ms a a b b a a b b | grep '^a b$$' > /dev/null
	./dedup-ms a a a a b b b b | grep '^a b$$' > /dev/null
	./dedup-ms a b c | grep '^a b c$$' > /dev/null
	./dedup-ms a a a a a a b c | grep '^a b c$$' > /dev/null
	./dedup-ms a a a a a b c a | grep '^a b c$$' > /dev/null
	./dedup-ms a b b b b b b c | grep '^a b c$$' > /dev/null
	./dedup-ms a b c c c c c c | grep '^a b c$$' > /dev/null
	./dedup-ms a a b b a a c c | grep '^a b c$$' > /dev/null
	./dedup-ms a b c a b c a b | grep '^a b c$$' > /dev/null

.PHONY: all clean check
