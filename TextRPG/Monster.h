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

//������, ����� ���� ���Ͷ� ��ų ����
class Slime : public Monster
{
public:
	Slime() : Monster(SLIME)
	{
		Name = "������";
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
		Name = "���";
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
		Name = "��ũ";
		Health = 150;
		Damage = 20;
		Defense = 10;
		Gold = 130;
		SkillCooldown = 4; // ��ų ��Ÿ�� ����
	}
	// ��ũ�� ��ų "�г��� �ϰ�"
	void UseSkill(Actor& Target) override;
};

class Zombie : public Monster
{
public:
	Zombie() : Monster(ZOMBIE)
	{
		Name = "����";
		Health = 170;
		Damage = 25;
		Defense = 2;
		Gold = 125;
		SkillCooldown = 4;
	}
	// ������ ��ų "����"
	void UseSkill(Actor& Target) override;
};

class Ghost : public Monster
{
public:
	Ghost() : Monster(GHOST)
	{
		Name = "����";
		Health = 100;
		Damage = 30;
		Defense = 0;
		Gold = 140;
		SkillCooldown = 3;
	}
	// ������ ��ų "���"
	void UseSkill(Actor& Target) override;
};

class Gargoyle : public Monster
{
public:
	Gargoyle() : Monster(GARGOYLE)
	{
		Name = "������";
		Health = 200;
		Damage = 35;
		Defense = 20;
		Gold = 300;
		SkillCooldown = 5;
	}
	// �������� ��ų "���ָ� ��Ÿ"
	void UseSkill(Actor& Target) override;
};