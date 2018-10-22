#include "stdafx.h"
#include "PhysicalComponent.h"


PhysicalComponent::PhysicalComponent(Vector2 position_, Vector2 velocity_, float speed_)
	:
	_position{ position_ },
	_velocity{velocity_},
	_speed{speed_}
{
}


PhysicalComponent::~PhysicalComponent()
{
}
