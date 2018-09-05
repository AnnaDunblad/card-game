/*------------------------------------------------------------------------------------------------------------------------------------------
The class Deck represents a deck of 52 playing cards that can be randomly shuffled, or individually drawn.  
Deck.h


Written for summer course in c++ 
2014 Anna Dunblad
------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef DECK_H
#define DECK_H

#include <iostream>  //input/output
#include "Card.h"
#define NCARDS 52

class Deck{

	
	public:
		Deck();
		void createDeck();  //creates pristine deck of 52 cards, sorted
		void shuffleDeck(); //shuffle deck randomly 
		void printDeck(); //print an whole deck by calling printCard() on every card
		int drawCard(); //draw a card from the deck that has not yet been drawn
		int compareCards(int rank1, int rank2); //returns 1 if rank 1 is greatest, 2 if rank2 is greatest and 0 if they have the same value
		void printDeckofDrawnCards(); //print a deck with cards that have been drawn  
		int currentCard; //card to be drawn

	private:
		Card deckOfCards[NCARDS]; //array of objects - not yet drawn cards





};



#endif
