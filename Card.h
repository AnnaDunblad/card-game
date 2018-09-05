/*------------------------------------------------------------------------------------------------------------------------------------------
The class Card represents a playing card with a rank and suit, e.g "Queen of diamonds"
Card.h

Suits: 1 for spades, 2 for hearts, 3 for diamonds, 4 for clubs
Ranks: 1 for ace, 11 for jack, 12 for queen, 13 for king



Written for summer course in c++ 
2014 Anna Dunblad
------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef CARD_H
#define CARD_H
#include <iostream>  //input/output


class Card{

	public:
		void setData(int _suit, int _rank); //set rank and suit of card 
		int getRank(); //return rank of card  
		void printCard(int printMethod); //print a card 
		Card(); //card with rank 0 and suit 0, aka "empty" card
		
	private:
		int rank;
		int suit;

};
#endif