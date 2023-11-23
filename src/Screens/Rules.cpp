#include "Rules.h"

namespace flappybird
{
	namespace rules
	{
		Sprite BackMenuRulesButton;

		void InitRules()
		{
			BackMenuRulesButton.texture = LoadTexture("res/credits/ReturnMenuButton.png");
			BackMenuRulesButton.position = { static_cast<float>(GetScreenWidth() - BackMenuRulesButton.texture.width),static_cast<float>(GetScreenHeight() - BackMenuRulesButton.texture.height) };
			BackMenuRulesButton.scale = 0.5f;
		}

		void RulesUpdate(Screen& currentScene)
		{
			if (MouseColision(BackMenuRulesButton))
			{
				BackMenuRulesButton.color = GRAY;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Menu;
				}
			}
			else
			{
				BackMenuRulesButton.color = WHITE;
			}
		}

		void RulesDrawing()
		{
			DrawSprite(BackMenuRulesButton);
		}
		
	}
}

