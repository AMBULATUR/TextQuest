#include <SFML/Graphics.hpp>
using namespace sf;
#define ResolutionX 1366/2
#define ResolutionY 768/2
void GameProcess(sf::RenderWindow & window)
{
	//auto sf = gameBackground.getScale();
	//sf.x = 1.0; sf.y = 1.0; //��� ���������� ����� �� 0.01 �� 1.0
	//gameBackground.setScale(sf);

	Texture gameBackground;
	gameBackground.loadFromFile("images/background.png");
	gameBackground.setSmooth(true);
	Sprite background(gameBackground);
	window.create(VideoMode(ResolutionX, ResolutionY, 32), "TextQuest", sf::Style::None);
	window.draw(background);
	window.display();
	while (!Keyboard::isKeyPressed(Keyboard::Escape));
}