/*------------------------------------------------------------------------------------------------------------------------------------------
Simple Card game Class Deck
Deck.cpp


Written for summer course in c++ 
2014 Anna Dunblad
------------------------------------------------------------------------------------------------------------------------------------------*/

#include "Deck.h"
#include "Card.h"
#include <ctime> //for time() 
#include <cstdlib> //for rand()
#include <iostream>  //input/output
#define NCARDS 52
#define NSUITS 4
#define NSUITCARDS 13


/**----------------------------------------------------------
			create Deck of 52 Card objects   
----------------------------------------------------------------**/

Deck::Deck(){


	int i = 0;

	for ( int suit = 1; suit <= NSUITS; suit++ ){ //suits
		for ( int rank = 1; rank <= NSUITCARDS; rank++ ){ //rank of ace to king in every suit
			deckOfCards[i].setData(suit,rank); 
			i++; //13 * 4 = 52 iterations
		}
	}

	currentCard = 0;  //starting at card 0    

}


/**----------------------------------------------------------
shuffleDeck, psuedo-randomly shuffle deck with Fisher-Yates algoritm:	   
----------------------------------------------------------------**/
void Deck::shuffleDeck(){

	
	for(int i = NCARDS-1; i >= 0; i--)
		{	
			int j= rand()%(i +1); //random numbers between 0 and i 
			
			Card tempHolder = deckOfCards[i];
			deckOfCards[i]=deckOfCards[j];
			deckOfCards[j]=tempHolder;
		}
			
}

/**-------------------------------------------------------------------------------------
draw a card from the deck. Returns rank of the card or -1 if no card is left to draw   
-----------------------------------------------------------------------------------------**/

int Deck::drawCard(){

	if(currentCard<NCARDS-1){ 
		 
		deckOfCards[currentCard].printCard(1);		 
		currentCard++;
		
		return deckOfCards[currentCard-1].getRank();; 
	
	
	}else{
		std::cout<<"You have played all cards!"<<std::endl;
		return -1; //to use in Game to exit game
	}
}

/**-------------------------------------------------------------------------------------------------
Compare the ranks of two cards. Returns 1 if rank1>rank2, 2 if rank1<rank2, and 0 if rank1==rank2   
-----------------------------------------------------------------------------------------------------**/

int Deck::compareCards(int rank1, int rank2){

	if(rank1>rank2)
		return 1;
	if(rank1<rank2)
		return 2;
	if(rank1==rank2)
		return 0;
	
	return -1; 
}

/**----------------------------------------------------------
print an whole deck by calling printCard() on every card	   
----------------------------------------------------------------**/	
void Deck::printDeck(){
	int printMethod;
	std::cout<<"How to you want to print the deck?"<<std::endl;
	std::cout<<"1. As real cards \n2. As a list with ranks and suit."<<std::endl;
	std::cin>> printMethod;
	
	if(printMethod == 1){
		for(int i=0; i<NCARDS; i++)
			 deckOfCards[i].printCard(1);
	
	}
	if(printMethod == 2){
		for(int i=0; i<NCARDS; i++)
			deckOfCards[i].printCard(2);
	}
	

	else{
		std::cout<<"Non-valid choice"<<std::endl;
	}
		
	

}

/**----------------------------------------------------------
print a deck with cards that have been drawn   
----------------------------------------------------------------**/	
void Deck::printDeckofDrawnCards(){

		int printMethod;
	std::cout<<"How to you want to print the deck?"<<std::endl;
	std::cout<<"1. As ''real'' cards \n2. As a list with ranks and suit."<<std::endl;
	std::cin>> printMethod;
	
	if(printMethod == 1){
		for(int i=0; i<currentCard; i++)
			 deckOfCards[i].printCard(1);
	
	}
	if(printMethod==2){
		for(int i=0; i<currentCard; i++)
			deckOfCards[i].printCard(2);
	}
	else{
		std::cout<<"Non-valid choice"<<std::endl;
	}
	

}




