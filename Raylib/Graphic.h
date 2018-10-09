#pragma once
#include "stdafx.h"

/* Holds loaded texture with data connected to that texture. */
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

};