#pragma once
// std
// lib
// non-system
#include "stdafx.h"
#include "Enums.h"
// system


// in : path and sprite size and enum association. from this rows and columns are generated. rows = directions. columns = frames of animation.
// association is used by TextureProvider
class Graphic
{
public:
	Graphic(const char * filePath_, GraphicsTypes graphicType_, int spriteSizeX_, int spriteSizeY_);
	~Graphic();
public:
private:
public:
	// flags
	// enums
	GraphicsTypes _graphicType;
	// primitives
	int const _spriteSizeX;
	int const _spriteSizeY;
	int const _nSpriteRows = _texture.height / _spriteSizeY;
	int const _nSpritesCols = _texture.width / _spriteSizeX;
	Vector2 _origin = { (float)_spriteSizeX / 2, (float)_spriteSizeY / 2 };
	// objects
	Texture2D const _texture;
private:
};