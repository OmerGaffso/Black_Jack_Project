PROGRAM := prog
OBJS := main.o 			\
		lists.o 		 \
		data.o   	  	  \
		betPhase.o	   	   \
		drawPhase.o 		\
		playersPhase.o		 \
		gameHandle.o		  \

FLAGS := 	-g				\
		 	-Wall			 \
			-pedantic		  \
			-o				   \

prog:	main.o	lists.o	data.o	betPhase.o drawPhase.o playersPhase.o gameHandle.o	*.h
	gcc ${FLAGS} prog ${OBJS}

main.o:	main.c	lists.o	data.o	betPhase.o drawPhase.o playersPhase.o gameHandle.o	*.h
	gcc -c ${FLAGS} main.o main.c 

lists.o:	lists.c	data.o	*.h
	gcc -c ${FLAGS} lists.o lists.c 

data.o:	data.c	*.h
	gcc -c ${FLAGS} data.o data.c

betPhase.o:	betPhase.c	data.o	*.h
	gcc -c ${FLAGS} betPhase.o betPhase.c

drawPhase.o:	drawPhase.c	lists.o data.o *.h
	gcc -c ${FLAGS} drawPhase.o drawPhase.c

playersPhase.o:	playersPhase.c	data.o lists.o drawPhase.o	*.h
	gcc -c ${FLAGS} playersPhase.o playersPhase.c

gameHandle.o:	gameHandle.c	data.o	*.h
	gcc -c ${FLAGS} gameHandle.o gameHandle.c

clean:
	rm -rf $(OBJS) $(PROGRAM)
