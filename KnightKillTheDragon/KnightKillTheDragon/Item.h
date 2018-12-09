#ifndef _ITEM_H
#define _ITEM_H
#include <string>
class Item
{
public:
	Item();
	Item(std::string id, int value);
	~Item();
	std::string getId() const;//得到武器或药水的名字	
	int getValue() const;//得到武器或药水的价值
	virtual void showInfo() = 0;//打印武器和药水的属性
	void setId(std::string name);//设置名字
private:
	std::string id;//物品的名字
	int value;//物品的价值
};
#endif // !__ITEM_H__

#pragma once

