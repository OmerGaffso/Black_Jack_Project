PROGRAM := prog
OBJS := main.o \
		lists.o \


prog:	main.o	lists.o *.h
	gcc -g -Wall -pedantic -o prog main.o lists.o 

main.o:	main.c	lists.o	*.h
	gcc -c -g -Wall -pedantic -o main.o main.c 

lists.o:	lists.c		*.h
	gcc -c -g -Wall -pedantic -o lists.o lists.c



clean:
	rm -rf $(OBJS) $(PROGRAM)
