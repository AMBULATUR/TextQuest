#include "menu.h"

class Game {
public:
	Game()
	{
		sf::RenderWindow window(VideoMode(1366 / 2, 768 / 2), "TextQuest", Style::None);
		menu(window);
	};
};

int main()
{
	Game obj;
	return 0;
}
