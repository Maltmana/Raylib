#pragma once
// std
// lib
// non-system
#include "stdafx.h"
// system
#include "EntityContainer.h"
#include "Enums.h"

class Creature;

// user input 
class Controller
{
public:
	Controller();
	~Controller();
public:
	// runs selection system and command system
	void Update(bool & p_paused, EntityContainer& entityContainer_);
	// draws selection rectangle
	void Draw();
private:
	void UpdateMousePos();
	void UpdateMouseDownPos();
	void TogglePause(bool & p_paused);
	void UpdateSelectionBox();
	void ControlCreatures(EntityContainer& entityContainer_);
public:
	// primitives
	// flags
	// objects
	Rectangle selectionRect = { 0,0,0,0 };
private: // TODO make stuff private that needs to be
	// primitives
	int _mouseX, _mouseY, _mouseDownX, _mouseDownY;
	EntityContainer _selectedEntities;
	// flags
	// objects
};