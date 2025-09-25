#include "Game.h"
#include "Player.h"
#include <time.h>
#include <stdlib.h>

// Player.cpp�� �ִ� MakeCharactor�� �������� �Լ��� �и��մϴ�.
Player* CreatePlayer()
{
    while (true)
    {
        printf("-----------------------\n");
        printf("  ĳ���͸� �����ϼ���!\n");
        printf("1) ���� 2) ���� 3) ����\n");
        printf("-----------------------\n");
        printf(">> ");

        int input = 0;
        std::cin >> input;
        switch (input)
        {
        case 1: 
            printf("���縦 �����Ͽ����ϴ�.\n\n"); 
            return new Warrior();
        case 2: 
            printf("������ �����Ͽ����ϴ�.\n\n"); 
            return new Thief();
        case 3: 
            printf("�����縦 �����Ͽ����ϴ�.\n\n");
            return new Mage();
        default: 
            printf("�߸��� �Է��Դϴ�.\n");
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    // 1. ĳ���� ����
    Player* player = CreatePlayer();
    player->ShowStatus();

    // 2. ������ �÷��̾� ������ ���� ��ü ����
    Game game(player);

    // 3. ���� ���� ���� ����
    game.Run();

    // 4. ������ ������ �÷��̾� �޸� ����
    delete player;
    player = nullptr;

    return 0;
}