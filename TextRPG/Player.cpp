#include "Player.h"
#include<map>
#include<iostream>



//
////������ ����
//void Day0924::TestMap()
//{
//	std::map<CharacterType, CharacterStatus> Characters;
//
//	Characters[CharacterType::Warrior] = { 10, 200, 15 };
//	Characters[CharacterType::Mage] = { 8, 100, 5 };
//	Characters[CharacterType::Archer] = { 12, 150, 20 };
//
//	CharacterStatus& MageStatus = Characters[CharacterType::Mage]; // []�����ڷ� Value�� ����
//	printf("[] ���ٹ� : %s", ToString(CharacterType::Mage).c_str());
//	PrintStatus(MageStatus);
//
//	if (Characters.contains(CharacterType::Mage))	// ���� Ű�� �����ϴ� ���� �����ϱ� ���� �ݵ�� üũ�ؾ� �Ѵ�.
//	{
//		// �ִ�.
//		CharacterStatus& MageStatus = Characters[CharacterType::Mage]; // []�����ڷ� Value�� ����
//		printf("\n[] ���ٹ� : %s", ToString(CharacterType::Mage).c_str());
//		PrintStatus(MageStatus);
//	}
//	else
//	{
//		// ����.
//	}
//
//	// ���� �׸� �����ϸ� �� �׸��� �����.
//	CharacterStatus& ThiefStatus = Characters[CharacterType::Thief];
//	printf("[] ���� Ű ���� : %s", ToString(CharacterType::Thief).c_str());
//	PrintStatus(ThiefStatus);
//
//	printf("\n��ü ĳ���� ���\n");
//	//for( const std::pair<CharacterType, CharacterStatus>& pair :Characters)
//	for (const auto& pair : Characters)
//	{
//		printf("ĳ���� Ÿ�� : %s", ToString(pair.first).c_str());
//		PrintStatus(pair.second); // first = Ű, second = value
//	}
//
//	printf("\n���� ����\n");
//	Characters.erase(CharacterType::Thief);
//
//	printf("\n��ü ĳ���� ���\n");
//	for (const auto& pair : Characters)
//	{
//		printf("ĳ���� Ÿ�� : %6s", ToString(pair.first).c_str());
//		PrintStatus(pair.second);	// first = Ű, second = value
//	}
//
//	printf("\n��ü ����\n");
//	Characters.clear();
//	printf("\n��ü ĳ���� ���\n");
//	for (const auto& pair : Characters)
//	{
//		printf("ĳ���� Ÿ�� : %6s", ToString(pair.first).c_str());
//		PrintStatus(pair.second);	// first = Ű, second = value
//	}
//
//	int i = 0;
//}

void Player::MakeCharactor()
{
	
}
