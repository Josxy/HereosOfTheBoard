/* Nazli Deniz Erdem - 2526317
I read and accept the submission rules and the important section
specified in assignment file. This is my own work that is done by myself
and my team-mate only */
#include <iostream>
#include "Board.h"

using namespace std;

//The default constructor for the Board class
Board::Board()
{
	row = 0;
	column = 0;
	health = 100;
	usageE = 0;
	usageM = 0;
	usageR = 0;
	usageK = 0;
	kill = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			pieces[i][j] = nullptr;
		}
	}
}

//The constructor to initialize the variables with given inputs
Board::Board(int r, int c, int h, int e, int m, int ra, int k, int kl)
{
	row = r;
	column = c;
	health = h;
	usageE = e;
	usageM = m;
	usageR = ra;
	usageK = k;
	kill = kl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			pieces[i][j] = nullptr;
		}
	}
}

//Getter and setter functions
int Board::rowGetter()
{
	return row;
}

void Board::rowSetter(int r)
{
	row = r;
}

int Board::columnGetter()
{
	return column;
}

void Board::columnSetter(int c)
{
	column = c;
}

int Board::healthGetter()
{
	return health;
}

void Board::healthSetter(int hp)
{
	health = hp;
}

int Board::usageEGetter()
{
	return usageE;
}

void Board::usageESetter(int e)
{
	usageE = e;
}

int Board::usageMGetter()
{
	return usageM;
}

void Board::usageMSetter(int m)
{
	usageM = m;
}

int Board::usageRGetter()
{
	return usageR;
}

void Board::usageRSetter(int r)
{
	usageR = r;
}

int Board::usageKGetter()
{
	return usageK;
}

void Board::usageKSetter(int k)
{
	usageK = k;
}

int Board::killGetter()
{
	return kill;
}

void Board::killSetter(int k)
{
	kill = k;
}

//This function returns a spesific piece by using the given row and column
Pieces* Board::pieceGetter(int r, int c)
{
	return pieces[r - 1][c - 1];
}

//This function is used to fill the pieces array
void Board::piecesAdder(Pieces& p)
{
	pieces[row][column] = &p;

	if (column == 2)
	{
		row++;
		column = 0;
	}
	else
	{
		column++;
	}
}

//This function changes the piece on the given row and column with another piece
void Board::pieceChanger(Pieces& p, int r, int c)
{
	pieces[r - 1][c - 1] = &p;
}

//This function prints the board by using the Board object which contains both of the players' board items
void Board::boardPrinter(Board* b, string player1, string player2)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == 1)//This condition is to print the user names and their health points on the each side of the boards
		{
			cout << "                ----------------------------         ----------------------------" << endl;
			cout << "                |        |        |        |         |        |        |        |" << endl;
			cout << " " << player1; cout << "     |";
			b[0].pieces[i][0]->print();
			cout << "|";
			b[0].pieces[i][1]->print();
			cout << "|";
			b[0].pieces[i][2]->print();
			cout << "|" << Board::numToLetter(i);
			cout << "       " << Board::numToLetter(i) << "|";
			b[1].pieces[i][2]->print();
			cout << "|";
			b[1].pieces[i][1]->print();
			cout << "|";
			b[1].pieces[i][0]->print();
			cout << "|"; cout << "          " << player2;
			cout << endl;

			//The conditions below are implemented so that the boards can have the same shape every time health points change
			if (b[0].health == 100 || b[0].health <= -10)
				cout << " (" << b[0].health << ")" << "          |        |        |        |         |        |        |        |          " << "(" << b[1].health << ")" << endl;
			else if (b[0].health > 9 || b[0].health < 0)
				cout << " (" << b[0].health << ")" << "           |        |        |        |         |        |        |        |          " << "(" << b[1].health << ")" << endl;
			else
				cout << " (" << b[0].health << ")" << "            |        |        |        |         |        |        |        |          " << "(" << b[1].health << ")" << endl;
		}
		else
		{
			cout << "                ----------------------------         ----------------------------" << endl;
			cout << "                |        |        |        |         |        |        |        |" << endl;
			cout << "                |";
			b[0].pieces[i][0]->print();
			cout << "|";
			b[0].pieces[i][1]->print();
			cout << "|";
			b[0].pieces[i][2]->print();
			cout << "|" << Board::numToLetter(i);
			cout << "       " << Board::numToLetter(i) << "|";
			b[1].pieces[i][2]->print();
			cout << "|";
			b[1].pieces[i][1]->print();
			cout << "|";
			b[1].pieces[i][0]->print();
			cout << "|";
			cout << endl;

			cout << "                |        |        |        |         |        |        |        |" << endl;
		}
	}

	cout << "                ----------------------------         ----------------------------" << endl;

}

