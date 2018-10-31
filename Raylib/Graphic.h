#pragma once
// std
// lib
// non-system
#include "stdafx.h"
#include "Enums.h"
// system

/* Holds loaded texture with data connected to that texture. */
class Graphic
{
public:
	Graphic(GraphicType graphicType_, const char * p_path, int p_nSpritesCol, int p_nSpritesRow)
		:
		_graphicType{graphicType_},
		m_texture{ LoadTexture(p_path) },
		m_nSpritesCol{ p_nSpritesCol },
		m_nSpriteRow{ p_nSpritesRow }
	{
	}
	~Graphic()
	{
		UnloadTexture(m_texture);
	}
public:
private:
public:
	// objects
	Texture2D const m_texture;
	// primitives
	GraphicType _graphicType;
	int const m_nSpritesCol;
	int const m_nSpriteRow;
	int const m_frameWidth = m_texture.width / m_nSpritesCol;
	int const m_frameHeight = m_texture.height / m_nSpriteRow;

private:

};