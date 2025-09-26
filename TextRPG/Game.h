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

    // 던전 클리어에 필요한 이동 횟수를 저장
    std::map<Dungeon, int> DungeonClearCounts;
    // 현재 던전의 남은 이동 횟수
    int CurrentDungeon = 0;
};