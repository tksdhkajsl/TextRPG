#include "Actor.h"
#include <algorithm> // std::max�� ����ϱ� ���� �ʿ�


void Actor::TakeDamage(int InDamage)
{
    // ������ ����� ���� ������ ��� (�ּ� 1�� �������� �޵��� ��)
    int FinalDamage = std::max(1, InDamage - Defense);

    Health -= FinalDamage;

    // ü���� 0 �̸����� �������� �ʵ��� ����
    if (Health < 0)
    {
        Health = 0;
    }
}