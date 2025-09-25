#pragma once

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
    void Shop(Player& InPlayer);
    Dungeon DungeonMove();
    void Inn(Player& InPlayer);
};