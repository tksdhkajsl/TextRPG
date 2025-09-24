#include "Map.h"
#include<iostream>
#include<cstdio>

void Map::MapMovement()
{
	int Move = 0;
	while (true)
	{
	printf("어디로 이동하시겠습니까?\n[1.던전 2.상점 3.여관 4.게임 종료]\n");
	std::cin >> Move;
		switch (Move)
		{
		case 1:
			Dungeon();
			
			
		case 2:
			Shop();
			
			
		case 3:
			Inn();
			
		case 4:
			printf("게임을 종료합니다.\n");
			exit(0);
		default:
			printf("잘못된 입력입니다. 다시 선택해주세요.\n");
			continue;
		}
	}

}

void Map::Shop()
{
	int Move = 0;
	printf("상점에 왔습니다.\n");
	while (true)
	{
		printf("[1.구매 2.나가기]\n");
		std::cin >> Move;
		switch (Move)
		{
		case 1:
			if (0)
			{
				
				//물건 살 때
			}
			else
			{
				printf("소지금이 부족합니다.\n");
				continue;
			}
		case 2:
			printf("상점을 나갑니다.\n");
			return MapMovement();
		default:
			printf("잘못된 입력입니다. 다시 선택해주세요.\n");
			continue;
		}
	}
}

void Map::Dungeon()
{
	int Move = 0;	
	while (true)
	{
		printf("어느 던전으로 이동하시겠습니까?\n[1.숲 2.묘지 3.탑 4.마을로 돌아가기]\n ");
		std::cin >> Move;
		switch (Move)
		{
		case 1:
			printf("숲으로 이동합니다.\n");
			break;
			
		case 2:
			printf("묘지로 이동합니다.\n");
			break;
		case 3:
			printf("탑으로 이동합니다.\n");
			break;
		case 4:
			printf("마을로 이동합니다.\n");
			return MapMovement();
		default:
			printf("잘못된 입력입니다. 다시 선택해주세요.\n");
			continue;
		}
	}
}

void Map::Inn()
{
	//여관 숙박하여 체력 회복 비용발생. 
	//비용 부족하면 숙박 못함
	int Move = 0;
	int InnGold = 100;
	int Gold = 0;
	printf("여관에 왔습니다.\n"); 
	while (true)
	{
		printf("[1.숙박[100 G] 2.나가기]\n");
		std::cin >> Move;
		switch (Move)
		{
		case 1:
			if (Gold > InnGold)
			{
				printf("숙박을 합니다. 하루가 지나갑니다.\n체력이 200회복 되었습니다.\n");
				//캐릭터 체력 회복 ex ) hp += 200;
			}
			else
			{
				printf("소지금이 부족합니다.\n");
				continue;
			}
		case 2:
			printf("여관을 나갑니다.\n");
			return MapMovement();
		default:
			printf("잘못된 입력입니다. 다시 선택해주세요.\n");
			continue;
		}
	}
}
