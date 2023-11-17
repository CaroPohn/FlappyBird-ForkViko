#pragma once

#include "raylib.h"
#include "raymath.h"

namespace flappybird
{
	struct Sprite
	{
		Texture2D texture = {};
		Vector2 position = {};
		float scale = {};
		float velocity = {};
		Color color = { WHITE };
	};

	void DrawSprite(Sprite sprite);

	bool MouseColision(Sprite rec);
}
