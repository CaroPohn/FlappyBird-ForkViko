#include "Game.h"

#include "ProgramUtilities/Utilities.h"

#include "Objects/Bird.h"
#include "Objects/Obstacles.h"
#include "LoseScreen.h"
#include <iostream>
#include <string>

namespace flappybird
{
	namespace game
	{
		const int MAX_OBSTACLES = 2;

		Bird player;
		Bird playerTwo;

		Texture2D player1Texture;
		Texture2D player2Texture;

		Texture2D upper1;
		Texture2D upper2;

		Texture2D bottom1;
		Texture2D bottom2;

		Texture2D pauseTexture;

		Obstacle obstacleArray[MAX_OBSTACLES];

		Sprite PauseButton;

		Sprite BackgroundLayer1;
		Sprite BackgroundLayer2;

		Sprite BackgroundLayer3_1;
		Sprite BackgroundLayer3_2;

		Sprite BackgroundLayer4_1;
		Sprite BackgroundLayer4_2;

		Sprite BackgroundLayer5_1;
		Sprite BackgroundLayer5_2;

		PlayerCount players;

		Sound playerHurt;
		Sound buttonGame;
		
		void InitGame(PlayerCount playerCount, int& pointsCounter, bool& isGameOver, bool& isPaused)
		{
			playerHurt = LoadSound("res/sounds/playerhurt.mp3");
			buttonGame = LoadSound("res/sounds/button.mp3");

			players = playerCount;
			pointsCounter = 0;

			int pauseButOffset = 10;

			isGameOver = false;
			isPaused = false;

			float firstPipeX = static_cast<float>(GetScreenWidth());
			float secondPipeX = firstPipeX + firstPipeX / 2;

			pauseTexture = LoadTexture("res/game/pause/pauseButton.png");

			player1Texture = LoadTexture("res/game/bird/player1.png");
			player2Texture = LoadTexture("res/game/bird/player2.png");

			upper1 = LoadTexture("res/game/obstacle/upObstacle.png");
			upper2 = LoadTexture("res/game/obstacle/upObstacleDark.png");

			bottom1 = LoadTexture("res/game/obstacle/downObstacle.png");
			bottom2 = LoadTexture("res/game/obstacle/downObstacleDark.png");

			PauseButton.texture = pauseTexture;
			PauseButton.scale = 0.5f;
			PauseButton.position = { static_cast<float>(pauseButOffset) , static_cast<float>(GetScreenHeight() - PauseButton.texture.height * PauseButton.scale - pauseButOffset)};

			if (players == PlayerCount::TwoPlayers)
			{
				InitBird(playerTwo, 200, KeyboardKey::KEY_UP, player2Texture);		
			}
			
			InitBird(player, 100, KeyboardKey::KEY_W, player1Texture);
			InitObstacle(obstacleArray[0], firstPipeX, player, playerTwo, upper1, bottom1);
			InitObstacle(obstacleArray[1], secondPipeX, player, playerTwo, upper2, bottom2);
			InitParallax();
		}

		void InitParallax()
		{
			float scale = 0.7f;
			int distanceBugFix = 5;
			int offsetBugFix = 7;

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
			BackgroundLayer3_2.position.x = (static_cast<float>(BackgroundLayer3_1.texture.width) * BackgroundLayer3_1.scale) / distanceBugFix + static_cast<float>(GetScreenWidth() - 7);

			BackgroundLayer4_1.texture = LoadTexture("res/game/background/layer_4.png");
			BackgroundLayer4_1.scale = scale;
			BackgroundLayer4_1.velocity = 60;
			BackgroundLayer4_1.position = { 0,0 };

			BackgroundLayer4_2.texture = LoadTexture("res/game/background/layer_4.png");
			BackgroundLayer4_2.scale = scale;
			BackgroundLayer4_2.velocity = 60;
			BackgroundLayer4_2.position.x = (static_cast<float>(BackgroundLayer4_1.texture.width) * BackgroundLayer4_1.scale) / distanceBugFix + static_cast<float>(GetScreenWidth() - offsetBugFix);

			BackgroundLayer5_1.texture = LoadTexture("res/game/background/layer_5.png");
			BackgroundLayer5_1.scale = scale;
			BackgroundLayer5_1.velocity = 100;
			BackgroundLayer5_1.position = { 0,0 };

			BackgroundLayer5_2.texture = LoadTexture("res/game/background/layer_5.png");
			BackgroundLayer5_2.scale = scale;
			BackgroundLayer5_2.velocity = 100;
			BackgroundLayer5_2.position.x = (static_cast<float>(BackgroundLayer5_1.texture.width) * BackgroundLayer5_1.scale) / distanceBugFix + static_cast<float>(GetScreenWidth() - offsetBugFix);
		}

