#include "Map.h"
#include<iostream>
#include<cstdio>

void Map::MapMovement()
{
	int Move = 0;
	while (true)
	{
	printf("���� �̵��Ͻðڽ��ϱ�?\n[1.���� 2.���� 3.���� 4.���� ����]\n");
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
			printf("������ �����մϴ�.\n");
			exit(0);
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
			continue;
		}
	}

}

void Map::Shop()
{
	int Move = 0;
	printf("������ �Խ��ϴ�.\n");
	while (true)
	{
		printf("[1.���� 2.������]\n");
		std::cin >> Move;
		switch (Move)
		{
		case 1:
			if (0)
			{
				
				//���� �� ��
			}
			else
			{
				printf("�������� �����մϴ�.\n");
				continue;
			}
		case 2:
			printf("������ �����ϴ�.\n");
			return MapMovement();
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
			continue;
		}
	}
}

void Map::Dungeon()
{
	int Move = 0;	
	while (true)
	{
		printf("��� �������� �̵��Ͻðڽ��ϱ�?\n[1.�� 2.���� 3.ž 4.������ ���ư���]\n ");
		std::cin >> Move;
		switch (Move)
		{
		case 1:
			printf("������ �̵��մϴ�.\n");
			break;
			
		case 2:
			printf("������ �̵��մϴ�.\n");
			break;
		case 3:
			printf("ž���� �̵��մϴ�.\n");
			break;
		case 4:
			printf("������ �̵��մϴ�.\n");
			return MapMovement();
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
			continue;
		}
	}
}

void Map::Inn()
{
	//���� �����Ͽ� ü�� ȸ�� ���߻�. 
	//��� �����ϸ� ���� ����
	int Move = 0;
	int InnGold = 100;
	int Gold = 0;
	printf("������ �Խ��ϴ�.\n"); 
	while (true)
	{
		printf("[1.����[100 G] 2.������]\n");
		std::cin >> Move;
		switch (Move)
		{
		case 1:
			if (Gold > InnGold)
			{
				printf("������ �մϴ�. �Ϸ簡 �������ϴ�.\nü���� 200ȸ�� �Ǿ����ϴ�.\n");
				//ĳ���� ü�� ȸ�� ex ) hp += 200;
			}
			else
			{
				printf("�������� �����մϴ�.\n");
				continue;
			}
		case 2:
			printf("������ �����ϴ�.\n");
			return MapMovement();
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
			continue;
		}
	}
}
