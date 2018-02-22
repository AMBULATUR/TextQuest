#include "menu.h"

class Game {
public:
	Game()
	{
		sf::RenderWindow window(VideoMode(1920 / 2, 1080 / 2), "TextQuest", Style::None);
		window.setFramerateLimit(30);
		menu(window);
	};
};

int main()
{
	Game obj;
	return 0;
}
