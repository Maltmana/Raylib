#include "Controller.h"
#include "Creature.h"
#include "RNG.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::Update(bool & p_paused, EntityContainer& entityContainer_)
{

	TogglePause(p_paused); // TODO implement pause feature
	UpdateMousePos();
	UpdateMouseDownPos();
	UpdateSelectionBox();
	ControlCreatures(entityContainer_);
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

void Controller::ControlCreatures(EntityContainer& entityContainer_)
{

	// use lock to validate the weak ptrs.
	std::list<std::shared_ptr<Creature>> validatedSelectedCreatures;
	for(auto & selected : _selectedEntities._entitiesWP)
	{
		if (!selected.expired())
		{
			validatedSelectedCreatures.emplace_back(selected);
		}

	}

	// create creatures
	if (IsKeyReleased(KEY_SPACE))
	{
		entityContainer_._entities.emplace_back(std::shared_ptr<Creature>(new Creature((GraphicType)(int)RNG::get_randi(0,2), GetMousePosition())));
	}

	// delete creatures
	if (IsKeyReleased(KEY_DELETE))
	{
		for (auto & selected : validatedSelectedCreatures)
		{
			std::vector<std::shared_ptr<Creature>>::iterator i = entityContainer_._entities.begin();
			while (i != entityContainer_._entities.end())
			{
				if (selected == *i)
				{
					i = entityContainer_._entities.erase(i);
				}
				else
				{
					++i;
				}
			}
		}
	}

	// "group destination" and defining a group so they can have relative movement
	if (!validatedSelectedCreatures.empty())
	{
		std::shared_ptr<Creature> & leader = validatedSelectedCreatures.back();
		Vector2 groupPos = leader->m_pos;

		// move creatures and clear their waypoints.  // TODO MAKE THEM MOVE RELATIVELY WHEN IN A GROUP SO CAN MAKE CUSTOM FORMATIONS
		for (auto & selected : validatedSelectedCreatures)
		{
			auto groupRelativeTarget = RayMath::Vector2Add(GetMousePosition(), RayMath::Vector2Subtract(selected->m_pos,groupPos));

			if (IsMouseButtonReleased(1) && IsKeyDown(KEY_LEFT_SHIFT))
			{
				selected->m_wayPoints.push_back(groupRelativeTarget);
			}
			else if (IsMouseButtonReleased(1))
			{
				selected->change_targ(groupRelativeTarget);
				selected->m_wayPoints.clear();
				selected->m_creatureTargetWayPoints.clear(); // TODO throws read access violation when a selected dude is killed and then a move command is issued (screen click)  
															// the selected creature was cleared but still calling this
															// need to remove selected creature from all lists as soon as he dies...
			}
		}
	}

		// select creatures
	if (IsMouseButtonReleased(0))
	{
		_selectedEntities._entitiesWP.clear();
		validatedSelectedCreatures.clear(); // not sure if i need to do both.
		for (auto & creature : entityContainer_._entities)
		{
			if (IsMouseButtonReleased(0) && CheckCollisionCircleRec(creature->m_pos, creature->m_collisionRadius,selectionRect))
			{
				// dont add them until you release the box.
				_selectedEntities._entitiesWP.push_back(creature);
			}
		}
	}

	// give creatures a target creature to attack
	if (IsMouseButtonReleased(1))
	{
		std::shared_ptr<Creature> targetedCreature = nullptr;
		for (auto  & creature : entityContainer_._entities)
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

	// print information of selected creatures
	float i = 0;
	std::string tempS;
	for (auto & selected : validatedSelectedCreatures)
	{ 
		tempS = "ID: " + std::to_string(selected->_id);
		float x = 10;
		DrawTextEx(GetFontDefault(), tempS.c_str(), { x, i * 10 }, 10, 2, RED);
		float spaces = tempS.size();
		float fontWidth = 6.5;

		x += spaces * fontWidth;
		tempS = "POS: " + std::to_string(selected->m_pos.x) + " , " + std::to_string(selected->m_pos.y);
		DrawTextEx(GetFontDefault(), tempS.c_str(), { x, i * 10 }, 10, 2, RED);
		spaces = tempS.size();

		tempS = "TARG: " + std::to_string(selected->m_targPos.x) + " , " + std::to_string(selected->m_targPos.y);
		x += spaces * fontWidth;
		DrawTextEx(GetFontDefault(), tempS.c_str(), { x, i * 10 }, 10, 2, RED);
		spaces = tempS.size();
		i++;
	}


}
