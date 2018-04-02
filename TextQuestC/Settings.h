#pragma once

#include "Helper.h"
#include <imgui.h>
#include <imgui-SFML.h>
#include "SettingsInit.h"

#define TopLeft 0
#define TopRight 1
#define BotLeft 2
#define BotRight 3

using namespace sf;

ImVec2 GetWindowPivot(int corner);
ImVec2 GetWindowPos(int corner);
void ShowExampleAppFixedOverlay(bool* p_open, ImVec2 window_pos, ImVec2 window_pos_pivot);
void Settings(RenderWindow & window, Vector2u WindowVector, SettingsInit::SetUp params)
{
	//Загрузка текстур
	Texture settingsBackground;
	settingsBackground.loadFromFile("images/SettingsBackground.png");
	//Преобразование в спрайт
	Sprite background(settingsBackground);
	
	//Начало отрисовки
	background.setScale(Vector2f(1.0f, 1.0f));

	ImVec2
		WindowSize(WindowVector.x / 2.0f, WindowVector.y / 2.0f),
		VideoWindowPos(WindowVector.x * 0.0f, WindowVector.y * 0.0f),
		AudioWindowPos(WindowVector.x / 2.0f, WindowVector.y * 0.0f),
		GameplayWindowPos(WindowVector.x * 0.0f, WindowVector.y / 2.0f),
		ControlWindowPos(WindowVector.x / 2.0f, WindowVector.y / 2.0f);

	std::string x = std::to_string(WindowVector.x);
	std::string y = std::to_string(WindowVector.y);
	std::string OptimalResolution = "optimal resolution - " + x + "x" + y;
	const char *RR = OptimalResolution.c_str();
#pragma endregion

#pragma region VideoVars
	static int current_item_1 = 1;
	static int Mode = 0;
#pragma endregion

#pragma region AudioVars
	static int MusicStatic = params.Music, EffectsStatic = params.Effects;
	static bool CheckMusic = params.MMusic;
	static bool CheckEffects = params.MEffects;
#pragma endregion





	
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
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				break;
			}
		}
		ImGui::SFML::Update(window, deltaClock.restart());



#pragma region VideoWindow
		ImGui::Begin("Video", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
		ImGui::SetWindowSize(WindowSize);
		ImGui::SetWindowPos(VideoWindowPos);
		ImGui::Button("Set"); ImGui::SameLine(); ImGui::Text(RR);
		ImGui::Text("");
		ImGui::Combo("Resolution", &current_item_1, " 640x480\0 800x600\0 1280x1024\0 1920x1080\0 1600x1200\0");
		ImGui::RadioButton("FullScreen", &Mode, 1); ImGui::SameLine();
		ImGui::RadioButton("Window", &Mode, 2);
		ImGui::Button("Save");
		ImGui::End();
#pragma endregion
#pragma region AudioWindow
		ImGui::Begin("Audio", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
		ImGui::SetWindowSize(WindowSize);
		ImGui::SetWindowPos(AudioWindowPos);
		ImGui::SliderInt("Music", &MusicStatic, 0, 100); ImGui::SameLine(); ImGui::Checkbox("Mute Music", &CheckMusic);
		ImGui::SliderInt("Effects", &EffectsStatic, 0, 100); ImGui::SameLine(); ImGui::Checkbox("Mute Effects", &CheckEffects);
		ImGui::Button("Save");
		ImGui::End();
#pragma endregion
#pragma region GamePlayWindow
		ImGui::Begin("Gameplay", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
		ImGui::SetWindowSize(WindowSize);
		ImGui::SetWindowPos(GameplayWindowPos);
		ImGui::Button("Save");
		ImGui::End();
#pragma endregion
#pragma region ControlWindow
		ImGui::Begin("Control", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
		ImGui::SetWindowSize(WindowSize);
		ImGui::SetWindowPos(ControlWindowPos);
		ImGui::Button("Save");
		ImGui::End();
#pragma endregion

		ShowExampleAppFixedOverlay(NULL, GetWindowPos(BotRight), GetWindowPivot(BotRight));
		ImGui::ShowTestWindow(); // DEBUG
		window.clear();
		window.draw(background);
		ImGui::SFML::Render(window);
		window.display();
	}
	ImGui::SFML::Shutdown();
}

static void ShowExampleAppFixedOverlay(bool* p_open, ImVec2 window_pos, ImVec2 window_pos_pivot)
{

	ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
	ImGui::SetNextWindowBgAlpha(0.3f);
	if (ImGui::Begin("MPos", p_open, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav))
	{
		ImGui::Text("Mouse Position: (%.1f,%.1f)", ImGui::GetIO().MousePos.x, ImGui::GetIO().MousePos.y);
	}
	ImGui::End();
}

static ImVec2 GetWindowPos(int corner)
{
	const float DISTANCE = 10.0f;
	return ImVec2(
		(corner & 1)
		?
		ImGui::GetIO().DisplaySize.x - DISTANCE
		:
		DISTANCE, (corner & 2) 
		?
		ImGui::GetIO().DisplaySize.y 
		:
		DISTANCE);

}

static ImVec2 GetWindowPivot(int corner)
{
	return ImVec2
	(
		(corner & 1)
		?
		1.0f 
		:
		0.0f,
		(corner & 2)
		?
		1.0f 
		:
		0.0f
	);
}