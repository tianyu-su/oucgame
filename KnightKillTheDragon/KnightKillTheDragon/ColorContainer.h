#pragma once
#ifndef __COLORCONTAINER_H__
#define __COLORCONTAINER_H__
#include <sstream>
class ColorContainer
{
public:
	ColorContainer();
	virtual ~ColorContainer();
	virtual void changeTextColor(char color, std::ostringstream &oss) = 0;
};
#endif // !__COLORCONTAINER_H__
