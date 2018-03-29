#pragma once
#include "Helper.h"
using namespace sf;
void GameProcess(RenderWindow & window, Vector2u WindowVector)
{
//�������� �������
	Texture gameBackground;
	gameBackground.loadFromFile("images/background.png");
//�������������� � ������
	Sprite background(gameBackground);
//background.setScale(Vector2f(0.5f, 0.5f));
	//������ ���������
	SetFullScreen(window, WindowVector);
	window.draw(background);
	window.display();
	Sleep();
}