#pragma once
#include "Helper.h"
#include <fstream>

using namespace sf;
void GameProcess(RenderWindow & window, Vector2u WindowVector)
{
	//�������� �������
	window.clear();
	Texture gameBackground;
	gameBackground.loadFromFile("images/GameInterface.png");
	//�������������� � ������
	Sprite background(gameBackground);
	//������ ���������
	//while (!Keyboard::isKeyPressed(Keyboard::Escape))
//	{
		window.draw(background);
		window.display();
	//}
	Sleep();
}