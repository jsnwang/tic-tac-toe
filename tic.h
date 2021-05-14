#pragma once

#include <vector>
#include <iostream>
#include <string>
#include "symbol.h"

using namespace std;

class tBoard
{
	private:
		//array that holds the symbols for the spaces
		symbol spaces_[9];
	public:
		//Default Constructor
		//Makes a board with all blank spaces
		tBoard();
		
		//Makes a move on the board
		//X is the row and y is the column
		//m is the symbol to place (either X or O)
		//It returns true if the move was made
		//If the move is illegal, return false and do not change the table
		bool move(symbol m, int x, int y);
		//Returns true if the game is over
		//This could be because of a winner or because of a tie
		bool game_over();
		//Returns who won X or O.
		//If the game was a tie, return  BLANK
		symbol winner();
		//puts the tictactoe board in a string
		string toString() const;
		//helps << operator
		void insert(ostream & out) const;
};
//Overload the output operator
ostream & operator<<(ostream& os, const tBoard& myTable);

