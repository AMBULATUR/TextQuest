#include <SFML/Graphics.hpp>
using namespace sf;
void GameProcess(sf::RenderWindow & window)
{
	//auto sf = gameBackground.getScale();
	//sf.x = 1.0; sf.y = 1.0; //Для уменьшения пикчи от 0.01 до 1.0
	//gameBackground.setScale(sf);

	Texture gameBackground;
	gameBackground.loadFromFile("images/background.png");
	gameBackground.setSmooth(true);
	Sprite background(gameBackground);
	window.create(VideoMode(1920, 1080, 32), "TextQuest", sf::Style::None);
	window.draw(background);
	window.display();
	while (!Keyboard::isKeyPressed(Keyboard::Escape));
}