#include "stdafx.h"
#include "GraphicsSystem.h"


GraphicsSystem::GraphicsSystem(std::vector<std::unique_ptr<Graphic>> const & graphicsContainer_)
	:
	_graphicsContainer{graphicsContainer_}
{
}



GraphicsSystem::~GraphicsSystem()
{
}

void GraphicsSystem::draw(GraphicsComponent const & graphicsComp_, PhysicalComponent const & physicalComp_, AnimationComponent const & animationComp_)
{

	for (auto const & graphic : _graphicsContainer) // TODO check if graphic unique ptr is valid
	{
		if (graphic.get()->_graphicType == graphicsComp_._graphicsType)
		{
			float scale = 2;

			//NOTE: Source rectangle (part of the texture to use for drawing)
			// animation system needs to provide X and Y here...
			float spriteSizeX = (float)graphic.get()->_spriteSizeX;
			float spriteSizeY = (float)graphic.get()->_spriteSizeY;
			Rectangle sourceRec = { animationComp_._currentFrameCol * spriteSizeX,
									animationComp_._currentFrameRow * spriteSizeY ,
									spriteSizeX,
									spriteSizeY };

			//// NOTE: Destination rectangle (screen rectangle where drawing part of texture)
			Rectangle destRec = { physicalComp_._position.x,
								physicalComp_._position.y,
								spriteSizeX,
								spriteSizeY };


			// drawing
			float rotation = 0.f;
			DrawTexturePro(graphic.get()->_texture, sourceRec, destRec, graphic.get()->_origin, rotation, WHITE);
			// draw collision sphere
			DrawCircleLines(physicalComp_._position.x, physicalComp_._position.y, physicalComp_._collisionRadius, RED);
			return;
		}
	}

	



}
