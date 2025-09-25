#include "Map.h"
#include "Actor.h"
#include <iostream>
#include <cstdio>
#include "Player.h"

void Map::Shop(Player& InPlayer)
{
	int Move = 0;
	printf("상점에 왔습니다.\n");
	while (true)
	{
		printf("[1.구매 2.나가기]\n>> ");
		std::cin >> Move;
		switch (Move)
		{
		case 1:
			if (InPlayer.Gold > 0)
			{
				printf("아직 판매하는 물건이 없습니다.\n");
			}
			else
			{
				printf("소지금이 부족합니다.\n");
			}
			break; // 버그 수정: break 추가
		case 2:
			printf("상점을 나갑니다.\n");
			return;
		default:
			printf("잘못된 입력입니다. 다시 선택해주세요.\n");
			continue;
		}
	}
}

Dungeon Map::DungeonMove()
{
	int Move = 0;
	while (true)
	{
		printf("\n어느 던전으로 이동하시겠습니까?\n[1.숲 2.묘지 3.탑 4.마을로 돌아가기]\n>> ");
		std::cin >> Move;
		switch (Move)
		{
		case 1:
			printf("숲으로 이동합니다.\n");
			return Dungeon::Forest;

		case 2:
			printf("묘지로 이동합니다.\n");
			return Dungeon::Cemetery;
		case 3:
			printf("탑으로 이동합니다.\n");
			return Dungeon::Top;
		case 4:
			printf("마을로 이동합니다.\n");
			return Dungeon::None;
		default:
			printf("잘못된 입력입니다. 다시 선택해주세요.\n");
			continue;
		}
	}
}

void Map::Inn(Player& InPlayer)
{
	int Move = 0;
	int InnGold = 100;

	printf("여관에 왔습니다.\n");
	while (true)
	{
		printf("[1.숙박 (모든 체력 회복) [100 G] 2.나가기]\n>> ");
		std::cin >> Move;
		switch (Move)
		{
		case 1:
			if (InPlayer.Gold >= InnGold)
			{
				InPlayer.Gold -= InnGold;
				printf("숙박을 합니다. 하루가 지나갑니다.\n체력이 200 회복되었습니다.\n");
				InPlayer.RecoverHealth(200); // 체력 200 회복
				InPlayer.ShowStatus();
			}
			else
			{
				printf("소지금이 부족합니다.\n");
			}
			break; // 버그 수정: break 추가
		case 2:
			printf("여관을 나갑니다.\n");
			return;
		default:
			printf("잘못된 입력입니다. 다시 선택해주세요.\n");
			continue;
		}
	}
}