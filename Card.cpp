/*------------------------------------------------------------------------------------------------------------------------------------------
Simple Card game Class Card
Card.cpp


Written for summer course in c++ 
2014 Anna Dunblad
------------------------------------------------------------------------------------------------------------------------------------------*/
#include "Card.h"
#include <iostream>  //input/output

 
 /**----------------------------------------------------------
			Constructor to create and initialize empty card
----------------------------------------------------------------**/ 
 Card::Card(){ 
	 suit=0;
	 rank=0;
 
 }
 
 
 /**----------------------------------------------------------
			set rank and suit of card 
----------------------------------------------------------------**/
  void Card::setData(int _suit, int _rank){
 
  rank=_rank;
  suit=_suit;
  
 }

 /**----------------------------------------------------------
			return rank of card  
----------------------------------------------------------------**/
 int Card::getRank(){
 
 return rank;
 }

 
 /**----------------------------------------------------------
					print a card   
----------------------------------------------------------------**/
 void Card::printCard(int printMethod){
 	
	const char* suitForPrint;
	rank=this->rank;
	
	switch(this->suit)
		{
		case 1:
			suitForPrint =  "\x06";  //♠
			break;
		case 2:
			suitForPrint = "\x03";  //♥
			break;
		case 3:
			suitForPrint = "\x04"; //♦
			break;
		 case 4:
			suitForPrint = "\x05";  //♣
			break;
		default:
		    suitForPrint = " ";  
			break;
		}
		 
	if(printMethod==1){
 

				std::cout<<"----------------------"<<std::endl;
				std::cout<<"|"<<rank<<"                   |"<<std::endl;
				std::cout<<"|"<<*suitForPrint<<"                   |"<<std::endl;
				std::cout<<"|                    |"<<std::endl;
				std::cout<<"|                    |"<<std::endl;
				std::cout<<"|         "<<*suitForPrint<<"          |"<<std::endl;
				std::cout<<"|                    |"<<std::endl;
				std::cout<<"|                    |"<<std::endl;
				std::cout<<"|                    |"<<std::endl;
				std::cout<<"|                   "<<rank<<"|"<<std::endl;
				std::cout<<"|                   "<<*suitForPrint<<"|"<<std::endl;
				std::cout<<"----------------------"<<std::endl;
				
	}
	else{
		
		switch(this->rank){
			case 1:
				std::cout<<"Ace of "<<*suitForPrint<<std::endl;
				break;
		   case 11:
				std::cout<<"Jack of "<<*suitForPrint<<std::endl;
				break;
			case 12:
				std::cout<<"Queen of "<<*suitForPrint<<std::endl;
				break;
			case 13:
				std::cout<<"King of "<<*suitForPrint<<std::endl;
				break;
			default:
				std::cout<<rank<<" of "<<*suitForPrint<<std::endl;		
		}
	}
 
}