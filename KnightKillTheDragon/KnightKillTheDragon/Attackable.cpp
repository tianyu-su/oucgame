#include "Attackable.h"
Attackable::Attackable()
{
}

Attackable::Attackable(std::string name, int pos_x, int pos_y, int life, int power, int exp, int protectPower, int level, int money):
						Role(name,pos_x,pos_y),life(life),power(power),exp(exp),protectPower(protectPower),level(level),money(money){}

Attackable::~Attackable()
{
}

int Attackable::getLife()const
{
	return this->life;
}

void Attackable::setLife(int life)
{
	this->life = life;
}

int Attackable::getPower()const
{
	return this->power;
}

void Attackable::setPower(int power)
{
	this->power = power;
}

int Attackable::getProtectPower()const
{
	return protectPower;
}

void Attackable::setProtectPower(int protectPower)
{
	this->protectPower = protectPower;
}

int Attackable::getExp()const
{
	return this->exp;
}

void Attackable::setExp(int exp)
{
	this->exp = exp;
}

int Attackable::getLevel()const
{
	return this->level;
}

void Attackable::setLevel(int level)
{
	this->level = level;
}

int Attackable::getMoney()const
{
	return this->money;
}

void Attackable::setMoney(int money)
{
	this->money = money;
}
