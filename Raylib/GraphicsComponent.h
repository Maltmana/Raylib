#pragma once

enum class GraphicsTypes
{
	Monk,
	Fabio,
	DKnight,
	Wizard,
	Druid,
	Priest,
	ThunderSword,
	BootsOfSpeed
};

struct GraphicsComponent
{
	GraphicsComponent(GraphicsTypes graphicsType_);
	~GraphicsComponent();
	// NO FUNCTIONS
	GraphicsTypes _graphicsType;

};

