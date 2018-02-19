#include <SFML/Graphics.hpp>
using namespace sf;

void Settings(sf::RenderWindow & window)
{
	Texture settingsBackground;
	settingsBackground.loadFromFile("images/settings.png");
	Sprite background(settingsBackground);
	background.setPosition(0, 0);
	window.create(VideoMode(1920, 1080, 32), "TextQuest", sf::Style::None);
	window.draw(background);
	window.display();
	while (!Keyboard::isKeyPressed(Keyboard::Escape));
}