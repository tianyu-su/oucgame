#pragma once
#ifndef __CONSTTABLE_H__
#define __CONSTTABLE_H__

const int WALL = 0;
const int ROAD = 1;
const int DOOR = 2;
const int NPC = 4;
const int PLAYER = 1;
const int MONSTER = -1;
const int MISSLOWER = 1;
const int MISSUPPER = 200;
const int BORNX = 5;   //初始位置x
const int BORNY = 14;	//初始位置y
const int BORNLIFE = 120; //初始生命值
const int MAXLIFE = 250;//满生命值
const int BORNPOWER = 25;	//初始攻击力
const int BORNPROTECTPOWER = 8;	//初始防御力
const int BORNEXP = 0; //初始经验值
const int BORNLEVEL = 1; //初始等级
const int BORNMONEY = 100;	//初始金钱
const int BORNENERGY = 10; //初始法力值
const int MAXENERHY = 50;//满法力值
const int BORNMISS = 30; //初始闪避值
const int BORNSPEED = 1; //初始速度
const int MONSTERMAXNUM = 15;//地图最多怪物数量
const int SHOPLISTCOUNT = 6;//武器店最大数目
const std::string SHOPLIST[SHOPLISTCOUNT] = { "刀","剑","弓箭","铠甲","盾牌","鞋子" };//武器店东西
//const std::string SHOPLIST[SHOPLISTCOUNT] = { "DAO","JIAN","GONGJIAN","KAIJIA","DUNPAI","XIEZI" };//武器店东西
const int WAREHOUSE = 3;//地图中遇到仓库
const int WEAPONHOUSE = 4;//地图中遇到武器店
const int HOSPITAL = 5;//地图中遇到医院
const char PLAYERATTR = 't';//新手图，打怪图直接输入A打开人物属性
const char PLAYERBAG = 'b';//新手图，打怪图直接输入B打开人物背包
const char MAINMENUE = 'm';//新手图，打怪图直接输入M回到主界面，并且自动存档
const int MAPROW = 12;
const int MAPCOLUMN = 50;
const int KNIFEPOWER = 1;        //刀的攻击力参数
const int KNIFECONSUME = 1;      //刀的耐久参数
const int SWORDPOWER = 1;        //剑的攻击力参数
const int SWORDCONSUME = 1;      //剑的耐久参数
const int SHOECONSUME = 1;       //鞋的耐久参数
const int SHOEMOVEPOWER = 1;     //鞋的移动速度参数
const int BOWPOWER = 1;          //弓箭的攻击力参数
const int BOWCONSUME = 1;        //弓箭的耐久参数
const int STABPOWER = 1;         //铠甲的攻击力参数
const int STABCONSUME = 1;       //铠甲的耐久参数
const int STABPROTECTPOWER = 1;  //铠甲的防御力参数
const int SHIELDCONSUME = 1;     //盾的耐久参数
const int SHIELDPROTECTPOWER = 1;//盾的防御力参数
const int WARESHOPCAPACITY = 25;    //仓库大小
const int BAGCOUNTCAPACITY = 10;	//背包大小
const int MONSTERLISTCOUNT = 10;	//怪物种类数量
const std::string MONSTERLIST[MONSTERLISTCOUNT] = { "巴达兽","萌萌兽","亚古兽","艾克萨兽",
												"加布兽","亚伯兽" ,"傻狗兽" ,"太阳兽" ,
													"公公兽" ,"冰雪亚古兽"};	//怪物名称
const int INITMONSTERLIFE = 80;//最低等级的怪生命值，随着人物的等级提升怪物属性提升
const int INITMONSTERPOWER = 10;//最低等级的怪攻击力，随着人物的等级提升怪物属性提升
const int INITMONSTEREXP = 5;//最低等级的怪经验，随着人物的等级提升怪物属性提升
const int INITMONSTERMONEY = 10;//最低等级的怪金钱，随着人物的等级提升怪物属性提升
const int INITMONSTERKPROTECTPOWER = 6;//最低等级的怪防御力，随着人物的等级提升怪物属性提升
const int DRAGONLIFE = 1000;
const int DRAGONPOWER = 100;
const int DRAGONPROTECTPOWER = 100;
const int DRAGONMONEY = 100000;
const int DRAGONEXP = 1000;
const int DRAGONLEVEL = 100;
#endif // !__CONSTTABLE_H__
