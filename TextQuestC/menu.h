#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "Settings.h"
#include "GameProcess.h"
#include "Helper.h"

using namespace sf;

void menu(RenderWindow & window, SettingsInit::SetUp params)
{
#pragma region Vars
	bool isMenu = 1;
	int Select = 0;
#pragma endregion
#pragma region Texture
	Texture
		mainMenu,
		NewGameButton,
		LoadingButton,
		SettingsButton,
		ExitButton;
#pragma endregion
#pragma region LoadTexture
	mainMenu.loadFromFile("images/MenuBackground.png");
	NewGameButton.loadFromFile("images/NewGame.png");
	LoadingButton.loadFromFile("images/Loading.png");
	SettingsButton.loadFromFile("images/Settings.png");
	ExitButton.loadFromFile("images/Exit.png");
#pragma endregion
#pragma region Sprite
	Sprite
		background(mainMenu),
		NGButton(NewGameButton),
		LButton(LoadingButton),
		SButton(SettingsButton),
		EButton(ExitButton);
#pragma endregion
#pragma region Positions
	NGButton.setPosition(100, 40);
	LButton.setPosition(100, 80);
	SButton.setPosition(100, 120);
	EButton.setPosition(100, 160);
#pragma endregion

	while (isMenu)
	{
		NGButton.setColor(Color::White);
		LButton.setColor(Color::White);
		SButton.setColor(Color::White);
		EButton.setColor(Color::White);
		Select = 0;

		if (IntRect(100, 40, 200, 30).contains(Mouse::getPosition(window)))
		{
			NGButton.setColor(Color::Blue); Select = 1;
		}
		if (IntRect(100, 80, 200, 30).contains(Mouse::getPosition(window)))
		{
			LButton.setColor(Color::Blue); Select = 2;
		}
		if (IntRect(100, 120, 200, 30).contains(Mouse::getPosition(window)))
		{
			SButton.setColor(Color::Blue); Select = 3;
		}
		if (IntRect(100, 160, 200, 30).contains(Mouse::getPosition(window)))
		{
			EButton.setColor(Color::Blue); Select = 4;
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (Select == 1) { GameProcess(window, params); };
			if (Select == 2) {}
			if (Select == 3) { Settings(window, params); }
			if (Select == 4) { window.close(); isMenu = false; }
		}
#pragma region WinDraw
		window.draw(background);
		window.draw(NGButton);
		window.draw(LButton);
		window.draw(SButton);
		window.draw(EButton);
#pragma endregion
		window.display();
	}
}