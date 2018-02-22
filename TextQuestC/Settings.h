#include <SFML/Graphics.hpp>
using namespace sf;
#define ResolutionX 1920
#define ResolutionY 1080
void Settings(sf::RenderWindow & window)
{
	Texture settingsBackground;
	settingsBackground.loadFromFile("images/settings.png");
	Sprite background(settingsBackground);
	background.setPosition(0, 0);
	window.create(VideoMode(ResolutionX, ResolutionY, 32), "TextQuest", sf::Style::None);
	window.draw(background);
	window.display();
	while (!Keyboard::isKeyPressed(Keyboard::Escape));
}