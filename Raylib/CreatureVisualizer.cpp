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

}
