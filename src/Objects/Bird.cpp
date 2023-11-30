#include "Bird.h"

namespace flappybird
{
	namespace game
	{
		float animationTimer = 0;

		Sound jump;

		void BirdUpdate(Bird& player)
		{
			float texturePos1 = 0;
			float texturePos2 = player.texture.width / 2.0f;

			const float animationCooldown = 0.3f;

			animationTimer += GetFrameTime();

			if (player.hitBox.y - player.hitBox.height > 0)
			{
				if (IsKeyPressed(player.actionKey))
				{
					PlaySound(jump);
					player.velocity.y = (player.aceleration);
					player.rotation = player.TOP_ROTATION;

					if (animationTimer >= animationCooldown)
					{
						if (player.source.x == texturePos1)
						{
							player.source = { texturePos2, 0, static_cast<float>(player.texture.width / 2), static_cast<float>(player.texture.height) };
						}

						animationTimer = 0;
					}
				}
				else
				{
					player.velocity.y += player.gravity * GetFrameTime();

					player.rotation += player.ROTATION_GRAVITY * GetFrameTime();

					if (player.rotation > player.LOWEST_ROTATION)
					{
						player.rotation = player.LOWEST_ROTATION;
					}

					if (player.velocity.y > player.TERMINAL_VELOCITY)
					{
						player.velocity.y = player.TERMINAL_VELOCITY;
					}

					if (animationTimer >= animationCooldown)
					{
						player.source = { texturePos1, 0, static_cast<float>(player.texture.width / 2), static_cast<float>(player.texture.height) };
					}
				}
			}
			else
			{
				player.velocity.y += player.gravity * GetFrameTime();

				player.rotation += player.ROTATION_GRAVITY * GetFrameTime();
				
				if (player.rotation > player.LOWEST_ROTATION)
				{
					player.rotation = player.LOWEST_ROTATION;
				}

				if (player.velocity.y > player.TERMINAL_VELOCITY)
				{
					player.velocity.y = player.TERMINAL_VELOCITY;
				}
			}

			float scale = 0.7f;
			player.hitBox.y += player.velocity.y * GetFrameTime();
			player.dest = { player.hitBox.x + player.hitBox.width / 2, player.hitBox.y + player.hitBox.height / 2, player.SPRITE_SIZE_W * scale, player.SPRITE_SIZE_H * scale };
		}

		void BirdDraw(Bird player)
		{
			DrawTexturePro(player.texture,player.source,player.dest,player.origin,player.rotation,player.color);
		}

		void InitBird(Bird& player, float xPos, KeyboardKey key, Texture2D texture)
		{
			jump = LoadSound("res/sounds/jump.mp3");

			player.actionKey = key;

			float scale = 0.7f;

			player.hitBox = { xPos, static_cast<float>(GetScreenHeight()) / 2 , player.SPRITE_SIZE_W * 0.3f, player.SPRITE_SIZE_H * 0.3f };
			player.velocity = {0,0};

			player.texture = texture;
			player.rotation = 0;

			player.origin = { (player.SPRITE_SIZE_W * scale) / 2, (player.SPRITE_SIZE_H * scale) / 2 };
			player.dest = { player.hitBox.x + player.origin.x, player.hitBox.y + player.origin.y, player.SPRITE_SIZE_W * scale, player.SPRITE_SIZE_H * scale };
			player.source = { 0, 0, static_cast<float>(player.texture.width) / 2, static_cast<float>(player.texture.height)};
		}
	}
}