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
        int Input = 0;
        std::cin >> Input;

        switch (Input)
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
            InPlayer->ShowStatus();
            return;
        case 5:
            printf("������ �����մϴ�.\n");
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
        CurrentDungeon = DungeonClearCounts[selectedDungeon];
        StartDungeonExploration(selectedDungeon);
    }
}

void Game::StartDungeonExploration(Dungeon DungeonType)
{
    printf("\n=== ���� Ž���� �����մϴ�. (��ǥ���� ���� �Ÿ�: %d) ===\n", CurrentDungeon);

    // ���� �̵� Ƚ���� 0���� Ŭ ���� �ݺ�
    while (CurrentDungeon > 0)
    {
        if (InPlayer->IsDead()) return;

        printf("\n[1. ������ �̵��ϱ� 2. ���� ���� 3. ������ ���ư���]\n>> ");
        int Input = 0;
        std::cin >> Input;

        switch (Input)
        {
        case 1:
            // ������ �̵��ϸ� ���൵ 1 ����
            CurrentDungeon--;

            printf("\n������ �̵��մϴ�... (���� �Ÿ�: %d)\n", CurrentDungeon);

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
            printf("\n(���� �Ÿ�: %d)\n", CurrentDungeon);
            InPlayer->ShowStatus();
            break;
        case 3:
            printf("Ž���� �����ϰ� ������ ���ư��ϴ�.\n");
            CurrentDungeon = 0; // ���� Ż���� ���� 0���� ����
            return;
        default:
            printf("�߸��� �Է��Դϴ�.\n");
            break;
        }

        // �̵� Ƚ���� ��� ä������ Ȯ��
        if (CurrentDungeon <= 0 && !InPlayer->IsDead())
        {
            printf("\n==================================\n");
            printf("    ������ Ŭ�����߽��ϴ�! \n");
            printf("  ������ �ڵ����� �����մϴ�.\n");
            printf("==================================\n");
            // ������ �ڿ������� ����Ǹ� �Լ��� ����
        }
    }
}