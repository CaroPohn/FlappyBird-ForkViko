#include "Obstacles.h"

#include <iostream>

namespace flappybird
{
	namespace game
	{
		int currentObstacle = 0;
		int Obstacle::obstacleCounter = 0;

		Obstacle::Obstacle()
		{
			obstacleCounter++;
			isOnScreen = false;
		}

		void ObstacleUpdate(Obstacle obstacleArray[], Bird& playerOne, Bird& playerTwo)
		{
			for (int i = 0; i < Obstacle::obstacleCounter; i++)
			{
				if (obstacleArray[i].isOnScreen)
				{
					obstacleArray[i].topPart.x -= obstacleArray[i].velocity * GetFrameTime();
					obstacleArray[i].lowPart.x -= obstacleArray[i].velocity * GetFrameTime();
					obstacleArray[i].middleSpace.x -= obstacleArray[i].velocity * GetFrameTime();

					if (obstacleArray[i].topPart.x + obstacleArray[i].topPart.width < 0)
					{
						obstacleArray[i].isOnScreen = false;
						ResetObstacle(obstacleArray[i], playerOne, playerTwo);
					}
				}
			}
		}

		void ObstacleDraw(Obstacle obstacleArray[])
		{
			for (int i = 0; i < Obstacle::obstacleCounter; i++)
			{
				if (obstacleArray[i].isOnScreen)
				{
					//DrawRectangleRec(obstacleArray[i].topPart, obstacleArray[i].color);
					//DrawRectangleRec(obstacleArray[i].lowPart, obstacleArray[i].color);
					//DrawRectangleRec(obstacleArray[i].middleSpace, PINK);
					DrawTexture(obstacleArray[i].upperTexture, static_cast<int>(obstacleArray[i].topPart.x), static_cast<int>(0 - (obstacleArray[i].upperTexture.height - obstacleArray[i].topPart.height)), WHITE);
					DrawTexture(obstacleArray[i].bottomTexture, static_cast<int>(obstacleArray[i].topPart.x), static_cast<int>(obstacleArray[i].lowPart.y), WHITE);
				}
			}
		}

		void InitObstacle(Obstacle& obstacle, float posX, Bird& playerOne, Bird& playerTwo, Texture2D upper, Texture2D bottom)
		{
			obstacle.middleSpace = { posX,  static_cast<float>(GetRandomValue(200,500)), 80, 160.0f };
			obstacle.topPart = { posX , 0, 80, obstacle.middleSpace.y };
			obstacle.lowPart = { posX , obstacle.middleSpace.y + obstacle.middleSpace.height, 80, static_cast<float>(GetScreenHeight()) };
			obstacle.isOnScreen = true;
			obstacle.timesChecked = 0;
			obstacle.justGivenPoints = false;
			obstacle.upperTexture = upper;
			obstacle.bottomTexture = bottom;

			playerOne.alredyChecked = false;
			playerTwo.alredyChecked = false;
		}

		void ResetObstacle(Obstacle& obstacle, Bird& playerOne, Bird& playerTwo)
		{
			obstacle.middleSpace = { static_cast<float>(GetScreenWidth()),  static_cast<float>(GetRandomValue(200,500)), 80, 160.0f };
			obstacle.topPart = { static_cast<float>(GetScreenWidth()) , 0, 80, obstacle.middleSpace.y };
			obstacle.lowPart = { static_cast<float>(GetScreenWidth()) , obstacle.middleSpace.y + obstacle.middleSpace.height, 80, static_cast<float>(GetScreenHeight()) };
			obstacle.isOnScreen = true;
			obstacle.timesChecked = 0;
			obstacle.justGivenPoints = false;

			playerOne.alredyChecked = false;
			playerTwo.alredyChecked = false;
		}
	}
}