default: archisogen

archisogen.o: archisogen.c
	gcc -c archisogen.c -o archisogen.o

archisogen: archisogen.o
	gcc archisogen.o -o archisogen

clean:
	-rm -f archisogen.o
	-rm -f archisogen
