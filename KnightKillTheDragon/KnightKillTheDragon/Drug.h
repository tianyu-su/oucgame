#ifndef _DRUG_H
#define _DRUG_H
#include "Item.h"
//#include "Player.h"
class Drug :public Item
{
public:
	Drug();//默认构造函数
	Drug(std::string id, int value, char type, int weight);//设置药水的名字和价值  
	void showInfo();//打印药水的属性
	char getType()const;
	int getWeight()const;
	~Drug();


private:
	char type;//药水的种类
	int weight;//药水回复的生命力
};
#endif // !_DRUG_H
#pragma once