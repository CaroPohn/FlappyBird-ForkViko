#include "Rules.h"

namespace flappybird
{
	namespace rules
	{
		Sprite BackMenuRulesButton;

		Texture2D rulesScreen;

		Texture2D backMenuRules1;
		Texture2D backMenuRules2;

		int buttonRulesOffset = 10;

		void InitRules()
		{
			rulesScreen = LoadTexture("res/rules/rulesScreen.png");

			backMenuRules1 = LoadTexture("res/rules/backmenu1.png");
			backMenuRules2 = LoadTexture("res/rules/backmenu2.png");

			BackMenuRulesButton.scale = 0.6f;
			BackMenuRulesButton.texture = backMenuRules1;
			BackMenuRulesButton.position = { static_cast<float>(GetScreenWidth() - BackMenuRulesButton.texture.width * BackMenuRulesButton.scale - buttonRulesOffset) , static_cast<float>(GetScreenHeight() - BackMenuRulesButton.texture.height * BackMenuRulesButton.scale - buttonRulesOffset) };
		}

		void RulesUpdate(Screen& currentScene)
		{
			if (MouseColision(BackMenuRulesButton))
			{
				BackMenuRulesButton.texture = backMenuRules2;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Menu;
				}
			}
			else
			{
				BackMenuRulesButton.texture = backMenuRules1;
			}
		}

		void RulesDrawing()
		{
			DrawTexture(rulesScreen, 0, 0, WHITE);
			DrawSprite(BackMenuRulesButton);
		}
		
	}
}

