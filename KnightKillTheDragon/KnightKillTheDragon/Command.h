#pragma once
#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "Player.h"
#include "Container.h"
#include "Map.h"
class Command {
public:
	static void newGame();//ѡ������Ϸ
	static void newerCountry(Player *player, int (&backupMap)[MAPROW][MAPCOLUMN],Container *ware =NULL);//���ִ�
	static void wareshop(Map &map, Player *player);//���вֿ�Ի�
	static void weapon(Player *player);//����������Ի�
	static void hospital(Player *player);//����ҽ�ݶԻ�
	static void clearCin();//�����������Ϣ�Լ�������Ϣ

};
#endif // !__COMMAND_H__