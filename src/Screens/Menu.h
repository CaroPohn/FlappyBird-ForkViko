#pragma once
#include "ScreenManagements/Screens.h"

namespace flappybird
{
	namespace menu
	{
		void InitMenu();
		void MenuUpdate(Screen& currentScene, int& pointsCounter, bool& isGameOver, bool& isPaused);
		void MenuDrawing();
		void UnloadTexturesMenu();
	}
}