#pragma once


class Map
{
public:
	void MapMovement();
	void Shop();
	void Dungeon();
	void Inn();

};

enum class Dungeon
{
	Forest = 10,
	Cemetery = 15,
	Top = 20
};