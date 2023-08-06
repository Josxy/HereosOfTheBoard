/* Yusuf Said Savaş - 2526655
I read and accept the submission rules and the important section
specified in assignment file. This is my own work that is done by myself
and my team-mate only */
#pragma once
#include <iostream>
#include <string.h>
using namespace std;
//Pieces Class
class Pieces
{
private:
	int life;
	char representation;
public:
	Pieces();
	Pieces(int, const char);
	virtual ~Pieces();
	void setLife(int);
	void setRep(const char);
	int getLife()const;
	char getRep()const;
	virtual void print();
	//~Pieces();
	//Pure virtual functions to use in derived classes. These functions make this class an abstract class.
	virtual void setDamage(int) = 0;
	virtual void setUsage(int) = 0;
	virtual int getDamage()const = 0;
	virtual int getUsage()const = 0;
	virtual int isItPiece() = 0;
	virtual int isPlacable(int) = 0;
	virtual int isDied() = 0;
	virtual int isUsable() = 0;
	virtual void decreaseHealth(int) = 0;
	virtual int isSpecial() = 0;
};
//Ranged Class
class Ranged : virtual public Pieces
{
private:
	int damage;
	int usage;
public:
	Ranged();
	Ranged(int, int, int, const char);
	void setDamage(int);
	void setUsage(int);
	int getDamage()const;
	int getUsage()const;
	virtual void print();
	virtual int isItPiece();
	virtual int isPlacable(int);
	virtual int isDied();
	virtual int isUsable();
	virtual void decreaseHealth(int);
	virtual int isSpecial();
};
//Bowman Class
class Bowman : virtual public Ranged
{
public:
	Bowman();
	void print();
	int isItPiece();
	int isPlacable(int);
	int isDied();
	int isUsable();
	void decreaseHealth(int);
	int isSpecial();
};
//Elf Class
class Elf : virtual public Ranged
{
public:
	Elf();
	void print();
	int isItPiece();
	int isPlacable(int);
	int isDied();
	int isUsable();
	void decreaseHealth(int);
	int isSpecial();
};
//Mage Class
class Mage : virtual public Ranged
{
public:
	Mage();
	int isItPiece();
	void print();
	int isPlacable(int);
	int isDied();
	int isUsable();
	void decreaseHealth(int);
	int isSpecial();
};
//Melee Class
class Melee : virtual public Pieces
{
private:
	int damage;
	int usage;
public:
	Melee();
	Melee(int, int, int, const char);
	void setDamage(int);
	void setUsage(int);
	int getDamage()const;
	int getUsage()const;
	virtual void print();
	virtual int isItPiece();
	virtual int isPlacable(int);
	virtual int isDied();
	virtual int isUsable();
	virtual void decreaseHealth(int);
	virtual int isSpecial();
};
//Spearman Class
class Spearman : virtual public Melee
{
public:
	Spearman();
	void print();
	int isItPiece();
	int isPlacable(int);
	int isDied();
	int isUsable();
	void decreaseHealth(int);
	int isSpecial();
};
//Ranger Class
class Ranger : virtual public Melee
{
public:
	Ranger();
	void print();
	int isItPiece();
	int isPlacable(int);
	int isDied();
	int isUsable();
	void decreaseHealth(int);
	int isSpecial();
};
//Swordsman Class
class Swordsman : virtual public Melee
{
public:
	Swordsman();
	void print();
	int isItPiece();
	int isPlacable(int);
	int isDied();
	int isUsable();
	void decreaseHealth(int);
	int isSpecial();
};
//Knight Class
class Knight : virtual public Melee
{
public:
	Knight();
	void print();
	int isItPiece();
	int isPlacable(int);
	int isDied();
	int isUsable();
	void decreaseHealth(int);
	int isSpecial();
};