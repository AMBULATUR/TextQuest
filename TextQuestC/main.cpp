#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

using namespace std;
SettingsInit SIObject;
class Game {
private:
public:
	Game()
	{
		//Vector2u WindowVector;
		//sf::RenderWindow window;
		sf::RenderWindow window(VideoMode(0, 0), "TextQuest", Style::Fullscreen);
		window.setVerticalSyncEnabled(true);
		Vector2u WindowVector = window.getSize();
		ImGui::CreateContext();
		menu(window, WindowVector);
	};
}; 

int main()
{
	auto vcs = SIObject.InitCheck();
	//Game run;
	return 0;
}
