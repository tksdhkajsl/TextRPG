#pragma once
#include "Player.h"
#include "Map.h"
#include "Exploration.h"
#include <map> // std::map�� ����ϱ� ���� �߰�

class Game
{
public:
    Game(Player* player);
    void Run();

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
    int currentDungeonProgress = 0;
};