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
		
		void InitGame(PlayerCount playerCount);
		void InitParallax();
		void GameUpdate(Screen& currentScene);
		void UpdateParallax();
		void UpdateLayer(Sprite& layer);
		void DrawGame();
		void DrawParallax();
		void CheckCollitions(Screen& currentScene, Bird toCheck);
		void CheckBirdObstacleCollition(Obstacle& obstacle, Bird& player);
	}
}