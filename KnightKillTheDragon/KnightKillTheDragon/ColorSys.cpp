#include "ColorSys.h"
#include <iostream>
using namespace std;
void ColorSys::changeTextColor(char color, std::ostringstream &oss)
{
	switch (color)
	{
	case 'W':
		ConsoleColor::setTextWhite(); break;
	case 'R':
		ConsoleColor::setTextRed(); break;
	case 'G':
		ConsoleColor::setTextGreen(); break;
	case 'B':
		ConsoleColor::setTextBlue(); break;
	case 'Y':
		ConsoleColor::setTextYellow(); break;
	case 'P':
		ConsoleColor::setTextPink(); break;
	case 'Q':
		ConsoleColor::setTextBrightBlue(); break;
	default:
		resetTextColor(); break;
	}
	//清空流，下次继续使用即可
	cout << oss.str();
	oss.str("");
	//恢复原来字体颜色
	resetTextColor();
}

void ColorSys::resetTextColor()
{
	ConsoleColor::setTextWhite();
}
