#pragma once
// std
// lib
// non-system
#include "stdafx.h"
// system

class Creature;
class EntityContainer;

// user input 
class Controller
{
public:
	Controller();
	~Controller();
public:
	// runs selection system and command system
	void Update(bool & p_paused, EntityContainer& entities_, std::list<std::weak_ptr<Creature>>& p_selectedCreatures);
	// draws selection rectangle
	void Draw();
private:
	void UpdateMousePos();
	void UpdateMouseDownPos();
	void TogglePause(bool & p_paused);
	void UpdateSelectionBox();
	void ControlCreatures(EntityContainer& entities_, std::list<std::weak_ptr<Creature>>& p_selectedCreatures);
public:
	// primitives
	// flags
	// objects
	Rectangle selectionRect = { 0,0,0,0 };
private: // TODO make stuff private that needs to be
	// primitives
	int _mouseX, _mouseY, _mouseDownX, _mouseDownY;
	// flags
	// objects
};