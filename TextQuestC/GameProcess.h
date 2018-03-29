#pragma once
#include "Helper.h"
using namespace sf;
void GameProcess(RenderWindow & window, Vector2u WindowVector)
{
//Загрузка текстур
	Texture gameBackground;
	gameBackground.loadFromFile("images/background.png");
//Преобразование в спрайт
	Sprite background(gameBackground);
//background.setScale(Vector2f(0.5f, 0.5f));
	//Начало отрисовки
	SetFullScreen(window, WindowVector);
	window.draw(background);
	window.display();
	Sleep();
}