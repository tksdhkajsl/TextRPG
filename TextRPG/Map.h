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
    // 아이템 ID를 키로, 아이템 상세 정보를 값으로 갖는 데이터베이스
    std::map<ItemID, ItemInfo> ItemDatabase;
};