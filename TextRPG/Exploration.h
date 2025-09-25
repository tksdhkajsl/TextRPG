#pragma once
#include "Monster.h"
#include "Map.h"      
#include "Player.h"

class Exploration
{
public:
	Exploration();
	~Exploration();

	void CreateMonster(Dungeon InDunType);
	void Move(Dungeon InDunType);
	void StartBattle(Player* InPlayer);

private:
	Monster* InMonster;
	int MoveCount = 0;
};

