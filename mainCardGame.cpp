/*------------------------------------------------------------------------------------------------------------------------------------------
Simple Card game S


Written for summer course in c++ 
2014 Anna Dunblad
------------------------------------------------------------------------------------------------------------------------------------------*/

#include <iostream>  //input/output
#include <ctime> //for time() used for initializing rand
#include <cstdlib>  //for srand
#include "Card.h"
#include "Deck.h"
#include "Game.h"

int main(){


	srand (time(0));  //initialize psuedo-random number generator with time of program starting
	std::cout<< "Welcome to the card game! \nGame is starting...\nCreating deck of cards..."<<std::endl;
	int choice; 
	
	Deck deck;
	Game game(&deck);

	while(1)
	{
		std::cout << "-------------------------------------"<<std::endl;
		std::cout<<"Please choose between: "<<std::endl;
		std::cout<<"1. New game \n2. Play (no shuffeling) \n3. See game score \n4. See used cards \n5. Print deck \n6. End game"<<std::endl;
		std::cout << "-------------------------------------"<<std::endl;

		std::cin>>choice;
		
		
		
		switch(choice)
		{
			case 1:
			
			std::cout<<"Shuffeling deck..."<<std::endl;
			deck.currentCard=0;
			game.resetGame();
			deck.shuffleDeck();
			game.play();

				
				
				break;
			case 2:
				
				game.play();
				
				break;
			case 3: 	
					game.printPosition();
					break;
				
			case 4:
				deck.printDeckofDrawnCards();
				break;	
			case 5:
				deck.printDeck();
				break;
				
			case 6:
				game.printWinner();
				std::cout<<"Ending game"; 
				return 0;
			default:
				std::cout<<"Not a valid input number"<<std::endl;
				break;
		}
		
	}





return 0;
}