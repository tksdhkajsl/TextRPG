#include "Actor.h"
#include <algorithm> 
#include <random>


int Actor::TakeDamage(int InDamage)
{
    // ������ ����� ���� ������ ��� (�ּ� 1�� �������� �޵��� ��)
    int FinalDamage = std::max(1, InDamage - Defense);
    
    //ũ��Ƽ�� Ȯ��
    int CriticalATT = rand() % 10;
    if (CriticalATT == 2 || CriticalATT == 4)
    {
        printf("ũ��Ƽ�� Hit!!!\n");
        FinalDamage *= 2;
    }
    Health -= FinalDamage;

    // ü���� 0 �̸����� �������� �ʵ��� ����
    if (Health < 0)
    {
        Health = 0;
    }

    //���� ���� ������ �� ����
    return FinalDamage;
}