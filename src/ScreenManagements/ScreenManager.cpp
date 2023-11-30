#include "ScreenManager.h"

#include "ProgramUtilities/Utilities.h"

#include "Screens.h"
#include "Screens/Game.h"
#include "Screens/Menu.h"
#include "Screens/Credits.h"
#include "Screens/Rules.h"
#include "Screens/LoseScreen.h"
#include "Screens/Pause.h"

namespace flappybird
{
	static int pointsCounter;
	static bool isGameOver;
	static bool isPaused;

	Screen currentScreen;

	static void InitProgram();
	static void Update();
	static void Draw();
	static void Close();


	void RunProgram()
	{
		InitProgram();
		InitAudioDevice();

		while (!WindowShouldClose() && currentScreen != Screen::Exit)
		{
			Update();
			Draw();
		}

		CloseAudioDevice();
		Close();
	}

	static void InitProgram()
	{
		int windowH = 720;
		int windowW = 1080;

		InitWindow(windowW, windowH, "Merry Christcats");

		menu::InitMenu();
		pause::InitPause();
		currentScreen = Screen::Menu;
		SetRandomSeed(NULL);
		SetExitKey(NULL);
	}

	static void Update()
	{

		switch (currentScreen)
		{
		case Screen::Menu:
			menu::MenuUpdate(currentScreen, pointsCounter, isGameOver, isPaused);
			break;
		case Screen::Game:
			if (!isPaused)
				game::GameUpdate(pointsCounter, isGameOver, isPaused);
			else
				pause::PauseUpdate(currentScreen, isPaused);
			break;
		case Screen::Credits:
			credits::CreditsUpdate(currentScreen);
			break;
		case Screen::Rules:
			rules::RulesUpdate(currentScreen);
			break;
		case Screen::Exit:
			Close();
			break;
		default:
			break;
		}

	}

	static void Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (currentScreen)
		{
		case Screen::Menu:
			menu::MenuDrawing();
			break;
		case Screen::Game:
			game::DrawGame(pointsCounter);
			if (isPaused)
				pause::DrawPause(isGameOver, pointsCounter);
			break;
		case Screen::Credits:
			credits::CreditsDrawing();
			break;
		case Screen::Rules:
			rules::RulesDrawing();
			break;
		case Screen::LoseScreen:
			loseScreen::LoseScreenDrawing(pointsCounter);
			break;
		default:
			break;
		}
		EndDrawing();
	}

	static void Close()
	{
		CloseWindow();
	}


}
