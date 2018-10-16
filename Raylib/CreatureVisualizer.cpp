#include "CreatureVisualizer.h"
#include "Creature.h"
#include "Graphic.h"

CreatureVisualizer::CreatureVisualizer()
{
}

CreatureVisualizer::~CreatureVisualizer()
{
}

void CreatureVisualizer::visualize(Creature const & creature, Graphic const & graphic) const
{



	update_animation(creature);
	draw(creature, graphic);
}

void CreatureVisualizer::update_animation(Creature const & creature) const
{
}

void CreatureVisualizer::draw(Creature const & creature, Graphic const & graphic) const
{
	float rotation = 0.f;
	// NOTE: Source rectangle (part of the texture to use for drawing)
	Rectangle sourceRec = { 0, 0, (float)graphic.m_frameWidth, (float)graphic.m_frameHeight };
	// NOTE: Destination rectangle (screen rectangle where drawing part of texture)
	Rectangle destRec = { 0,0, (float)graphic.m_frameWidth, (float)graphic.m_frameHeight};
	// NOTE: Origin of the texture (rotation/scale point), it's relative to destination rectangle size
	Vector2 origin = { 0,0 };

	int typeOffset = (graphic.m_frameWidth * 3 * (int)creature.type);
	int frameOffset = ((creature.m_animation.currentFrame - 1) * graphic.m_frameWidth);
	sourceRec.x = typeOffset + frameOffset;
	sourceRec.y = creature.m_animation.currentFrameRow * 18;
	destRec.x = creature.m_pos.x;
	destRec.y = creature.m_pos.y;

	DrawTexturePro(graphic.m_texture, sourceRec, destRec, origin, rotation, WHITE);

	// draw collision box
	DrawRectangleLinesEx(creature.m_collision, 1, RED);
}
