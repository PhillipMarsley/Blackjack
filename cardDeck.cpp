#include <iostream>
#include <string>
#include <vector>

#include "cardDeck.hpp"

//---------- card base ----------//
std::string row0 = ""; 
std::string row1 = ""; 
std::string row2 = ""; 
std::string row3 = ""; 
std::string row4 = ""; 
std::string row5 = ""; 
std::string row6 = ""; 
std::string row7 = ""; 
std::string row8 = ""; 
std::string row9 = ""; 
std::string row10 = ""; 

//---------- card additions ----------//
void addString()
{
	row0.append(" ------------- \t");
	row1.append("|             |\t");
	row2.append("|             |\t");
	row3.append("|             |\t");
	row4.append("|             |\t");
	row5.append("|             |\t");
	row6.append("|             |\t");
	row7.append("|             |\t");
	row8.append("|             |\t");
	row9.append("|             |\t");
	row10.append(" ------------- \t");
}

//---------- card editing ----------//

//startIndex is the starting index of each card in the string (0, 16, 32, etc..)
//suitIndex is the starting index of each card in the string for the card's suit (startIndex + 2) (0, 18, 36, etc..)
void editDots(int card, int i)
{	
	int startIndex = i * 16;
	int suitIndex = i * 18;
	switch(card % 13)
	{
		case 0: //Ace
		{
			row5.replace(7 + startIndex, 1, "O");
			break;
		}
		case 1:	//Two
		{
			row3.replace(7 + startIndex, 1, "O");
			row7.replace(7 + startIndex, 1, "O");
			break;
		}
		case 2: //Three
		{
			row3.replace(7 + startIndex, 1, "O");
			row5.replace(7 + startIndex, 1, "O");
			row7.replace(7 + startIndex, 1, "O");
			break;
		}
		case 3: //Four
		{
			row3.replace(4 + startIndex, 1, "O");
			row3.replace(10 + startIndex, 1, "O");
			row7.replace(4 + startIndex, 1, "O");
			row7.replace(10 + startIndex, 1, "O");	
			break;
		} 
		case 4: //Five
		{
			row3.replace(4 + startIndex, 1, "O");
			row3.replace(10 + startIndex, 1, "O");
			row5.replace(7 + startIndex, 1, "O");
			row7.replace(4 + startIndex, 1, "O");
			row7.replace(10 + startIndex, 1, "O");
			break;
		} 
		case 5: //Six
		{
			row3.replace(4 + startIndex, 1, "O");
			row3.replace(10 + startIndex, 1, "O");
			row5.replace(4 + startIndex, 1, "O");
			row5.replace(10 + startIndex, 1, "O");
			row7.replace(4 + startIndex, 1, "O");
			row7.replace(10 + startIndex, 1, "O");	
			break;
		}
		case 6: //Seven
		{
			row3.replace(4 + startIndex, 1, "O");
			row3.replace(10 + startIndex, 1, "O");
			row4.replace(7 + startIndex, 1, "O");
			row5.replace(4 + startIndex, 1, "O");
			row5.replace(10 + startIndex, 1, "O");
			row7.replace(4 + startIndex, 1, "O");
			row7.replace(10 + startIndex, 1, "O");
			break;
		}
		case 7: //Eight
		{
			row3.replace(4 + startIndex, 1, "O");
			row3.replace(10 + startIndex, 1, "O");
			row4.replace(7 + startIndex, 1, "O");
			row5.replace(4 + startIndex, 1, "O");
			row5.replace(10 + startIndex, 1, "O");
			row6.replace(7 + startIndex, 1, "O");
			row7.replace(4 + startIndex, 1, "O");
			row7.replace(10 + startIndex, 1, "O");	
			break;
		}
		case 8: //Nine
		{
			row2.replace(4 + suitIndex, 1, "O");
			row2.replace(10 + suitIndex, 1, "O");

			row4.replace(4 + startIndex, 1, "O");
			row4.replace(10 + startIndex, 1, "O");
			row5.replace(7 + startIndex, 1, "O");
			row6.replace(4 + startIndex, 1, "O");
			row6.replace(10 + startIndex, 1, "O");

			row8.replace(4 + suitIndex, 1, "O");
			row8.replace(10 + suitIndex, 1, "O");
			break;
		}
		case 9: //Ten
		{
			row2.replace(4 + suitIndex, 1, "O");
			row2.replace(10 + suitIndex, 1, "O");

			row3.replace(7 + startIndex, 1, "O");
			row4.replace(4 + startIndex, 1, "O");
			row4.replace(10 + startIndex, 1, "O");
			row6.replace(4 + startIndex, 1, "O");
			row6.replace(10 + startIndex, 1, "O");
			row7.replace(7 + startIndex, 1, "O");

			row8.replace(4 + suitIndex, 1, "O");
			row8.replace(10 + suitIndex, 1, "O");
			break;
		}
		case 10: //Jack
		{
		}
		case 11: //Queen
		{
		}
		case 12: //King
		{ 
			row2.replace(4 + suitIndex, 1, "-");
			row2.replace(5 + suitIndex, 1, "-");
			row2.replace(6 + suitIndex, 1, "-");
			row2.replace(7 + suitIndex, 1, "-");
			row2.replace(8 + suitIndex, 1, "-");
			row2.replace(9 + suitIndex, 1, "-");
			row2.replace(10 + suitIndex, 1, "-");

			row3.replace(3 + startIndex, 1, "|");
			row3.replace(11 + startIndex, 1, "|");
			row4.replace(3 + startIndex, 1, "|");
			row4.replace(11 + startIndex, 1, "|");
			row5.replace(3 + startIndex, 1, "|");
			row5.replace(11 + startIndex, 1, "|");
			row6.replace(3 + startIndex, 1, "|");
			row6.replace(11 + startIndex, 1, "|");
			row7.replace(3 + startIndex, 1, "|");
			row7.replace(11 + startIndex, 1, "|");

			row8.replace(4 + suitIndex, 1, "-");
			row8.replace(5 + suitIndex, 1, "-");
			row8.replace(6 + suitIndex, 1, "-");
			row8.replace(7 + suitIndex, 1, "-");
			row8.replace(8 + suitIndex, 1, "-");
			row8.replace(9 + suitIndex, 1, "-");
			row8.replace(10 + suitIndex, 1, "-");
			break;
		}
	}
}


