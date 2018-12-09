#pragma once
#ifndef __ROLE_H__
#define __ROLE_H__
#include <string>
class Role
{
public:
	Role();
	Role(std::string name, int pos_x, int pos_y);
	virtual ~Role();
	std::string getName();
	void setName(std::string name);
	int getPos_x()const;
	int getPos_y()const;
	void move(int x, int y);
	virtual void showInfo()const = 0;
private:
	std::string name;//Ãû×Ö
	int pos_x, pos_y;//Î»ÖÃ
};

#endif // !__ROLE_H__
