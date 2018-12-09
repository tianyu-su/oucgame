#include <iostream>
#include<iomanip>
using namespace std;
#include"Drug.h"

Drug::Drug() {}//默认构造函数
Drug::Drug(std::string id, int value, char type, int weight) :Item(id, value) {
	this->type = type;
	this->weight = weight;
}//设置药水的名字和价值

Drug::~Drug() {}

//打印出药水的属性
void Drug::showInfo() {
	cout << setw(6) << "名称" << setw(8) << "价值" << setw(8) << "类型" << setw(8) << "可恢复力" << endl;
	cout << setw(6) << getId() << setw(8) << getValue() << setw(8) << getType() << setw(8) << getWeight() << endl;
}
char Drug::getType()const
{
	return type;
}
int Drug::getWeight()const
{
	return weight;
}