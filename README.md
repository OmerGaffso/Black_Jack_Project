# Black_Jack_Project
Final Project of C programming course, a part of the Embedded Systems path in RT Group (Israel). 

# Description 
This project is a terminal based game of black jack between a human player and a computer controlled dealer.
The deck and the player hands are implemented via linked list.

The player starts the game with 1000$.

The program follows the basic rules of a black jack game:

    The player bets. In this project bets can be multiples of 10 only.    
    The player and dealer receive 2 cards each. The player hand is printed fully, and the dealer have one card "hidden".
    The player hand value is calculated, and the player can choose if he hit (draw another card) or stand (keep his current hand value).
    Card values:
        Ace - can have value of either 1 or 11
        2-9 - have their face value
        Jack, Queen and King - have value of 10

    If the player gets hand value of 21, he wins the pot multiplied by 2.5.
    If the player hand value is greater than 21 (bust), he loses the bet.

    In case the player chose to stand, the dealer starts playing.

    The dealer follows the following algorithm:
        Calculate the hand value. If greater than player's hand value, player loses.
        Otherwise - the dealer will continue drawing card until one of the following conditions occur:
            * The dealer hand value is greater than the player's.
            * The dealer hand value has reached 17 or more.
            * The dealer hand value is greater than 21 - it's a "dealer bust" and the player wins the pot multiplied by 2.
            * The dealer hand value is greater or equal to 17 and less than 21, and his hand value is equal to the player value. In this case, the pot remains as is (with the player bet) and the game resets (if the player chooses to continue play).
            * The dealer hand value is greater or equal to 17 and less than 21, and his hand value is greater than the player's hand value. The player loses the pot.

    After each round, the player is prompted if he wishes to continue playing, and is expected to answer with yes to continue playing or no to end the game.
    If he wishes to continue, the cards are returned to the deck, and the game starts over from the player betting phase.
    
    If the player cash is less than 10, the game is over because the player cannot bet anymore.
    
# Files/Dirs 
    makefile
    README.md
    
    /.vscode

    main.c
    data.c
    lists.c
    betPhase.c
    drawPhase.c
    playerDecision.c
    dealerPhase.c
    gameHandle.c

    data.h
    lists.h
    betPhase.h
    drawPhase.h
    playerDecision.h
    dealerPhase.h
    gameHandle.h

# How To Compile And Run 

Option 1:
    
   open terminal at the project location and type: 
        
    make

   Note: Uses flags -Wall -pedantic

Option 2:
    
   in the .vscode folder youll find the files launch.json & tasks.json. You can use them to compile and run the project in vscode.

# How To Clean .o Files and prog 

*** only if compiled using makefile (option 1 in comiling) ***

open terminal at the project location and type:
  
  make clean

