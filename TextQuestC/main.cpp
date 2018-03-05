#include "menu.h"


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
using namespace std;
class Game {
private:
public:
	Game()
	{
<<<<<<< HEAD
		sf::RenderWindow window(VideoMode(1366 / 2, 768 / 2), "TextQuest", Style::None);
		menu(window);
=======
		sf::RenderWindow window(VideoMode(0, 0), "TextQuest", Style::Fullscreen);
		window.setVerticalSyncEnabled(true);
		Vector2u sz = window.getSize();
		ImGui::CreateContext();
		menu(window, sz);
>>>>>>> AMBULATUR/master
	};
};
int main()
{
	Game obj;
	return 0;
}
