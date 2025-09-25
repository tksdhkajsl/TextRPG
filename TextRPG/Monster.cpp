#include "Monster.h"
#include <cstdio>
#include <algorithm> // std::max 사용을 위해 추가

void Monster::ShowStatus() const
{
	printf("=======================\n");
	printf("      << %s Status >>\n", Name.c_str());
	printf("=======================\n");

	printf("체력 (Health):   %d\n", Health);
	printf("공격력 (Damage): %d\n", Damage);
	printf("방어력 (Defense):%d\n", Defense);
}

// Orc 스킬 구현
void Orc::UseSkill(Actor& Target)
{
	printf("\n%s(이)가 분노하며 [맹렬한 공격]을 사용합니다!\n", Name.c_str());
	int SkillDamage = static_cast<int>(Damage * 1.8f); // 기본 공격력의 1.8배 데미지
	Target.TakeDamage(SkillDamage);
	printf("%s에게 %d의 큰 데미지를 입혔다!\n", Target.GetName().c_str(), std::max(1, SkillDamage - Target.Defense));
	CurrentSkillCooldown = SkillCooldown;
}