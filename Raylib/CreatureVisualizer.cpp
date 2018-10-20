#include "CreatureVisualizer.h"
#include "Creature.h"
#include "Graphic.h"

CreatureVisualizer::CreatureVisualizer()
{
}

CreatureVisualizer::~CreatureVisualizer()
{
}

void CreatureVisualizer::visualize(std::shared_ptr<Creature> const & creature, Graphic const & graphic) const
{



	update_animation(creature);
	draw(creature, graphic);
}

void CreatureVisualizer::update_animation(std::shared_ptr<Creature> const & creature) const
{
}

void CreatureVisualizer::draw(std::shared_ptr<Creature> const & creature, Graphic const & graphic) const
{
	float rotation = 0.f;
	// NOTE: Source rectangle (part of the texture to use for drawing)
	Rectangle sourceRec = { 0, 0, (float)graphic.m_frameWidth, (float)graphic.m_frameHeight };
	// NOTE: Destination rectangle (screen rectangle where drawing part of texture)
	Rectangle destRec = { 0,0, (float)graphic.m_frameWidth, (float)graphic.m_frameHeight};
	// NOTE: Origin of the texture (rotation/scale point), it's relative to destination rectangle size
	Vector2 origin = { 0,0 };

	int typeOffset = (graphic.m_frameWidth * 3 * (int)creature->type);
	int frameOffset = ((creature->m_animation.currentFrame - 1) * graphic.m_frameWidth);
	sourceRec.x = typeOffset + frameOffset;
	sourceRec.y = creature->m_animation.currentFrameRow * graphic.m_frameHeight;
	destRec.x = creature->m_pos.x - graphic.m_frameWidth/2;
	destRec.y = creature->m_pos.y - (graphic.m_frameHeight-1);

	DrawTexturePro(graphic.m_texture, sourceRec, destRec, origin, rotation, WHITE);

	// draw collision sphere
	DrawCircleLines(creature->m_pos.x, creature->m_pos.y, creature->m_collisionRadius, RED);
}
