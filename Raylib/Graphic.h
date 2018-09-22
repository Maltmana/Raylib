#pragma once
#include "stdafx.h"
class Graphic
{
public:
	Graphic(std::string p_path)
		:
		texture{ LoadTexture(p_path.c_str()) }
	{
	}
	// member funcs

	// member vars
	Texture2D const texture;
};