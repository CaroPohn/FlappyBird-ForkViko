#pragma once

#include "ProgramUtilities/Utilities.h"

#include "ScreenManagements/Screens.h"

namespace flappybird
{
	namespace loseScreen
	{
		void InitLoseScreen();
		void LoseScreenUpdate(Screen& currentScene);
		void LoseScreenDrawing(int pointsCounter);
	}
}
