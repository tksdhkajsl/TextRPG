#include "Monster.h"
#include <cstdio>
#include <algorithm> 

void Monster::ShowStatus() const
{
	printf("=========================\n");
	printf("<< %s 상태 (Status) >>\n", Name.c_str());
	printf("=========================\n");

	printf("체력 (HP):   %d\n", Health);
	printf("공격력 (ATT): %d\n", Damage);
	printf("방어력 (DEF):%d\n", Defense);
}

// 몬스터 스킬 구현
void Orc::UseSkill(Actor& Target)
{
	printf("\n%s(이)가 분노하며 [분노의 일격](을)를 사용합니다!\n", Name.c_str());
	int SkillDamage = static_cast<int>(Damage * 1.8f); // 기본 공격력의 1.8배 데미지
	int TargetDamage = Target.TakeDamage(SkillDamage);
	printf("%s에게 %d의 큰 데미지를 입혔다!\n", Target.GetName().c_str(), TargetDamage);
	CurrentSkillCooldown = SkillCooldown;// 스킬 사용 후 쿨타임 적용
}

void Zombie::UseSkill(Actor& Target)
{
	printf("\n좀비(이)가 [물기] 스킬(을)를 사용합니다!\n");
	int SkillDamage = static_cast<int>(Damage * 0.5f); // 한 타당 기본 공격력의 50% 데미지

	int Random = rand() % 3;
	// 첫 번째 공격
	int TargetDamage = Target.TakeDamage(SkillDamage);
	printf("첫 번째 물기 공격! %s에게 %d의 데미지!\n", Target.GetName().c_str(), TargetDamage);

	// 조건문으로 생존 확인
	if (!Target.IsDead())
	{
		for (int i = 0; i < 2; i++)
		{
			Random;
			if (Random == 0) //30% 확률로 공격 성공여부
			{
			// N 번째 공격
				TargetDamage = Target.TakeDamage(SkillDamage);
				printf("%d 번째 물기 공격! %s에게 %d의 데미지!\n", (i + 2), Target.GetName().c_str(), TargetDamage);
				if (Target.IsDead())// 생존 확인
				{
					break;
				}
			}
			else
			{
				printf("좀비가 %d 번째 물기 공격에 실패하였습니다.\n", (i + 2));
			}

		}
	}
	CurrentSkillCooldown = SkillCooldown;
}

void Ghost::UseSkill(Actor& Target)
{
	printf("\n유령(이)가 [비명] 스킬(을)를 사용합니다!\n");
	int SkillDamage = static_cast<int>(Damage * 1.3f); // 기본 공격력의 1.3배 데미지
	int TargetDamage = Target.TakeDamage(SkillDamage);

	printf("%s의 고막에 %d 데미지(을)를 입혔다!\n", Target.GetName().c_str(), TargetDamage);
	CurrentSkillCooldown = SkillCooldown; 
}

void Gargoyle::UseSkill(Actor& Target)
{
	printf("\n%s(이)가 [돌주먹 강타](을)를 사용합니다! 대상의 방어력을 무시합니다.\n", Name.c_str());
	int OriginalDefense = Target.Defense;
	Target.Defense = 0; // 대상의 방어력을 일시적으로 완전 무시
	int SkillDamage = static_cast<int>(Damage * 2.0f); // 기본 공격력의 2배 데미지

	int TargetDamage = Target.TakeDamage(SkillDamage);
	printf("묵직한 돌주먹(이)가 %s(을)를 덮쳐 %d의 데미지를 입혔다!\n", Target.GetName().c_str(), TargetDamage);
	Target.Defense = OriginalDefense; // 대상의 방어력을 원상 복구
	CurrentSkillCooldown = SkillCooldown;
}
