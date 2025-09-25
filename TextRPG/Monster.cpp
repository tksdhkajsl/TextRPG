#include "Monster.h"
#include <cstdio>
#include <algorithm> // std::max ����� ���� �߰�

void Monster::ShowStatus() const
{
	printf("=======================\n");
	printf("      << %s Status >>\n", Name.c_str());
	printf("=======================\n");

	printf("ü�� (Health):   %d\n", Health);
	printf("���ݷ� (Damage): %d\n", Damage);
	printf("���� (Defense):%d\n", Defense);
}

// Orc ��ų ����
void Orc::UseSkill(Actor& Target)
{
	printf("\n%s(��)�� �г��ϸ� [�ͷ��� ����]�� ����մϴ�!\n", Name.c_str());
	int SkillDamage = static_cast<int>(Damage * 1.8f); // �⺻ ���ݷ��� 1.8�� ������
	Target.TakeDamage(SkillDamage);
	printf("%s���� %d�� ū �������� ������!\n", Target.GetName().c_str(), std::max(1, SkillDamage - Target.Defense));
	CurrentSkillCooldown = SkillCooldown;
}