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
		Name = "����";
		Health = 500;
		Damage = 20;
		Defense = 15;
		MaxHP = 500;
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
		Damage = 35;
		Defense = 5;
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
		Damage = 40;
		Defense = 0;
		MaxHP = 200;
		SkillCooldown = 4; // ȭ���� ��Ÿ��: 4��
	}
	// �������� ��ų ȭ����
	void UseSkill(Actor& Target) override;
};