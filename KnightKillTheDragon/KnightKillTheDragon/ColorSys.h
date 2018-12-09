#pragma once
#ifndef __COLORSYS_H__
#define __COLORSYS_H__
#include "ColorContainer.h"
#include "ConsoleColorl.h"
class ColorSys :public ColorContainer,private ConsoleColor {
public:
	virtual void changeTextColor(char color, std::ostringstream &oss);
private:
	void resetTextColor();//恢复原来字体颜色，白色
};
#endif // !__COLORSYS_H__
