#include "Player.h"
#include<map>
#include<iostream>



//
////참조할 내용
//void Day0924::TestMap()
//{
//	std::map<CharacterType, CharacterStatus> Characters;
//
//	Characters[CharacterType::Warrior] = { 10, 200, 15 };
//	Characters[CharacterType::Mage] = { 8, 100, 5 };
//	Characters[CharacterType::Archer] = { 12, 150, 20 };
//
//	CharacterStatus& MageStatus = Characters[CharacterType::Mage]; // []연산자로 Value에 접근
//	printf("[] 접근법 : %s", ToString(CharacterType::Mage).c_str());
//	PrintStatus(MageStatus);
//
//	if (Characters.contains(CharacterType::Mage))	// 없는 키에 접근하는 것을 방지하기 위해 반드시 체크해야 한다.
//	{
//		// 있다.
//		CharacterStatus& MageStatus = Characters[CharacterType::Mage]; // []연산자로 Value에 접근
//		printf("\n[] 접근법 : %s", ToString(CharacterType::Mage).c_str());
//		PrintStatus(MageStatus);
//	}
//	else
//	{
//		// 없다.
//	}
//
//	// 없는 항목에 접근하면 새 항목이 생긴다.
//	CharacterStatus& ThiefStatus = Characters[CharacterType::Thief];
//	printf("[] 없는 키 접근 : %s", ToString(CharacterType::Thief).c_str());
//	PrintStatus(ThiefStatus);
//
//	printf("\n전체 캐릭터 출력\n");
//	//for( const std::pair<CharacterType, CharacterStatus>& pair :Characters)
//	for (const auto& pair : Characters)
//	{
//		printf("캐릭터 타입 : %s", ToString(pair.first).c_str());
//		PrintStatus(pair.second); // first = 키, second = value
//	}
//
//	printf("\n도적 삭제\n");
//	Characters.erase(CharacterType::Thief);
//
//	printf("\n전체 캐릭터 출력\n");
//	for (const auto& pair : Characters)
//	{
//		printf("캐릭터 타입 : %6s", ToString(pair.first).c_str());
//		PrintStatus(pair.second);	// first = 키, second = value
//	}
//
//	printf("\n전체 삭제\n");
//	Characters.clear();
//	printf("\n전체 캐릭터 출력\n");
//	for (const auto& pair : Characters)
//	{
//		printf("캐릭터 타입 : %6s", ToString(pair.first).c_str());
//		PrintStatus(pair.second);	// first = 키, second = value
//	}
//
//	int i = 0;
//}

void Player::MakeCharactor()
{
	
}
