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

		static Texture2D menu1;
		static Texture2D menu2;

		void InitMenu()
		{
			menu1 = LoadTexture("res/menu/menu1.png");
			menu2 = LoadTexture("res/menu/menu2.png");

			onePlayerT1 = LoadTexture("res/menu/OnePlayer1.png");
			onePlayerT2 = LoadTexture("res/menu/OnePlayer2.png");

			twoPlayersT1 = LoadTexture("res/menu/TwoPlayers1.png");
			twoPlayersT2 = LoadTexture("res/menu/TwoPlayers2.png");

			creditsT1 = LoadTexture("res/menu/credits1.png");
			creditsT2 = LoadTexture("res/menu/credits2.png");

			onePlayer.position = { static_cast<float>(GetScreenWidth()) / 2 - 80 , 350};
			onePlayer.scale = 0.6f;
			onePlayer.texture = onePlayerT1;

			twoPlayers.position = { static_cast<float>(GetScreenWidth()) / 2 - 80 , 430 };
			twoPlayers.scale = 0.6f;
			twoPlayers.texture = twoPlayersT1;

			credits.position = { static_cast<float>(GetScreenWidth()) / 2 - 80, 510};
			credits.scale = 0.6f;
			credits.texture = creditsT1;

			rules.position = { static_cast<float>(GetScreenWidth()) / 2 - 80, 590 };
			rules.scale = 0.5f;
			rules.texture = LoadTexture("res/menu/Rules.png");

			exit.position = { static_cast<float>(GetScreenWidth()) / 2 - 80, 670 };
			exit.scale = 0.5f;
			exit.texture = LoadTexture("res/menu/ExitButton.png");

		}

		void MenuUpdate(Screen& currentScene, int& pointsCounter, bool& isGameOver, bool& isPaused)
		{
			if (MouseColision(onePlayer))
			{
				onePlayer.texture = onePlayerT2;
				
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
				credits.texture = creditsT2;

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
		}
	}
}