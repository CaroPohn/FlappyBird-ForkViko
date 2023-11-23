#include "LoseScreen.h"

#include <iostream>
#include <string>

namespace flappybird
{
	static Sprite BackMenuButton;

	namespace loseScreen
	{
		void InitLoseScreen()
		{
			BackMenuButton.position = { 400,550 };
			BackMenuButton.scale = 0.6f;
			BackMenuButton.texture = LoadTexture("res/credits/ReturnMenuButton.png");
		}

		void LoseScreenUpdate(Screen& currentScene)
		{
			if (MouseColision(BackMenuButton))
			{
				BackMenuButton.color = GRAY;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Menu;
				}
			}
			else
			{
				BackMenuButton.color = WHITE;
			}
		}

		void LoseScreenDrawing(int pointsCounter)
		{
			DrawText(std::to_string(pointsCounter).c_str(), GetScreenWidth() / 2, GetScreenHeight() / 2, 70, WHITE);
			DrawSprite(BackMenuButton);
		}
		
	}
}

