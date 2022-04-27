PROGRAM := prog
OBJS := main.o 			\
		lists.o 		 \
		data.o   	  	  \
		betPhase.o	   	   \
		drawPhase.o 		\
		playerDecision.o	 \
		dealerPhase.o		  \
		gameHandle.o		   \

prog:	main.o	lists.o	data.o	betPhase.o drawPhase.o playerDecision.o dealerPhase.o gameHandle.o	*.h
	gcc -g -Wall -pedantic -o prog ${OBJS}

main.o:	main.c	lists.o	data.o	betPhase.o drawPhase.o playerDecision.o dealerPhase.o gameHandle.o	*.h
	gcc -c -g -Wall -pedantic -o main.o main.c 

lists.o:	lists.c	data.o	*.h
	gcc -c -g -Wall -pedantic -o lists.o lists.c 

data.o:	data.c	*.h
	gcc -c -g -Wall -pedantic -o data.o data.c

betPhase.o:	betPhase.c	data.o	*.h
	gcc -c -g -Wall -pedantic -o betPhase.o betPhase.c

drawPhase.o:	drawPhase.c	lists.o data.o *.h
	gcc -c -g -Wall -pedantic -o drawPhase.o drawPhase.c

playerDecision.o:	playerDecision.c	data.o lists.o drawPhase.o	*.h
	gcc -c -g -Wall -pedantic -o playerDecision.o playerDecision.c

dealerPhase.o:	dealerPhase.c	data.o lists.o	*.h
	gcc -c -g -Wall -pedantic -o dealerPhase.o dealerPhase.c

gameHandle.o:	gameHandle.c	data.o	*.h
	gcc -c -g -Wall -pedantic -o gameHandle.o gameHandle.c

clean:
	rm -rf $(OBJS) $(PROGRAM)
