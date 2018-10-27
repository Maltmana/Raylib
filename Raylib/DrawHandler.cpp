#include "stdafx.h"
#include "DrawHandler.h"


DrawHandler::DrawHandler()
{
}


DrawHandler::~DrawHandler()
{
}

void DrawHandler::handle_drawing(EntityContainer& entityContainer_, GraphicContainer& graphicContainer_)
{
	for (std::shared_ptr<Creature> const & creature : entityContainer_._entities)
	{
		auto& graphic = *graphicContainer_.getGraphics().front().get(); // TODO NEXT make it contingent on enum type.
		float rotation = 0.f;
		// NOTE: Source rectangle (part of the texture to use for drawing)
		Rectangle sourceRec = { 0, 0, (float)graphic.m_frameWidth, (float)graphic.m_frameHeight };
		// NOTE: Destination rectangle (screen rectangle where drawing part of texture)
		Rectangle destRec = { 0,0, (float)graphic.m_frameWidth, (float)graphic.m_frameHeight };
		// NOTE: Origin of the texture (rotation/scale point), it's relative to destination rectangle size
		Vector2 origin = { 0,0 };

		int typeOffset = (graphic.m_frameWidth * 3 * (int)creature->type);
		int frameOffset = ((creature->m_animation.currentFrame - 1) * graphic.m_frameWidth);
		sourceRec.x = typeOffset + frameOffset;
		sourceRec.y = creature->m_animation.currentFrameRow * graphic.m_frameHeight;
		destRec.x = creature->m_pos.x - graphic.m_frameWidth / 2;
		destRec.y = creature->m_pos.y - (graphic.m_frameHeight - 1);

		DrawTexturePro(graphic.m_texture, sourceRec, destRec, origin, rotation, WHITE);

		// draw collision sphere
		DrawCircleLines(creature->m_pos.x, creature->m_pos.y, creature->m_collisionRadius, RED);
	}
}
