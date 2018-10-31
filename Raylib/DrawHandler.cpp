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
		for (auto& graphic : graphicContainer_.getGraphics())
		{
			if (creature->_graphicType == graphic->_graphicType)
			{
				int facingOffset{ creature->m_facing * graphic->m_frameHeight };
				int animationOffset = ((creature->m_animation.currentFrame - 1) * graphic->m_frameWidth);


				// NOTE: Source rectangle (part of the texture to use for drawing)
				Rectangle sourceRec = { animationOffset, facingOffset, (float)graphic->m_frameWidth, (float)graphic->m_frameHeight };

				int creaturePosX = creature->m_pos.x - graphic->m_frameWidth / 2;
				int creaturePosY = creature->m_pos.y - (graphic->m_frameHeight - 1);
				// NOTE: Destination rectangle (screen rectangle where drawing part of texture)
				Rectangle destRec = { creaturePosX,creaturePosY, (float)graphic->m_frameWidth, (float)graphic->m_frameHeight };
				// NOTE: Origin of the texture (rotation/scale point), it's relative to destination rectangle size
				Vector2 origin = { 0,0 };



				float rotation = 0.f;
				DrawTexturePro(graphic->m_texture, sourceRec, destRec, origin, rotation, WHITE);

				// draw collision sphere
				DrawCircleLines(creature->m_pos.x, creature->m_pos.y, creature->m_collisionRadius, RED);
			}
		}
	}
}
