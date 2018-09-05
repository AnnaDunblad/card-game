/*------------------------------------------------------------------------------------------------------------------------------------------
Simple Card game Class Card
Game.cpp


Written for summer course in c++ 
2014 Anna Dunblad
------------------------------------------------------------------------------------------------------------------------------------------*/
#include "Game.h"
#include <iostream>  //input/output

 /**----------------------------------------------------------
	Constructor to create and initialize empty game
----------------------------------------------------------------**/
Game::Game(Deck* _deck){

	
		totalPlayerScore = 0;
		totalComputerScore = 0;
		deck = _deck ;
		



}

 /**----------------------------------------------------------
	Resets score to 0 
----------------------------------------------------------------**/

void Game::resetGame(){

		totalPlayerScore = 0;
		totalComputerScore = 0;
}


 /**----------------------------------------------------------
Play game by comparing cards and rounds by the "best-out-of-three" principle
----------------------------------------------------------------**/
int Game::play(){

	int rank1, rank2;
	int result [3] = {0, 0, 0}; //array used to store results from the three rounds

	for(int i=0; i<3 ; i++){ //three rounds
	
		std::cout << "-------------------------------------"<<std::endl;
		std::cout<<"You drew:"<<std::endl;
		rank1=deck->drawCard();
		if(rank1==-1) { // if all cards have been drawn, print winner and then return to main menu
			printWinner();
			return 0; 
			}
		std::cout<<"The computer drew:"<<std::endl;
		rank2=deck->drawCard();
			if(rank2==-1) { // if all cards have been drawn, print winner and then return to main menu
			printWinner();
			return 0; 
			}
		std::cout << "-------------------------------------"<<std::endl;
		

		switch(deck->compareCards(rank1,rank2)) //compare cards in each round
			{
			case 1:
				result[i]=1; //player wins round 
				std::cout<<"You card has the higher rank!"<<std::endl;
				break;
			case 2:
				result[i]=2; //computer wins round
				std::cout<<"The computers card has the higher rank!"<<std::endl;
				break;
			default:
				result[i]=0; //noone wins round
				std::cout<<"It's a draw!"<<std::endl;
				break;
			}

		if(i==1) //if someone won the first two rounds, skip the last round and declare winner
		{

			if((result[0]==1) && (result[1]==1)){
			std::cout << "-------------------------------------"<<std::endl;
			std::cout<<"You won the first two rounds,\nno need playing in the last.\n You won!"<<std::endl;
			totalPlayerScore++;
			i=3;
			}

			if((result[0]==2) && (result[1]==2)){
			std::cout << "-------------------------------------"<<std::endl;
			std::cout<<"The computer won the first two rounds,\nno need playing in the last.\nBetter luck next time! \n"<<std::endl;
			totalComputerScore++;
			i=3;
			}
		}
	}
	//Analyze result from the three rounds
	
	//check if the player won the first and last round or the second and last round
	if((result[1]==1 && result[2]==1) || (result[0]==1 && result[2]==1)){
	std::cout<<"You won!"<<std::endl;
	totalPlayerScore++;
	}

	//check if the computer won the first and last round or the second and last round
	if((result[1]==2 && result[2]==2) || (result[0]==2 && result[2]==2)){
	std::cout<<"The computer won. Better luck next time! \n"<<std::endl;
	totalComputerScore++;
	}

	// Checks if the 3 results are all similar (indicating 3 ties) or all different (indicating 1 tie, one computer victory and one player victory)
	if(isAllDifferent(result[0],result[1],result[2]) || isAllSame(result[0],result[1],result[2])){
		std::cout<<"Noone won!"<<std::endl;

	}
	//checking for two ties and one player wictory
	if(hasTwoZeros(result[0],result[1],result[2]) && (max(max(result[0],result[1]),max(result[0],result[2]))==1))
	{
		std::cout<<"You won!"<<std::endl;
		totalPlayerScore++;
	}

	//checking for two ties and one computer wictory
	if(hasTwoZeros(result[0],result[1],result[2]) && (max(max(result[0],result[1]),max(result[0],result[2]))==2))
	{
		std::cout<<"The computer won. Better luck next time! \n"<<std::endl;
		totalComputerScore++;
	}


	return 0;
}		

 /**----------------------------------------------------------
Comparing method. Returns the biggest of two values
----------------------------------------------------------------**/
int Game::max(int a, int b){
	 return a>b ? a : b;  //returns a if a>b, else b
}


 /**----------------------------------------------------------
Comparing method. Returns true if all three integers
have the same value
----------------------------------------------------------------**/

bool Game::isAllSame(int a, int b, int c){
 
	 if((a==b) && (c==a))
		return true;
	else 
		return false;

}


 /**----------------------------------------------------------
Comparing method. Returns true if all three integers have
  different values
----------------------------------------------------------------**/
bool Game::isAllDifferent(int a, int b, int c){

	if(a!=b && a!=c && b!=c)
		return true;
	else
		return false;
}

 /**----------------------------------------------------------
Comparing method. Returns true if at least two out of three
 integers have the value zero
----------------------------------------------------------------**/
bool Game::hasTwoZeros(int a, int b, int c){
	
	if((a==0 && b==0) || (b==0 && c==0) || (a==0 && c==0))
		return true;
	else
		return false;
}

 /**----------------------------------------------------------
	Print actual position with regards to scores
----------------------------------------------------------------**/
void Game::printPosition(){
	
	if(totalPlayerScore>totalComputerScore)
		std::cout<<"You are in the lead with score "<<totalPlayerScore<<"\nthe computer have score "<<totalComputerScore<<std::endl;
	if(totalPlayerScore<totalComputerScore)
		std::cout<<"The computer is in the lead with score "<<totalComputerScore<<"\nyou have score "<<totalPlayerScore<<std::endl;
	if(totalPlayerScore==totalComputerScore)
		std::cout<<"It's a tie. Anyone can win! Both have scored "<<totalPlayerScore<<"points"<<std::endl;
}


 /**--------------------------------------------------------------
 prints actual position with regards to score with message about 
 victory or loss, used in end of game
------------------------------------------------------------------**/

void Game::printWinner(){
	
	if(totalPlayerScore>totalComputerScore)
		std::cout<<"You won with score "<<totalPlayerScore<<"\nthe computer got score "<<totalComputerScore<<std::endl;
	if(totalPlayerScore<totalComputerScore)
		std::cout<<"The computer won with score "<<totalComputerScore<<"\nyou got score "<<totalPlayerScore<<std::endl;
	if(totalPlayerScore==totalComputerScore)
		std::cout<<"It's a tie. Nooone won. Score is "<<totalPlayerScore<<std::endl;
}


		