void editStrings(int card, int i)
{
	int startIndex = i * 16;
	int suitIndex = i * 18;

	std::string rank = "";
	switch(card % 13)
	{
		case 0: rank = "A"; break;
		case 1: rank = "2"; break;
		case 2: rank = "3"; break;	
		case 3: rank = "4"; break;
		case 4: rank = "5"; break;	
		case 5: rank = "6"; break;	
		case 6: rank = "7"; break;	
		case 7: rank = "8"; break;	
		case 8: rank = "9"; break;	
		case 9: rank = "1"; break;	
		case 10: rank = "J"; break;	
		case 11: rank = "Q"; break;	
		case 12: rank = "K"; break;	
	}

	// "A", "2", "3", "4", "5", "6", "7", "8", "9", "1", J", "Q", "k"
		row1.replace(startIndex + 2, 1, rank);
		row9.replace(startIndex + 12, 1, rank);

	// "0"
	if (card % 13 == 9)
	{
		row1.replace(startIndex + 3, 1, "0");
		row9.replace(startIndex + 13, 1, "0");
	}

	// J", "Q", "k"
	if(card % 13 > 9)
	{
		row5.replace(startIndex + 7, 1, rank);
	}
	
	editDots(card, i);

/*
	//This does not work in the console. UTF-8
	//Characters have odd spacing to them

	//"♠", "♥", "♣", "♦"
	std::string suit = "";
	if (card >= 0 && card <= 12)
		suit = "♠";
	else if (card >= 13 && card <= 25)
		suit = "♥";
	else if (card >= 26 && card <= 38)
		suit = "♣";
	else if (card >= 39 && card <= 51)
		suit = "♦";
	row2.replace(suitIndex + 2, 1, suit);
	row8.replace(suitIndex + 11, 1, suit);
	*/
}


//---------- card printing ----------//
void printString()
{
	std::cout << row0 << std::endl;
	std::cout << row1 << std::endl;
	std::cout << row2 << std::endl;
	std::cout << row3 << std::endl;
	std::cout << row4 << std::endl;
	std::cout << row5 << std::endl;	
	std::cout << row6 << std::endl;
	std::cout << row7 << std::endl;
	std::cout << row8 << std::endl;
	std::cout << row9 << std::endl;
	std::cout << row10 << std::endl;
}


