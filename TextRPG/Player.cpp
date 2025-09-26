#include "Player.h"
#include "Map.h"
#include "Game.h"
#include <map>
#include <iostream>
#include <algorithm>


void Player::ShowStatus() const
{
	printf("=======================\n");
	printf("<< %s 상태 (Status) >>\n", this->Name.c_str());
	printf("=======================\n");
	printf("체력 (HP):   %d / %d\n", this->Health, this->MaxHP);
	printf("공격력 (ATT): %d\n", this->Damage);
	printf("방어력 (DEF): %d\n", this->Defense);
	printf("소지금 (Gold):   %d G\n", this->Gold);
	printf("-----------------------\n");
}
void Player::EquipItem(const ItemInfo& InItem)
{
	
	if (InItem.Type == ItemType::WEAPON)
	{
		printf("무기 [%s](을)를 장착했습니다.\n", InItem.Name.c_str());
		Weapon = InItem.Attack; // 무기 공격력 추가
	}
	else if (InItem.Type == ItemType::ARMOR)
	{
		printf("방어구 [%s](을)를 장착했습니다.\n", InItem.Name.c_str());
		Armor = InItem.Defense; // 방어구 방어력 추가
	}

	// 장비 교체 후 최종 능력치(Damage, Defense)를 다시 계산
	// 장비를 살 때 마다 변수에 집어 넣어져서 중복 착용 불가능
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

// --- 스킬 구현 ---

void Warrior::UseSkill(Actor& Target)
{
	printf("\n전사가 [강타] 스킬을 사용합니다!\n");
	int SkillDamage = static_cast<int>(Damage * 2.0f); // 기본 공격력의 2배 데미지
	int TargetDamage = Target.TakeDamage(SkillDamage);

	printf("%s에게 %d의 강력한 데미지를 입혔다!\n", Target.GetName().c_str(), TargetDamage);
	CurrentSkillCooldown = SkillCooldown; // 스킬 사용 후 쿨타임 적용
}

void Thief::UseSkill(Actor& Target)
{
	printf("\n도적이 [이중 공격] 스킬을 사용합니다! 두 번 빠르게 공격합니다.\n");
	int SkillDamage = static_cast<int>(Damage * 0.8f); // 한 타당 기본 공격력의 80% 데미지

	// 첫 번째 공격
	int TargetDamage = Target.TakeDamage(SkillDamage);
	printf("첫 번째 공격! %s에게 %d의 데미지!\n", Target.GetName().c_str(), TargetDamage);

	// 첫 타에 몬스터 사망할 수 있어서 조건문으로 생존 확인
	if (!Target.IsDead()) 
	{
		// 두 번째 공격
		TargetDamage = Target.TakeDamage(SkillDamage);
		printf("두 번째 공격! %s에게 %d의 데미지!\n", Target.GetName().c_str(), TargetDamage);
	}
	CurrentSkillCooldown = SkillCooldown;
}

void Mage::UseSkill(Actor& Target)
{
	printf("\n마법사가 [화염구] 스킬을 시전합니다! 대상의 방어력을 일부 무시합니다.\n");
	int OriginalDefense = Target.Defense;
	Target.Defense /= 2; // 대상의 방어력을 일시적으로 절반으로 만듦
	int SkillDamage = static_cast<int>(Damage * 1.5f); // 기본 공격력의 1.5배 데미지

	int TargetDamage = Target.TakeDamage(SkillDamage);
	printf("거대한 화염구가 %s를 덮쳐 %d의 데미지를 입혔다!\n", Target.GetName().c_str(), TargetDamage);
	Target.Defense = OriginalDefense; // 대상의 방어력을 원상 복구
	CurrentSkillCooldown = SkillCooldown;
}