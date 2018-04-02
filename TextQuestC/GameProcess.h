#pragma once
#include "Helper.h"
using namespace sf;
<<<<<<< HEAD
#define ResolutionX 1366/2
#define ResolutionY 768/2
void GameProcess(sf::RenderWindow & window)
=======
void GameProcess(RenderWindow & window, Vector2u sz)
>>>>>>> AMBULATUR/master
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