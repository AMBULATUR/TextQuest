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
		ImGuiIO& io = ImGui::GetIO();
		static const ImWchar ranges[] =
		{	
		 0x0020, 0x00FF, // Basic Latin + Latin Supplement
        0x0400, 0x052F, // Cyrillic + Cyrillic Supplement
        0x2DE0, 0x2DFF, // Cyrillic Extended-A
        0xA640, 0xA69F, // Cyrillic Extended-B
        0,
		};
		//io->Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
		io.Fonts->GetGlyphRangesCyrillic();
		 io.Fonts->AddFontFromFileTTF("arial.ttf", 16,NULL,ranges);
		ImGui::SFML::Init(window);
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
