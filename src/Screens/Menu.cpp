#include "Menu.h"

#include "ProgramUtilities/Utilities.h"

#include "Game.h"
#include "Credits.h"
#include "Screens/Rules.h"

namespace flappybird
{
	namespace menu
	{
		static Sprite title;
		static Sprite onePlayer;
		static Sprite twoPlayers;
		static Sprite rules;
		static Sprite credits;
		static Sprite exit;

		void InitMenu()
		{
			title.position = { static_cast<float>(GetScreenWidth()) / 2 - 240, 60 };
			title.scale = 0.7f;
			title.texture = LoadTexture("res/menu/Title.png");

			onePlayer.position = { static_cast<float>(GetScreenWidth()) / 2 - 80 , 400};
			onePlayer.scale = 0.5f;
			onePlayer.texture = LoadTexture("res/menu/OnePlayer.png");

			twoPlayers.position = { static_cast<float>(GetScreenWidth()) / 2 - 80 , 460 };
			twoPlayers.scale = 0.5f;
			twoPlayers.texture = LoadTexture("res/menu/TwoPlayers.png");

			credits.position = { static_cast<float>(GetScreenWidth()) / 2 - 80, 520};
			credits.scale = 0.5f;
			credits.texture = LoadTexture("res/menu/CreditsButton.png");

			rules.position = { static_cast<float>(GetScreenWidth()) / 2 - 80, 580 };
			rules.scale = 0.5f;
			rules.texture = LoadTexture("res/menu/Rules.png");

			exit.position = { static_cast<float>(GetScreenWidth()) / 2 - 80, 640 };
			exit.scale = 0.5f;
			exit.texture = LoadTexture("res/menu/ExitButton.png");

		}

		void MenuUpdate(Screen& currentScene, int& pointsCounter, bool& isGameOver, bool& isPaused)
		{
			if (MouseColision(onePlayer))
			{
				onePlayer.color = GRAY;
				
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Game;
					game::InitGame(game::PlayerCount::OnePlayer, pointsCounter, isGameOver, isPaused);
				}
			}
			else
			{
				onePlayer.color = WHITE;
			}

			if (MouseColision(twoPlayers))
			{
				twoPlayers.color = GRAY;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Game;
					game::InitGame(game::PlayerCount::TwoPlayers, pointsCounter, isGameOver, isPaused);
				}
			}
			else
			{
				twoPlayers.color = WHITE;
			}

			if (MouseColision(exit))
			{
				exit.color = GRAY;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Exit;
				}
			}
			else
			{
				exit.color = WHITE;
			}

			if (MouseColision(credits))
			{
				credits.color = GRAY;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Credits;
					credits::InitCredits();
				}
			}
			else
			{
				credits.color = WHITE;
			}

			if (MouseColision(rules))
			{
				rules.color = GRAY;

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Rules;
					rules::InitRules();
				}
			}
			else
			{
				rules.color = WHITE;
			}
		}
		

		void MenuDrawing()
		{
			DrawSprite(title);
			DrawSprite(onePlayer);
			DrawSprite(twoPlayers);
			DrawSprite(credits);
			DrawSprite(rules);
			DrawSprite(exit);
		}
	}
}