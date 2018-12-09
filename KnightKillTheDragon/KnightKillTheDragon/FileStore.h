#ifndef FILESTORE_H
#define FILESTORE_H
#include "Map.h"
#include "Player.h"
struct PlayerAttr
{
	std::string name;
	int pos_x, pos_y;
	int life;
	int power;
	int exp;
	int protectPower;
	int level;
	int money;
	int energy;
	int miss;
	int moveSpeed;
	int nowPos;
};

struct AllDataSize
{
	unsigned int playerAttr, bag, ware, mapData;
};

class FileStore {
public:
	static void StoreGameToFile(Map& m);
	static Map * ReadGameFile();
};


#endif // !FILESTORE_H


