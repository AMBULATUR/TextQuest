#pragma once
#include "Helper.h"
#include <fstream>

using namespace sf;
void GameProcess(RenderWindow & window, SettingsInit::SetUp params,Vector2u WindowVector)
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
	if (params.FullScreenMode == 0)
	{
		WindowVector.x = WindowVector.x / 2;
		WindowVector.y = WindowVector.y / 2;
	}
	const Vector2f defaultResolution = Vector2f(1920.0F, 1080.0F);
	background.setScale(static_cast<float>(WindowVector.x) / defaultResolution.x,
		static_cast<float>(WindowVector.y) / defaultResolution.y); // Так считаем размер спрайтов
	
	text.setString("Hello \n asd");
	text.setPosition(100,100);
	window.draw(background);
	window.draw(text);
	window.display();

	Sleep();
}