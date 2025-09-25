#include "Actor.h"
#include <algorithm> // std::max를 사용하기 위해 필요


void Actor::TakeDamage(int InDamage)
{
    // 방어력을 고려한 최종 데미지 계산 (최소 1의 데미지는 받도록 함)
    int FinalDamage = std::max(1, InDamage - Defense);

    Health -= FinalDamage;

    // 체력이 0 미만으로 내려가지 않도록 보정
    if (Health < 0)
    {
        Health = 0;
    }
}