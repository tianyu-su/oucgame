#include "Utill.h"

void Utill::changeForeground(char color)  //改变字的颜色  R 红 B 蓝 G 绿
{
	//改变输出颜色
	HANDLE consolehwnd;//创建句柄
	consolehwnd =
		GetStdHandle(STD_OUTPUT_HANDLE);//实例化句柄
	switch (color) {
	case 'R':
		SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY | FOREGROUND_RED);
		break;
	case 'B':
		SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		break;
	case 'G':
		SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		break;
	default:
		break;
	}
}

void Utill::ForegroundRGS()  //亮红绿
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void Utill::ForegroundGBS()	//亮绿蓝
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void Utill::ForegroundBRS()	//亮蓝绿
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void Utill::ForegroundALL() //全色
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void Utill::HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void Utill::gotoxy(unsigned char x, unsigned char y)
{
	COORD cor;
	HANDLE hout;
	cor.X = y;
	cor.Y = x;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, cor);
}
