#include "Game.h"
#include <iostream>

Game::Game(Player* InPlayer)
    : InPlayer(InPlayer)
{
    // 생성자에서 각 던전별 클리어 조건(이동 횟수)을 초기화
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

        printf("\n어디로 이동하시겠습니까?\n[1.던전 2.상점 3.여관 4.상태 보기 5.게임 종료]\n>> ");
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
            printf("게임을 종료합니다.\n");
            break;
        default:
            printf("잘못된 입력입니다.\n");
            break;
        }
    }
}

void Game::GoToDungeon()
{
    Dungeon selectedDungeon = InMap.DungeonMove();
    if (selectedDungeon != Dungeon::None)
    {
        // 던전에 입장하기 전에, 해당 던전의 목표 이동 횟수로 진행도를 설정
        CurrentDungeon = DungeonClearCounts[selectedDungeon];
        StartDungeonExploration(selectedDungeon);
    }
}

void Game::StartDungeonExploration(Dungeon DungeonType)
{
    printf("\n=== 던전 탐험을 시작합니다. (목표까지 남은 거리: %d) ===\n", CurrentDungeon);

    // 남은 이동 횟수가 0보다 클 동안 반복
    while (CurrentDungeon > 0)
    {
        if (InPlayer->IsDead()) return;

        printf("\n[1. 앞으로 이동하기 2. 상태 보기 3. 마을로 돌아가기]\n>> ");
        int Input = 0;
        std::cin >> Input;

        switch (Input)
        {
        case 1:
            // 앞으로 이동하면 진행도 1 감소
            CurrentDungeon--;

            printf("\n앞으로 이동합니다... (남은 거리: %d)\n", CurrentDungeon);

            // 50% 확률로 몬스터와 조우
            if (rand() % 2 == 0)
            {
                InExploration.CreateMonster(DungeonType);
                InExploration.StartBattle(InPlayer);
            }
            else
            {
                printf("아무 일도 일어나지 않았습니다.\n");
            }
            break;
        case 2:
            printf("\n(남은 거리: %d)\n", CurrentDungeon);
            InPlayer->ShowStatus();
            break;
        case 3:
            printf("탐험을 포기하고 마을로 돌아갑니다.\n");
            CurrentDungeon = 0; // 루프 탈출을 위해 0으로 설정
            return;
        default:
            printf("잘못된 입력입니다.\n");
            break;
        }

        // 이동 횟수를 모두 채웠는지 확인
        if (CurrentDungeon <= 0 && !InPlayer->IsDead())
        {
            printf("\n==================================\n");
            printf("    던전을 클리어했습니다! \n");
            printf("  마을로 자동으로 복귀합니다.\n");
            printf("==================================\n");
            // 루프가 자연스럽게 종료되며 함수가 끝남
        }
    }
}