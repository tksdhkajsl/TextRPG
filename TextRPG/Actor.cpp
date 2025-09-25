#include "Actor.h"
#include <algorithm> 
#include <random>


int Actor::TakeDamage(int InDamage)
{
    // 방어력을 고려한 최종 데미지 계산 (최소 1의 데미지는 받도록 함)
    int FinalDamage = std::max(1, InDamage - Defense);
    
    //크리티컬 확률
    int CriticalATT = rand() % 10;
    if (CriticalATT == 2 || CriticalATT == 4)
    {
        printf("크리티컬 Hit!!!\n");
        FinalDamage *= 2;
    }
    Health -= FinalDamage;

    // 체력이 0 미만으로 내려가지 않도록 보정
    if (Health < 0)
    {
        Health = 0;
    }

    //최종 입힌 데미지 값 전달
    return FinalDamage;
}