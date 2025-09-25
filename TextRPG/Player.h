#pragma once
#include "Actor.h"
#include "Item.h"
#include <iostream> 
#include <string>

class Player : public Actor
{
public:
	void ShowStatus() const override;
	void RecoverHealth(int InHP);
	void EquipItem(const ItemInfo& InItem);
public:
	int Armor = 0;
	int Weapon = 0;

	int BaseATT = 0;
	int BaseDEF = 0;
};

class Warrior : public Player
{
public:
	Warrior()
	{
		Name = "전사";
		Health = 500;
		MaxHP = 500;
		BaseATT = 20;
		BaseDEF = 15;
		Damage = BaseATT;
		Defense = BaseDEF;
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
		BaseATT = 35;
		BaseDEF = 5;
		Damage = BaseATT;
		Defense = BaseDEF;
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
		BaseATT = 40;
		BaseDEF = 0;
		Damage = BaseATT;
		Defense = BaseDEF;
		MaxHP = 200;
		SkillCooldown = 4; // 화염구 쿨타임: 4턴
	}
	// 마법사의 스킬 화염구
	void UseSkill(Actor& Target) override;
};