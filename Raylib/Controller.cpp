#include "Controller.h"
#include "Creature.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::Update(bool & p_paused, std::list<std::shared_ptr<Creature>> & p_creatures, std::list<std::weak_ptr<Creature>> & p_selectedCreatures)
{

	TogglePause(p_paused); // TODO implement pause feature
	UpdateMousePos();
	UpdateMouseDownPos();
	UpdateSelectionBox();
	ControlCreatures(p_creatures, p_selectedCreatures);
}

void Controller::Draw()
{
	DrawRectangleLinesEx(selectionRect, 2, GREEN);
}

void Controller::UpdateMousePos()
{
	_mouseX = GetMouseX();
	_mouseY = GetMouseY();

}

void Controller::UpdateMouseDownPos()
{
	if (IsMouseButtonPressed(0))
	{
		_mouseDownX = _mouseX;
		_mouseDownY = _mouseY;
	}
	else if (IsMouseButtonReleased(0))
	{
		_mouseDownX = 0;
		_mouseDownY = 0;
	}
}

void Controller::TogglePause(bool & p_paused) // TODO add timer so pause doesn't spam.
{
	if (IsKeyReleased(284))
	{
		if (p_paused == false)
		{
			p_paused = true;
		}
		else
		{
			p_paused = false;
		}
	}
}

void Controller::UpdateSelectionBox()
{
	float _mouseX = this->_mouseX; // TODO this is horrible and cheating lol
	float _mouseY = this->_mouseY;
	float _mouseDownX = this->_mouseDownX;
	float _mouseDownY = this->_mouseDownY;

	// set the rect to between mouse curr and mouse down
	if (IsMouseButtonDown(0))
	{
		if (_mouseX - _mouseDownX <= 0 && _mouseY - _mouseDownY <= 0)
		{
			selectionRect = { _mouseX, _mouseY, _mouseDownX - _mouseX ,_mouseDownY - _mouseY };
		}
		else if (_mouseY - _mouseDownY <= 0)
		{
			selectionRect = { _mouseDownX, _mouseY, _mouseX - _mouseDownX, _mouseDownY - _mouseY };
		}
		else if (_mouseX - _mouseDownX <= 0)
		{
			selectionRect = { _mouseX, _mouseDownY, _mouseDownX - _mouseX,_mouseY - _mouseDownY };
		}
		else
		{
			selectionRect = { _mouseDownX, _mouseDownY,_mouseX - _mouseDownX,_mouseY - _mouseDownY };
		}
	}

	// set rect to default
	if (!IsMouseButtonDown(0) && !IsMouseButtonReleased(0))
	{
		selectionRect = { 0,0,0,0 };
	}
}

void Controller::ControlCreatures(std::list<std::shared_ptr<Creature>> & p_creatures, std::list<std::weak_ptr<Creature>> & p_selectedCreatures)
{

	// use lock to validate the weak ptrs.
	std::list<std::shared_ptr<Creature>> validatedSelectedCreatures;
	for(auto & selected : p_selectedCreatures)
	{
		if (!selected.expired())
		{
			validatedSelectedCreatures.emplace_back(selected);
		}

	}

	// create creatures
	if (IsKeyReleased(KEY_SPACE))
	{
		p_creatures.emplace_back(std::shared_ptr<Creature>(new Creature(GetMousePosition())));
	}

	// delete creatures
	if (IsKeyReleased(KEY_DELETE))
	{
		for (auto & selected : validatedSelectedCreatures)
		{
			std::list<std::shared_ptr<Creature>>::iterator i = p_creatures.begin();
			while (i != p_creatures.end())
			{
				if (selected == *i)
				{
					i = p_creatures.erase(i);
				}
				else
				{
					++i;
				}
			}
		}
	}

	// move creatures and clear their waypoints.  // TODO MAKE THEM MOVE RELATIVELY WHEN IN A GROUP SO CAN MAKE CUSTOM FORMATIONS
	for (auto & selected : validatedSelectedCreatures)
	{
			if (IsMouseButtonReleased(1) && IsKeyDown(KEY_LEFT_SHIFT))
			{
				selected->m_wayPoints.push_back(GetMousePosition());
			}
			else if (IsMouseButtonReleased(1))
			{
				selected->change_targ(GetMousePosition());
				selected->m_wayPoints.clear();
				selected->m_creatureTargetWayPoints.clear(); // TODO throws read access violation when a selected dude is killed and then a move command is issued (screen click)  
															// the selected creature was cleared but still calling this
															// need to remove selected creature from all lists as soon as he dies...
			}
	}

		// select creatures
	if (IsMouseButtonReleased(0))
	{
		p_selectedCreatures.clear();
		validatedSelectedCreatures.clear(); // not sure if i need to do both.
		for (auto & creature : p_creatures)
		{
			if (IsMouseButtonReleased(0) && CheckCollisionCircleRec(creature->m_pos, creature->m_collisionRadius,selectionRect))
			{
				// dont add them until you release the box.
				p_selectedCreatures.push_back(creature);
			}
		}
	}

	// give creatures a target creature to attack
	if (IsMouseButtonReleased(1))
	{
		std::shared_ptr<Creature> targetedCreature = nullptr;
		for (auto  & creature : p_creatures)
		{
			if (CheckCollisionPointCircle({ (float)_mouseX, (float)_mouseY}, creature->m_pos, creature->m_collisionRadius))
			{
				targetedCreature = creature;
				std::cout << "mouse targeted ID: " << targetedCreature->_id << '\n';
			}
		}
		if (targetedCreature != nullptr)
		{
			for (auto & selected : validatedSelectedCreatures)
			{
				if (selected != targetedCreature)
				{
					selected->m_creatureTargetWayPoints.emplace_front(targetedCreature);
					std::cout << selected->_id << " is emplacing " << targetedCreature->_id << '\n';
				}

			}
		}
	}
}
