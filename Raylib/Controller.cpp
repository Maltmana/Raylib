#include "Controller.h"
#include "Creature.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::update(bool & p_paused, std::vector<Creature> & p_creatures, std::vector<std::reference_wrapper<Creature>> & p_selectedCreatures)
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

	if (!p_paused)
	{
		if (IsKeyReleased(KEY_SPACE))
		{
			p_creatures.emplace_back(GetMousePosition());
		}

		if (IsMouseButtonPressed(0))
		{
			mouseDownPosition = GetMousePosition();
		}

	}

	// if button is pressed mess with selection rect.
	if (IsMouseButtonDown(0))
	{
		int mouseY = (int)GetMouseY();

		if ((float)GetMouseX() - mouseDownPosition.x <= 0 && (float)GetMouseY() - mouseDownPosition.y <= 0)
		{
			selectionRect = { (float)GetMouseX(), (float)GetMouseY(), mouseDownPosition.x - (float)GetMouseX(),mouseDownPosition.y - (float)GetMouseY() };
		}
		else if ((float)GetMouseY() - mouseDownPosition.y <= 0)
		{
			selectionRect = { mouseDownPosition.x, (float)GetMouseY(), (float)GetMouseX() - mouseDownPosition.x, mouseDownPosition.y - (float)GetMouseY() };
		}
		else if ((float)GetMouseX() - mouseDownPosition.x <= 0)
		{
			selectionRect = { (float)GetMouseX(), mouseDownPosition.y, mouseDownPosition.x - (float)GetMouseX(),(float)GetMouseY() - mouseDownPosition.y };
		}
		else
		{
			selectionRect = { mouseDownPosition.x, mouseDownPosition.y,(float)GetMouseX() - mouseDownPosition.x,(float)GetMouseY() - mouseDownPosition.y };
		}
	}

	if (IsMouseButtonReleased(0) && !p_paused)
	{
		mouseDownPosition = { 0,0 };
	}

	if (!p_paused)
	{
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
	}


	if (IsMouseButtonReleased(0))
	{
		p_selectedCreatures.clear();
		for (auto & creature : p_creatures)
		{
			if (IsMouseButtonReleased(0) && CheckCollisionRecs(creature.m_collision, selectionRect))
			{
				// dont add them until you release the box.
				p_selectedCreatures.push_back(creature);
			}
		}
	}

	if (!IsMouseButtonDown(0))
	{
		selectionRect = { 0,0,0,0 };
	}


}
