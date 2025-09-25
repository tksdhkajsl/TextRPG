#pragma once
#include "Actor.h"


enum MonsterType
{
	SLIME,
	GOBLIN,
	ORC,
	ZOMBIE,
	GHOST,
	GARGOYLE
};

class Monster : public Actor
{
public:
	Monster(int InMonsterType) {};
	void ShowStatus() const override;
};

class Slime : public Monster
{
public:
	Slime() : Monster(SLIME)
	{
		Name = "슬라임";
		Health = 50;
		Damage = 10; 
		Defense = 0;
		Gold = 10;
	}
};

class Goblin : public Monster
{
public:
	Goblin() : Monster(GOBLIN)
	{
		Name = "고블린";
		Health = 80;
		Damage = 15;
		Defense = 5;
		Gold = 20;
	}
};

class Orc : public Monster
{
public:
	Orc() : Monster(ORC)
	{
		Name = "오크";
		Health = 150;
		Damage = 20;
		Defense = 10;
		Gold = 30;
		SkillCooldown = 4; // 스킬 쿨타임 설정
	}
	// 오크의 스킬 "분노의 일격"
	void UseSkill(Actor& Target) override;
};

class Zombie : public Monster
{
public:
	Zombie() : Monster(ZOMBIE)
	{
		Name = "좀비";
		Health = 110;
		Damage = 25;
		Defense = 2;
		Gold = 25;
	}
};

class Ghost : public Monster
{
public:
	Ghost() : Monster(GHOST)
	{
		Name = "유령";
		Health = 80;
		Damage = 30;
		Defense = 0;
		Gold = 40;
	}
};

class Gargoyle : public Monster
{
public:
	Gargoyle() : Monster(GARGOYLE)
	{
		Name = "가고일";
		Health = 200;
		Damage = 35;
		Defense = 20;
		Gold = 100;
	}
};