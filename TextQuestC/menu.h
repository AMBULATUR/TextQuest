#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "Settings.h"
#include "GameProcess.h"
#include "Helper.h"



using namespace sf;

void menu(RenderWindow & window,Vector2u sz)
{
	SetWindowResolution(window, sz);
	Texture menuTexture1, menuTexture2, menuTexture3;
	menuTexture1.loadFromFile("images/111.png");
	menuTexture2.loadFromFile("images/222.png");
	menuTexture3.loadFromFile("images/333.png");
	
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3);

	bool isMenu = 1;
	int menuNum = 0;

	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(100, 30, 200, 30).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(100, 90, 200, 30).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(100, 150, 200, 30).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				GameProcess(window,sz); SetWindowResolution(window, sz); window.setFramerateLimit(30);
			};

			if (menuNum == 2)
			{
				Settings(window,sz); SetWindowResolution(window, sz); window.setFramerateLimit(30);
			}
			if (menuNum == 3) { window.close(); isMenu = false; }
		}

		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
}

