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

//슬라임, 고블린은 저급 몬스터라 스킬 없음
class Slime : public Monster
{
public:
	Slime() : Monster(SLIME)
	{
		Name = "슬라임";
		Health = 50;
		Damage = 10; 
		Defense = 0;
		Gold = 30;
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
		Gold = 50;
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
		Gold = 130;
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
		Health = 170;
		Damage = 25;
		Defense = 2;
		Gold = 125;
		SkillCooldown = 4;
	}
	// 좀비의 스킬 "물기"
	void UseSkill(Actor& Target) override;
};

class Ghost : public Monster
{
public:
	Ghost() : Monster(GHOST)
	{
		Name = "유령";
		Health = 100;
		Damage = 30;
		Defense = 0;
		Gold = 140;
		SkillCooldown = 3;
	}
	// 유령의 스킬 "비명"
	void UseSkill(Actor& Target) override;
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
		Gold = 300;
		SkillCooldown = 5;
	}
	// 가고일의 스킬 "돌주먹 강타"
	void UseSkill(Actor& Target) override;
};