#pragma once

#include "ProgramUtilities/Utilities.h"
#include "Bird.h"

namespace flappybird
{
	namespace game
	{
		struct Obstacle
		{
			Rectangle topPart = {0, 0, 90, 0};
			Rectangle middleSpace = {};
			Rectangle lowPart = {};

			Color color = { RED };

			float velocity = { 160 };

			bool isOnScreen = false;

			static int obstacleCounter;

			const int MAX_PIPES_IN_SCREEN = 1;

			int timesChecked;
			bool justGivenPoints;

			Obstacle();

		};
	
		void ObstacleUpdate(Obstacle obstacleArray[], Bird& playerOne, Bird& playerTwo);
		void ObstacleDraw(Obstacle obstacleArray[]);
		void InitObstacle(Obstacle& obstacle, float posX);
		void ResetObstacle(Obstacle& obstacle, Bird& playerOne, Bird& playerTwo);
	}
}

