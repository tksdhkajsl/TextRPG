#include <iostream>
#include <cstdio>
#include <vector>
#include "Map.h"
#include "Actor.h"
#include "Player.h"

// �����ڿ��� ������ ��� �ʱ�ȭ
// ���� ������ ��� �κ� AI ���� ���� ����;; 
// �������� ���� ������ ����� �����
Map::Map()
{
	ItemDatabase[ItemID::ShortSword] = { ItemID::ShortSword,   ItemType::WEAPON, "���ҵ�",   1000, 22, 0 };
	ItemDatabase[ItemID::LongSword] = { ItemID::LongSword,    ItemType::WEAPON, "�ռҵ�",   1300, 25, 0 };
	ItemDatabase[ItemID::Staff] = { ItemID::Staff,        ItemType::WEAPON, "������",   1500, 20, 3 };
	ItemDatabase[ItemID::LeatherArmor] = { ItemID::LeatherArmor, ItemType::ARMOR,  "���װ���", 1800, 0, 25 };
	ItemDatabase[ItemID::HeavyArmor] = { ItemID::HeavyArmor,   ItemType::ARMOR,  "�߰���",   2400, 0, 40 };
	ItemDatabase[ItemID::ClothArmor] = { ItemID::ClothArmor,   ItemType::ARMOR,  "õ��",     1700, 0, 20 };
}

void Map::Shop(Player& InPlayer)
{
	
	
	printf("\n������ ���� ���� ȯ���մϴ�! (���� ������: %d Gold)\n", InPlayer.Gold);
	while (true)
	{
		printf("\n[1. ������ ���� 2. ������]\n>> ");
		int Input = 0;
		std::cin >> Input;

		if (Input == 1) // ����
		{
			printf("\n--- �Ǹ� ��� ---\n");
			// �Ǹ� ����� �������� �����Ͽ� �����ֱ�
			std::vector<ItemInfo> SellList;
			int ItemIndex = 1;
			for (auto const& [ID, Info] : ItemDatabase)
			{
				printf("%d. %s [���ݷ�:%d ����:%d] (%d Gold)\n", ItemIndex, Info.Name.c_str(), Info.Attack, Info.Defense, Info.Price);
				SellList.push_back(Info);
				ItemIndex++;
			}
			printf("%d. �������� �ʱ�\n", ItemIndex);

			printf(">> ");
			int BuyChoice = 0;
			std::cin >> BuyChoice;

			if (BuyChoice > 0 && BuyChoice < ItemIndex)
			{
				ItemInfo& SelectedItem = SellList[BuyChoice - 1];

				if (InPlayer.Gold >= SelectedItem.Price)
				{
					InPlayer.Gold -= SelectedItem.Price;
					InPlayer.EquipItem(SelectedItem);
					printf("\n���Ű� �Ϸ�Ǿ����ϴ�! (���� ������: %d Gold)\n", InPlayer.Gold);
					InPlayer.ShowStatus();
				}
				else
				{
					printf("�������� �����մϴ�.\n");
				}
			}
			else if (BuyChoice == ItemIndex)
			{
				printf("���Ÿ� ����մϴ�.\n");
			}
			else
			{
				printf("�߸��� �Է��Դϴ�.\n");
			}
		}
		else if (Input == 2) // ������
		{
			printf("������ �����ϴ�.\n");
			return;
		}
		else
		{
			printf("�߸��� �Է��Դϴ�.\n");
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
		printf("[1.���� (��� ü�� ȸ��) [100 Gold] 2.������]\n>> ");
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
			break; 
		case 2:
			printf("������ �����ϴ�.\n");
			return;
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
			continue;
		}
	}
}