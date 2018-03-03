#pragma once
#include "Helper.h"

#include <imgui.h>
#include <imgui-SFML.h>

using namespace sf;
void Settings(RenderWindow & window, Vector2u sz)
{
	//Загрузка текстур
	Texture settingsBackground;
	settingsBackground.loadFromFile("images/settings.png");
	//Преобразование в спрайт
	Sprite background(settingsBackground);
	//Начало отрисовки
	SetFullScreen(window, sz);
	window.setFramerateLimit(60); //FrameRate for IMGUI
	//######################
	ImGui::CreateContext();
	ImGui::SFML::Init(window);

	sf::Clock deltaClock;
	while (!Keyboard::isKeyPressed(Keyboard::Escape)) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);

			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				break;
			}
		}

		ImGui::SFML::Update(window, deltaClock.restart());
		ImGui::ShowTestWindow();
		window.clear();
		window.draw(background);
		ImGui::SFML::Render(window);
		window.display();
	}
	//######################
	ImGui::SFML::Shutdown();
}