#pragma once

#include "ScreenManagements/Screens.h"
#include "ProgramUtilities/Utilities.h"

namespace flappybird
{
	namespace game
	{
		void InitGame();
		void InitParallax();
		void GameUpdate(Screen& currentScene);
		void UpdateParallax();
		void UpdateLayer(Sprite& layer);
		void DrawGame();
		void DrawParallax();
		//void GameCollitions(Screen& currentScene); la nomenclatura esta mal
		void CheckCollitions(Screen& currentScene);
	}
}