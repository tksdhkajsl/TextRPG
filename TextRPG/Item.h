#pragma once
#include <string>
#include <map>
// �������� ���� (����/��)�� �����ϱ� ���� enum
enum class ItemType
{
    WEAPON,
    ARMOR
};

// �������� �Ǹ��� ������ ���
enum class ItemID
{
    ShortSword,
    LongSword,
    Staff,
    LeatherArmor,
    HeavyArmor,
    ClothArmor
};

// ���� �������� �� ������ ���� ����ü
struct ItemInfo
{
    ItemID ID;
    ItemType Type;
    std::string Name;
    int Price;
    int Attack;
    int Defense;
};