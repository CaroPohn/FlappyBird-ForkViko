#include "Credits.h"

#include "ProgramUtilities/Utilities.h"

namespace flappybird
{
	namespace credits
	{
		Texture2D creditsBack;

		Texture2D backMenuCred1;
		Texture2D backMenuCred2;

		Sprite ReturnMenuButton;

		int buttonCredOffset = 10;

		void InitCredits()
		{
			backMenuCred1 = LoadTexture("res/credits/backmenu1.png");
			backMenuCred2 = LoadTexture("res/credits/backmenu2.png");

			ReturnMenuButton.scale = 0.6f;
			ReturnMenuButton.texture = backMenuCred1;
			ReturnMenuButton.position = {static_cast<float>(GetScreenWidth() - ReturnMenuButton.texture.width * ReturnMenuButton.scale - buttonCredOffset) , static_cast<float>(GetScreenHeight() - ReturnMenuButton.texture.height * ReturnMenuButton.scale - buttonCredOffset)};

			creditsBack = LoadTexture("res/credits/creditsScreen.png");
		}

		void CreditsUpdate(Screen& currentScene)
		{

			if (MouseColision(ReturnMenuButton))
			{
				ReturnMenuButton.texture = backMenuCred2;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Menu;
				}
			}
			else
			{
				ReturnMenuButton.texture = backMenuCred1;
			}

		}

		void CreditsDrawing()
		{
			DrawTexture(creditsBack, 0, 0, WHITE);
			DrawSprite(ReturnMenuButton);
		}
	}
}