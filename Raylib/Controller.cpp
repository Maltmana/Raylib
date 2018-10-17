#include "Controller.h"
#include "Creature.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::Update(bool & p_paused, std::list<Creature> & p_creatures, std::list<std::reference_wrapper<Creature>> & p_selectedCreatures)
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

void Controller::ControlCreatures(std::list<Creature>& p_creatures, std::list<std::reference_wrapper<Creature>>& p_selectedCreatures)
{
	// create creatures
	if (IsKeyReleased(KEY_SPACE))
	{
		p_creatures.emplace_back(GetMousePosition());
	}

	// move creatures
		for (Creature & selected : p_selectedCreatures)
		{

			if (IsMouseButtonReleased(1))
			{
				selected.change_targ(GetMousePosition());
			}
			if (IsMouseButtonReleased(1) && IsKeyDown(KEY_LEFT_SHIFT))
			{
				selected.m_wayPoints.push_back(GetMousePosition());
			}
		}

		// select creatures
	if (IsMouseButtonReleased(0))
	{
		p_selectedCreatures.clear();
		for (auto & creature : p_creatures)
		{
			if (IsMouseButtonReleased(0) && CheckCollisionCircleRec(creature.m_pos, creature.m_collisionRadius,selectionRect))
			{
				// dont add them until you release the box.
				p_selectedCreatures.push_back(creature);
			}
		}
	}
}
