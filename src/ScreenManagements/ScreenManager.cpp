#include "ScreenManager.h"

#include "ProgramUtilities/Utilities.h"

#include "Screens.h"
#include "Screens/Game.h"
#include "Screens/Menu.h"
#include "Screens/Credits.h"
#include "Screens/LoseScreen.h"


namespace flappybird
{
	int pointsCounter;

	Screen currentScreen;

	static void InitProgram();
	static void Update();
	static void Draw();
	static void Close();


	void RunProgram()
	{
		InitProgram();

		while (!WindowShouldClose() && currentScreen != Screen::Exit)
		{
			Update();
			Draw();
		}

		Close();
	}

	static void InitProgram()
	{
		int windowH = 720;
		int windowW = 1080;

		InitWindow(windowW, windowH, "Flappy Viko by Mateo Viko Monastra");

		menu::InitMenu();
		currentScreen = Screen::Menu;
		SetRandomSeed(NULL);
		SetExitKey(NULL);
	}

	static void Update()
	{

		switch (currentScreen)
		{
		case Screen::Menu:
			menu::MenuUpdate(currentScreen, pointsCounter);
			break;
		case Screen::Game:
			game::GameUpdate(currentScreen, pointsCounter);
			break;
		case Screen::Credits:
			credits::CreditsUpdate(currentScreen);
			break;
		case Screen::LoseScreen:
			loseScreen::LoseScreenUpdate(currentScreen);
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
			break;
		case Screen::Credits:
			credits::CreditsDrawing();
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