//---------- card totals ----------//
int cardTotal(std::vector<int> hand)
{
	int total = 0;
	for (unsigned i = 0; i < hand.size(); i++)
	{
		switch (hand[i] % 13)
		{
			case 0: break;
			case 1: total += 2; break;
			case 2: total += 3; break;
			case 3: total += 4; break;
			case 4: total += 5; break;
			case 5: total += 6; break;
			case 6: total += 7; break;
			case 7: total += 8; break;
			case 8: total += 9; break;
			case 9: total += 10; break;
			case 10: total += 10; break;
			case 11: total += 10; break;
			case 12: total += 10; break;
			default: break;
			}
	}

	for (unsigned i = 0; i < hand.size(); i++)
	{
		if (hand[i] % 13 == 0)
		{
			if (total <= 10)
			{
				total += 11;
			}
			else if (total >= 11)
			{
				total += 1;
			}
		}
	}
	return total;
}

//---------- card string swaping ----------//
std::string playerRow0 = ""; 
std::string playerRow1 = ""; 
std::string playerRow2 = ""; 
std::string playerRow3 = ""; 
std::string playerRow4 = ""; 
std::string playerRow5 = ""; 
std::string playerRow6 = ""; 
std::string playerRow7 = ""; 
std::string playerRow8 = ""; 
std::string playerRow9 = ""; 
std::string playerRow10 = ""; 

std::string opponentRow0 = ""; 
std::string opponentRow1 = ""; 
std::string opponentRow2 = ""; 
std::string opponentRow3 = ""; 
std::string opponentRow4 = ""; 
std::string opponentRow5 = ""; 
std::string opponentRow6 = ""; 
std::string opponentRow7 = ""; 
std::string opponentRow8 = ""; 
std::string opponentRow9 = ""; 
std::string opponentRow10 = ""; 

void playerSwapFromMain()
{
	playerRow0.swap (row0);
	playerRow1.swap (row1);
	playerRow2.swap (row2);
	playerRow3.swap (row3);
	playerRow4.swap (row4);
	playerRow5.swap (row5);
	playerRow6.swap (row6);
	playerRow7.swap (row7);
	playerRow8.swap (row8);
	playerRow9.swap (row9);
	playerRow10.swap (row10);
}

void playerSwapBackToMain()
{
	row0.swap (playerRow0);
	row1.swap (playerRow1);
	row2.swap (playerRow2);
	row3.swap (playerRow3);
	row4.swap (playerRow4);
	row5.swap (playerRow5);
	row6.swap (playerRow6);
	row7.swap (playerRow7);
	row8.swap (playerRow8);
	row9.swap (playerRow9);
	row10.swap (playerRow10);
}		

void opponentSwapFromMain()
{
	opponentRow0.swap (row0);
	opponentRow1.swap (row1);
	opponentRow2.swap (row2);
	opponentRow3.swap (row3);
	opponentRow4.swap (row4);
	opponentRow5.swap (row5);
	opponentRow6.swap (row6);
	opponentRow7.swap (row7);
	opponentRow8.swap (row8);
	opponentRow9.swap (row9);
	opponentRow10.swap (row10);
}

void opponentSwapBackToMain()
{
	row0.swap (opponentRow0);
	row1.swap (opponentRow1);
	row2.swap (opponentRow2);
	row3.swap (opponentRow3);
	row4.swap (opponentRow4);
	row5.swap (opponentRow5);
	row6.swap (opponentRow6);
	row7.swap (opponentRow7);
	row8.swap (opponentRow8);
	row9.swap (opponentRow9);
	row10.swap (opponentRow10);
}		


char heldRow0[16];
char heldRow1[16];
char heldRow2[16];
char heldRow3[16];
char heldRow4[16];
char heldRow5[16];
char heldRow6[16];
char heldRow7[16];
char heldRow8[16];
char heldRow9[16];
char heldRow10[16];

