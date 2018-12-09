#include <iostream>
#include <Windows.h>
#include "Map.h"
#include "Player.h"
#include "ConstTable.h"
#include "Container.h"
#include "Command.h"
#include "FileStore.h"
#include "Utill.h"
#include "ColorContainer.h"
#include "ColorSys.h"
#include "Error.h"
using namespace std;
int main() {

	//展示开始界面
	int type;
	Utill::HideCursor();
	try
	{
		while (true)
		{
			Map::showMenu();
			cout << "请输入功能:";
			cin >> type;
			if (type == 1)
				Command::newGame();
			else if (type == 2) {
				//读到map 里面
				try
				{
					Map *map = FileStore::ReadGameFile();
					int mapData[MAPROW][MAPCOLUMN];
					map->getMapData(mapData);
					Command::newerCountry(map->getPlayer(), mapData, map->getWare());
				}
				catch (Error &ex)
				{
					ColorContainer *c = new ColorSys();
					ostringstream oss;
					oss << ex.what() << endl;
					c->changeTextColor('R', oss);
					oss << "请开始新的游戏！" << endl;
					c->changeTextColor('R', oss);
					delete c;
				}
			}
			else if (type == 3) {
				//打开二维码
				system("QR.png");
				cout << "下载的 Map.dat 复制到游戏根目录即可！" << endl;
				system("pause");
			}
			else
				exit(0);
		}


	}
	catch (const std::exception&)
	{
		ColorContainer *c = new ColorSys();
		ostringstream oss;
		oss << "\n游戏文件虽坏，请重新打开!开始新的征程！\t程序即将退出..." << endl;
		c->changeTextColor('R', oss);
		Sleep(1500);
		delete c;
		exit(0);
	}
	return 0;
};