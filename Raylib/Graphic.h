#pragma once
#include "stdafx.h"
class Graphic
{
public:
	Graphic(const char * p_path, int p_nSpritesCol, int p_nSpritesRow)
		:
		m_texture{ LoadTexture(p_path) },
		m_nSpritesCol{ p_nSpritesCol },
		m_nSpriteRow{ p_nSpritesRow }
	{
	}
	~Graphic()
	{
		UnloadTexture(m_texture);
	}
	// member funcs

	// member vars
	Texture2D const m_texture;
	int const m_nSpritesCol;
	int const m_nSpriteRow;
	int const m_frameWidth = m_texture.width / m_nSpritesCol;
	int const m_frameHeight = m_texture.height / m_nSpriteRow;
	// NOTE: Source rectangle (part of the texture to use for drawing)
	Rectangle m_sourceRec = { 0, 0, (float)m_frameWidth, (float)m_frameHeight };
	// NOTE: Destination rectangle (screen rectangle where drawing part of texture)
	Rectangle destRec = { 0,0, (float)m_frameWidth * 2, (float)m_frameHeight * 2 };
	// NOTE: Origin of the texture (rotation/scale point), it's relative to destination rectangle size
	Vector2 origin = { (float)m_frameWidth, (float)m_frameHeight };
};