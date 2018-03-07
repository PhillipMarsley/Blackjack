#include <iostream>		//std::cout & std::cin
#include <string>		//std::string
#include <vector>		//std::vector
#include <random>		//std::random
#include <algorithm>    //std::sort

#include <time.h>		//timer functions

#include "cardDeck.hpp"

#include <limits> //std::cin.ignore()

//========================================================================================

//Returns random values uniformly distributed in the range [a, b]
int random(int a, int b)
{
  thread_local std::mt19937 eng{std::random_device{}()};
  std::uniform_int_distribution<int> dist(a, b);
  return dist(eng);
}

//Checks the player imput
std::string d = "";
void check(std::string a, std::string b, std::string c)
{
	do
	{
		std::cout << a << std::endl;
		std::cout << "Enter \"Hit\" or \"Stand\" as shown." << std::endl;
		std::cin >> d;
	}
	while(b != d && c != d);
}

//delays the output of the program for 1 seconds
void delayOutput(int delay)
{
	time_t timer;

	unsigned long tenSeconds = 0;
	tenSeconds = time(&timer) + delay;

	unsigned long currentTime = 0;
	while (true)
	{
		currentTime = time(&timer);	//gets current time; same as: timer = time(NULL)
									//number of seconds since 00:00 hours, Jan 1, 1970 UTC
		if (currentTime == tenSeconds)
		{
			break;
		}
	}
}

void pressEnterToContinue()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
	std::cout << "Press the ENTER key to Continue." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
	std::cout << "Next pround processing. . ." << std::endl;
}

//========================================================================================

