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

// [수정] static 제거 및 매개변수 일치
void Exploration::CreateMonster(Dungeon InDunType)
{
    if (InMonster != nullptr)
    {
        delete InMonster;
        InMonster = nullptr;
    }

    switch (InDunType)
    {
    case Dungeon::Forest:
    {
        int random = rand() % 3;
        if (random == 0) InMonster = new Slime();
        else if (random == 1) InMonster = new Goblin();
        else InMonster = new Orc();
    }
    break;
    case Dungeon::Cemetery:
    {
        int random = rand() % 2;
        if (random == 0) InMonster = new Zombie();
        else InMonster = new Ghost();
    }
    break;
    case Dungeon::Top:
        InMonster = new Gargoyle();
        break;
    }

    if (InMonster != nullptr)
    {
        // [수정] printf에 인수가 누락되지 않도록 주의
        printf("\n%s(이)가 나타났다!\n", InMonster->GetName().c_str());
    }
}

// [수정] static 제거 및 매개변수 일치, 함수 내용 추가
void Exploration::Move(Dungeon InDunType)
{
    MoveCount++;
    printf("앞으로 이동하여 %d 칸 만큼 전진했습니다.\n", MoveCount);
}

// [수정] static 제거 및 매개변수 일치
void Exploration::StartBattle(Player* InPlayer)
{
    while (true)
    {
        printf("\n--- %s ---\n", InPlayer->GetName().c_str());
        printf("HP: %d\n", InPlayer->GetHealth());
        printf("--- %s ---\n", InMonster->GetName().c_str());
        printf("HP: %d\n", InMonster->GetHealth());

        printf("\n[1. 공격 2. 스킬 3. 도망가기]\n>> ");
        int choice;
        std::cin >> choice;

        if (choice == 1) // 공격
        {
            printf("\n플레이어의 공격!\n");
            InMonster->TakeDamage(InPlayer->Damage);
            printf("%s에게 %d의 데미지를 입혔다!\n", InMonster->GetName().c_str(), std::max(1, InPlayer->Damage - InMonster->Defense));
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
        else if (choice == 3) // 도망
        {
            if (rand() % 2 == 0)
            {
                printf("\n무사히 도망쳤다!\n");
                delete InMonster;
                InMonster = nullptr;
                return;
            }
            else
            {
                printf("\n도망치지 못했다!\n");
                // 도망 실패 시 몬스터에게 턴이 넘어감
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
            InPlayer->TakeDamage(InMonster->Damage);
            printf("플레이어는 %d의 데미지를 입었다!\n", std::max(1, InMonster->Damage - InPlayer->Defense));
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