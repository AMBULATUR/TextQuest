#pragma once
#include "Helper.h"
#include <fstream>

using namespace sf;
{
	//Çàãðóçêà òåêñòóð
	window.clear();
	Texture gameBackground;
	gameBackground.loadFromFile("images/GameInterface.png");
	//Ïðåîáðàçîâàíèå â ñïðàéò
	Sprite background(gameBackground);
	//Íà÷àëî îòðèñîâêè
	//while (!Keyboard::isKeyPressed(Keyboard::Escape))
//	{
		window.draw(background);
		window.display();
	//}
	Sleep();
}