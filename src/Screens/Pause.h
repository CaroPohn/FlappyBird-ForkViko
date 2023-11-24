#pragma once

#include "ProgramUtilities/Utilities.h"

#include "ScreenManagements/Screens.h"

namespace flappybird
{
	namespace pause
	{
		void InitPause();
		void PauseUpdate(Screen& currentScene, bool& isPaused);
		void DrawPause(bool isGameOver, int pointsCounter);
	}

}