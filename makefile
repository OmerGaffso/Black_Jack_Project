PROGRAM := prog
OBJS := main.o 			\
		lists.o 		 \
		data.o   	  	  \
		betPhase.o	   	   \
		drawPhase.o 		\

prog:	main.o	lists.o	data.o	betPhase.o drawPhase.o *.h
	gcc -g -Wall -pedantic -o prog main.o lists.o data.o betPhase.o drawPhase.o

main.o:	main.c	lists.o	data.o	drawPhase.o	*.h
	gcc -c -g -Wall -pedantic -o main.o main.c 

lists.o:	lists.c	data.o	*.h
	gcc -c -g -Wall -pedantic -o lists.o lists.c 

data.o:	data.c	*.h
	gcc -c -g -Wall -pedantic -o data.o data.c

betPhase.o:	betPhase.c	*.h
	gcc -c -g -Wall -pedantic -o betPhase.o betPhase.c

drawPhase.o:	drawPhase.c	lists.o data.o *.h
	gcc -c -g -Wall -pedantic -o drawPhase.o drawPhase.c

clean:
	rm -rf $(OBJS) $(PROGRAM)
