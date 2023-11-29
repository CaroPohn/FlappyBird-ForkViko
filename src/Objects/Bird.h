#pragma once

#include "ProgramUtilities/Utilities.h"

namespace flappybird
{
	namespace game
	{
		struct Bird
		{
			const float SPRITE_SIZE_W = 180;
			const float SPRITE_SIZE_H = 100;
			Texture2D texture = {};
			Rectangle dest = { 0, 0, SPRITE_SIZE_W, SPRITE_SIZE_H };
			Rectangle source = {};
			Vector2 origin = {};

			float rotation = {};
			const float ROTATION_GRAVITY = { 50 };
			const float TOP_ROTATION = { -40 };
			const float LOWEST_ROTATION = { 50 };

			KeyboardKey actionKey;

			Rectangle hitBox = {};
			Color color = { WHITE };

			Vector2 velocity = { 0,0 };

			const float TERMINAL_VELOCITY = 400;
			float gravity = { 300 };

			float aceleration = {-250};

			bool alredyChecked = false;
		};
	
		void BirdUpdate(Bird& player);
		void BirdDraw(Bird player);
		void InitBird(Bird& player, float xPos, KeyboardKey key, Texture2D texture);
	
	}
}