#include "Player.h"
#include "Error.h"
#include <iostream>
using namespace std;
Player::Player(std::string name, int pos_x, int pos_y, int life, int power, int exp, int protectPower, int level, int money, int energy, int miss, int moveSpeed,int nowPos, Container & bag) :
	Attackable(name, pos_x, pos_y, life, power, exp, protectPower, level, money), bag(bag), energy(energy), miss(miss), moveSpeed(moveSpeed) ,nowPos(nowPos){}

Player::~Player()
{
	/*if (instance != NULL)
		delete instance;*/
}

int Player::getMiss()const
{
	return this->miss;
}

void Player::setMiss(int miss)
{
	this->miss = miss;
}

int Player::getMoveSpeed()const
{
	return this->moveSpeed;
}

int Player::getEnergy() const
{
	return this->energy;
}

void Player::setEnergy(int energy)
{
	this->energy = energy;
}

void Player::setMoveSpeed(int moveSpeed)
{
	this->moveSpeed = moveSpeed;
}

void Player::showInfo() const
{
	cout << "HP:" << getLife() << "\t\t" << "攻击力:" << getPower() << "\t" << "防御力:" << getProtectPower() << endl
		<< "MP:" << getEnergy() << "\t\t" << "等级:" << getLevel() << "\t\t" << "金钱:" <<  getMoney() << endl
		<< "EXP:" << getExp() << "\t\t" << "移速:" << getMoveSpeed() << "\t\t" << "闪避:" << getMiss()<<endl;

}

void Player::showBag()
{
	bag.showGoods();
	if (!bag.getNowSize())
		cout << "无" << endl;
}

int Player::getNowPos() const
{
	return nowPos;
}

bool Player::pushBag(Item *item)
{
	if(bag.push(item))
	{
		//修改属性
		Equipment *equipment= dynamic_cast<Equipment*>(item);
		if (equipment != NULL) {
			setPower(getPower() + equipment->getPower());
			setProtectPower(getProtectPower() + equipment->getProtectPower());
			setMoveSpeed(getMoveSpeed() + equipment->getMovePower());
		}
		else {
			throw Error("属性修改异常！");
		}
		return true;
	}
	else {
		return false;
	}
}

void Player::removeBag(Item * item)
{
	bag.remove(item);
	//修改属性
	Equipment *equipment = dynamic_cast<Equipment*>(item);
	if (equipment != NULL) {
		setPower(getPower() - equipment->getPower());
		setProtectPower(getProtectPower() - equipment->getProtectPower());
		setMoveSpeed(getMoveSpeed() - equipment->getMovePower());
	}
	else {
		throw Error("程序异常！");
	}

}

int Player::getSkillPower()const
{
	return skillList[getLevel()];
}

int Player::getSkillComsume() const
{
	return skillComsume[getLevel()];
}

void Player::initRevive(int life, int energy)
{
	this->setLife(life);
	this->setEnergy(energy);
}

void Player::setExp(int exp)
{
	if (exp + getExp() > rankExp[getLevel()]) {
		setLevel(getLevel() + 1);
		exp = exp + getExp() - rankExp[getLevel()]<0?
			(0-(exp + getExp() - rankExp[getLevel()])):(exp + getExp() - rankExp[getLevel()]);
	}
		Attackable::setExp(exp);
}


void Player::setNowPos(int x)
{
	nowPos = x;
}

Player * Player::creatPlayer(std::string name, int pos_x, int pos_y, int life, int power, int exp, int protectPower, int level, int money, int energy, int miss, int moveSpeed,int nowPos, Container & bag)
{
	if (instance != NULL)
		return instance;
	else
		return instance= new Player( name,  pos_x,  pos_y,  life,  power,  exp,  protectPower,  level,  money,  energy,  miss,  moveSpeed,nowPos, bag);
}

void Player::deletePlayer()
{
	if (Player::instance) {
		delete Player::instance;
		Player::instance = NULL;
	}
}

Container * Player::getBag() const
{
	return &bag;
}

int Player::skillList[10] = {3,3,3,6,6,6,6,9,9,9 };
int Player::skillComsume[10] = { 3,3,3,6,6,6,6,9,9,9 };
int Player::rankExp[10] = { 100,150,210,290,390,410,500,570,640,1<<30 };
Player* Player::instance = NULL;

Player::Release::~Release()
{
	if (Player::instance)
		delete Player::instance;
}
