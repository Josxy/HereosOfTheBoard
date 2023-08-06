/* Nazli Deniz Erdem - 2526317
I read and accept the submission rules and the important section
specified in assignment file. This is my own work that is done by myself
and my team-mate only */
#pragma once
#include "Pieces.h"

class Board
{
private:
	int row;
	int column;
	Pieces* pieces[4][3];
	int health;
	int usageE;
	int usageM;
	int usageR;
	int usageK;
	int kill;

public:
	Board();
	Board(int, int, int, int, int, int, int, int);
	int rowGetter();
	void rowSetter(int);
	int columnGetter();
	void columnSetter(int);
	int healthGetter();
	void healthSetter(int);
	int usageEGetter();
	void usageESetter(int);
	int usageMGetter();
	void usageMSetter(int);
	int usageRGetter();
	void usageRSetter(int);
	int usageKGetter();
	void usageKSetter(int);
	int killGetter();
	void killSetter(int);
	Pieces* pieceGetter(int, int);
	void piecesAdder(Pieces&);
	void pieceChanger(Pieces&, int, int);
	static void boardPrinter(Board*, string, string);
	static char numToLetter(int);
	int letterConverter(char);
	int isEmpty(int, int);
	void lifeBonus();
	void attackBonus();
	int Eusage(int);
	int Musage(int);
	int Rusage(int);
	int Kusage(int);
	int enemyChecker(int);
	void roundAttack(Board*);
	void removeDead(Pieces&);
	int piecePlacer(char);

};