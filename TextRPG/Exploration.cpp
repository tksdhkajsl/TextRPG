#include "Exploration.h"
#include <random>
#include <iostream>

Exploration::Exploration() : InMonster(nullptr)
{
}

Exploration::~Exploration()
{
    if (InMonster != nullptr)
        delete InMonster;
}


void Exploration::CreateMonster(Dungeon InDunType)
{
    int random = 0;
    if (InMonster != nullptr)
    {
        delete InMonster;
        InMonster = nullptr;
    }

    switch (InDunType)
    {
    case Dungeon::Forest:
    {
        random = rand() % 3;
        if (random == 0)
        {
            InMonster = new Slime();
        }
        else if (random == 1)
        {
            InMonster = new Goblin();
        }
        else
        {
            InMonster = new Orc();
        }
    }
    break;
    case Dungeon::Cemetery:
    {
        random = rand() % 2;
        if (random == 0)
        {
            InMonster = new Zombie();
        }
        else
        {
            InMonster = new Ghost();
        }
    }
    break;
    case Dungeon::Top:
        random = rand() % 5;
        if (random == 0)
        {
            InMonster = new Goblin();
        }
        else if (random == 1)
        {
            InMonster = new Orc();
        }
        else if (random == 2)
        {
            InMonster = new Zombie();
        }
        else if (random == 3)
        {
            InMonster = new Ghost();
        }
        else
        {
        InMonster = new Gargoyle();
        }
        break;
    }

    if (InMonster != nullptr)
    {
        
        printf("\n[%s](이)가 나타났다!\n", InMonster->GetName().c_str());
    }
}


void Exploration::Move(Dungeon InDunType)
{
    MoveCount++;
    printf("앞으로 이동하여 %d 칸 만큼 전진했습니다.\n", MoveCount);
}


void Exploration::StartBattle(Player* InPlayer)
{
    while (true)
    {
        printf("\n--- [%s] ---\n", InPlayer->GetName().c_str());
        printf("체력 (HP): %d\n", InPlayer->GetHP());
        printf("공격력 (ATT): %d\n", InPlayer->GetATT());
        printf("방어력 (DEF): %d\n", InPlayer->GetDEF());
        printf("--- [%s] ---\n", InMonster->GetName().c_str());
        printf("체력 (HP): %d\n", InMonster->GetHP());
        printf("공격력 (ATT): %d\n", InMonster->GetATT());
        printf("방어력 (DEF): %d\n", InMonster->GetDEF());

        printf("\n[1. 공격 2. 스킬]\n>> ");
        int choice;
        std::cin >> choice;

        if (choice == 1) // 공격
        {
           
            printf("\n플레이어의 공격!\n");
            int InDamage = InMonster->TakeDamage(InPlayer->Damage);
            printf("%s에게 %d의 데미지를 입혔다!\n", InMonster->GetName().c_str(), InDamage);
        }
        else if (choice == 2) // 스킬
        {
            if (InPlayer->IsSkillReady())
            {
                InPlayer->UseSkill(*InMonster);
            }
            else
            {
                printf("\n스킬을 아직 사용할 수 없습니다! (쿨타임 남음)\n");
                continue; // 행동 선택으로 다시 돌아감
            }
        }        
        else
        {
            printf("잘못된 입력입니다.\n");
            continue;
        }

        // 몬스터 사망 체크
        if (InMonster->IsDead())
        {
            printf("\n%s를 물리쳤다!\n", InMonster->GetName().c_str());
            InPlayer->Gold += InMonster->Gold;
            printf("%d 골드를 획득했다!\n", InMonster->Gold);
            delete InMonster;
            InMonster = nullptr;
            return;
        }

        // 몬스터의 턴
        // 30% 확률로 스킬이 준비되었다면 스킬 사용
        if (InMonster->IsSkillReady() && rand() % 10 < 3)
        {
            InMonster->UseSkill(*InPlayer);
        }
        else // 아니면 일반 공격
        {
            printf("\n%s의 공격!\n", InMonster->GetName().c_str());
            int InDamage = InPlayer->TakeDamage(InMonster->Damage);
            printf("플레이어는 %d의 데미지를 입었다!\n", InDamage);
        }

        // 플레이어 사망 체크
        if (InPlayer->IsDead())
        {
            printf("\n당신은 사망했습니다...\n");
            return;
        }

        // 턴 종료 시 양쪽 모두 쿨타임 감소
        InPlayer->TickCooldown();
        InMonster->TickCooldown();
    }
}