#pragma once
#ifndef __MONSTER_H__
#define __MONSTER_H__
#include "Attackable.h"
#include "Equipment.h"
class Monster:public Attackable
{
public:
	Monster(Equipment *equipment);
	virtual ~Monster();
	virtual void showInfo()const;//查看怪物属性
	Equipment *getItem()const;//返回掉落物品

private:
	 Equipment *equipment;//掉落的装备
};

#endif // !__MONSTER_H__
