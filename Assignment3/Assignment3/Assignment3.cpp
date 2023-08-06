/* Nazli Deniz Erdem - 2526317
I read and accept the submission rules and the important section
specified in assignment file. This is my own work that is done by myself
and my team-mate only */
#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

int main()
{

	cout << "\n                                     \\\\                     //" << endl;
	cout << "                                      \\\\    ___________    //" << endl;
	cout << "                                       \\\\  /           \\  //" << endl;
	cout << "                             (          \\\\/             \\//          )" << endl;
	cout << "                             /\\          |               |          /\\" << endl;
	cout << "                            /  )         |   WELCOME TO  |         (  \\" << endl;
	cout << "                    ###------------->    |     HEROES    |    <-------------###" << endl;
	cout << "                            \\  )         |       OF      |         (  /" << endl;
	cout << "                             \\/          |   THE BOARD   |          \\/" << endl;
	cout << "                             (            \\             /            )" << endl;
	cout << "                                           \\           /" << endl;
	cout << "                                            - .     . -" << endl;
	cout << "                                             //`:::`\\\\" << endl;
	cout << "                                            //   '   \\\\" << endl;
	cout << "                                           //         \\\\" << endl;

	srand((unsigned)time(NULL));
	int random = 1 + (rand() % 2);

	Pieces* p = new Melee();

	//The pieces array of both of the players is filled with Ranged objects
	Board b[2];
	//For player1
	b[0] = Board();
	b[0].piecesAdder(*p);
	b[0].piecesAdder(*p);
	b[0].piecesAdder(*p);
	b[0].piecesAdder(*p);
	b[0].piecesAdder(*p);
	b[0].piecesAdder(*p);
	b[0].piecesAdder(*p);
	b[0].piecesAdder(*p);
	b[0].piecesAdder(*p);
	b[0].piecesAdder(*p);
	b[0].piecesAdder(*p);
	b[0].piecesAdder(*p);
	//For player2
	b[1] = Board();
	b[1].piecesAdder(*p);
	b[1].piecesAdder(*p);
	b[1].piecesAdder(*p);
	b[1].piecesAdder(*p);
	b[1].piecesAdder(*p);
	b[1].piecesAdder(*p);
	b[1].piecesAdder(*p);
	b[1].piecesAdder(*p);
	b[1].piecesAdder(*p);
	b[1].piecesAdder(*p);
	b[1].piecesAdder(*p);
	b[1].piecesAdder(*p);


	string xplayer1;
	string xplayer2;
	string player1;
	string player2;

	cout << "\n                             Please enter the name of the first player: " << endl;
	cout << "                                              "; getline(cin, xplayer1);
	std::cin.clear();
	cout << "\n                             Please enter the name of the second player: " << endl;
	cout << "                                              "; getline(cin, xplayer2);

	player1 = xplayer1;
	player2 = xplayer2;

	//Both of the names are resized to 10 characters so that the boards can have the same shape with every name entered
	xplayer1.resize(10, ' ');
	xplayer2.resize(10, ' ');

	cout << "\n                             The boards are ready. Let's get started!" << endl << endl;

	int i = 1;
	int turnStarter = 1 + (rand() % 2);
	do
	{
		cout << "\n                                  ---------- Round " << i << " ----------" << endl << endl;

		cout << "                    1         2         3                3         2         1" << endl;

		Board::boardPrinter(b, xplayer1, xplayer2);

		if (turnStarter == 1)
		{
			char piece;
			cout << "\nIt is " << player1 << "'s turn" << endl << endl;
			do
			{
				cout << "Ranged Pieces(Column 1 and 2):" << endl;
				cout << "(B)OWMAN -> health: 12, damage: 3" << endl;
				cout << "(E)LF -> health: 8, damage: 6, " << 3 - b[0].usageEGetter() << " lives left" << endl;
				cout << "(M)AGE -> health: 4, damage: 8, " << 2 - b[0].usageMGetter() << " lives left" << endl << endl;
				cout << "Melee Pieces(Column 2 and 3):" << endl;
				cout << "(S)PEARMAN -> health: 6, damage: 3" << endl;
				cout << "(R)ANGER -> health: 8 points, damage: 6, " << 2 - b[0].usageRGetter() << " lives left" << endl;
				cout << "S(W)ORDSMAN -> health: 6, damage: 4" << endl;
				cout << "(K)NIGHT -> health: 10 points, damage: 10, " << 1 - b[0].usageKGetter() << " lives left" << endl << endl;
				cout << "Please choose your hero " << player1 << ": "; cin >> piece;;

			} while (!b[0].piecePlacer(piece));
			//The dead characters are removed after the attack
			b[0].roundAttack(&b[1]);
			b[1].removeDead(*p);
			b[0].removeDead(*p);

			cout << "                   1         2         3                3         2         1" << endl;
			Board::boardPrinter(b, xplayer1, xplayer2);

			//This condition is to stop the loop after one of the players reach 0 health point
			if (b[0].healthGetter() <= 0 || b[1].healthGetter() <= 0)
				break;

			cout << "\nIt is " << player2 << "'s turn" << endl << endl;
			do
			{
				cout << "Ranged Pieces(Column 1 and 2):" << endl;
				cout << "(B)OWMAN -> health: 12, damage: 3" << endl;
				cout << "(E)LF -> health: 8, damage: 6, " << 3 - b[1].usageEGetter() << " lives left" << endl;
				cout << "(M)AGE -> health: 4, damage: 8, " << 2 - b[1].usageMGetter() << " lives left" << endl << endl;
				cout << "Melee Pieces(Column 2 and 3):" << endl;
				cout << "(S)PEARMAN -> health: 6, damage: 3" << endl;
				cout << "(R)ANGER -> health: 8 points, damage: 6, " << 2 - b[1].usageRGetter() << " lives left" << endl;
				cout << "S(W)ORDSMAN -> health: 6, damage: 4" << endl;
				cout << "(K)NIGHT -> health: 10 points, damage: 10, " << 1 - b[1].usageKGetter() << " lives left" << endl << endl;
				cout << "Please choose your hero " << player2 << ": "; cin >> piece;
			} while (!b[1].piecePlacer(piece));
			b[1].roundAttack(&b[0]);

		}
		else
		{
			char piece;
			cout << "\nIt is " << player2 << "'s turn" << endl << endl;
			do
			{
				cout << "Ranged Pieces(Column 1 and 2):" << endl;
				cout << "(B)OWMAN -> health: 12, damage: 3" << endl;
				cout << "(E)LF -> health: 8, damage: 6, " << 3 - b[1].usageEGetter() << " lives left" << endl;
				cout << "(M)AGE -> health: 4, damage: 8, " << 2 - b[1].usageMGetter() << " lives left" << endl << endl;
				cout << "Melee Pieces(Column 2 and 3):" << endl;
				cout << "(S)PEARMAN -> health: 6, damage: 3" << endl;
				cout << "(R)ANGER -> health: 8 points, damage: 6, " << 2 - b[1].usageRGetter() << " lives left" << endl;
				cout << "S(W)ORDSMAN -> health: 6, damage: 4" << endl;
				cout << "(K)NIGHT -> health: 10 points, damage: 10, " << 1 - b[1].usageKGetter() << " lives left" << endl << endl;
				cout << "Please choose your hero " << player2 << ": "; cin >> piece;
			} while (!b[1].piecePlacer(piece));
			//The dead characters are removed after the attack
			b[1].roundAttack(&b[0]);
			b[1].removeDead(*p);
			b[0].removeDead(*p);

			cout << "                   1         2         3                3         2         1" << endl;
			Board::boardPrinter(b, xplayer1, xplayer2);

			//This condition is to stop the loop after one of the players reach 0 health point
			if (b[0].healthGetter() <= 0 || b[1].healthGetter() <= 0)
				break;

			cout << "\nIt is " << player1 << "'s turn" << endl << endl;
			do
			{
				cout << "Ranged Pieces(Column 1 and 2):" << endl;
				cout << "(B)OWMAN -> Health: 12, Damage: 3" << endl;
				cout << "(E)LF -> Health: 8, Damage: 6, " << 3 - b[0].usageEGetter() << " lives left" << endl;
				cout << "(M)AGE -> Health: 4, Damage: 8, " << 2 - b[0].usageMGetter() << " lives left" << endl << endl;
				cout << "Melee Pieces(Column 2 and 3):" << endl;
				cout << "(S)PEARMAN -> Health: 6, Damage: 3" << endl;
				cout << "(R)ANGER -> Health: 8 points, Damage: 6, " << 2 - b[0].usageRGetter() << " lives left" << endl;
				cout << "S(W)ORDSMAN -> Health: 6, Damage: 4" << endl;
				cout << "(K)NIGHT -> Health: 10 points, Damage: 10, " << 1 - b[0].usageKGetter() << " lives left" << endl << endl;
				cout << "Please choose your hero " << player1 << ": "; cin >> piece;
			} while (!b[0].piecePlacer(piece));
			b[0].roundAttack(&b[1]);
		}
		//The dead characters are removed after the attack
		b[1].removeDead(*p);
		b[0].removeDead(*p);

		i++;

	} while (b[0].healthGetter() > 0 && b[1].healthGetter() > 0);

	//The kill details
	if (b[0].healthGetter() <= 0)
	{
		cout << endl;
		cout << player2 << " is the winner with " << b[1].killGetter() << " kills!!" << endl;
		cout << player1 << " takes the second place with " << b[0].killGetter() << " kills. Better luck next time!" << endl;
	}
	else
	{
		cout << endl;
		cout << player1 << " is the winner with " << b[0].killGetter() << " kills!!" << endl;
		cout << player2 << " takes the second place with " << b[1].killGetter() << " kills. Better luck next time!" << endl;;
	}

	//Destructor is called for the pieces left on the board
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (b[0].pieceGetter(i, j)->isItPiece())
			{
				b[0].pieceGetter(i, j)->~Pieces();
			}
			if (b[1].pieceGetter(i, j)->isItPiece())
			{
				b[1].pieceGetter(i, j)->~Pieces();
			}
		}
	}
	delete p;
	return 0;
}