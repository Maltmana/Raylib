#include "CreatureVisualizer.h"
#include "Creature.h"
#include "Graphic.h"

CreatureVisualizer::CreatureVisualizer()
{
}

CreatureVisualizer::~CreatureVisualizer()
{
}

void CreatureVisualizer::visualize(Creature const & creature, Graphic const & graphic)
{
	update_animation(creature);
	draw(creature, graphic);
}

void CreatureVisualizer::update_animation(Creature const & creature)
{
}

void CreatureVisualizer::draw(Creature const & creature, Graphic const & graphic)
{
	float rotation = 0.f;

	Rectangle destRec = { creature.m_pos.x, creature.m_pos.y,graphic.m_frameWidth, graphic.m_frameHeight };
	DrawTexturePro(graphic.m_texture, graphic.m_sourceRec, destRec, graphic.origin, rotation, WHITE);

	// draw collision box
	DrawRectangleLinesEx(creature.m_collision, 1, RED);
}
