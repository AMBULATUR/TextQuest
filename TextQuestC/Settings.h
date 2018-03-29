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
void Settings(RenderWindow & window, Vector2u WindowVector)
{
	//Загрузка текстур
	Texture settingsBackground;
	settingsBackground.loadFromFile("images/settings.png");
	//Преобразование в спрайт
	Sprite background(settingsBackground);
	
	//Начало отрисовки
	// sz = Vector2u(1280, 1024);
	background.setScale(Vector2f(1.0f, 1.0f));
	SetFullScreen(window, WindowVector);


	//OtherVars Start
	window.setFramerateLimit(60); //FrameRate for IMGUI

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




	//OtherVars End

	//Video Vars
	static int current_item_1 = 1;
	static int Mode = 0;

	//Music Vars
	static int MusicStatic = 50, EffectsStatic = 50;
	static bool CheckMusic = false;
	static bool CheckEffects = false;




	//ImGuiPars Start

	ImGui::SFML::Init(window);
	ImGui::StyleColorsDark();
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowRounding = 0.0f;
	style.WindowBorderSize = 0;



	//ImGuiPars End
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


		//######################




		//VideoWindow Start
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

		//VideoWindow End

		//AudioWindow Start
		ImGui::Begin("Audio", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
		ImGui::SetWindowSize(WindowSize);
		ImGui::SetWindowPos(AudioWindowPos);
		ImGui::SliderInt("Music", &MusicStatic, 0, 100); ImGui::SameLine(); ImGui::Checkbox("Mute Music", &CheckMusic);
		ImGui::SliderInt("Effects", &EffectsStatic, 0, 100); ImGui::SameLine(); ImGui::Checkbox("Mute Effects", &CheckEffects);
		ImGui::Button("Save");
		ImGui::End();
		//AudioWindow End

		//GameplayWindow Start
		ImGui::Begin("Gameplay", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
		ImGui::SetWindowSize(WindowSize);
		ImGui::SetWindowPos(GameplayWindowPos);
		ImGui::Button("Save");
		ImGui::End();
		//GameplayWindow End

		//ControlWindow Start
		ImGui::Begin("Control", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
		ImGui::SetWindowSize(WindowSize);
		ImGui::SetWindowPos(ControlWindowPos);
		ImGui::Button("Save");

		ShowExampleAppFixedOverlay(NULL, GetWindowPos(BotRight), GetWindowPivot(BotRight));

		ImGui::End();
		//ControlWindow End
		ImGui::ShowTestWindow(); // DEBUG


		window.clear();
		window.draw(background);
		ImGui::SFML::Render(window);
		window.display();
	}
	//######################
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