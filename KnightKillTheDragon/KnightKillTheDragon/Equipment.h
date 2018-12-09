#ifndef _EQUIPMENT_H
#define _EQUIPMENT_H
#include <string>
#include "Item.h"
//#include "Player.h"
class Equipment :public Item
{
public:
	Equipment(std::string id, int value, int power, int consume, int protectPower, int movePower);//构造函数初始化武器的名称和价值和属性等
	~Equipment();
	Equipment(const Equipment &equipment);//复制构造函数
	void showInfo();///打印武器的属性

	int getPower()const; //获得武器的攻击力
						 //int setPower();

	int getConsume()const;//获得武器的耐久

	int getProtectPower()const;//获得武器的防御力（护甲）
							   //int setProtectPower();

	int getMovePower()const; //获得武器的移动速度
							 //int setMovePower();
	Equipment();
	void initEquipment(int index,int money);//通过武器的编号判断那种物品，通过金钱响应赋予属性，得到一个完整属性的实例,没有属性置零
private:
	int power; //装备的攻击力
	int consume;//装备的耐久
	int protectPower;//护甲
	int movePower;//移动速度
};


#endif // !_EQUIPMENT_H
#pragma once

