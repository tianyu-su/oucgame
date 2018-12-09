#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <limits>
#include <cmath>
#include <Windows.h>
#include <conio.h>
#include "Command.h"
#include "Player.h"
#include "ConstTable.h"
#include "Map.h"
#include "Error.h"
#include "Container.h"
#include "Equipment.h"
#include "FileStore.h"
#include "Battle.h"
#include "Utill.h"
#include "ColorContainer.h"
#include "ColorSys.h"
using namespace std;
ColorContainer *c = new ColorSys();
ostringstream oss;
void Command::newGame()
{
	//删除之前玩家
	Player::deletePlayer();
	string name;
	Utill::changeForeground('G');
	cout << "流落到异世界的骑士，快去打败恶龙拯救你的公主吧！" << endl;
	cout << "你的名字：";
	Utill::ForegroundALL();
	clearCin();
	cin >> name;
	Player *player = Player::creatPlayer(name, BORNX, BORNY, BORNLIFE, BORNPOWER, BORNEXP, BORNPROTECTPOWER,
		BORNLEVEL, BORNMONEY, BORNENERGY, BORNMISS, BORNSPEED, 0, Container(BAGCOUNTCAPACITY));
	cout << player->getName() << "  你的征程即将开始！" << endl;
	Sleep(100);
	system("cls");
	//进入新手村
	
	//随便搞一个地图数组，为了解决蜜汁指针传递二维数组失败，被迫使用引用实现
	int laji[MAPROW][MAPCOLUMN] = { 0 };
	newerCountry(player,laji);
}

void Command::newerCountry(Player *player, int(&backupMap)[MAPROW][MAPCOLUMN], Container *ware)
{
	//Container wareCon = (backupMap->getWare() ? Container(*backupMap->getWare()) : Container(WARESHOPCAPACITY));
	Container wareCon = (ware ? Container(*ware) : Container(WARESHOPCAPACITY));
	Map map(*player,wareCon);
	if (ware)
		map.setMapData(backupMap);
	int nowPos = 0;
	do
	{
		map.showNowposMap();
		oss << "移动：W A S D  查看人物属性:T  打开背包:B  主界面：M";
		c->changeTextColor('Y', oss);
		//oss.str("");
		try {
			//方向 w a s d
			char dir, choice;
			dir = _getch();
			//标准化输入
			dir=tolower(dir);
			if (dir == 'w' || dir == 'a' || dir == 's' || dir == 'd') {
				//需要更改 mapmove 函数，要有返回值
				int moveType = map.mapMove(dir);
				switch (moveType)
				{
				case ROAD:
					map.showNowposMap();
					//更新地图
					break;
				case WAREHOUSE:
					//询问是否打开仓库
					oss << "是否打开仓库? (Y/N)";
					c->changeTextColor('Y', oss);
					//oss.str("");
					clearCin();
					cin >> choice;
					choice=tolower(choice);
					if (choice == 'y')
						wareshop(map,player);
					break;
				case WEAPONHOUSE:
					//询问是否买武器
					oss << "是否购买武器? (Y/N)";
					c->changeTextColor('Y', oss);
					//oss.str("");
					clearCin();
					cin >> choice;
					choice=tolower(choice);
					if (choice == 'y')
						weapon(player);
						break;

				case HOSPITAL:
					//询问是否进入医馆
					oss << "是否进入医馆? (Y/N)";
					c->changeTextColor('Y', oss);
					//oss.str("");
					clearCin();
					cin >> choice;
					choice=tolower(choice);
					if (choice == 'y')
						hospital(player);
					break;

				case DOOR:
					//切换地图
					nowPos = player->getNowPos();
					if (nowPos == 1)
						map.showMapTwo();
					else if (nowPos == 2 && player->getPos_y() == 0)
						map.showMapOne();
					else if (nowPos == 2 && player->getPos_y() == 47)
						map.showMapThree();
					else if (nowPos == 3)
						map.showMapTwo();
					break;
				case MONSTER:
					//询问是否打怪
					oss << "是否进入战斗? (Y/N)";
					c->changeTextColor('Y', oss);
					//oss.str("");
					clearCin();
					cin >> choice;
					choice=tolower(choice);
					if (choice == 'y') {
						Battle battle(*player);
						battle.beginBattle();
						map.battleFinish(battle.showResult());
						if (player->getNowPos() == 3)
						{
							map.gameEnd();
							//FileStore::StoreGameToFile(map);
							//显示界面
							system("cls");
							Map::showMenu();
							return;
						}
						system("pause");
					}
					break;
				default:
					break;
				}
			}
			else if (dir == PLAYERATTR) {
				//打开人物属性
				cout << endl;
				player->showInfo();
				system("pause");
			}
			else if (dir == PLAYERBAG) {
				//打开背包
				cout << endl;
				oss << "背包:";
				c->changeTextColor('Y', oss);
				//oss.str("");
				player->showBag();
				system("pause");

			}
			else if (dir == MAINMENUE) {
				//回到主菜单
				//存档
				FileStore::StoreGameToFile(map);
				//显示界面
				system("cls");
				Map::showMenu();
				return;
			}
			else {
				throw Error("输入有误");
			}

		}
		catch (Error &ex) {
			cout << ex.what() << endl;
		}
	} while (true);
}

