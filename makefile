suffix: main.o trie.o suffix.o
	gcc main.o trie.o suffix.o -o suffix
	
main.o: main.c trie.h suffix.h
	gcc -c main.c
	
trie.o: trie.c trie.h
	gcc -c trie.c

suffix.o: suffix.c suffix.h trie.c trie.h
	gcc -c suffix.c

clean:
	rm *.o suffix

txt:
	rm *.txt