void opponentCardOneHide(int card)
{
	std::size_t length0 = row0.copy(heldRow0, 15, 0);
	heldRow0[length0] = '\0';
	std::size_t length1 = row1.copy(heldRow1, 15, 0);
	heldRow1[length1] = '\0';
	std::size_t length2 = row2.copy(heldRow2, 15, 0);
	heldRow2[length2] = '\0';
	std::size_t length3 = row3.copy(heldRow3, 15, 0);
	heldRow3[length3] = '\0';
	std::size_t length4 = row4.copy(heldRow4, 15, 0);
	heldRow4[length4] = '\0';
	std::size_t length5 = row5.copy(heldRow5, 15, 0);
	heldRow5[length5] = '\0';
	std::size_t length6 = row6.copy(heldRow6, 15, 0);
	heldRow6[length6] = '\0';
	std::size_t length7 = row7.copy(heldRow7, 15, 0);
	heldRow7[length7] = '\0';
	std::size_t length8 = row8.copy(heldRow8, 15, 0);
	heldRow8[length8] = '\0';
	std::size_t length9 = row9.copy(heldRow9, 15, 0);
	heldRow9[length9] = '\0';
	std::size_t length10 = row10.copy(heldRow10, 15, 0);
	heldRow10[length10] = '\0';

	if(card >= 0 && card <= 12)
	{
		row0.replace(0, 15, " ------------- ");
		row1.replace(0, 15, "|:::::: ::::::|");
		row2.replace(0, 17, "|:::::   :::::|");
		row3.replace(0, 15, "|::::     ::::|");
		row4.replace(0, 15, "|::         ::|");
		row5.replace(0, 15, "|:           :|");
		row6.replace(0, 15, "|:           :|");
		row7.replace(0, 15, "|::  :   :  ::|");
		row8.replace(0, 17, "|:::::: ::::::|");
		row9.replace(0, 15, "|:::::   :::::|");
		row10.replace(0, 15, " ------------- ");
	}

	if(card >= 13 && card <= 25)
	{
		row0.replace(0, 15, " ------------- ");
		row1.replace(0, 15, "|:::::::::::::|");
		row2.replace(0, 17, "|:::::   :::::|");
		row3.replace(0, 15, "|::::     ::::|");
		row4.replace(0, 15, "|:::::   :::::|");
		row5.replace(0, 15, "|:   :::::   :|");
		row6.replace(0, 15, "|     :::     |");
		row7.replace(0, 15, "|:   :: ::   :|");
		row8.replace(0, 17, "|:::::: ::::::|");
		row9.replace(0, 15, "|:::::   :::::|");
		row10.replace(0, 15, " ------------- ");
	}

	if(card >= 26 && card <= 38)
	{
		row0.replace(0, 15, " ------------- ");
		row1.replace(0, 15, "|:::::::::::::|");
		row2.replace(0, 17, "|:::  :::  :::|");
		row3.replace(0, 15, "|:     :     :|");
		row4.replace(0, 15, "|             |");
		row5.replace(0, 15, "|:           :|");
		row6.replace(0, 15, "|::         ::|");
		row7.replace(0, 15, "|::::     ::::|");
		row8.replace(0, 17, "|:::::: ::::::|");
		row9.replace(0, 15, "|:::::::::::::|");
		row10.replace(0, 15, " ------------- ");
	}

	if (card >= 39 && card <= 51)
	{
		row0.replace(0, 15, " ------------- ");
		row1.replace(0, 15, "|:::::: ::::::|");
		row2.replace(0, 17, "|:::::   :::::|");
		row3.replace(0, 15, "|::::     ::::|");
		row4.replace(0, 15, "|:::       :::|");
		row5.replace(0, 15, "|::         ::|");
		row6.replace(0, 15, "|:::       :::|");
		row7.replace(0, 15, "|::::     ::::|");
		row8.replace(0, 17, "|:::::   :::::|");
		row9.replace(0, 15, "|:::::: ::::::|");
		row10.replace(0, 15, " ------------- ");
	}
}

void opponentCardOneShow()
{
	row0.replace(0, 15, heldRow0);
	row1.replace(0, 15, heldRow1);
	row2.replace(0, 15, heldRow2);
	row3.replace(0, 15, heldRow3);
	row4.replace(0, 15, heldRow4);
	row5.replace(0, 15, heldRow5);
	row6.replace(0, 15, heldRow6);
	row7.replace(0, 15, heldRow7);
	row8.replace(0, 15, heldRow8);
	row9.replace(0, 15, heldRow9);
	row10.replace(0, 15, heldRow10);
}

//---------- card reset ----------//
void resetString()
{
	row0.erase (row0.begin(), row0.end());
	row1.erase (row1.begin(), row1.end());
	row2.erase (row2.begin(), row2.end());
	row3.erase (row3.begin(), row3.end());
	row4.erase (row4.begin(), row4.end());
	row5.erase (row5.begin(), row5.end());
	row6.erase (row6.begin(), row6.end());
	row7.erase (row7.begin(), row7.end());
	row8.erase (row8.begin(), row8.end());
	row9.erase (row9.begin(), row9.end());
	row10.erase (row10.begin(), row10.end());
}
