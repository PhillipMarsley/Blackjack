#ifndef CARDDECK_H_
#define CARDDECK_H_

#include <string>
#include <vector>

//---------- card addition ----------//
	void addString();

//---------- card editing ----------//
	void editDots(int, int);

	void editStrings(int, int);

//---------- card printing ----------//
	void printString();

//---------- card totals ----------//
	int cardTotal(std::vector<int>);

//---------- card string swaping ----------//
	void playerSwapFromMain();

	void playerSwapBackToMain();	

	void opponentSwapFromMain();

	void opponentSwapBackToMain();	

//---------- opponent card hiding ----------//
	void opponentCardOneHide(int);

	void opponentCardOneShow();

//---------- resets ----------//
	void resetString();

#endif
