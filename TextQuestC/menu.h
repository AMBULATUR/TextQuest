#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "Settings.h"
#include "GameProcess.h"
#include "Helper.h"

using namespace sf;

void menu(RenderWindow & window, SettingsInit::SetUp params, Vector2u WindowVector)
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
	mainMenu.loadFromFile("images/MenuBackground.jpg");
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
	NGButton.setPosition(40, 80);
	LButton.setPosition(40, 140);
	SButton.setPosition(40, 200);
	EButton.setPosition(40, 260);
#pragma endregion
	const Vector2f defaultResolution = Vector2f(1920.0F, 1080.0F);
	
	
	
	
	while (isMenu)
	{
		if (params.FullScreenMode == 0)
		{
			background.setScale(static_cast<float>(WindowVector.x / 2) / defaultResolution.x,
				static_cast<float>(WindowVector.y / 2) / defaultResolution.y);
		}
		else
		{
			background.setScale(static_cast<float>(WindowVector.x) / defaultResolution.x,
				static_cast<float>(WindowVector.y) / defaultResolution.y);
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			NGButton.setColor(Color::White);
			LButton.setColor(Color::White);
			SButton.setColor(Color::White);
			EButton.setColor(Color::White);
			Select = 0;

			if (IntRect(40, 80, 200, 30).contains(Mouse::getPosition(window)))
			{
				NGButton.setColor(Color::Cyan); Select = 1;
			}
			if (IntRect(40, 140, 200, 30).contains(Mouse::getPosition(window)))
			{
				LButton.setColor(Color::Cyan); Select = 2;
			}
			if (IntRect(40, 200, 200, 30).contains(Mouse::getPosition(window)))
			{
				SButton.setColor(Color::Cyan); Select = 3;
			}
			if (IntRect(40, 260, 200, 30).contains(Mouse::getPosition(window)))
			{
				EButton.setColor(Color::Red); Select = 4;
			}

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (Select == 1) { GameProcess(window, params, WindowVector); };
				if (Select == 2) {}
				if (Select == 3) { Settings(window, params, WindowVector); }
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
}