#include "Map.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <ctime>
#include <string>
#include "ConstTable.h"
#include "Utill.h"
using namespace std;


Map::Map(Player& p,Container &wareshop) :man(p), wareshop(wareshop) {}

Map::Map(Player & p, Container & wareshop, int(&backupMap)[MAPROW][MAPCOLUMN]) : man(p), wareshop(wareshop)
{
	memcpy(mapData, backupMap, sizeof(backupMap));
}

void Map::showMapOne() {
	char* file;
	int nowPos = man.getNowPos();
	if (nowPos == 0)  //出生
	{
		file = "MapOneData.txt";
		this->DataRead(file);  //读取地图数据
		man.setNowPos(1);
	}
	else if (nowPos == 2)   //从2号图到1号图
	{
		file = "MapOneData.txt";
		this->DataRead(file);  //读取地图数据
		man.setNowPos(1);
		man.move(5, 47);   //传送门
	}
	else
	{
		file = "MapOneData.txt";
		this->DataRead(file);  //读取地图数据
	}
	file = "MapOne.txt";
	this->show(man.getPos_x(), man.getPos_y(), file);  //读取地图显示数据
}

void Map::showMapTwo() {
	char* file;
	int nowPos = man.getNowPos();
	if (nowPos == 1) //从1号图到2号图
	{
		file = "MapTwoData.txt";
		this->DataRead(file);	//读取基本地图信息
		man.setNowPos(2);
		man.move(5, 3);	//传送门
		this->monserGenerator();	//生成怪物修改地图信息
	}
	if (nowPos == 3) //从3号图到2号图
	{
		file = "MapTwoData.txt";
		this->DataRead(file);	//读取基本地图信息
		man.setNowPos(2);
		man.move(5, 46);	//传送门
		this->monserGenerator();	//生成怪物修改地图信息
	}
	if(nowPos == 4)
	{
		file = "MapTwoData.txt";
		this->DataRead(file);	//读取基本地图信息
		man.setNowPos(2);
		this->monserGenerator();	//生成怪物修改地图信息
	}
	file = "MapTwo.txt";
	this->showMonster(man.getPos_x(),man.getPos_y(), file);
}

void Map::showMapThree() {
	char* file;
	int nowPos = man.getNowPos();
	file = "MapThreeData.txt";
	this->DataRead(file);  //读取地图数据
	for (int i = 0; i < 11; i++)
		mapData[i][15] = -1;
	if (nowPos == 2)  //从2号图到3号图
	{
		man.setNowPos(3);
		man.move(5, 3);		//传送门
	}
	file = "MapThree.txt";
	this->show(man.getPos_x(), man.getPos_y(), file); //读取地图显示数据
}

int Map::mapMove(char dir) {
	int x = man.getPos_x();
	int y = man.getPos_y();
	Utill::gotoxy(x, y);
	putchar(' ');
	switch (dir) {
	case 'w':
		x--;
		if (mapData[x][y])
		{
			man.move(x, y);
			Utill::gotoxy(x, y);
			putchar('o');
			//showNowposMap();
			Utill::gotoxy(13, 0);
			return mapData[x][y];
		}
		Utill::gotoxy(x+1, y);
		putchar('o');
		Utill::gotoxy(13, 0);
		return mapData[x+1][y];
	case 'a':
		y--;
		if (mapData[x][y])
		{
			man.move(x, y);
			//showNowposMap();
			Utill::gotoxy(x, y);
			putchar('o');
			Utill::gotoxy(13, 0);
			return mapData[x][y];
		}
		//showNowposMap();
		Utill::gotoxy(x, y+1);
		putchar('o');
		Utill::gotoxy(13, 0);
		return mapData[x][y+1];
	case 's':
		x++;
		if (mapData[x][y])
		{
			man.move(x, y);
			//showNowposMap();
			Utill::gotoxy(x, y);
			putchar('o');
			Utill::gotoxy(13, 0);
			return mapData[x][y];
		}
		//showNowposMap();
		Utill::gotoxy(x+1, y);
		putchar('o');
		Utill::gotoxy(13, 0);
		return mapData[x + 1][y];
	case 'd':
		y++;
		if (mapData[x][y])
		{
			man.move(x, y);
			//showNowposMap();
			Utill::gotoxy(x, y);
			putchar('o');
			Utill::gotoxy(13, 0);
			return mapData[x][y];
		}
		//showNowposMap();
		Utill::gotoxy(x, y-1);
		putchar('o');
		Utill::gotoxy(13, 0);
		return mapData[x][y-1];
	default:
		break;
	}
	return mapData[x][y];
}

