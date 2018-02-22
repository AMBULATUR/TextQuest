#include "menu.h"
class Game {
private:
public:
	Game()
	{
		sf::RenderWindow window(VideoMode(0, 0), "TextQuest", Style::Fullscreen);
		auto sz = window.getSize();
		window.setFramerateLimit(30);
		menu(window,sz);
	};

};
int main()
{
	Game obj;
	return 0;
}
