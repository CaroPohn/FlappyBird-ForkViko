#pragma once

#include "ProgramUtilities/Utilities.h"

#include "ScreenManagements/Screens.h"

namespace flappybird
{
	namespace rules
	{
		void InitRules();
		void RulesUpdate(Screen& currentScene);
		void RulesDrawing();
	}
}
