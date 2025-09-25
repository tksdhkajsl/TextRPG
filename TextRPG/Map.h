#pragma once
#include "Item.h"

class Player; 

enum class Dungeon
{
    None,
    Forest,
    Cemetery,
    Top
};

class Map
{
public:
    Map(); 
    ~Map() {};
    void Shop(Player& InPlayer);
    Dungeon DungeonMove();
    void Inn(Player& InPlayer);

private:
    // ������ ID�� Ű��, ������ �� ������ ������ ���� �����ͺ��̽�
    std::map<ItemID, ItemInfo> ItemDatabase;
};