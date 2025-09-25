#pragma once
#include "Actor.h"
#include <iostream> 
#include <string>

class Player : public Actor
{
public:
	void ShowStatus() const override;
	void RecoverHealth(int InHP);

public:
	int Amor = 0;
	int Weapon = 0;
};

class Warrior : public Player
{
public:
	Warrior()
	{
		Name = "전사";
		Health = 500;
		Damage = 20;
		Defense = 15;
		MaxHP = 500;
		SkillCooldown = 3; // 강타 쿨타임: 3턴
	}
	// 전사의 스킬 강타
	void UseSkill(Actor& Target) override;
};

class Thief : public Player
{
public:
	Thief()
	{
		Name = "도적";
		Health = 350;
		Damage = 35;
		Defense = 5;
		MaxHP = 350;
		SkillCooldown = 4; // 이중 공격 쿨타임: 4턴
	}
	// 도적의 스킬 이중 공격
	void UseSkill(Actor& Target) override;
};

class Mage : public Player
{
public:
	Mage()
	{
		Name = "마법사";
		Health = 200;
		Damage = 40;
		Defense = 0;
		MaxHP = 200;
		SkillCooldown = 4; // 화염구 쿨타임: 4턴
	}
	// 마법사의 스킬 화염구
	void UseSkill(Actor& Target) override;
};