#include "Game.h"

#include "ProgramUtilities/Utilities.h"

#include "Objects/Bird.h"
#include "Objects/Obstacles.h"

namespace flappybird
{
	namespace game
	{
		const int MAX_OBSTACLES = 2;

		Bird player;
		Obstacle obstacleArray[MAX_OBSTACLES];

		Sprite BackgroundLayer1;
		Sprite BackgroundLayer2;

		Sprite BackgroundLayer3_1;
		Sprite BackgroundLayer3_2;

		Sprite BackgroundLayer4_1;
		Sprite BackgroundLayer4_2;

		Sprite BackgroundLayer5_1;
		Sprite BackgroundLayer5_2;
		
		void InitGame()
		{
			float firstPipeX = static_cast<float>(GetScreenWidth());
			float secondPipeX = firstPipeX + firstPipeX / 2;
			
			InitBird(player);
			InitObstacle(obstacleArray[0], firstPipeX);
			InitObstacle(obstacleArray[1], secondPipeX);
			InitParallax();
		}

		void InitParallax()
		{
			float scale = 0.7f;
			int distanceBugFix = 6;

			BackgroundLayer1.texture = LoadTexture("res/game/background/layer_1.png");
			BackgroundLayer1.scale = scale;
			BackgroundLayer1.position = { 0,0 };

			BackgroundLayer2.texture = LoadTexture("res/game/background/layer_2.png");
			BackgroundLayer2.scale = scale;
			BackgroundLayer2.position = { 0,0 };

			BackgroundLayer3_1.texture = LoadTexture("res/game/background/layer_3.png");
			BackgroundLayer3_1.scale = scale;
			BackgroundLayer3_1.velocity = 30;
			BackgroundLayer3_1.position = { 0,0 };

			BackgroundLayer3_2.texture = LoadTexture("res/game/background/layer_3.png");
			BackgroundLayer3_2.scale = scale;
			BackgroundLayer3_2.velocity = 30;
			BackgroundLayer3_2.position.x = (static_cast<float>(BackgroundLayer3_1.texture.width) * BackgroundLayer3_1.scale) / distanceBugFix + static_cast<float>(GetScreenWidth());

			BackgroundLayer4_1.texture = LoadTexture("res/game/background/layer_4.png");
			BackgroundLayer4_1.scale = scale;
			BackgroundLayer4_1.velocity = 60;
			BackgroundLayer4_1.position = { 0,0 };

			BackgroundLayer4_2.texture = LoadTexture("res/game/background/layer_4.png");
			BackgroundLayer4_2.scale = scale;
			BackgroundLayer4_2.velocity = 60;
			BackgroundLayer4_2.position.x = (static_cast<float>(BackgroundLayer4_1.texture.width) * BackgroundLayer4_1.scale) / distanceBugFix + static_cast<float>(GetScreenWidth());

			BackgroundLayer5_1.texture = LoadTexture("res/game/background/layer_5.png");
			BackgroundLayer5_1.scale = scale;
			BackgroundLayer5_1.velocity = 100;
			BackgroundLayer5_1.position = { 0,0 };

			BackgroundLayer5_2.texture = LoadTexture("res/game/background/layer_5.png");
			BackgroundLayer5_2.scale = scale;
			BackgroundLayer5_2.velocity = 100;
			BackgroundLayer5_2.position.x = (static_cast<float>(BackgroundLayer5_1.texture.width) * BackgroundLayer5_1.scale) / distanceBugFix + static_cast<float>(GetScreenWidth());
		}

		void GameUpdate(Screen& currentScene)
		{
			BirdUpdate(player);

			ObstacleUpdate(obstacleArray);
			
			CheckCollitions(currentScene);

			UpdateParallax();
			
			if (IsKeyDown(KEY_ESCAPE))
			{
				currentScene = Screen::Menu;
			}
		}

		void UpdateParallax()
		{
			UpdateLayer(BackgroundLayer3_1);
			UpdateLayer(BackgroundLayer3_2);
			UpdateLayer(BackgroundLayer4_1);
			UpdateLayer(BackgroundLayer4_2);
			UpdateLayer(BackgroundLayer5_1);
			UpdateLayer(BackgroundLayer5_2);
		}

		void UpdateLayer(Sprite& layer)
		{
			layer.position.x -= layer.velocity * GetFrameTime();

			if (layer.position.x + layer.texture.width * layer.scale < 0)
			{
				layer.position.x = static_cast<float>(GetScreenWidth());
			}
		}

		void DrawGame()
		{
			DrawParallax();
			ObstacleDraw(obstacleArray);
			BirdDraw(player);
			DrawText("Press Esc to return Menu", GetScreenWidth() - 300, 20, 20, BLACK);
		}

		void DrawParallax()
		{
			DrawSprite(BackgroundLayer1);
			DrawSprite(BackgroundLayer2);
			DrawSprite(BackgroundLayer3_1);
			DrawSprite(BackgroundLayer3_2);
			DrawSprite(BackgroundLayer4_1);
			DrawSprite(BackgroundLayer4_2);
			DrawSprite(BackgroundLayer5_1);
			DrawSprite(BackgroundLayer5_2);
		}

		void CheckCollitions(Screen& currentScene)
		{
			for (int i = 0; i < MAX_OBSTACLES; i++)
			{
				if (obstacleArray[i].isOnScreen)
				{
					if (CheckCollisionRecs(player.hitBox, obstacleArray[i].lowPart) || CheckCollisionRecs(player.hitBox, obstacleArray[i].topPart))
					{
						currentScene = Screen::Menu;
					}
				}
			}
			if (player.hitBox.y + player.hitBox.height > GetScreenHeight() - player.hitBox.height)
			{
				InitBird(player);
			}
		}
	}
}