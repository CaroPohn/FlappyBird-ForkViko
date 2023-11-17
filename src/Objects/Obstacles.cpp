#include "Obstacles.h"

namespace flappybird
{
	namespace game
	{
		static void CreateObstacle(Obstacle  obstacle[]);

		int obstacleCounter = 0;
		int currentObstacle = 0;

		void ObstacleUpdate(Obstacle obstacle[])
		{
			for (int i = 0; i < obstacle[i].MAX_OBSTACLES; i++)
			{
				if (obstacle[i].isOnScreen)
				{
					obstacle[i].topPart.x -= obstacle[i].velocity * GetFrameTime();
					obstacle[i].lowPart.x -= obstacle[i].velocity * GetFrameTime();
					obstacle[i].middleSpace.x -= obstacle[i].velocity * GetFrameTime();

					if (obstacle[i].topPart.x + obstacle[i].topPart.width < 0)
					{
						obstacle[i].isOnScreen = false;
					}
				}

				CreateObstacle(obstacle);
			}
		}

		void ObstacleDraw(Obstacle obstacle[])
		{
			for (int i = 0; i < obstacle[i].MAX_OBSTACLES; i++)
			{
				if (obstacle[i].isOnScreen)
				{
					DrawRectangleRec(obstacle[i].topPart, obstacle[i].color);
					DrawRectangleRec(obstacle[i].lowPart, obstacle[i].color);
					DrawRectangleRec(obstacle[i].middleSpace, PINK);
				}
			}
		}

		void InitObstacle(Obstacle obstacle[])
		{
			for (int i = 0; i < obstacle[i].MAX_OBSTACLES; i++)
			{
				obstacle[i].isOnScreen = false;
			}
		}
	
		static void CreateObstacle(Obstacle  obstacle[])
		{
			obstacleCounter = 0;

			for (int i = 0; i < obstacle[i].MAX_OBSTACLES; i++)
			{
				if (obstacle[i].isOnScreen)
				{
					obstacleCounter++;
				}
			}

			for (int i = 0; i < obstacle[i].MAX_OBSTACLES; i++)
			{

				if (!obstacle[i].isOnScreen && obstacle[i].MAX_PIPES_IN_SCREEN > obstacleCounter)
				{

					obstacle[i].middleSpace = { static_cast<float>(GetScreenWidth()),  static_cast<float>(GetRandomValue(200,500)), 90,  150.0f};
					
					obstacle[i].topPart = { static_cast<float>(GetScreenWidth()) , 0, 90, obstacle[i].middleSpace.y};

					obstacle[i].lowPart = { static_cast<float>(GetScreenWidth()) , obstacle[i].middleSpace.y + obstacle[i].middleSpace.height, 90, static_cast<float>(GetScreenHeight())};

					obstacle[i].isOnScreen = true;
				}
			}
		}
	
	}
}