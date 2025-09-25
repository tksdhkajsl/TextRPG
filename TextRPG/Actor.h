#pragma once
#include<string>

class Actor
{
public:
	// �����ڿ��� ��Ÿ�� �ʱ�ȭ
	Actor() : SkillCooldown(0), CurrentSkillCooldown(0) {}
	virtual ~Actor() {} // ���� �Ҹ��� �߰�

	virtual void ShowStatus() const {};

	// ��ų ����� ���� ���� �Լ� (�⺻�����δ� �ƹ��͵� �� ��)
	// Target: ��ų�� ����� ���
	virtual void UseSkill(Actor& Target) {}

	// ���� ���� ������ ��Ÿ���� ���ҽ�Ű�� �Լ�
	void TickCooldown()
	{
		if (CurrentSkillCooldown > 0)
		{
			CurrentSkillCooldown--;
		}
	}

	bool IsSkillReady() const { return CurrentSkillCooldown == 0; }
	bool IsDead() { return Health <= 0; }
	std::string GetName() const { return Name; }
	int GetHealth() const { return Health; }
	void TakeDamage(int InDamage);

	int Gold = 0;
	int Damage = 10;
	int Defense = 0;

protected:
	int MaxHP = 0;
	int Health = 100;
	std::string Name = "\0";

	int SkillCooldown; // ��ų�� �� ��Ÿ�� (�� ��)
	int CurrentSkillCooldown; // ���� ���� ��Ÿ��
};