void Map::showMenu() {
	system("cls");
	Utill::changeForeground('R');
	char* file = "WelcomeMenu.txt";
	ifstream fin(file);   //读取并显示欢迎界面
	char data[100];
	for (int i = 0; i < 18; i++) {
		fin.getline(data, 100);
		cout << data << endl;
		if (i == 13)
			Utill::ForegroundRGS();
	}
	Utill::ForegroundALL();
}

Container * Map::getWareshop() const
{
	return &wareshop;
}

void Map::DataRead(char *file) {  //读取地图数字信息
	ifstream ifs(file);
	int i = 0;
	if (ifs) {
		for (int i = 0; i < MAPROW; i++){
			string str;
			getline(ifs, str);
			for (int j = 0; j < MAPCOLUMN; j++){
				mapData[i][j] = (int)str[j]-48;
			}
		}
	}
}

void Map::show(char* file) {
	system("cls");
	ifstream fin(file);
	string str;
	if (fin) {
		for (int i = 0; i < MAPROW; i++)
		{
			getline(fin, str);
			cout << str << endl;
		}
	}
	fin.close();
}

void Map::show(int x, int y, char* file) 
{
	system("cls");
	ifstream fin(file);
	string str;
	if (fin) {
		for (int i = 0; i < MAPROW; i++)
		{
			getline(fin, str);
			if (x == i)
				str[y] = 'o';
			cout << str << endl;
		}
	}
	fin.close();
}

void Map::showMonster(int x, int y, char * file)
{
	system("cls");
	ifstream fin(file);
	string str;
	if (fin) {
		for (int i = 0; i < MAPROW; i++)
		{
			getline(fin, str);
			for (int j = 0; j < MAPCOLUMN; j++)
				if (mapData[i][j] == -1)
					str[j] = 'x';
			if (x == i)
				str[y] = 'o';
			cout << str << endl;
		}
	}
	fin.close();
}

void Map::gameEnd()
{
	system("cls");
	Utill::ForegroundGBS();
	cout << "恭喜你成功击败了恶龙！" << endl;
	Sleep(800);
	cout << "将公主从恶龙的巢穴拯救出来，公主回到了你的身边！" << endl;
	Sleep(500);
	cout << "但是";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << "." << endl;
	Sleep(2000);
	Utill::ForegroundRGS();
	cout << "你的冒险还没有结束!" << endl;
	Sleep(2000);
	Utill::ForegroundALL();
	system("cls");

}
void Map::battleFinish(bool status) {
	if (status) {  //战斗胜利  怪物死亡
		int manPosx = man.getPos_x();
		int manPosy = man.getPos_y();
		mapData[manPosx][manPosy] = 1;
	}
	else  //战斗失败  死亡复活
	{
		man.setNowPos(1); //初始地图1
		man.move(BORNX, BORNY);  //复活于初始地图位置
	}
}

void Map::monserGenerator() {
	srand((unsigned)time(NULL));
	int monPosx, monPosy;
	int cnt(0); //记录已成功生成的怪物数量
	while(true)
	{
		monPosx = (rand() % 11) + 1;
		monPosy = (rand() % 48) + 1;
		if (mapData[monPosx][monPosy] == 1)
		{
			mapData[monPosx][monPosy] = -1;
			cnt++;
		}
		if (cnt == MONSTERMAXNUM)
			return;
	}
}

void Map::showNowposMap()
{
	int nowPos = man.getNowPos();
	if (nowPos == 1 || !nowPos)
	{
		showMapOne();
	}
	else if (nowPos == 2 || nowPos ==4)
	{
		showMapTwo();
	}
	else if (nowPos == 3)
	{

		showMapThree();
	}
	else
		return;
}

void Map::setManPos(int x)
{
	man.setNowPos(x);
}

Container & Map::getBag()
{
	return *man.getBag();
}

Container * Map::getWare()
{
	return &(this->wareshop);
}

void Map::getMapData(int backupMapData[][MAPCOLUMN])
{
	memcpy(backupMapData, mapData, sizeof(mapData));
}

void Map::setMapData(int(&backupMap)[MAPROW][MAPCOLUMN])
{
	memcpy(mapData, backupMap, sizeof(backupMap));
}


int Map::getManPos()
{
	return man.getNowPos();
}

Player * Map::getPlayer()
{
	return &man;
}

