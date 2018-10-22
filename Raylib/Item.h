#pragma once
#include "stdafx.h"
#include "Enums.h"

// changes speed, attack dmg, defense, hp regen, or can be activatable
// eventually will hold a function pointer which will have these effects
class Item // inherit from entity.
{
public:
	Item();
	~Item();
public:
private:
public:
	// to inheritance
	Vector2 _pos{ 100,100 }; // TODO temp
	// to graphic object
	ItemGraphicsTypes _graphicType = ItemGraphicsTypes::BootsOfSpeed;
	// primitives
	int _speedMod = 100; // these should probably be key value. or enums.
	int _healthMod;
	int _damageMod;
	int _armourMod;
	int _hpRegenMod;
	// flags
	bool _activatable;
	// objects
	// magic _specialActive // more complex like throwing fire balls with a cooldown, shooting lightning and stuff
	 // effect _specialPassive; // more complex behavior like splash damage, cold status effect, 
private:
};

