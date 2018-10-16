#pragma once
// std
// lib
// non-system
#include "stdafx.h"
// system

class Creature;

// user input 
class Controller
{
public:
	Controller();
	~Controller();
public:
	void Update(bool & p_paused, std::list<Creature> & p_creatures, std::list<std::reference_wrapper<Creature>> & p_selectedCreatures);
private:
	void UpdateMousePos();
	void UpdateMouseDownPos();
	void TogglePause(bool & p_paused);
	void UpdateSelectionBox();
	void ControlCreatures(std::list<Creature> & p_creatures, std::list<std::reference_wrapper<Creature>> & p_selectedCreatures);
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