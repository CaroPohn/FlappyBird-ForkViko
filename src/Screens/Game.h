#pragma once

#include "ScreenManagements/Screens.h"
#include "ProgramUtilities/Utilities.h"
#include "Objects/Bird.h"
#include "Objects/Obstacles.h"

namespace flappybird
{
	namespace game
	{
		enum class PlayerCount
		{
			OnePlayer = 1,
			TwoPlayers = 2
		};
		
		void InitGame(PlayerCount playerCount, int& pointsCounter, bool& isGameOver, bool& isPaused);
		void InitParallax();
		void GameUpdate(int& pointsCounter, bool& isGameOver, bool& isPaused);
		void UpdateParallax();
		void UpdateLayer(Sprite& layer);
		void DrawGame(int pointsCounter);
		void DrawParallax();
		void CheckCollitions(Bird toCheck, int& pointsCounter, bool& isGameOver, bool& isPaused);
		void CheckBirdObstacleCollition(Obstacle& obstacle, Bird& playerToCheck, int& pointsCounter);
	}
}