//This function is a helper function for boardPrinter. It helps with printing the letters of the board
char Board::numToLetter(int i)
{
	switch (i)
	{
	case 0:
		return 'A';
	case 1:
		return 'B';
	case 2:
		return 'C';
	case 3:
		return 'D';
	default:
		return 'X';
	}
}

//This function is used when the user is asked for the row. It converts the letter entered by the user to integer.
int Board::letterConverter(char letter)
{
	switch (letter)
	{
	case 'A':
		return 1;
	case 'a':
		return 1;
	case 'B':
		return 2;
	case 'b':
		return 2;
	case 'C':
		return 3;
	case 'c':
		return 3;
	case 'D':
		return 4;
	case 'd':
		return 4;
	default:
		return 10;
	}
}

//This function checks if the row and column entered by the user already has a character on the board or not
int Board::isEmpty(int r, int c)
{
	if (pieces[r - 1][c - 1]->isItPiece())
		return 0;
	else
		return 1;
}

//This function gives a bonus life point to all the players on the board when Mage is used.
void Board::lifeBonus()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (pieces[i][j]->isItPiece() && !(pieces[i][j]->getRep() == 'M'))
			{
				pieces[i][j]->setLife(pieces[i][j]->getLife() + 1);
			}
		}
	}

}

//This function gives a bonus attack point to all the players on the board when Knight is used.
void Board::attackBonus()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (pieces[i][j]->isItPiece() && !(pieces[i][j]->getRep() == 'K'))
			{
				pieces[i][j]->setLife(pieces[i][j]->getDamage() + 1);
			}
		}
	}
}

//This function keeps the track of the usage of Elf
int Board::Eusage(int u)
{
	if (usageE == u)
	{
		return 0;
	}
	else
	{
		usageE++;
		return 1;
	}
}

//This function keeps the track of the usage of Mage
int Board::Musage(int u)
{
	if (usageM == u)
	{
		return 0;
	}
	else
	{
		usageM++;
		return 1;
	}
}

//This function keeps the track of the usage of Ranger
int Board::Rusage(int u)
{
	if (usageR == u)
	{
		return 0;
	}
	else
	{
		usageR++;
		return 1;
	}
}

//This function keeps the track of the usage of Knight
int Board::Kusage(int u)
{
	if (usageK == u)
	{
		return 0;
	}
	else
	{
		usageK++;
		return 1;
	}
}

//This function checks if the given row has any enemies or not
int Board::enemyChecker(int r)
{
	for (int i = 0; i < 3; i++)
	{
		if (pieces[r - 1][i]->isItPiece())
		{
			return 1;
		}
	}
	return 0;
}

//This function is used during attack to change the health points of characters on the board and also the user
void Board::roundAttack(Board* b)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (pieces[i][j]->isItPiece())
			{
				if (b->enemyChecker(i + 1))
				{
					if (b->pieces[i][2]->isItPiece())//Characters attack to only the first column that has an enemy
					{
						b->pieces[i][2]->decreaseHealth(pieces[i][j]->getDamage());
					}
					else if (b->pieces[i][1]->isItPiece())
					{
						b->pieces[i][1]->decreaseHealth(pieces[i][j]->getDamage());
					}
					else if (b->pieces[i][0]->isItPiece())
					{
						b->pieces[i][0]->decreaseHealth(pieces[i][j]->getDamage());
					}
				}
				else
				{
					b->healthSetter(b->healthGetter() - pieces[i][j]->getDamage());
				}
			}
		}
	}
}

