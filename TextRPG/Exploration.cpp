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
        random = (rand() % 4) + 1;
        if (random == 1)
        {
            InMonster = new Goblin();
        }
        else if (random == 2)
        {
            InMonster = new Orc();
        }
        else if (random == 3)
        {
            InMonster = new Zombie();
        }
        else if (random == 4)
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
        // [����] printf�� �μ��� �������� �ʵ��� ����
        printf("\n%s(��)�� ��Ÿ����!\n", InMonster->GetName().c_str());
    }
}

// [����] static ���� �� �Ű����� ��ġ, �Լ� ���� �߰�
void Exploration::Move(Dungeon InDunType)
{
    MoveCount++;
    printf("������ �̵��Ͽ� %d ĭ ��ŭ �����߽��ϴ�.\n", MoveCount);
}

// [����] static ���� �� �Ű����� ��ġ
void Exploration::StartBattle(Player* InPlayer)
{
    while (true)
    {
        printf("\n--- %s ---\n", InPlayer->GetName().c_str());
        printf("ü�� (HP): %d\n", InPlayer->GetHP());
        printf("���ݷ� (ATT): %d\n", InPlayer->GetATT());
        printf("���� (DEF): %d\n", InPlayer->GetDEF());
        printf("--- %s ---\n", InMonster->GetName().c_str());
        printf("ü�� (HP): %d\n", InMonster->GetHP());
        printf("���ݷ� (ATT): %d\n", InMonster->GetATT());
        printf("���� (DEF): %d\n", InMonster->GetDEF());

        printf("\n[1. ���� 2. ��ų]\n>> ");
        int choice;
        std::cin >> choice;

        if (choice == 1) // ����
        {
            printf("\n�÷��̾��� ����!\n");
            InMonster->TakeDamage(InPlayer->Damage);
            printf("%s���� %d�� �������� ������!\n", InMonster->GetName().c_str(), std::max(1, InPlayer->Damage - InMonster->Defense));
        }
        else if (choice == 2) // ��ų
        {
            if (InPlayer->IsSkillReady())
            {
                InPlayer->UseSkill(*InMonster);
            }
            else
            {
                printf("\n��ų�� ���� ����� �� �����ϴ�! (��Ÿ�� ����)\n");
                continue; // �ൿ �������� �ٽ� ���ư�
            }
        }        
        else
        {
            printf("�߸��� �Է��Դϴ�.\n");
            continue;
        }

        // ���� ��� üũ
        if (InMonster->IsDead())
        {
            printf("\n%s�� �����ƴ�!\n", InMonster->GetName().c_str());
            InPlayer->Gold += InMonster->Gold;
            printf("%d ��带 ȹ���ߴ�!\n", InMonster->Gold);
            delete InMonster;
            InMonster = nullptr;
            return;
        }

        // ������ ��
        // 30% Ȯ���� ��ų�� �غ�Ǿ��ٸ� ��ų ���
        if (InMonster->IsSkillReady() && rand() % 10 < 3)
        {
            InMonster->UseSkill(*InPlayer);
        }
        else // �ƴϸ� �Ϲ� ����
        {
            printf("\n%s�� ����!\n", InMonster->GetName().c_str());
            InPlayer->TakeDamage(InMonster->Damage);
            printf("�÷��̾�� %d�� �������� �Ծ���!\n", std::max(1, InMonster->Damage - InPlayer->Defense));
        }

        // �÷��̾� ��� üũ
        if (InPlayer->IsDead())
        {
            printf("\n����� ����߽��ϴ�...\n");
            return;
        }

        // �� ���� �� ���� ��� ��Ÿ�� ����
        InPlayer->TickCooldown();
        InMonster->TickCooldown();
    }
}