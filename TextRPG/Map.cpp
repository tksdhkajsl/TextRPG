#include "Map.h"
#include "Actor.h"
#include <iostream>
#include <cstdio>
#include "Player.h"

void Map::Shop(Player& InPlayer)
{
	int Move = 0;
	printf("������ �Խ��ϴ�.\n");
	while (true)
	{
		printf("[1.���� 2.������]\n>> ");
		std::cin >> Move;
		switch (Move)
		{
		case 1:
			if (InPlayer.Gold > 0)
			{
				printf("���� �Ǹ��ϴ� ������ �����ϴ�.\n");
			}
			else
			{
				printf("�������� �����մϴ�.\n");
			}
			break; // ���� ����: break �߰�
		case 2:
			printf("������ �����ϴ�.\n");
			return;
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
			continue;
		}
	}
}

Dungeon Map::DungeonMove()
{
	int Move = 0;
	while (true)
	{
		printf("\n��� �������� �̵��Ͻðڽ��ϱ�?\n[1.�� 2.���� 3.ž 4.������ ���ư���]\n>> ");
		std::cin >> Move;
		switch (Move)
		{
		case 1:
			printf("������ �̵��մϴ�.\n");
			return Dungeon::Forest;

		case 2:
			printf("������ �̵��մϴ�.\n");
			return Dungeon::Cemetery;
		case 3:
			printf("ž���� �̵��մϴ�.\n");
			return Dungeon::Top;
		case 4:
			printf("������ �̵��մϴ�.\n");
			return Dungeon::None;
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
			continue;
		}
	}
}

void Map::Inn(Player& InPlayer)
{
	int Move = 0;
	int InnGold = 100;

	printf("������ �Խ��ϴ�.\n");
	while (true)
	{
		printf("[1.���� (��� ü�� ȸ��) [100 G] 2.������]\n>> ");
		std::cin >> Move;
		switch (Move)
		{
		case 1:
			if (InPlayer.Gold >= InnGold)
			{
				InPlayer.Gold -= InnGold;
				printf("������ �մϴ�. �Ϸ簡 �������ϴ�.\nü���� 200 ȸ���Ǿ����ϴ�.\n");
				InPlayer.RecoverHealth(200); // ü�� 200 ȸ��
				InPlayer.ShowStatus();
			}
			else
			{
				printf("�������� �����մϴ�.\n");
			}
			break; // ���� ����: break �߰�
		case 2:
			printf("������ �����ϴ�.\n");
			return;
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
			continue;
		}
	}
}