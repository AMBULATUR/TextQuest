#pragma once
#include "Helper.h"
#include <fstream>

using namespace sf;
void GameProcess(RenderWindow & window, SettingsInit::SetUp params, Vector2u WindowVector)
{
	//Загрузка текстур
	window.clear();
	Texture gameBackground;
	gameBackground.loadFromFile("images/GameInterface.png");
	//Преобразование в спрайт
	Sprite background(gameBackground);
	//Начало отрисовки

	if (params.FullScreenMode == 0)
	{
		WindowVector.x = WindowVector.x / 2;
		WindowVector.y = WindowVector.y / 2;
	}
	ImVec2
		WindowSize(static_cast<float>(WindowVector.x / 2), static_cast<float>(WindowVector.y / 2)),
		TextWindowPos(WindowVector.x * 0.0f, WindowVector.y * 0.0f), // RightTopWindowPos(WindowVector.x / 2.0f, WindowVector.y * 0.0f),
		AnswerWindowPos(WindowVector.x * 0.0f, WindowVector.y / 2.0f); // RightBotWindowPos(WindowVector.x / 2.0f, WindowVector.y / 2.0f);

	const Vector2f defaultResolution = Vector2f(1920.0F, 1080.0F); //<---- Разрешения исходной пикчи.
	background.setScale(static_cast<float>(WindowVector.x) / defaultResolution.x, static_cast<float>(WindowVector.y) / defaultResolution.y);
	// размер спрайта по x = (Текущее разрешение.x/Разрешение background.png.x)
	// размер спрайта по y = (Текущее разрешение.y/Разрешение background.png.y)
	// адаптивный размер спрайта = setScale(x,y)

#pragma region ImGuiPars
	ImGui::SFML::Init(window);
	ImGui::StyleColorsDark();
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowRounding = 0.0f;
	style.WindowBorderSize = 0;
#pragma endregion

	sf::Clock deltaClock;
	while (!Keyboard::isKeyPressed(Keyboard::Escape)) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);
		}
		ImGui::SFML::Update(window, deltaClock.restart());

#pragma region TextWindow
	ImGui::Begin("Text", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
	ImGui::SetWindowSize(WindowSize);
	ImGui::SetWindowPos(TextWindowPos);
	ImGui::TextWrapped("TextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextTextText");
	ImGui::End();
#pragma endregion
#pragma region AnswerWindow
	ImGui::Begin("Answer", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
	ImGui::SetWindowSize(WindowSize);
	ImGui::SetWindowPos(AnswerWindowPos);

	static int selected = -1;
	for (int n = 0; n < 5; n++)
	{
		char buf[32];
		sprintf(buf, "Select %d", n);
		if (ImGui::Selectable(buf, selected == n))
			selected = n;
	}
	if (ImGui::Button("#NO DESIGN BUTTON \n Press"))
	{
		//Код который будет выполняться, пример есть в Settings.h
		int sfd = 1;
	}

	ImGui::End();
#pragma endregion




	ImGui::ShowTestWindow(); // DEBUG
	window.clear();
	window.draw(background);
	ImGui::SFML::Render(window);
	window.display();
	}
	ImGui::SFML::Shutdown();
}