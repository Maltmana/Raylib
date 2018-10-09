#pragma once
#include "stdafx.h"


class Creature;

/* Functions for user input and data relevant to user input. */
class Controller
{
public:
	Controller();
	~Controller();
public:
	void update(bool & p_paused, std::vector<Creature> & p_creatures, std::vector<std::reference_wrapper<Creature>> & p_selectedCreatures);

public:
	Vector2 mouseDownPosition = { 0,0 };

	Rectangle selectionRect = { 0,0,0,0 };

};