void Command::wareshop(Map &map,Player *player)
{
	Container *wareshop = map.getWareshop();//map 类加入仓库成员，返回仓库指针
	int choice;
	do
	{
		cout << "仓库容量：" << wareshop->getNowSize() << "/" << wareshop->getTotalSize() << endl;
		cout << "仓库物品：" << endl;
		wareshop->showGoods();
		if (!wareshop->getNowSize())
			cout << "空" << endl;
		cout << "1.取出物品  2.存放物品  3.离开" << endl;
		int number;
		cout << "请选择：";
		clearCin();
		cin >> choice;

		try
		{
			if (choice == 1) {
				cout << "请输入取出商品编号,只能输入一件商品！" << endl;
				cout << "请输入：";
				clearCin();
				cin >> number;
				if (number > wareshop->getNowSize() && number>0)
					throw Error("请输入正确的商品编号！");
				Item *item = wareshop->getItemByIndex(number - 1);
				//仓库减少这个商品，放在背包，先判断是否能装的下
				if (player->pushBag(item)) {
					wareshop->remove(item);
					cout << item->getId() << "成功放入你的背包！" << endl;
				}
				else {
					cout << "背包满了，不可以加入东西!" << endl;
				}
			}
			else if (choice == 2) {
				if (wareshop->getNowSize() >= wareshop->getTotalSize()) {
					cout << "仓库已满不能存放物品，是否丢弃物品（Y/N）";
					char yesOrNo;
					clearCin();
					cin >> yesOrNo;
					yesOrNo=tolower(yesOrNo);
					if (yesOrNo == 'y') {
						cout << "请输入丢弃商品编号,只能输入一件商品！" << endl;
						cout << "请输入：";
						clearCin();
						cin >> number;
						if (number > wareshop->getNowSize() && number>0)
							throw Error("请输入正确的商品编号！");
						Item *item = wareshop->getItemByIndex(number - 1);
						wareshop->remove(item);
						cout << item->getId() << "已经被丢弃！" << endl;
					}
				}
				else {
					cout << "背包物品:";
					Container *bag = player->getBag();
					bag->showGoods();
					if (bag->getNowSize()) {
						cout << "请输入存入商品编号,只能输入一件商品！" << endl;
						cout << "请输入：";
						clearCin();
						cin >> number;
						if (number > bag->getNowSize() && number>0)
							throw Error("请输入正确的商品编号！");
						Item *item = bag->getItemByIndex(number - 1);
						//放入仓库，背包减少
						wareshop->push(item);
						player->removeBag(item);
						cout << item->getId() << "成功放入你的仓库！" << endl;
					}
					else {
						cout << "空" << endl;
					}
				}

			}
			else if(choice!=3) {
				throw Error("请输入正确的功能！");
			}
		}
		catch (Error &ex)
		{
			cout << ex.what() << endl;
		}
		Sleep(1000);
		system("cls");
		map.showNowposMap();
	} while (choice!=3);
}

