#include "LoseScreen.h"

#include <iostream>
#include <string>

#include "ProgramUtilities/Utilities.h"

namespace flappybird
{
	static Sprite BackMenuButton;
	static Sprite PlayAgain;

	namespace loseScreen
	{
		void InitLoseScreen()
		{
			BackMenuButton.position = { 400,550 };
			BackMenuButton.scale = 0.6f;
			BackMenuButton.texture = LoadTexture("res/credits/ReturnMenuButton.png");

			PlayAgain.position = { 200,650 };
			PlayAgain.scale = 0.6f;
			PlayAgain.texture = LoadTexture("res/menu/OnePlayer.png");
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

			if (MouseColision(PlayAgain))
			{
				PlayAgain.color = GRAY;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Game;
					
				}
			}
			else
			{
				PlayAgain.color = WHITE;
			}

		}

		void LoseScreenDrawing(int pointsCounter)
		{
			DrawText(std::to_string(pointsCounter).c_str(), GetScreenWidth() / 2, GetScreenHeight() / 2, 70, WHITE);
			DrawSprite(BackMenuButton);
		}
		
	}
}

