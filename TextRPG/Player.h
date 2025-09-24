#pragma once
#include "Actor.h"
#include <iostream> 
#include <string>


class Player :  public Actor
{
public:
	void MakeCharactor();
};

class Warrior : public Actor
{
public:
	
	Actor::Health;
	Actor::Damage;
	Actor::Defense;
private:
	std::string Name = "ภüป็";
};
