#include "Monster.h"
#include <cstdio>
#include <algorithm> 

void Monster::ShowStatus() const
{
	printf("=========================\n");
	printf("<< %s ���� (Status) >>\n", Name.c_str());
	printf("=========================\n");

	printf("ü�� (HP):   %d\n", Health);
	printf("���ݷ� (ATT): %d\n", Damage);
	printf("���� (DEF):%d\n", Defense);
}

// ���� ��ų ����
void Orc::UseSkill(Actor& Target)
{
	printf("\n%s(��)�� �г��ϸ� [�г��� �ϰ�](��)�� ����մϴ�!\n", Name.c_str());
	int SkillDamage = static_cast<int>(Damage * 1.8f); // �⺻ ���ݷ��� 1.8�� ������
	int TargetDamage = Target.TakeDamage(SkillDamage);
	printf("%s���� %d�� ū �������� ������!\n", Target.GetName().c_str(), TargetDamage);
	CurrentSkillCooldown = SkillCooldown;// ��ų ��� �� ��Ÿ�� ����
}

void Zombie::UseSkill(Actor& Target)
{
	printf("\n����(��)�� [����] ��ų(��)�� ����մϴ�!\n");
	int SkillDamage = static_cast<int>(Damage * 0.5f); // �� Ÿ�� �⺻ ���ݷ��� 50% ������

	int Random = rand() % 3;
	// ù ��° ����
	int TargetDamage = Target.TakeDamage(SkillDamage);
	printf("ù ��° ���� ����! %s���� %d�� ������!\n", Target.GetName().c_str(), TargetDamage);

	// ���ǹ����� ���� Ȯ��
	if (!Target.IsDead())
	{
		for (int i = 0; i < 2; i++)
		{
			Random;
			if (Random == 0) //30% Ȯ���� ���� ��������
			{
			// N ��° ����
				TargetDamage = Target.TakeDamage(SkillDamage);
				printf("%d ��° ���� ����! %s���� %d�� ������!\n", (i + 2), Target.GetName().c_str(), TargetDamage);
				if (Target.IsDead())// ���� Ȯ��
				{
					break;
				}
			}
			else
			{
				printf("���� %d ��° ���� ���ݿ� �����Ͽ����ϴ�.\n", (i + 2));
			}

		}
	}
	CurrentSkillCooldown = SkillCooldown;
}

void Ghost::UseSkill(Actor& Target)
{
	printf("\n����(��)�� [���] ��ų(��)�� ����մϴ�!\n");
	int SkillDamage = static_cast<int>(Damage * 1.3f); // �⺻ ���ݷ��� 1.3�� ������
	int TargetDamage = Target.TakeDamage(SkillDamage);

	printf("%s�� ���� %d ������(��)�� ������!\n", Target.GetName().c_str(), TargetDamage);
	CurrentSkillCooldown = SkillCooldown; 
}

void Gargoyle::UseSkill(Actor& Target)
{
	printf("\n%s(��)�� [���ָ� ��Ÿ](��)�� ����մϴ�! ����� ������ �����մϴ�.\n", Name.c_str());
	int OriginalDefense = Target.Defense;
	Target.Defense = 0; // ����� ������ �Ͻ������� ���� ����
	int SkillDamage = static_cast<int>(Damage * 2.0f); // �⺻ ���ݷ��� 2�� ������

	int TargetDamage = Target.TakeDamage(SkillDamage);
	printf("������ ���ָ�(��)�� %s(��)�� ���� %d�� �������� ������!\n", Target.GetName().c_str(), TargetDamage);
	Target.Defense = OriginalDefense; // ����� ������ ���� ����
	CurrentSkillCooldown = SkillCooldown;
}
