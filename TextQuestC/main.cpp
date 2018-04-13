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
		sf::RenderWindow  window(VideoMode(0, 0, 32), "TextQuest", Style::Fullscreen);
		Vector2u WindowVector = window.getSize();
		if (params.FullScreenMode == 0)
		{
			window.create(VideoMode(WindowVector.x / 2 , WindowVector.y / 2, 32), "TextQuest", sf::Style::None);
		}
		ImGui::CreateContext();
		//	SetFullScreen(window, WindowVector);
		window.setFramerateLimit(60);
		menu(window, params, WindowVector);
	};
};

int main()
{
	//SettingsInit::SetUp *vcs;
	auto vcs = SIObject.InitCheck();

	Game run(*vcs);
	return 0;
}
