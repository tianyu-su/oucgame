#pragma once
#ifndef __ATTACKABLE_H__
#define __ATTACKABLE_H__
#include "Role.h"
#include <string>
class Attackable:public Role 
{
public:
	Attackable();
	Attackable(std::string name, int pos_x, int pos_y, int life, 
				int power , int exp , int protectPower , 
				int level , int money);
	virtual ~Attackable();
	int getLife()const;
	void setLife(int life);
	int getPower()const;
	void setPower(int power);
	int getProtectPower()const;
	void setProtectPower(int protectPower);
	int getExp()const;
	virtual void setExp(int exp);//设置经验
	int getLevel()const;
	void setLevel(int level);
	int getMoney()const;
	void setMoney(int money);

private:
	int life;//生命值
	int power;//攻击力
	int protectPower;//护甲
	int exp;//经验
	int level;//等级
	int money;//金钱
};

#endif // !__ATTACKABLE_H__
