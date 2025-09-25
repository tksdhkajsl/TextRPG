#include "Game.h"
#include "Player.h"
#include <time.h>
#include <stdlib.h>

// Player.cpp에 있던 MakeCharactor를 독립적인 함수로 분리합니다.
Player* CreatePlayer()
{
    while (true)
    {
        printf("-----------------------\n");
        printf("  캐릭터를 생성하세요!\n");
        printf("1) 전사 2) 도적 3) 법사\n");
        printf("-----------------------\n");
        printf(">> ");

        int input = 0;
        std::cin >> input;
        switch (input)
        {
        case 1: 
            printf("전사를 생성하였습니다.\n\n"); 
            return new Warrior();
        case 2: 
            printf("도적을 생성하였습니다.\n\n"); 
            return new Thief();
        case 3: 
            printf("마법사를 생성하였습니다.\n\n");
            return new Mage();
        default: 
            printf("잘못된 입력입니다.\n");
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    // 1. 캐릭터 생성
    Player* player = CreatePlayer();
    player->ShowStatus();

    // 2. 생성된 플레이어 정보로 게임 객체 생성
    Game game(player);

    // 3. 게임 메인 루프 실행
    game.Run();

    // 4. 게임이 끝나면 플레이어 메모리 해제
    delete player;
    player = nullptr;

    return 0;
}