//This function removes the characters that has 0 or less health point
void Board::removeDead(Pieces& p)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (pieces[i][j]->isItPiece())
			{
				if (!pieces[i][j]->isDied())
				{
					//Destructor is called for the dead character
					pieces[i][j]->~Pieces();
					pieces[i][j] = &p;
					kill++;
				}
			}
		}
	}
}

//This function takes the character, row and the column from the user and places the characters
//Also returns 1 if the character is placed successfully otherwise returns 0
int Board::piecePlacer(char character)
{
	char letter;
	int number;

	cout << "\nWhere do you want to place your hero?" << endl;
	cout << "Enter a letter: "; cin >> letter;
	cout << "Enter a number: "; cin >> number; cout << endl;

	if (character == 'B' || character == 'b')
	{
		Bowman* b = new Bowman();
		if (b->isPlacable(number) && this->isEmpty(this->letterConverter(letter), number))
		{
			this->pieceChanger(*b, this->letterConverter(letter), number);
			return 1;
		}
		else
		{
			cout << "You cannot place into this position" << endl;
			return 0;
		}
	}
	else if (character == 'E' || character == 'e')
	{
		Elf* e = new Elf();
		if (this->Eusage(e->getUsage()))
		{
			if (e->isPlacable(number) && this->isEmpty(this->letterConverter(letter), number))
			{
				this->pieceChanger(*e, this->letterConverter(letter), number);
				return 1;
			}
			else
			{
				cout << "You cannot place into this position" << endl;
				return 0;
			}
		}
		else
		{
			cout << "Sorry, you can't add an Elf anymore" << endl;
			return 0;
		}
	}
	else if (character == 'M' || character == 'm')
	{
		Mage* m = new Mage();
		if (this->Musage(m->getUsage()))
		{
			if (m->isPlacable(number) && this->isEmpty(this->letterConverter(letter), number))
			{
				this->pieceChanger(*m, this->letterConverter(letter), number);
				lifeBonus();
				return 1;
			}
			else
			{
				cout << "You cannot place into this position" << endl;
				return 0;
			}
		}
		else
		{
			cout << "Sorry, you can't add a Mage anymore" << endl;
			return 0;
		}
	}
	else if (character == 'S' || character == 's')
	{
		Spearman* s = new Spearman();
		if (s->isPlacable(number) && this->isEmpty(this->letterConverter(letter), number))
		{
			this->pieceChanger(*s, this->letterConverter(letter), number);
			return 1;
		}
		else
		{
			cout << "You cannot place into this position" << endl;
			return 0;
		}
	}
	else if (character == 'R' || character == 'r')
	{
		Ranger* r = new Ranger();
		if (this->Rusage(r->getUsage()))
		{
			if (r->isPlacable(number) && this->isEmpty(this->letterConverter(letter), number))
			{
				this->pieceChanger(*r, this->letterConverter(letter), number);
				return 1;
			}
			else
			{
				cout << "You cannot place into this position" << endl;
				return 0;
			}
		}
		else
		{
			cout << "Sorry, you can't add a Ranger anymore" << endl;
			return 0;
		}
	}
	else if (character == 'W' || character == 'w')
	{
		Swordsman* w = new Swordsman();
		if (w->isPlacable(number) && this->isEmpty(this->letterConverter(letter), number))
		{
			this->pieceChanger(*w, this->letterConverter(letter), number);
			return 1;
		}
		else
		{
			cout << "You cannot place into this position" << endl;
			return 0;
		}
	}
	else if (character == 'K' || character == 'k')
	{
		Knight* k = new Knight();
		if (this->Kusage(k->getUsage()))
		{
			if (k->isPlacable(number) && this->isEmpty(this->letterConverter(letter), number))
			{
				this->pieceChanger(*k, this->letterConverter(letter), number);
				attackBonus();
				return 1;
			}
			else
			{
				cout << "You cannot place into this position" << endl;
				return 0;
			}
		}
		else
		{
			cout << "Sorry, you can't add a Knight anymore" << endl;
			return 0;
		}
	}
}