#include "Game.h"
#include <iostream>

Game::Game(Player* InPlayer)
    : InPlayer(InPlayer)
{
    // �����ڿ��� �� ������ Ŭ���� ����(�̵� Ƚ��)�� �ʱ�ȭ
    DungeonClearCounts[Dungeon::Forest] = 15;
    DungeonClearCounts[Dungeon::Cemetery] = 20;
    DungeonClearCounts[Dungeon::Top] = 25;
}

void Game::Run()
{
    while (true)
    {
        if (InPlayer->IsDead())
        {
            printf("\n===== GAME OVER =====\n");
            return;
        }

        printf("\n���� �̵��Ͻðڽ��ϱ�?\n[1.���� 2.���� 3.���� 4.���� ���� 5.���� ����]\n>> ");
        int choice = 0;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            GoToDungeon();
            break;
        case 2:
            InMap.Shop(*InPlayer);
            break;
        case 3:
            InMap.Inn(*InPlayer);
            break;
        case 4:
            printf("������ �����մϴ�.\n");
            return;
        case 5:
            InPlayer->ShowStatus();
            break;
        default:
            printf("�߸��� �Է��Դϴ�.\n");
            break;
        }
    }
}

void Game::GoToDungeon()
{
    Dungeon selectedDungeon = InMap.DungeonMove();
    if (selectedDungeon != Dungeon::None)
    {
        // ������ �����ϱ� ����, �ش� ������ ��ǥ �̵� Ƚ���� ���൵�� ����
        currentDungeonProgress = DungeonClearCounts[selectedDungeon];
        StartDungeonExploration(selectedDungeon);
    }
}

void Game::StartDungeonExploration(Dungeon DungeonType)
{
    printf("\n=== ���� Ž���� �����մϴ�. (��ǥ���� ���� �Ÿ�: %d) ===\n", currentDungeonProgress);

    // ���� �̵� Ƚ���� 0���� Ŭ ���� �ݺ�
    while (currentDungeonProgress > 0)
    {
        if (InPlayer->IsDead()) return;

        printf("\n[1. ������ �̵��ϱ� 2. ���� ���� 3. ������ ���ư���]\n>> ");
        int choice = 0;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            // ������ �̵��ϸ� ���൵ 1 ����
            currentDungeonProgress--;

            printf("\n������ �̵��մϴ�... (���� �Ÿ�: %d)\n", currentDungeonProgress);

            // 50% Ȯ���� ���Ϳ� ����
            if (rand() % 2 == 0)
            {
                InExploration.CreateMonster(DungeonType);
                InExploration.StartBattle(InPlayer);
            }
            else
            {
                printf("�ƹ� �ϵ� �Ͼ�� �ʾҽ��ϴ�.\n");
            }
            break;
        case 2:
            InPlayer->ShowStatus();
            break;
        case 3:
            printf("Ž���� �����ϰ� ������ ���ư��ϴ�.\n");
            currentDungeonProgress = 0; // ���� Ż���� ���� 0���� ����
            return;
        default:
            printf("�߸��� �Է��Դϴ�.\n");
            break;
        }

        // �̵� Ƚ���� ��� ä������ Ȯ��
        if (currentDungeonProgress <= 0 && !InPlayer->IsDead())
        {
            printf("\n==================================\n");
            printf("    ������ Ŭ�����߽��ϴ�! \n");
            printf("  ������ �ڵ����� �����մϴ�.\n");
            printf("==================================\n");
            // ������ �ڿ������� ����Ǹ� �Լ��� ����
        }
    }
}