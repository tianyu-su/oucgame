#include "Role.h"
#include <string>
using namespace std;
Role::Role()
{
}
Role::Role(std::string name, int pos_x, int pos_y) :name(name), pos_x(pos_x), pos_y(pos_y) {}

Role::~Role()
{
}
string Role::getName() {
	return name;
}

void Role::setName(std::string newName)
{
	this->name = newName;
}

int Role::getPos_x()const
{
	return pos_x;
}


int Role::getPos_y()const
{
	return pos_y;
}

void Role::move(int x, int y)
{
	this->pos_x = x;
	this->pos_y = y;
}

