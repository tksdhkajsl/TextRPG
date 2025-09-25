#include "Player.h"
#include "Map.h"
#include "Game.h"
#include <map>
#include <iostream>
#include <algorithm>


void Player::ShowStatus() const
{
	printf("=======================\n");
	printf("      << %s Status >>\n", this->Name.c_str());
	printf("=======================\n");
	printf("체력 (Health):   %d / %d\n", this->Health, this->MaxHP);
	printf("공격력 (Damage): %d\n", this->Damage);
	printf("방어력 (Defense):%d\n", this->Defense);
	printf("소지금 (Gold):   %d G\n", this->Gold);
	printf("-----------------------\n");
}

void Player::RecoverHealth(int InHP)
{
	Health += InHP;
	if (Health > MaxHP)
	{
		Health = MaxHP;
	}
}

// --- 스킬 구현 ---

void Warrior::UseSkill(Actor& Target)
{
	printf("\n전사가 [강타] 스킬을 사용합니다!\n");
	int SkillDamage = static_cast<int>(Damage * 2.0f); // 기본 공격력의 2배 데미지
	Target.TakeDamage(SkillDamage);

	printf("%s에게 %d의 강력한 데미지를 입혔다!\n", Target.GetName().c_str(), std::max(1, SkillDamage - Target.Defense));
	CurrentSkillCooldown = SkillCooldown; // 스킬 사용 후 쿨타임 적용
}

void Thief::UseSkill(Actor& Target)
{
	printf("\n도적이 [이중 공격] 스킬을 사용합니다! 두 번 빠르게 공격합니다.\n");
	int SkillDamage = static_cast<int>(Damage * 0.8f); // 한 타당 기본 공격력의 80% 데미지

	// 첫 번째 공격
	Target.TakeDamage(SkillDamage);
	printf("첫 번째 공격! %s에게 %d의 데미지!\n", Target.GetName().c_str(), std::max(1, SkillDamage - Target.Defense));

	if (!Target.IsDead()) // 첫 타에 죽지 않았다면 두 번째 공격
	{
		// 두 번째 공격
		Target.TakeDamage(SkillDamage);
		printf("두 번째 공격! %s에게 %d의 데미지!\n", Target.GetName().c_str(), std::max(1, SkillDamage - Target.Defense));
	}
	CurrentSkillCooldown = SkillCooldown;
}

void Mage::UseSkill(Actor& Target)
{
	printf("\n마법사가 [화염구] 스킬을 시전합니다! 대상의 방어력을 일부 무시합니다.\n");
	int OriginalDefense = Target.Defense;
	Target.Defense /= 2; // 대상의 방어력을 일시적으로 절반으로 만듦
	int SkillDamage = static_cast<int>(Damage * 1.5f); // 기본 공격력의 1.5배 데미지

	Target.TakeDamage(SkillDamage);
	printf("거대한 화염구가 %s를 덮쳐 %d의 데미지를 입혔다!\n", Target.GetName().c_str(), std::max(1, SkillDamage - Target.Defense));
	Target.Defense = OriginalDefense; // 대상의 방어력을 원상 복구
	CurrentSkillCooldown = SkillCooldown;
}