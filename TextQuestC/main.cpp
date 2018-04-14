#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "main.h"
using namespace std;
SettingsInit SIObject;
class Game {
private:
public:
	Game(SettingsInit::SetUp params)
	{
		sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
		sf::RenderWindow  window;
		Vector2u WindowVector (desktop.width, desktop.height);
		if (params.FullScreenMode == 1)
		{
			window.create(VideoMode(WindowVector.x, WindowVector.y, desktop.bitsPerPixel), "TextQuest", Style::Fullscreen);
		}	
		else
		{
			window.create(VideoMode(WindowVector.x / 2, WindowVector.y / 2, 32), "TextQuest", sf::Style::None);
		}
		ImGui::CreateContext();
		window.setFramerateLimit(60);
		menu(window, params, WindowVector);
	};
};

int main()
{
	auto vcs = SIObject.InitCheck();

	Game run(*vcs);
	return 0;
}
