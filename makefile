all: isort txtfind

isort: sort.o mainSort.o
	gcc -g  -Wall -o isort sort.o mainSort.o
txtfind: Str.o mainStr.o
	gcc -g  -Wall -o txtfind Str.o mainStr.o
sort.o: sort.c
	gcc -g  -Wall -c sort.c
Str.o: Str.c
	gcc -g  -Wall -c Str.c
mainSort.o: mainSort.c
	gcc -g  -Wall  -c mainSort.c

mainStr.o: mainStr.c
	gcc -g  -Wall -c mainStr.c



clean:
	rm -f *.o *.a *.so isort txtfind