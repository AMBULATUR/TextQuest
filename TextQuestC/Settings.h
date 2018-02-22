#pragma once
#include "Helper.h"
using namespace sf;
void Settings(RenderWindow & window,Vector2u sz)
{
//�������� �������
	Texture settingsBackground;
	settingsBackground.loadFromFile("images/settings.png");
//�������������� � ������
	Sprite background(settingsBackground);
//������ ���������
	SetFullScreen(window, sz);
	window.draw(background);
	window.display();
	Sleep();
}