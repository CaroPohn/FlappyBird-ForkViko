#include "Pause.h"

#include <iostream>
#include <string>

#include "ProgramUtilities/Utilities.h"

namespace flappybird
{
	namespace pause
	{
		static Sprite BackMenuButton;
		static Sprite PlayAgain;

		void InitPause()
		{
			BackMenuButton.position = { 400,550 };
			BackMenuButton.scale = 0.6f;
			BackMenuButton.texture = LoadTexture("res/credits/ReturnMenuButton.png");

			PlayAgain.position = { 200,650 };
			PlayAgain.scale = 0.6f;
			PlayAgain.texture = LoadTexture("res/menu/OnePlayer.png");
		}

		void PauseUpdate(Screen& currentScene, bool& isPaused)
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
					isPaused = false;
				}
			}
			else
			{
				PlayAgain.color = WHITE;
			}
		}

		void DrawPause(bool isGameOver, int pointsCounter)
		{
			if (isGameOver)
			{
				DrawText(std::to_string(pointsCounter).c_str(), GetScreenWidth() / 2, GetScreenHeight() / 2, 70, WHITE);
				DrawSprite(BackMenuButton);
				DrawSprite(PlayAgain);
			}
			else
			{
				DrawText("PAUSED", GetScreenWidth() / 2, GetScreenHeight() / 2, 70, WHITE);
				DrawSprite(BackMenuButton);
				DrawSprite(PlayAgain);
			}
		}
	}
}

