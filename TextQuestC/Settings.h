#pragma once
#include "Helper.h"

#include <imgui.h>
#include <imgui-SFML.h>

using namespace sf;
void Settings(RenderWindow & window, Vector2u sz)
{
	//Загрузка текстур
	Texture settingsBackground;
	settingsBackground.loadFromFile("images/settings.png");
	//Преобразование в спрайт
	Sprite background(settingsBackground);
	//Начало отрисовки
	SetFullScreen(window, sz);
	window.draw(background);
	window.display();
	
	//######################

	
	//######################
	
	Sleep();
}