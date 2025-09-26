#pragma once
#include "Player.h"
#include "Map.h"
#include "Exploration.h"
#include <map> 

class Game
{
public:
    Game(Player* player);
    void Run();

    int GetCurrentDungeon() const { return CurrentDungeon; }
private:
    void GoToDungeon();
    void StartDungeonExploration(Dungeon dungeonType);

private:
    Player* InPlayer;
    Map InMap;
    Exploration InExploration;

    // ���� Ŭ��� �ʿ��� �̵� Ƚ���� ����
    std::map<Dungeon, int> DungeonClearCounts;
    // ���� ������ ���� �̵� Ƚ��
    int CurrentDungeon = 0;
};