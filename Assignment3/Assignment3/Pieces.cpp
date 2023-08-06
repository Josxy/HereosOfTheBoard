/* Yusuf Said Savaş - 2526655
I read and accept the submission rules and the important section
specified in assignment file. This is my own work that is done by myself
and my team-mate only */
#include "Pieces.h"
//------------------------------------------------------------------------------
//---------------------------------PIECES FUNCTIONS-----------------------------
//------------------------------------------------------------------------------
//Default constructor for pieces
Pieces::Pieces()
{
	this->life = 0;
	this->representation = 'U';
}
//Constructor for pieces with spesific input
Pieces::Pieces(int health, const char symbol)
{
	this->life = health;
	this->representation = symbol;
}
//Destructor for pieces
Pieces::~Pieces()
{
}
//Setter function for life of the piece
void Pieces::setLife(int health)
{
	this->life = health;
}
//Setter function for the representation of piece
void Pieces::setRep(const char symbol)
{
	this->representation = symbol;
}
//Getter function for the life of the piece
int Pieces::getLife()const
{
	return this->life;
}
//Getter function for the representation of piece
char Pieces::getRep()const
{
	return this->representation;
}
//Getter function for the damage. It's a virtual function. It will return the result of the function in the derived class
int Pieces::getDamage()const
{
	return 0;
}
//Getter function for the usage. It's a virtual function. It will return the result of the function in the derived class
int Pieces::getUsage()const
{
	return 0;
}
//Virtual print
void Pieces::print()
{
	cout << "        ";
}
//------------------------------------------------------------------------------
//-------------------------------RANGED FUNCTIONS-------------------------------
//------------------------------------------------------------------------------
//Default constructor for ranged class.
Ranged::Ranged() : Pieces()
{
	this->damage = 0;
	this->usage = 0;
}
//Constructor for the ranged class with the spesific input
Ranged::Ranged(int hit, int use, int health, const char symbol) :Pieces(health, symbol)
{
	this->damage = hit;
	this->usage = use;
}
//Setter function for damage
void Ranged::setDamage(int hit)
{
	this->damage = hit;
}
//Setter function for usage
void Ranged::setUsage(int use)
{
	this->usage = use;
}
//Getter function for damage
int Ranged::getDamage()const
{
	return this->damage;
}
//Getter function for usage
int Ranged::getUsage()const
{
	return this->usage;
}
//Printer for ranged
void Ranged::print()
{
	cout << "        ";
}
//Checks that is it a empty piece or character
int Ranged::isItPiece()
{
	return 0;
}
//This is a virtual function. we will use it in the derived classes.
int Ranged::isPlacable(int column)
{
	return -1;
}
//This is a virtual function. we will use it in the derived classes.
int Ranged::isDied()
{
	return -1;
}
//This is a virtual function. we will use it in the derived classes.
int Ranged::isUsable()
{
	return -1;
}
//This is a virtual function. we will use it in the derived classes.
void Ranged::decreaseHealth(int h)
{
}
//This is a virtual function. we will use it in the derived classes.
int Ranged::isSpecial()
{
	return -1;
}
//------------------------------------------------------------------------------
//--------------------------------BOWMAN FUNCTIONS------------------------------
//------------------------------------------------------------------------------
//Constructor for Bowman. It sends the spesific values specified in the manual.
Bowman::Bowman() :Ranged(3, 100, 12, 'B'), Pieces(12, 'B')
{

}
//It checks if it is can placed in that column.
int Bowman::isPlacable(int column)
{
	if (column == 1 || column == 2)
		return 1;
	else
		return 0;
}
//It checks if it is alive
int Bowman::isDied()
{
	if (this->getLife() > 0)
		return 1;
	else
		return 0;
}
//It checks if it is still usable
int Bowman::isUsable()
{
	if (this->getUsage() > 0)
		return 1;
	else
		return 0;
}
//Print for bowman
void Bowman::print()
{
	if (this->getLife() > 9)
	{
		cout << "  B(" << this->getLife() << ") ";
	}
	else
	{
		cout << "  B(" << this->getLife() << ")  ";
	}
}
//Checks that is it a empty piece or character
int Bowman::isItPiece()
{
	return 1;
}
//Decreases the health according to damage 
void Bowman::decreaseHealth(int damage)
{
	this->setLife(this->getLife() - damage);
}
//Check if it has a special spec.It will return 1 for Mage,2 for Knight and 0 for the rest.
int Bowman::isSpecial()
{
	return 0;
}
//------------------------------------------------------------------------------
//----------------------------------ELF FUNCTIONS-------------------------------
//------------------------------------------------------------------------------
//Constructor for Ranged. It sends the spesific values specified in the manual.
Elf::Elf() :Ranged(6, 3, 8, 'E'), Pieces(8, 'E')
{

}
//It checks if it is can placed in that column.
int Elf::isPlacable(int column)
{
	if (column == 1 || column == 2)
		return 1;
	else
		return 0;
}
//It checks if it is alive
int Elf::isDied()
{
	if (this->getLife() > 0)
		return 1;
	else
		return 0;
}
//It checks if it is still usable
int Elf::isUsable()
{
	if (this->getUsage() > 0)
		return 1;
	else
		return 0;
}
//Print for elf
void Elf::print()
{
	if (this->getLife() > 9)
	{
		cout << "  E(" << this->getLife() << ") ";
	}
	else
	{
		cout << "  E(" << this->getLife() << ")  ";
	}
}
//Checks that is it a empty piece or character
int Elf::isItPiece()
{
	return 1;
}
//Decreases the health according to damage
void Elf::decreaseHealth(int damage)
{
	this->setLife(this->getLife() - damage);
}
//Check if it has a special spec.It will return 1 for Mage,2 for Knight and 0 for the rest.
int Elf::isSpecial()
{
	return 0;
}
//------------------------------------------------------------------------------
//---------------------------------MAGE FUNCTIONS-------------------------------
//------------------------------------------------------------------------------
//Constructor for Mage. It sends the spesific values specified in the manual.
Mage::Mage() :Ranged(8, 2, 4, 'M'), Pieces(4, 'M')
{

}
//It checks if it is can placed in that column.
int Mage::isPlacable(int column)
{
	if (column == 1 || column == 2)
		return 1;
	else
		return 0;
}
//It checks if it is alive
int Mage::isDied()
{
	if (this->getLife() > 0)
		return 1;
	else
		return 0;
}
//It checks if it is still usable
int Mage::isUsable()
{
	if (this->getUsage() > 0)
		return 1;
	else
		return 0;
}
//Print for Mage
void Mage::print()
{
	if (this->getLife() > 9)
	{
		cout << "  M(" << this->getLife() << ") ";
	}
	else
	{
		cout << "  M(" << this->getLife() << ")  ";
	}
}
//Checks that is it a empty piece or character
int Mage::isItPiece()
{
	return 1;
}
//Decreases the health according to damage
void Mage::decreaseHealth(int damage)
{
	this->setLife(this->getLife() - damage);
}
//Check if it has a special spec.It will return 1 for Mage,2 for Knight and 0 for the rest.
int Mage::isSpecial()
{
	return 1;
}
//------------------------------------------------------------------------------
//---------------------------------MELEE FUNCTIONS------------------------------
//------------------------------------------------------------------------------
//Default constructor for Melee
Melee::Melee() :Pieces()
{
	this->damage = 0;
	this->usage = 0;
}
//Constructor for the Melee class with the spesific input
Melee::Melee(int hit, int use, int health, const char symbol) :Pieces(health, symbol)
{
	this->damage = hit;
	this->usage = use;
}
//Setter function for damage
void Melee::setDamage(int hit)
{
	this->damage = hit;
}
//Setter function for usage
void Melee::setUsage(int use)
{
	this->usage = use;
}
//Getter function for damage
int Melee::getDamage()const
{
	return this->damage;
}
//Getter function for usage
int Melee::getUsage()const
{
	return this->usage;
}
//Printer for ranged
void Melee::print()
{
	cout << "        ";
}
//Checks that is it a empty piece or character
int Melee::isItPiece()
{
	return 0;
}
//This is a virtual function. we will use it in the derived classes.
int Melee::isPlacable(int column)
{
	return -1;
}
//This is a virtual function. we will use it in the derived classes.
int Melee::isDied()
{
	return -1;
}
//This is a virtual function. we will use it in the derived classes.
int Melee::isUsable()
{
	return -1;
}
//This is a virtual function. we will use it in the derived classes.
void Melee::decreaseHealth(int h)
{
}
//This is a virtual function. we will use it in the derived classes.
int Melee::isSpecial()
{
	return -1;
}
//------------------------------------------------------------------------------
//-------------------------------SPEARMAN FUNCTIONS-----------------------------
//------------------------------------------------------------------------------
//Constructor for Spearman. It sends the spesific values specified in the manual.
Spearman::Spearman() :Melee(3, 100, 6, 'S'), Pieces(6, 'S')
{

}
//It checks if it is can placed in that column.
int Spearman::isPlacable(int column)
{
	if (column == 2 || column == 3)
		return 1;
	else
		return 0;
}
//It checks if it is alive
int Spearman::isDied()
{
	if (this->getLife() > 0)
		return 1;
	else
		return 0;
}
//It checks if it is still usable
int Spearman::isUsable()
{
	if (this->getUsage() > 0)
		return 1;
	else
		return 0;
}
//Print for Spearman
void Spearman::print()
{
	if (this->getLife() > 9)
	{
		cout << "  S(" << this->getLife() << ") ";
	}
	else
	{
		cout << "  S(" << this->getLife() << ")  ";
	}
}
//Checks that is it a empty piece or character
int Spearman::isItPiece()
{
	return 1;
}
//Decreases the health according to damage
void Spearman::decreaseHealth(int damage)
{
	this->setLife(this->getLife() - damage);
}
//Check if it has a special spec.It will return 1 for Mage,2 for Knight and 0 for the rest.
int Spearman::isSpecial()
{
	return 0;
}
//----------------------------------------------------------------------------
//-------------------------------RANGER FUNCTIONS-----------------------------
// ---------------------------------------------------------------------------
//Constructor for Ranger. It sends the spesific values specified in the manual.
Ranger::Ranger() :Melee(6, 2, 8, 'R'), Pieces(8, 'R')
{

}
//It checks if it is can placed in that column.
int Ranger::isPlacable(int column)
{
	if (column == 2 || column == 3)
		return 1;
	else
		return 0;
}
//It checks if it is alive
int Ranger::isDied()
{
	if (this->getLife() > 0)
		return 1;
	else
		return 0;
}
//It checks if it is still usable
int Ranger::isUsable()
{
	if (this->getUsage() > 0)
		return 1;
	else
		return 0;
}
//Print for Ranger
void Ranger::print()
{
	if (this->getLife() > 9)
	{
		cout << "  R(" << this->getLife() << ") ";
	}
	else
	{
		cout << "  R(" << this->getLife() << ")  ";
	}
}
//Checks that is it a empty piece or character
int Ranger::isItPiece()
{
	return 1;
}
//Decreases the health according to damage
void Ranger::decreaseHealth(int damage)
{
	this->setLife(this->getLife() - damage);
}
//Check if it has a special spec.It will return 1 for Mage,2 for Knight and 0 for the rest.
int Ranger::isSpecial()
{
	return 0;
}
//-------------------------------------------------------------------------------
//-------------------------------SWORDSMAN FUNCTIONS-----------------------------
// ------------------------------------------------------------------------------
//Constructor for Swordsman. It sends the spesific values specified in the manual.
Swordsman::Swordsman() :Melee(4, 100, 6, 'W'), Pieces(6, 'W')
{

}
//It checks if it is can placed in that column.
int Swordsman::isPlacable(int column)
{
	if (column == 2 || column == 3)
		return 1;
	else
		return 0;
}
//It checks if it is alive
int Swordsman::isDied()
{
	if (this->getLife() > 0)
		return 1;
	else
		return 0;
}
//It checks if it is still usable
int Swordsman::isUsable()
{
	if (this->getUsage() > 0)
		return 1;
	else
		return 0;
}
//Print for Swordsman
void Swordsman::print()
{
	if (this->getLife() > 9)
	{
		cout << "  W(" << this->getLife() << ") ";
	}
	else
	{
		cout << "  W(" << this->getLife() << ")  ";
	}
}
//Checks that is it a empty piece or character
int Swordsman::isItPiece()
{
	return 1;
}
//Decreases the health according to damage
void Swordsman::decreaseHealth(int damage)
{
	this->setLife(this->getLife() - damage);
}
//Check if it has a special spec.It will return 1 for Mage,2 for Knight and 0 for the rest.
int Swordsman::isSpecial()
{
	return 0;
}
//----------------------------------------------------------------------------
//-------------------------------KNIGHT FUNCTIONS-----------------------------
// ---------------------------------------------------------------------------
//Constructor for Knight. It sends the spesific values specified in the manual.
Knight::Knight() :Melee(10, 1, 10, 'K'), Pieces(10, 'K')
{

}
//It checks if it is can placed in that column.
int Knight::isPlacable(int column)
{
	if (column == 2 || column == 3)
		return 1;
	else
		return 0;
}
//It checks if it is alive
int Knight::isDied()
{
	if (this->getLife() > 0)
		return 1;
	else
		return 0;
}
//It checks if it is still usable
int Knight::isUsable()
{
	if (this->getUsage() > 0)
		return 1;
	else
		return 0;
}
//Print for Knight
void Knight::print()
{
	if (this->getLife() > 9)
	{
		cout << "  K(" << this->getLife() << ") ";
	}
	else
	{
		cout << "  K(" << this->getLife() << ")  ";
	}
}
//Checks that is it a empty piece or character
int Knight::isItPiece()
{
	return 1;
}
//Decreases the health according to damage
void Knight::decreaseHealth(int damage)
{
	this->setLife(this->getLife() - damage);
}
//Check if it has a special spec.It will return 1 for Mage,2 for Knight and 0 for the rest.
int Knight::isSpecial()
{
	return 2;
}