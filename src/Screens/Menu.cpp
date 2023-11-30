#include "Menu.h"

#include "ProgramUtilities/Utilities.h"

#include "Game.h"
#include "Credits.h"
#include "Screens/Rules.h"

namespace flappybird
{
	namespace menu
	{
		static Sprite onePlayer;
		static Sprite twoPlayers;
		static Sprite rules;
		static Sprite credits;
		static Sprite exit;

		static Texture2D onePlayerT1;
		static Texture2D onePlayerT2;

		static Texture2D twoPlayersT1;
		static Texture2D twoPlayersT2;

		static Texture2D creditsT1;
		static Texture2D creditsT2;

		static Texture2D rulesT1;
		static Texture2D rulesT2;

		static Texture2D exitT1;
		static Texture2D exitT2;

		static Texture2D menu1;
		static Texture2D menu2;

		Sound menuButton;

		void InitMenu()
		{
			menuButton = LoadSound("res/sounds/button.mp3");

			menu1 = LoadTexture("res/menu/menu1.png");
			menu2 = LoadTexture("res/menu/menu2.png");

			onePlayerT1 = LoadTexture("res/menu/OnePlayer1.png");
			onePlayerT2 = LoadTexture("res/menu/OnePlayer2.png");

			twoPlayersT1 = LoadTexture("res/menu/TwoPlayers1.png");
			twoPlayersT2 = LoadTexture("res/menu/TwoPlayers2.png");

			creditsT1 = LoadTexture("res/menu/credits1.png");
			creditsT2 = LoadTexture("res/menu/credits2.png");

			rulesT1 = LoadTexture("res/menu/rules1.png");
			rulesT2 = LoadTexture("res/menu/rules2.png");

			exitT1 = LoadTexture("res/menu/exit1.png");
			exitT2 = LoadTexture("res/menu/exit2.png");

			onePlayer.position = { static_cast<float>(GetScreenWidth()) / 2 - 80 , 350 };
			onePlayer.scale = 0.6f;
			onePlayer.texture = onePlayerT1;

			twoPlayers.position = { static_cast<float>(GetScreenWidth()) / 2 - 80 , 420 };
			twoPlayers.scale = 0.6f;
			twoPlayers.texture = twoPlayersT1;

			credits.position = { static_cast<float>(GetScreenWidth()) / 2 - 80, 490 };
			credits.scale = 0.6f;
			credits.texture = creditsT1;

			rules.position = { static_cast<float>(GetScreenWidth()) / 2 - 80, 560 };
			rules.scale = 0.6f;
			rules.texture = rulesT1;

			exit.position = { static_cast<float>(GetScreenWidth()) / 2 - 80, 630 };
			exit.scale = 0.6f;
			exit.texture = exitT1;

		}

		void MenuUpdate(Screen& currentScene, int& pointsCounter, bool& isGameOver, bool& isPaused)
		{
			if (MouseColision(onePlayer))
			{
				onePlayer.texture = onePlayerT2;
				PlaySound(menuButton);

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Game;
					game::InitGame(game::PlayerCount::OnePlayer, pointsCounter, isGameOver, isPaused);
				}
			}
			else
			{
				onePlayer.texture = onePlayerT1;
			}

			if (MouseColision(twoPlayers))
			{
				twoPlayers.texture = twoPlayersT2;
				PlaySound(menuButton);

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Game;
					game::InitGame(game::PlayerCount::TwoPlayers, pointsCounter, isGameOver, isPaused);
				}
			}
			else
			{
				twoPlayers.texture = twoPlayersT1;
			}

			if (MouseColision(exit))
			{
				exit.texture = exitT2;
				PlaySound(menuButton);

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Exit;
				}
			}
			else
			{
				exit.texture = exitT1;
			}

			if (MouseColision(credits))
			{
				credits.texture = creditsT2;
				PlaySound(menuButton);

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Credits;
					credits::InitCredits();
				}
			}
			else
			{
				credits.texture = creditsT1;
			}

			if (MouseColision(rules))
			{
				rules.texture = rulesT2;
				PlaySound(menuButton);

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScene = Screen::Rules;
					rules::InitRules();
				}
			}
			else
			{
				rules.texture = rulesT1;
			}
		}


		void MenuDrawing()
		{
			int frame = 0;

			frame += static_cast<int>(GetTime());

			if (frame % 2 == 0)
			{
				DrawTexture(menu1, 0, 0, WHITE);
			}
			else
				DrawTexture(menu2, 0, 0, WHITE);

			DrawSprite(onePlayer);
			DrawSprite(twoPlayers);
			DrawSprite(credits);
			DrawSprite(rules);
			DrawSprite(exit);

			DrawText("1.0", 2, 2, 50, RED);
		}

		void UnloadTexturesMenu()
		{
			UnloadTexture(onePlayerT1);
			UnloadTexture(onePlayerT2);
			UnloadTexture(twoPlayersT1);
			UnloadTexture(twoPlayersT2);
			UnloadTexture(creditsT1);
			UnloadTexture(creditsT2);
			UnloadTexture(rulesT1);
			UnloadTexture(rulesT2);
			UnloadTexture(exitT1);
			UnloadTexture(exitT2);
			UnloadTexture(menu1);
			UnloadTexture(menu2);
		}
	}
}