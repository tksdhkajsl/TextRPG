#include "Player.h"
#include "Map.h"
#include "Game.h"
#include <map>
#include <iostream>
#include <algorithm>


void Player::ShowStatus() const
{
	printf("=======================\n");
	printf("<< %s ���� (Status) >>\n", this->Name.c_str());
	printf("=======================\n");
	printf("ü�� (HP):   %d / %d\n", this->Health, this->MaxHP);
	printf("���ݷ� (ATT): %d\n", this->Damage);
	printf("���� (DEF): %d\n", this->Defense);
	printf("������ (Gold):   %d G\n", this->Gold);
	printf("-----------------------\n");
}
void Player::EquipItem(const ItemInfo& InItem)
{
	
	if (InItem.Type == ItemType::WEAPON)
	{
		printf("���� [%s](��)�� �����߽��ϴ�.\n", InItem.Name.c_str());
		Weapon = InItem.Attack; // ���� ���ݷ� �߰�
	}
	else if (InItem.Type == ItemType::ARMOR)
	{
		printf("�� [%s](��)�� �����߽��ϴ�.\n", InItem.Name.c_str());
		Armor = InItem.Defense; // �� ���� �߰�
	}

	// ��� ��ü �� ���� �ɷ�ġ(Damage, Defense)�� �ٽ� ���
	// ��� �� �� ���� ������ ���� �־����� �ߺ� ���� �Ұ���
	Damage =  BaseATT + Weapon;
	Defense = BaseDEF + Armor;
}


void Player::RecoverHealth(int InHP)
{
	Health += InHP;
	if (Health > MaxHP)
	{
		Health = MaxHP;
	}
}

// --- ��ų ���� ---

void Warrior::UseSkill(Actor& Target)
{
	printf("\n���簡 [��Ÿ] ��ų�� ����մϴ�!\n");
	int SkillDamage = static_cast<int>(Damage * 2.0f); // �⺻ ���ݷ��� 2�� ������
	int TargetDamage = Target.TakeDamage(SkillDamage);

	printf("%s���� %d�� ������ �������� ������!\n", Target.GetName().c_str(), TargetDamage);
	CurrentSkillCooldown = SkillCooldown; // ��ų ��� �� ��Ÿ�� ����
}

void Thief::UseSkill(Actor& Target)
{
	printf("\n������ [���� ����] ��ų�� ����մϴ�! �� �� ������ �����մϴ�.\n");
	int SkillDamage = static_cast<int>(Damage * 0.8f); // �� Ÿ�� �⺻ ���ݷ��� 80% ������

	// ù ��° ����
	int TargetDamage = Target.TakeDamage(SkillDamage);
	printf("ù ��° ����! %s���� %d�� ������!\n", Target.GetName().c_str(), TargetDamage);

	// ù Ÿ�� ���� ����� �� �־ ���ǹ����� ���� Ȯ��
	if (!Target.IsDead()) 
	{
		// �� ��° ����
		TargetDamage = Target.TakeDamage(SkillDamage);
		printf("�� ��° ����! %s���� %d�� ������!\n", Target.GetName().c_str(), TargetDamage);
	}
	CurrentSkillCooldown = SkillCooldown;
}

void Mage::UseSkill(Actor& Target)
{
	printf("\n�����簡 [ȭ����] ��ų�� �����մϴ�! ����� ������ �Ϻ� �����մϴ�.\n");
	int OriginalDefense = Target.Defense;
	Target.Defense /= 2; // ����� ������ �Ͻ������� �������� ����
	int SkillDamage = static_cast<int>(Damage * 1.5f); // �⺻ ���ݷ��� 1.5�� ������

	int TargetDamage = Target.TakeDamage(SkillDamage);
	printf("�Ŵ��� ȭ������ %s�� ���� %d�� �������� ������!\n", Target.GetName().c_str(), TargetDamage);
	Target.Defense = OriginalDefense; // ����� ������ ���� ����
	CurrentSkillCooldown = SkillCooldown;
}