int main()
{
	std::vector<int> cardDeck;
	for (int i = 0; i < 52; i++)
	{
		cardDeck.push_back(i);
	}

	std::vector<int> cardDeck2;
	std::vector<int> playerHand;
	std::vector<int> opponentHand;

	int deckSize = 51;
	int rounds = 1;
	int totalWinsPlayer = 0;
	int totalWinsOpponent = 0;

	bool breakLoop = false;

	while (deckSize > 8)
	{
		//clears the console screen
		std::cout << std::string(50, '\n');

		std::cout << " ------------------------- " << std::endl;
		std::cout << "|  Welcome to Blackjack!  |" << std::endl;
		std::cout << " ------------------------- " << std::endl;
		std::cout << "       | Round " << rounds << " |"  << std::endl;
		std::cout << "        --------- " << std::endl;
		std::cout << std::string(20, '\n');

		//delays the output
		delayOutput(2);	

//========================================================================================
		//draw 2 cards (player)
		for (int i = 0; i < 2; i++)
		{			
			int cardNum = random(0, deckSize);
			playerHand.push_back (cardDeck.at(cardNum)); //adds the element chosen from cardDeck to playerHand
			cardDeck2.push_back (cardDeck.at(cardNum)); //holds the to-be erased element from cardDeck
			cardDeck.erase (cardDeck.begin() + cardNum); //erases chosen element from cardDeck
			deckSize--;

			addString();
			editStrings(playerHand[i], i);
		}
		//clears the console screen
		std::cout << std::string(50, '\n');

		//std::cout << "Your card total is " << cardTotal(playerHand) << '.' << std::endl;
		printString();

		//string swapping
		playerSwapFromMain();

//========================================================================================
		//draw 2 cards (opponent)
		for (int i = 0; i < 2; i++)
		{			
			int cardNum = random(0, deckSize);
			opponentHand.push_back (cardDeck.at(cardNum));
			cardDeck2.push_back (cardDeck.at(cardNum));
			cardDeck.erase (cardDeck.begin() + cardNum);
			deckSize--;

			addString();
			editStrings(opponentHand[i], i);
		}
		//std::cout << "Opponent card total is " << cardTotal(opponentHand) << '.' << std::endl;

		//hide opponent card
		opponentCardOneHide(opponentHand[0]);

		printString();

		//String swapping
		opponentSwapFromMain();
		playerSwapBackToMain();

		std::cout << std::endl;
		std::cout << std::endl;
//========================================================================================
		//player hit/stand
		unsigned i = 2;
		while(true)
		{
			int playerTotal = cardTotal(playerHand);
		
			if (playerTotal <= 21)
			{
				std::cout << "Your card total is " << playerTotal << '.' << std::endl;
				check("Will you \"Hit\" or \"Stand\"?", "Hit", "Stand");

				if (d == "Hit")
				{
					std::cout << "You have chosen to Hit" << std::endl;

					int cardNum = random(0, deckSize);
					playerHand.push_back (cardDeck.at(cardNum));
					cardDeck2.push_back (cardDeck.at(cardNum));
					cardDeck.erase (cardDeck.begin() + cardNum);
					deckSize--;

					addString();
					editStrings(playerHand[i], i);

					//std::cout << "Your card total is now " << cardTotal(playerHand) << '.' << std::endl;
					//std::cout << "Opponent card total is " << cardTotal(opponentHand) << '.' << std::endl;

					//clears the console screen
					std::cout << std::string(50, '\n');

					printString();

					//String swapping
					playerSwapFromMain();
					opponentSwapBackToMain();

					printString();

					//string swapping
					opponentSwapFromMain();
					playerSwapBackToMain();
				}
				else if (d == "Stand")
				{
					std::cout << "You have chosen to Stand at " << cardTotal(playerHand) << '.' << std::endl;
					//std::cout << "Opponent card total is " << cardTotal(opponentHand) << '.' << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
					break;
				}
			}
			else if (playerTotal >= 22)
			{
				totalWinsOpponent++;
				std::cout << "You have Busted at " << cardTotal(playerHand) << '.' << std::endl;
				std::cout << " - - - - - - - - - " << std::endl;
				std::cout << "|                 |" << std::endl;
				std::cout << "|  Opponent Wins  |" << std::endl;
				std::cout << "|                 |" << std::endl;
				std::cout << " - - - - - - - - - " << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;

				//delays the output
				delayOutput(1);	

				pressEnterToContinue();

				breakLoop = true; //BREAKS OUT OF THE REST OF THE CODE
				break;
			}
			std::cout << std::endl;
			std::cout << std::endl;
			i++;
		}

		if (breakLoop == false) //ALLOWS THE REST OF THE CODE TO CONTINUE OF THE PLAYER DID NOT BUST
		{
			//string swapping
			playerSwapFromMain();
			opponentSwapBackToMain();

			//show opponent card
			opponentCardOneShow();

			//delays the output
			delayOutput(1);	

			std::cout << "Opponent flips their card." << std::endl;

			//delays the output
			delayOutput(1);	

			//clears the console screen
			std::cout << std::string(50, '\n');

			//string swapping
			opponentSwapFromMain();
			playerSwapBackToMain();

			printString();

			//string swapping
			playerSwapFromMain();
			opponentSwapBackToMain();

			printString();

//========================================================================================
			//opponent hit/stand
			unsigned j = 2;
			int l = 0;
			while (true)
			{
				int opponentTotal = cardTotal(opponentHand);

				//delays the output
				delayOutput(1);		

				if (opponentTotal <= 17)
				{
					int cardNum = random(0, deckSize);
					opponentHand.push_back (cardDeck.at(cardNum));
					cardDeck2.push_back (cardDeck.at(cardNum));
					cardDeck.erase (cardDeck.begin() + cardNum);
					deckSize--;

					addString();
					editStrings(opponentHand[j], j);	

					//std::cout << "Your card total is " << cardTotal(playerHand) << '.' << std::endl;
					//std::cout << "Opponent card total is now " << cardTotal(opponentHand) << '.' << std::endl;

					//string swapping
					opponentSwapFromMain();
					playerSwapBackToMain();

					for (l = l; l < 1; l++)
					{
						std::cout << "Opponent has chosen Hit!" << std::endl;
						//delays the output
						delayOutput(1);	
					}
					//clears the console screen
					std::cout << std::string(50, '\n');

					printString();

					//string swapping
					playerSwapFromMain();
					opponentSwapBackToMain();

					printString();

					std::cout << "Opponent has chosen Hit!" << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;

					j++;
				}
				else if (opponentTotal >= 18 && opponentTotal <= 21)
				{
					//std::cout << "Your card total is " << cardTotal(playerHand) << '.' << std::endl;
					std::cout << "Opponent has chosen to Stand at " << cardTotal(opponentHand) << '.' << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
					break;
				}
				else if (opponentTotal >= 22)
				{
					totalWinsPlayer++;
					std::cout << "Opponent has Busted at " << cardTotal(opponentHand) << '.' << std::endl;
					std::cout << " - - - -- - - - " << std::endl;
					std::cout << "|              |" << std::endl;
					std::cout << "|   You Win!   |" << std::endl;
					std::cout << "|              |" << std::endl;
					std::cout << " - - - -- - - - " << std::endl;
					std::cout << "Card total: " << cardTotal(playerHand) << '!' << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;

					//delays the output
					delayOutput(1);	

					pressEnterToContinue();

					breakLoop = true; //BREAKS OUT OF THE REST OF THE CODE
					break;
				}
			}

//========================================================================================

			if (breakLoop == false)//ALLOWS THE REST OF THE CODE TO CONTINUE OF THE OPPONENT DID NOT BUST
			{
				//delays the output
				delayOutput(2);	

				int playerFinialTotal = cardTotal(playerHand);
				int opponentFinialTotal = cardTotal(opponentHand);

				if (opponentFinialTotal > playerFinialTotal)
				{
					totalWinsOpponent++;
					std::cout << " - - - - - - - - - " << std::endl;
					std::cout << "|                 |" << std::endl;
					std::cout << "|  Opponent Wins  |" << std::endl;
					std::cout << "|                 |" << std::endl;
					std::cout << " - - - - - - - - - " << std::endl;
					std::cout << "Card total: " << opponentFinialTotal << '.' << std::endl;
				}
				else if (playerFinialTotal > opponentFinialTotal)
				{
					totalWinsPlayer++;
					std::cout << " - - - -- - - - " << std::endl;
					std::cout << "|              |" << std::endl;
					std::cout << "|   You Win!   |" << std::endl;
					std::cout << "|              |" << std::endl;
					std::cout << " - - - -- - - - " << std::endl;
					std::cout << "Card total: " << playerFinialTotal << '!' << std::endl;
				}
				else if (playerFinialTotal == opponentFinialTotal)
				{
					std::cout << " - - - -  - - - - " << std::endl;
					std::cout << "|                |" << std::endl;
					std::cout << "| [" << playerFinialTotal << "] Draw [" << opponentFinialTotal << "] |" << std::endl;
					std::cout << "|                |" << std::endl;
					std::cout << " - - - -  - - - -" << std::endl;
				}

				//delays the output
				delayOutput(1);	

				std::cout << std::endl;
				pressEnterToContinue();
			}//ALLOWS THE REST OF THE CODE TO CONTINUE OF THE OPPONENT DID NOT BUST
		}//ALLOWS THE REST OF THE CODE TO CONTINUE OF THE PLAYER DID NOT BUST

		//delays the output
		delayOutput(2);	

		//opponentString is within main
		//reset opponent string
		resetString();

		//reset main string
		opponentSwapFromMain();
		resetString();

		//reset player string
		playerSwapBackToMain();
		resetString();

		//reset main string
		playerSwapFromMain();
		resetString();

		//reset player vector
		playerHand.clear();

		//reset opponent vector
		opponentHand.clear();

		rounds++;
		breakLoop = false;
	}

	//delays the output
	delayOutput(2);	

	//clears the console screen
	std::cout << std::string(50, '\n');
	std::cout << " - - - -- - - - " << std::endl;
	std::cout << "|              |" << std::endl;
	std::cout << "|   Game End   |" << std::endl;
	std::cout << "|              |" << std::endl;
	std::cout << " - - - -- - - - " << std::endl;
	std::cout << "Rounds = " << rounds - 1 << std::endl;
	std::cout << "Total wins by you = " << totalWinsPlayer << std::endl;
	std::cout << "Total wins the opponent = " << totalWinsOpponent << std::endl;
	std::cout << std::string(20, '\n');

	return 0;
}
