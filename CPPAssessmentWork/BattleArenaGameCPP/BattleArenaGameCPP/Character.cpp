#include <iostream>
class Character
{
public:
	//parameters
	int maxHealth = 0;
	int currentHealth = 0;
	int minDamage = 0;
	int maxDamage = 0;
	std::string name;
	std::string type;
	int typeID = 0; //this will do the same as type just make it easier to work with
	//had to remove methods and move them to BattleArenaGameCPP.cpp kept getting bugs keeping them here and didn't have time to figure it out
};