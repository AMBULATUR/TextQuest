#pragma once
#include "Helper.h"
using namespace sf;
void GameProcess(RenderWindow & window, Vector2u sz)
{
//�������� �������
	Texture gameBackground;
	gameBackground.loadFromFile("images/background.png");
//�������������� � ������
	Sprite background(gameBackground);
//������ ���������
	SetFullScreen(window, sz);
	window.draw(background);
	window.display();
	Sleep();
}