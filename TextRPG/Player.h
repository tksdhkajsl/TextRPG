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
		Name = "����";
		Health = 500;
		MaxHP = 500;
		BaseATT = 20;
		BaseDEF = 15;
		Damage = BaseATT;
		Defense = BaseDEF;
		SkillCooldown = 3; // ��Ÿ ��Ÿ��: 3��
	}
	// ������ ��ų ��Ÿ
	void UseSkill(Actor& Target) override;
};

class Thief : public Player
{
public:
	Thief()
	{
		Name = "����";
		Health = 350;
		BaseATT = 35;
		BaseDEF = 5;
		Damage = BaseATT;
		Defense = BaseDEF;
		MaxHP = 350;
		SkillCooldown = 4; // ���� ���� ��Ÿ��: 4��
	}
	// ������ ��ų ���� ����
	void UseSkill(Actor& Target) override;
};

class Mage : public Player
{
public:
	Mage()
	{
		Name = "������";
		Health = 200;
		BaseATT = 40;
		BaseDEF = 0;
		Damage = BaseATT;
		Defense = BaseDEF;
		MaxHP = 200;
		SkillCooldown = 4; // ȭ���� ��Ÿ��: 4��
	}
	// �������� ��ų ȭ����
	void UseSkill(Actor& Target) override;
};