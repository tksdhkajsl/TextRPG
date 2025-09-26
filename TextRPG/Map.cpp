#include <iostream>
#include <cstdio>
#include <vector>
#include "Map.h"
#include "Actor.h"
#include "Player.h"

// 생성자에서 아이템 목록 초기화
// 상점 구현은 상당 부분 AI 도움 많이 받음;; 
// 생각보다 상점 구현이 상당히 어려움
Map::Map()
{
	ItemDatabase[ItemID::ShortSword] = { ItemID::ShortSword,   ItemType::WEAPON, "숏소드",   1000, 22, 0 };
	ItemDatabase[ItemID::LongSword] = { ItemID::LongSword,    ItemType::WEAPON, "롱소드",   1300, 25, 0 };
	ItemDatabase[ItemID::Staff] = { ItemID::Staff,        ItemType::WEAPON, "스태프",   1500, 20, 3 };
	ItemDatabase[ItemID::LeatherArmor] = { ItemID::LeatherArmor, ItemType::ARMOR,  "가죽갑옷", 1800, 0, 25 };
	ItemDatabase[ItemID::HeavyArmor] = { ItemID::HeavyArmor,   ItemType::ARMOR,  "중갑옷",   2400, 0, 40 };
	ItemDatabase[ItemID::ClothArmor] = { ItemID::ClothArmor,   ItemType::ARMOR,  "천옷",     1700, 0, 20 };
}

void Map::Shop(Player& InPlayer)
{
	
	
	printf("\n상점에 오신 것을 환영합니다! (현재 소지금: %d Gold)\n", InPlayer.Gold);
	while (true)
	{
		printf("\n[1. 아이템 구매 2. 나가기]\n>> ");
		int Input = 0;
		std::cin >> Input;

		if (Input == 1) // 구매
		{
			printf("\n--- 판매 목록 ---\n");
			// 판매 목록을 동적으로 생성하여 보여주기
			std::vector<ItemInfo> SellList;
			int ItemIndex = 1;
			for (auto const& [ID, Info] : ItemDatabase)
			{
				printf("%d. %s [공격력:%d 방어력:%d] (%d Gold)\n", ItemIndex, Info.Name.c_str(), Info.Attack, Info.Defense, Info.Price);
				SellList.push_back(Info);
				ItemIndex++;
			}
			printf("%d. 구매하지 않기\n", ItemIndex);

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
					printf("\n구매가 완료되었습니다! (남은 소지금: %d Gold)\n", InPlayer.Gold);
					InPlayer.ShowStatus();
				}
				else
				{
					printf("소지금이 부족합니다.\n");
				}
			}
			else if (BuyChoice == ItemIndex)
			{
				printf("구매를 취소합니다.\n");
			}
			else
			{
				printf("잘못된 입력입니다.\n");
			}
		}
		else if (Input == 2) // 나가기
		{
			printf("상점을 나갑니다.\n");
			return;
		}
		else
		{
			printf("잘못된 입력입니다.\n");
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
		printf("[1.숙박 (모든 체력 회복) [100 Gold] 2.나가기]\n>> ");
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
			break; 
		case 2:
			printf("여관을 나갑니다.\n");
			return;
		default:
			printf("잘못된 입력입니다. 다시 선택해주세요.\n");
			continue;
		}
	}
}