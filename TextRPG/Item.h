#pragma once
#include <string>
#include <map>
// 아이템의 종류 (무기/방어구)를 구분하기 위한 enum
enum class ItemType
{
    WEAPON,
    ARMOR
};

// 상점에서 판매할 아이템 목록
enum class ItemID
{
    ShortSword,
    LongSword,
    Staff,
    LeatherArmor,
    HeavyArmor,
    ClothArmor
};

// 개별 아이템의 상세 정보를 담을 구조체
struct ItemInfo
{
    ItemID ID;
    ItemType Type;
    std::string Name;
    int Price;
    int Attack;
    int Defense;
};