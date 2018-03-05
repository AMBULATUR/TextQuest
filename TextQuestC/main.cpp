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
		sf::RenderWindow window(VideoMode(0, 0), "TextQuest", Style::Fullscreen);
		window.setVerticalSyncEnabled(true);
		Vector2u sz = window.getSize();
		ImGui::CreateContext();
		menu(window, sz);
	};
};
int main()
{
	Game obj;
	return 0;
}
