#pragma once
#include "Helper.h"
#include <fstream>

using namespace sf;
void GameProcess(RenderWindow & window, Vector2u WindowVector)
{
	//Загрузка текстур
	window.clear();
	Texture gameBackground;
	gameBackground.loadFromFile("images/GameInterface.png");
	//Преобразование в спрайт
	Sprite background(gameBackground);
	//Начало отрисовки
	//while (!Keyboard::isKeyPressed(Keyboard::Escape))
//	{
		window.draw(background);
		window.display();
	//}
	Sleep();
}