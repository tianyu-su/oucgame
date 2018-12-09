#ifndef MAP_H
#define MAP_H
#include "Player.h"
#include "Container.h"
#include "ConstTable.h"
class Map {
public:
	Map(Player& p,Container &wareshop);
	Map(Player& p, Container &wareshop,int (&backupMap)[MAPROW][MAPCOLUMN]);
	void showMapOne();  //地图1
	void showMapTwo();	//地图2
	void showMapThree();  //地图3
	int mapMove(char dir);  //移动
	void battleFinish(bool status);
	static void showMenu();
	Container *getWareshop()const;//获取仓库
	void showNowposMap();//更新当前地图
	Player *getPlayer();//获取player
	int getManPos();
	void setManPos(int x);
	Container& getBag();	//返回背包
	Container* getWare();	//返回仓库
	void getMapData(int backupMapData[][MAPCOLUMN]);//返回地图数据到参数中
	void setMapData(int(&backupMap)[MAPROW][MAPCOLUMN]);//设置对象地图数据
	void gameEnd(); //打败恶龙结局

private:
	void DataRead(char *file);
	void show(char* file);   //读取file中的地图数据并显示
	void show(int x, int y, char* file);  //显示地图，(x,y)是人物在地图上的坐标  重载
	void showMonster(int x, int y, char* file); 
	void monserGenerator();	//在当前地图生成怪物
	int mapData[MAPROW][MAPCOLUMN];   //地图数据   0墙 1路 2可访问NPC 3门 -1怪物
	Player& man;
	Container &wareshop;
};

#endif
