#include "Graphic.h"



Graphic::Graphic(const char * filePath_, GraphicsTypes graphicType_, int spriteSizeX_, int spriteSizeY_)
	:
	_texture{ LoadTexture(filePath_) },
	_graphicType{ graphicType_ },
	_spriteSizeX{ spriteSizeX_ },
	_spriteSizeY{ spriteSizeY_ }
{
}
Graphic::~Graphic()
{
	UnloadTexture(_texture);
}
