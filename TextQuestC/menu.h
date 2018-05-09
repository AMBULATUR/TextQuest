#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>


#include <SFML\Audio.hpp>
#include "Settings.h"
#include "GameProcess.h"
#include "Helper.h"

using namespace sf;
string LoadSave()
{
	ifstream fin;
	char out[1000];
	out[0] = 0;
	fin.open(PATH + "SaveFile.txt");
	if (fin.is_open())
	{
		fin.getline(out, 1000);
	}
	return out[0] == NULL ? "file1.txt" : out;
}
void menu(RenderWindow & window, SettingsInit::SetUp params, Vector2u WindowVector)
{

#pragma region Init Texture

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

#pragma region LoadMusic
	Music MainMenuMusic;
	MainMenuMusic.openFromFile("music/mainmenu.ogg");
	MainMenuMusic.play();
#pragma endregion
#pragma region Sprite
	Sprite
		background(mainMenu),
		NGButton(NewGameButton),
		LButton(LoadingButton),
		SButton(SettingsButton),
		EButton(ExitButton);
#pragma endregion
#pragma region Vars
	bool isMenu = 1;
	int Select = 0;
	FloatRect NG;
	FloatRect LB;
	FloatRect SB;
	FloatRect EB;

#pragma endregion

	while (isMenu)
	{
		if (params.MMusic == false && MainMenuMusic.getStatus() == false)
			MainMenuMusic.play();
		if (params.MMusic == true)
			MainMenuMusic.stop();

		MainMenuMusic.setVolume(params.Music);
		if (params.FullScreenMode == 0)
		{
			NGButton.setPosition(40, 80); LButton.setPosition(40, 140);
			SButton.setPosition(40, 200); EButton.setPosition(40, 260);

			NGButton.setScale(1.0f, 1.0f); LButton.setScale(1.0f, 1.0f);
			SButton.setScale(1.0f, 1.0f); EButton.setScale(1.0f, 1.0f);

			background.setScale(static_cast<float>(WindowVector.x / 2) / mainMenu.getSize().x,
				static_cast<float>(WindowVector.y / 2) / mainMenu.getSize().y);
		}
		else
		{
			NGButton.setPosition(40, 80); LButton.setPosition(40, 180);
			SButton.setPosition(40, 280); EButton.setPosition(40, 380);

			NGButton.setScale(2.0f, 2.0f); LButton.setScale(2.0f, 2.0f);
			SButton.setScale(2.0f, 2.0f); EButton.setScale(2.0f, 2.0f);

			background.setScale(static_cast<float>(WindowVector.x) / mainMenu.getSize().x,
				static_cast<float>(WindowVector.y) / mainMenu.getSize().y);
		}
		NG = NGButton.getGlobalBounds();
		LB = LButton.getGlobalBounds();
		SB = SButton.getGlobalBounds();
		EB = EButton.getGlobalBounds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			NGButton.setColor(Color::White); LButton.setColor(Color::White);
			SButton.setColor(Color::White); EButton.setColor(Color::White);
			Select = 0;


			if (IntRect(NG.left, NG.top, NG.width, NG.height).contains(Mouse::getPosition(window)))
			{
				NGButton.setColor(Color::Cyan); Select = 1;
			}
			if (IntRect(LB.left, LB.top, LB.width, LB.height).contains(Mouse::getPosition(window)))
			{
				LButton.setColor(Color::Cyan); Select = 2;
			}
			if (IntRect(SB.left, SB.top, SB.width, SB.height).contains(Mouse::getPosition(window)))
			{
				SButton.setColor(Color::Cyan); Select = 3;
			}
			if (IntRect(EB.left, EB.top, EB.width, EB.height).contains(Mouse::getPosition(window)))
			{
				EButton.setColor(Color::Red); Select = 4;
			}

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (Select == 1) { remove("Story/SaveFile.txt"); GameProcess(window, params, WindowVector, LoadSave()); };
				if (Select == 2) { GameProcess(window, params, WindowVector, LoadSave()); }
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