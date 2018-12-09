#ifndef UTILL_H
#define UTILL_H
#include <string>
#include <Windows.h>
class Utill {
public:
	static void changeForeground(char color);
	static void ForegroundRGS();
	static void ForegroundGBS();
	static void ForegroundBRS();
	static void ForegroundALL();
	static void HideCursor();
	static void gotoxy(unsigned char x, unsigned char y);
};


#endif