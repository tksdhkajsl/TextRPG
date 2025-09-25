#pragma once
#include<string>

class Actor
{
public:
	// 생성자에서 쿨타임 초기화
	Actor() : SkillCooldown(0), CurrentSkillCooldown(0) {}
	virtual ~Actor() {} // 가상 소멸자 추가

	virtual void ShowStatus() const {};

	// 스킬 사용을 위한 가상 함수 (기본적으로는 아무것도 안 함)
	// Target: 스킬을 사용할 대상
	virtual void UseSkill(Actor& Target) {}

	// 턴이 지날 때마다 쿨타임을 감소시키는 함수
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

	int SkillCooldown; // 스킬의 총 쿨타임 (턴 수)
	int CurrentSkillCooldown; // 현재 남은 쿨타임
};