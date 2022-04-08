PROGRAM := prog
OBJS := main.o \
		lists.o \
		data.o   \
		betPhase.o\

prog:	main.o	lists.o	data.o	betPhase.o *.h
	gcc -g -Wall -pedantic -o prog main.o lists.o data.o betPhase.o 

main.o:	main.c	lists.o	data.o	*.h
	gcc -c -g -Wall -pedantic -o main.o main.c 

lists.o:	lists.c	data.o	*.h
	gcc -c -g -Wall -pedantic -o lists.o lists.c 

data.o:	data.c	*.h
	gcc -c -g -Wall -pedantic -o data.o data.c

betPhase.o:	betPhase.c	*.h
	gcc -c -g -Wall -pedantic -o betPhase.o betPhase.c

clean:
	rm -rf $(OBJS) $(PROGRAM)
