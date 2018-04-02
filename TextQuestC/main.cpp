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
	};
}; 

int main()
{
	//SettingsInit::SetUp *vcs;
	auto vcs = SIObject.InitCheck();
	
	Game run(*vcs);
	return 0;
}
