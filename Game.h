/*------------------------------------------------------------------------------------------------------------------------------------------
The class Game represents a card game with rounds and score
The game is: compare two cards from a deck, the player with the highest card wins the round. 
The game compares rounds with the "best-out-of-three"-principle to determine winner of game. 
The game can be played till there is no more cards to deal from the deck.
Scores are keepen tracks on to determine the total winner when the game stops
Game.h


Written for summer course in c++ 
2014 Anna Dunblad
------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef GAME_H
#define GAME_H

#include "Deck.h" 
#include <iostream>  //input/output

class Game{


	

	public:
		Game(Deck* _deck); //creates a game with pointer to new pristine deck
		void printWinner(); //prints total score for each player (used when ending game)
		void printPosition(); //prints total score for each player (used when playing game)
		int play(); //the game itself 
		void resetGame(); //sets score to zero
		
	private:
		Deck* deck;  //to be assigned to Deck pointer in Game constructor
		int totalPlayerScore; //stores total score of player
		int totalComputerScore; //stores total score of computer
		bool isAllSame(int a, int b, int c); //returns true if all integers has the same value
		bool isAllDifferent(int a, int b, int c); //returns true if all integers has different values
		bool hasTwoZeros(int a, int b, int c); //returns true if at least two out of three integers has the value zero
		int max(int a, int b); //returns the biggest of two integers






};

#endif