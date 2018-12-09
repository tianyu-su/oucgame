#pragma once
#ifndef __CONTAINER_H__
#define __CONTAINER_H__
#include <vector>
#include <string>
#include "Equipment.h"
#include "Drug.h"
#include "Item.h"
#include "Attackable.h"
class Container
{
public:
	Container(int capacity);
	Container(const Container &con);
	bool push(Item* item);//加入容器,成功真；装不下返回假;
	void remove(Item *item);//删除item
	void showGoods();//显示所有商品名字
	int getNowSize()const;//获取当前物品数量
	int getTotalSize()const;//获取容器的总大小
	Item *getItemByIndex(int index);//通过商品编号获取商品
	~Container();
private:
	int capacity;//背包容量
	int num;//背包现有物品数量
	std::vector<Item*> goods;//背包内的物品
};

#endif // !__CONTAINER_H__
