#include "Pause.h"

#include <iostream>
#include <string>

#include "ProgramUtilities/Utilities.h"

namespace flappybird
{
	namespace pause
	{
		Texture2D pauseBack;
		Texture2D gameOverBack;
		Texture2D points;

		Texture2D backMenuPause1;
		Texture2D backMenuPause2;

		Texture2D play1;
		Texture2D play2;

		static Sprite BackMenuButton;
		static Sprite PlayAgain;

		Sound buttonPause;

		void InitPause()
		{
			float buttonYPos = 620.0f;
			float buttonPlayOffset = 30.0f;
			float buttonBackMOffset = 15.0f;

			buttonPause = LoadSound("res/sounds/button.mp3");

			points = LoadTexture("res/game/pause/points.png");

			pauseBack = LoadTexture("res/game/pause/pauseBack.png");
			gameOverBack = LoadTexture("res/game/pause/gameOverBack.png");

			backMenuPause1 = LoadTexture("res/game/pause/backmenu1.png");
			backMenuPause2 = LoadTexture("res/game/pause/backmenu2.png");

			play1 = LoadTexture("res/game/pause/play1.png");
			play2 = LoadTexture("res/game/pause/play2.png");

			BackMenuButton.texture = backMenuPause1;
			BackMenuButton.scale = 0.6f;
			BackMenuButton.position = { GetScreenWidth() / 2 + buttonBackMOffset , buttonYPos };

			PlayAgain.texture = play1;
			PlayAgain.scale = 0.6f;
			PlayAgain.position = { GetScreenWidth() / 2 - BackMenuButton.texture.width * BackMenuButton.scale - buttonPlayOffset , buttonYPos };
		}

		void PauseUpdate(Screen& currentScene, bool& isPaused)
		{

			if (MouseColision(BackMenuButton))
			{
				BackMenuButton.texture = backMenuPause2;
				PlaySound(buttonPause);

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Menu;
				}
			}
			else
			{
				BackMenuButton.texture = backMenuPause1;
			}

			if (MouseColision(PlayAgain))
			{
				PlayAgain.texture = play2;
				PlaySound(buttonPause);

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					isPaused = false;
				}
			}
			else
			{
				PlayAgain.texture = play1;
			}
		}

		void DrawPause(bool isGameOver, int pointsCounter)
		{
			if (isGameOver)
			{
				int pointsOffset = 155;
				float pointsScale = 0.7f;

				DrawTexture(gameOverBack, 0, 0, WHITE);
				DrawText(std::to_string(pointsCounter).c_str(), GetScreenWidth() - pointsOffset, 26, 70, WHITE);
				DrawTextureEx(points, { static_cast<float>(GetScreenWidth() - points.width * pointsScale - pointsOffset), 20 }, 0, pointsScale, WHITE);
				DrawSprite(BackMenuButton);
				DrawSprite(PlayAgain);
			}
			else
			{
				DrawTexture(pauseBack, 0, 0, WHITE);
				DrawSprite(BackMenuButton);
				DrawSprite(PlayAgain);
			}
		}
	}
}

