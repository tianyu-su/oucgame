#include "Battle.h"
#include "ConstTable.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "ConstTable.h"
using namespace std;

Battle::Battle(Player & player) :player(player) {
	unsigned seed = static_cast<unsigned>(time(NULL));
	srand(seed);
	if (player.getNowPos() == 3)
	{
		//生成BOSS
		Equipment *equipment = new Equipment();
		equipment->initEquipment(rand() % SHOPLISTCOUNT, rand() % 20 + 1);
		monster = new Monster(equipment);
		monster->setName("BOSS: DRAGON!");
		monster->setLife(DRAGONLIFE);
		monster->setPower(DRAGONPOWER);
		monster->setProtectPower(DRAGONPROTECTPOWER);
		monster->setMoney(DRAGONMONEY);
		monster->setExp(DRAGONEXP);
		monster->setLevel(DRAGONLEVEL);
		this->backupPlayerLife = player.getLife();
		this->backupPlayerEnergy = player.getEnergy();
	}
	else
	{
		//创建怪物掉落物品
		Equipment *equipment = new Equipment();
		equipment->initEquipment(rand() % SHOPLISTCOUNT, rand() % 20 + 1);
		//随机生成怪物
		monster = new Monster(equipment);
		monster->setName(MONSTERLIST[rand() % MONSTERLISTCOUNT]);
		monster->setLife(static_cast<int> (INITMONSTERLIFE*(1 + player.getLevel()*0.1)));
		monster->setPower(static_cast<int> (INITMONSTERPOWER*(1 + player.getLevel()*0.1)));
		monster->setProtectPower(static_cast<int> (INITMONSTERPOWER*(1 + player.getLevel()*0.1)));
		monster->setMoney(static_cast<int> (INITMONSTERMONEY*(1 + player.getLevel()*0.1)));
		monster->setExp(static_cast<int> (INITMONSTEREXP*(1 + player.getLevel()*0.1)));
		monster->setLevel(player.getLevel() - 1);
		this->backupPlayerLife = player.getLife();
		this->backupPlayerEnergy = player.getEnergy();
	}
}

Battle::~Battle()
{
	if (monster != NULL)
		delete monster;
}

void Battle::beginBattle()
{
	unsigned seed = static_cast<unsigned>(time(NULL));
	int nowAttacker = PLAYER;
	//初始化随机种子
	srand(seed);
	showAttrPanel();
	cout << monster->getName() << ":我要开始攻击了！" << endl;
	cout << player.getName() << ":come on!" << endl;
	cout << endl;
	while (!judegeEnd()) {
		if (nowAttacker == PLAYER) {
			cout << "请选择攻击方式:1.技能  2.普通攻击" << endl;
			cout << "请输入选择:";
			int attackType = 0;
			int totalPower = player.getPower();
			cin >> attackType;
			if (attackType == 1) {
				if (player.getEnergy() < player.getSkillComsume())
				{
					cout << "MP不足无法使用技能，自动转为普通攻击" << endl;
					Sleep(1000);
				}
				else {
					int playerLevel = player.getLevel();
					if (playerLevel > 8)
					{
						cout << "你使用了技能 百步穿杨";
						Sleep(1000);
					}
					if (playerLevel > 5)
					{
						cout << "你使用了技能 小李飞刀";
						Sleep(1000);
					}
					if (playerLevel > 2)
					{
						cout << "你使用了技能 牛刀小试";
						Sleep(1000);
					}
					totalPower += player.getSkillPower();
					player.setEnergy(player.getEnergy() - player.getSkillComsume());
				}
			}
			int injuryValue = totalPower - monster->getProtectPower();
			//如果防御太高，还是需要造成伤害否则游戏不能结束
			if (injuryValue <= 0)
				injuryValue =static_cast<int>(ceil(player.getPower()*0.6));
			monster->setLife(monster->getLife() - injuryValue);
			cout << player.getName() << "对" << monster->getName() << "造成 " << injuryValue << " 点伤害！" << endl;
			Sleep(1000);
		}
		else
		{
			bool isMiss = false;
			//随机闪避值和人物闪避值比较，随机大闪避失败,左闭右开
			isMiss = player.getMiss() > (rand() % (MISSUPPER - MISSLOWER)) + MISSLOWER;
			if (!isMiss) {
				int injuryValue = monster->getPower() - player.getProtectPower();
				//如果防御太高，还是需要造成伤害否则游戏不能结束
				if (injuryValue <= 0)
					injuryValue =static_cast<int>(ceil(monster->getPower()*0.6));
				player.setLife(player.getLife() - injuryValue);
				cout << monster->getName() << "对" << player.getName() << "造成 " << injuryValue << " 点伤害！" << endl;
				Sleep(1000);
			}
			else
			{
				cout <<"你以矫健的身法成功闪避怪兽的攻击！" << endl;
				Sleep(1000);
			}

		}
		//转换攻击者
		nowAttacker = -nowAttacker;
		showAttrPanel();
	}
}

int Battle::judegeEnd()
{
	if (player.getLife()<=0)
		return -1;
	if (monster->getLife()<=0)
		return 1;
	return 0;
}

bool Battle::showResult()
{
	cout << "本次战斗结束！" << endl;
	if (judegeEnd() == 1) {
		player.setExp(player.getExp() + monster->getExp());
		player.setMoney(player.getMoney() + monster->getMoney());
		//复制一个装备，因为在退出战斗系统的时候MONSTER被析构，物品指针消失
		Equipment *backupEquipmet = new Equipment(*(monster->getItem()));
		player.pushBag(backupEquipmet);
		cout << "恭喜你获得胜利!" << endl;;
		cout << "获得：" << "经验：" << monster->getExp() <<
			"\t金钱:" << monster->getMoney() <<
			"\t物品：" << monster->getItem()->getId() << endl;
		Sleep(1500);
		//回到打怪之前上一幅图，并且上一幅图怪物消失
		return true;
	}
	else {
		cout << "你在战斗中阵亡，将在新手村复活！" << endl;
		Sleep(1000);
		player.initRevive(backupPlayerLife, backupPlayerEnergy);
		//更改地图并且修改人物坐标
		return false;
	}
}

void Battle::showAttrPanel()
{
	if (monster->getLife() < 0)
		monster->setLife(0);
	if (player.getLife() < 0)
		player.setLife(0);
	system("cls");
	cout << monster->getName() << ":" << endl;
	monster->showInfo();
	cout << endl;
	cout << player.getName() << ":" << endl;
	player.showInfo();
	cout << endl;
}