void Command::weapon(Player * player)
{

	int choice;
	do
	{
		cout << "欢迎来到武器店~" << endl;
		cout << "1.购买  2.离开" << endl;
		clearCin();
		cout << "选择:";
		cin >> choice;
		try {
			if (choice == 1) {
				cout << "物品清单" << endl;
				for (int i = 1; i <= SHOPLISTCOUNT; i++)
					cout << i << "." << SHOPLIST[i - 1] << "\t\t";
				cout << endl;
				cout << "请输入要购买的武器编号:";
				int number;
				clearCin();
				cin >> number;
				if (number > 0 && number <= SHOPLISTCOUNT) {
					cout << "请输入金额：";
					int  money;
					clearCin();
					cin >> money;
					if (money<0 || money>player->getMoney()) {
						ostringstream oss;
						oss << "您的钱不够了，你有 " << player->getMoney() << " ！";
						throw Error(oss.str());
					}
					else {
						//先生成一个空对象，然后赋值属性
						Equipment *weapon=new Equipment();
						weapon->initEquipment(number-1, money);
						//得到一个完整的装备,放入背包
						//判断是否放的进去
						Container *bag = player->getBag();
						if (!player->pushBag(weapon)) {
							cout << "你的背包满了，不可以购买。";
							char yOn;
							cout << "是否扔掉物品(Y/N):" ;
							clearCin();
							cin >> yOn;
							yOn=tolower(yOn);
							if (yOn == 'y') {
								cout << "你的背包物品：";
								bag->showGoods();
								if (bag->getNowSize()) {
									cout << "请选择丢弃的物品编号:";
									int number;
									clearCin();
									cin >> number;
									if (number > 0 && number < bag->getNowSize()) {
										Item *item = bag->getItemByIndex(number - 1);
										player->removeBag(item);
										cout << item->getId() << " 丢弃成功！" << endl;

									}
									else {
										throw Error("请检查输入的物品编号！");
									}
								
								}
								else {
									cout << "空" << endl;
								}
							}
						}
						else {
							cout << "购买成功！ " << endl;
							weapon->showInfo();
							player->setMoney(player->getMoney() - money);
						}

					}
				}
				else
					throw Error("请检查输入的武器编号！");
			}
			else if (choice != 2)
				throw Error("请输入正确的功能！");
		}
		catch (Error &ex) {
			cout << ex.what() << endl;
		}
		Sleep(1000);
		system("cls");
	} while (choice!=2);
}

void Command::hospital(Player * player)
{
	int choice;
	do
	{
	cout << "欢迎来到华佗神医馆，在这里你将可以恢复生命值，法力值!" << endl;
		cout << "1.恢复生命值 2.恢复法力值 3.离开" << endl;
		cout << "请输入功能:";
		cin >> choice;
		try
		{
			if (choice == 3) break;
			cout << "输入金额:";
			int money;
			cin >> money;
			if (money<0 || money>player->getMoney()) {
				ostringstream oss;
				oss << "请输入正确金额" << "你现在有 " << player->getMoney() << endl;
				throw Error(oss.str());
			}
			double proportion = money % 99 / 100.0;
			if (choice == 1) {
				player->setLife(static_cast<int>(ceil( player->getLife()*(1+proportion))));
				if (player->getLife() > MAXLIFE)
					player->setLife(MAXLIFE);
				player->setMoney(player->getMoney() - money);
			}
			else if (choice == 2) {
				player->setEnergy(static_cast<int>(ceil(player->getEnergy()*(1+proportion))));
				if (player->getEnergy() > MAXLIFE)
					player->setEnergy(MAXLIFE);
				player->setMoney(player->getMoney() - money);
			}
			else if (choice != 3)
				throw Error("请输入正确的选择！");
			cout << "你的状态：" << endl;;
			player->showInfo();
		}
		catch (Error &ex)
		{
			cout << ex.what() << endl;
		}
		Sleep(1000);
		system("cls");
	} while (choice!=3);
}

void Command::clearCin()
{
	//清除缓冲区的出错信息
	cin.clear();
	//清除缓冲区的无效残留信息

	// numeric_limits<streamsize>::max() 返回输入缓冲的大小。
	// ignore 函数在此将把输入流中的数据清空。
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	//system("pause");
	//system("cls");

}