		void GameUpdate(int& pointsCounter, bool& isGameOver, bool& isPaused)
		{						
			if (isGameOver)
			{
				InitGame(players, pointsCounter, isGameOver, isPaused);
				isGameOver = false;
			}
			
			if (players == PlayerCount::TwoPlayers)
			{
				BirdUpdate(playerTwo);
				CheckCollitions(playerTwo, pointsCounter, isGameOver, isPaused);
			}

			BirdUpdate(player);
			ObstacleUpdate(obstacleArray, player, playerTwo);
			CheckCollitions(player, pointsCounter, isGameOver, isPaused);
			UpdateParallax();

			if (MouseColision(PauseButton))
			{
				PauseButton.color = GRAY;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					PlaySound(buttonGame);
					isPaused = true;
				}
			}
			else
			{
				PauseButton.color = WHITE;
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
			int distanceBugFix = 5;
			int offsetBugFix = 7;

			layer.position.x -= layer.velocity * GetFrameTime();

			if (layer.position.x + layer.texture.width * layer.scale < 0)
			{
				layer.position.x = static_cast<float>(GetScreenWidth() + (static_cast<float>(BackgroundLayer5_1.texture.width) * BackgroundLayer5_1.scale) / distanceBugFix) - offsetBugFix;
			}
		}

		void DrawGame(int pointsCounter)
		{
			DrawParallax();
			ObstacleDraw(obstacleArray);
			BirdDraw(player);

			if (players == PlayerCount::TwoPlayers)
			{
				BirdDraw(playerTwo);
			}

			DrawText(std::to_string(pointsCounter).c_str(), 10, 10, 60, RED);
			DrawSprite(PauseButton);
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

		void CheckCollitions(Bird toCheck, int& pointsCounter, bool& isGameOver, bool& isPaused)
		{
			if (toCheck.hitBox.y > GetScreenHeight())
			{
				PlaySound(playerHurt);
				isGameOver = true;
				isPaused = true;
				return;
			}

			for (int i = 0; i < MAX_OBSTACLES; i++)
			{
				if (obstacleArray[i].isOnScreen)
				{
					if (CheckCollisionRecs(toCheck.hitBox, obstacleArray[i].lowPart) || CheckCollisionRecs(toCheck.hitBox, obstacleArray[i].topPart))
					{
						PlaySound(playerHurt);
						isGameOver = true;
						isPaused = true;
						return;
					}
				}
			}

			CheckBirdObstacleCollition(obstacleArray[0], player, pointsCounter);
			CheckBirdObstacleCollition(obstacleArray[1], player, pointsCounter);

			CheckBirdObstacleCollition(obstacleArray[0], playerTwo, pointsCounter);
			CheckBirdObstacleCollition(obstacleArray[1], playerTwo, pointsCounter);
		}

		void CheckBirdObstacleCollition(Obstacle& obstacle, Bird& playerToCheck, int& pointsCounter)
		{
			if (obstacle.justGivenPoints)
				return;

			if (playerToCheck.alredyChecked)
				return;

			if (CheckCollisionRecs(obstacle.middleSpace, playerToCheck.hitBox))
			{
				obstacle.timesChecked++;
				playerToCheck.alredyChecked = true;
			}

			if (obstacle.timesChecked == static_cast<int>(players))
			{
				pointsCounter++;
				obstacle.justGivenPoints = true;
			}
		}
	}
}