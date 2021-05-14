#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "symbol.h"
#include "tic.h"

tBoard::tBoard()
{
	//creates a board with all blank spaces
	for (int i = 0; i < 9; i++)
		spaces_[i] = BLANK;
}
//changes the symbol on the space corresponding to the coordinates
bool tBoard::move(symbol m, int x, int y)
{
	//at row 0, col 0, changes the space located at 0, 0 to the specified symbol and returns true
	//if there is already a symbol there, returns false
	if (x == 0 && y == 0){
		if (spaces_[0] == BLANK){
			spaces_[0] = m;
			return true;
		}
		else
			return false;
	}
	else if (x == 0 && y == 1){
		if (spaces_[1] == BLANK){
			spaces_[1] = m;
			return true;
		}
		else
			return false;
	}
	else if (x == 0 && y == 2){
		if (spaces_[2] == BLANK){
			spaces_[2] = m;
			return true;
		}
		else
			return false;
	}
	else if (x == 1 && y == 0){
		if (spaces_[3] == BLANK){
			spaces_[3] = m;
			return true;
		}
		else
			return false;
	}
	else if (x == 1 && y == 1){
		if (spaces_[4] == BLANK){
			spaces_[4] = m;
			return true;
		}
		else
			return false;
	}
	else if (x == 1 && y == 2){
		if (spaces_[5] == BLANK){
			spaces_[5] = m;
			return true;
		}
		else
			return false;
	}
	else if (x == 2 && y == 0){
		if (spaces_[6] == BLANK){
			spaces_[6] = m;
			return true;
		}
		else
			return false;
	}
	else if (x == 2 && y == 1){
		if (spaces_[7] == BLANK){
			spaces_[7] = m;
			return true;
		}
		else
			return false;
	}
	else if (x == 2 && y == 2){
		if (spaces_[8] == BLANK){
			spaces_[8] = m;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
//checks for one of the 8 winning moves in tic tac toe and returns truw if it finds one
//if no winning moves are found, checks if the board is completely filled or not. returns false if it isn't
bool tBoard::game_over()
{
	bool t;
	
	if (spaces_[0] == spaces_[1] && spaces_[1] == spaces_[2] && spaces_[0] == spaces_[2] && spaces_[0] != BLANK)
		return true;
	else if (spaces_[3] == spaces_[4] && spaces_[4] == spaces_[5] && spaces_[3] == spaces_[5] && spaces_[3] != BLANK)
		return true;
	else if (spaces_[6] == spaces_[7] && spaces_[7] == spaces_[8] && spaces_[6] == spaces_[8] && spaces_[6] != BLANK)
		return true;
	else if (spaces_[0] == spaces_[3] && spaces_[3] == spaces_[6] && spaces_[0] == spaces_[6] && spaces_[0] != BLANK)
		return true;
	else if (spaces_[1] == spaces_[4] && spaces_[4] == spaces_[7] && spaces_[1] == spaces_[7] && spaces_[1] != BLANK)
		return true;
	else if (spaces_[2] == spaces_[5] && spaces_[5] == spaces_[8] && spaces_[2] == spaces_[8] && spaces_[2] != BLANK)
		return true;
	else if (spaces_[0] == spaces_[4] && spaces_[4] == spaces_[8] && spaces_[0] == spaces_[8] && spaces_[0] != BLANK)
		return true;
	else if (spaces_[2] == spaces_[4] && spaces_[4] == spaces_[6] && spaces_[2] == spaces_[6] && spaces_[2] != BLANK)
		return true;
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (!(spaces_[i] == BLANK))
				t = true;
			else
				return false;
		}
		return t;
	}
}
//same as game_over_ but returns the winning symbol
//if no winning symbol, returns BLANK which is a tie
symbol tBoard::winner()
{
	if (spaces_[0] == spaces_[1] && spaces_[1] == spaces_[2] && spaces_[0] == spaces_[2] && spaces_[0] != BLANK)
	{
		if (spaces_[0] == X)
			return X;
		else
			return O;
	}
	else if (spaces_[3] == spaces_[4] && spaces_[4] == spaces_[5] && spaces_[3] == spaces_[5] && spaces_[3] != BLANK)
	{
		if (spaces_[3] == X)
			return X;
		else
			return O;
	}
	else if (spaces_[6] == spaces_[7] && spaces_[7] == spaces_[8] && spaces_[6] == spaces_[8] && spaces_[6] != BLANK)
	{
		if (spaces_[6] == X)
			return X;
		else
			return O;
	}
	else if (spaces_[0] == spaces_[3] && spaces_[3] == spaces_[6] && spaces_[0] == spaces_[6] && spaces_[0] != BLANK)
	{
		if (spaces_[0] == X)
			return X;
		else
			return O;
	}
	else if (spaces_[1] == spaces_[4] && spaces_[4] == spaces_[7] && spaces_[1] == spaces_[7] && spaces_[1] != BLANK)
	{
		if (spaces_[1] == X)
			return X;
		else
			return O;
	}
	else if (spaces_[2] == spaces_[5] && spaces_[5] == spaces_[8] && spaces_[2] == spaces_[8] && spaces_[2] != BLANK)
	{
		if (spaces_[2] == X)
			return X;
		else
			return O;
	}
	else if (spaces_[0] == spaces_[4] && spaces_[4] == spaces_[8] && spaces_[0] == spaces_[8] && spaces_[0] != BLANK)
	{
		if (spaces_[0] == X)
			return X;
		else
			return O;
	}
	else if (spaces_[2] == spaces_[4] && spaces_[4] == spaces_[6] && spaces_[2] == spaces_[6] && spaces_[2] != BLANK)
	{
		if (spaces_[2] == X)
			return X;
		else
			return O;
	}
	else
		return BLANK;
}
//puts the board into a string
string tBoard::toString() const
{
	ostringstream os;
	os << " |  0  |  1  |  2  |" << endl
		<< " +-----------------+" << endl
		<< "0|  " << spaces_[0] << "  |  " << spaces_[1] << "  |  " << spaces_[2] << "  |" << endl
		<< " +-----------------+" << endl
		<< "1|  " << spaces_[3] << "  |  " << spaces_[4] << "  |  " << spaces_[5] << "  |" << endl
		<< " +-----------------+" << endl
		<< "2|  " << spaces_[6] << "  |  " << spaces_[7] << "  |  " << spaces_[8] << "  |" << endl
		<< " +-----------------+" << endl;

	string return_string = os.str();
	return return_string;
}
//facilitates the overloading of << operator
void tBoard::insert(ostream & out) const
{
	out << toString();
}
//outputs the tic tac toe board
ostream & operator<<(ostream& os, const tBoard& myTable)
{
	myTable.insert(os);
	return os;
}