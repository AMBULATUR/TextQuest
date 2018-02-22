#pragma once
#include "Helper.h"
using namespace sf;
void GameProcess(RenderWindow & window, Vector2u sz)
{
//Загрузка текстур
	Texture gameBackground;
	gameBackground.loadFromFile("images/background.png");
//Преобразование в спрайт
	Sprite background(gameBackground);
//Начало отрисовки
	SetFullScreen(window, sz);
	window.draw(background);
	window.display();
	Sleep();
}