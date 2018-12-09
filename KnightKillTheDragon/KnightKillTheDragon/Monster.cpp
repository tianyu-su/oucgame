#include "Monster.h"
#include "ConstTable.h"
#include <iostream>
#include <ctime>
using namespace std;
Monster::Monster(Equipment *equipment) : equipment(equipment) {
	
}

Monster::~Monster()
{
}

void Monster::showInfo() const
{
	cout << "HP:" << getLife() << "\t\t" << "攻击力:" << getPower() << endl
		<< "防御力:" << getProtectPower() << "\t" << "等级:" << getLevel() << endl;

}

Equipment *Monster::getItem() const
{
	return this->equipment;
}

