#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Attackable.h"
#include "Player.h"
#include "Container.h"
#include <string>
class Player :public Attackable
{
public:
	int getMiss()const;
	void setMiss(int miss);
	int getMoveSpeed()const;
	int getEnergy()const;
	void setEnergy(int energy);
	void setMoveSpeed(int moveSpeed);
	void showInfo()const;//查看人物属性
	void showBag();//查看背包
	bool pushBag(Item *item);//放入物品
	void removeBag(Item *item);//取出物品
	int getSkillPower()const;//返回技能加成
	int getSkillComsume()const; //返回技能消耗
	void initRevive(int life, int energy);//战斗致死，回到战斗前状态。
	virtual void setExp(int exp); //设置经验并且更新等级
	int getNowPos() const;
	void setNowPos(int x);
	//单例模式
	static Player *creatPlayer(std::string name, int pos_x, int pos_y, int life,
		int power, int exp, int protectPower,
		int level, int money, int energy, int miss,
		int moveSpeed,int nowPos, Container &bag);
	static void deletePlayer();
	Container *getBag()const;//获取背包

private:
	int miss;//闪避值
	int moveSpeed;//移速
	int energy;//法力值
	Container &bag;
	static int skillList[10];//技能列表
	static int skillComsume[10];//使用技能的消耗蓝
	static int rankExp[10];//记录升级所需经验，十级满级

	int nowPos;  //人物当前位置
	//单例模式
	static Player *instance;
	Player(std::string name, int pos_x, int pos_y, int life,
		int power, int exp, int protectPower,
		int level, int money, int energy, int miss,
		int moveSpeed, int  nowPos,Container &bag);
	class Release
	{
	public:
		~Release();
	};
	static Release  release;
	virtual ~Player();

};
#endif // !__PLAYER_H__
