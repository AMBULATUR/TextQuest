#pragma once
#include "Helper.h"
#include <fstream>

using namespace sf;
void GameProcess(RenderWindow & window, SettingsInit::SetUp params)
{
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 20);

	//Загрузка текстур
	window.clear();
	Texture gameBackground;
	gameBackground.loadFromFile("images/GameInterface.png");
	//Преобразование в спрайт
	Sprite background(gameBackground);
	//Начало отрисовки

	
	text.setString("Hello \n asd");
	text.setPosition(500,500);
	window.draw(background);
	window.draw(text);
	window.display();

	Sleep();
}