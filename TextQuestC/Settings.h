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
static SettingsInit::SetUp SendSettings(SettingsInit::SetUp params, int Mode, int MusicStatic, int EffectsStatic, bool CheckMusic, bool CheckEffects, RenderWindow & window);
void Settings(RenderWindow & window, SettingsInit::SetUp & params, Vector2u WindowVector)
{
	//Загрузка текстур
	Texture settingsBackground;
	settingsBackground.loadFromFile("images/SettingsBackground.png");
	//Преобразование в спрайт

	Sprite background(settingsBackground);

	static string x;
	static string y;


#pragma region VideoVars
	int Mode = params.FullScreenMode;
#pragma endregion

#pragma region AudioVars
	int
		MusicStatic = params.Music,
		EffectsStatic = params.Effects;
	bool CheckMusic = params.MMusic;
	bool CheckEffects = params.MEffects;
#pragma endregion
	if (params.FullScreenMode == 0)
	{
		WindowVector.x = WindowVector.x / 2;
		WindowVector.y = WindowVector.y / 2;
		x = std::to_string(WindowVector.x);
		y = std::to_string(WindowVector.y);
	}
	else
	{
		x = std::to_string(WindowVector.x);
		y = std::to_string(WindowVector.y);
	}
	const Vector2f defaultResolution = Vector2f(1920.0F, 1080.0F);
	background.setScale(static_cast<float>(WindowVector.x) / defaultResolution.x,
		static_cast<float>(WindowVector.y) / defaultResolution.y); // Так считаем размер спрайтов

	//Начало отрисовки

	ImVec2
		WindowSize(static_cast<float>(WindowVector.x), static_cast<float>(WindowVector.y)),
		VideoWindowPos(WindowVector.x * 0.0f, WindowVector.y * 0.0f);

	std::string OptimalResolution = "Current resolution - " + x + "x" + y;
	const char *RR = OptimalResolution.c_str();





#pragma region ImGuiPars
	int clicked = 0;

	ImGui::SFML::Init(window);
	ImGui::StyleColorsDark();
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowRounding = 0.0f;
	style.WindowBorderSize = 0;
#pragma endregion

	sf::Clock deltaClock;
	while (!Keyboard::isKeyPressed(Keyboard::Escape) && clicked != 1) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);
		}
		ImGui::SFML::Update(window, deltaClock.restart());



#pragma region VideoWindow
		ImGui::Begin("Video", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
		ImGui::SetWindowSize(WindowSize);
		ImGui::SetWindowPos(VideoWindowPos);
		//ImGui::Button("Set"); ImGui::SameLine(); 
		ImGui::Text(RR);
		ImGui::Text("");
		ImGui::RadioButton("FullScreen", &Mode, 1); ImGui::SameLine();
		ImGui::RadioButton("Window", &Mode, 0);
		ImGui::SliderInt("Music", &MusicStatic, 0, 100); ImGui::SameLine(); ImGui::Checkbox("Mute Music", &CheckMusic);
		ImGui::SliderInt("Effects", &EffectsStatic, 0, 100); ImGui::SameLine(); ImGui::Checkbox("Mute Effects", &CheckEffects);
		if (ImGui::Button("Save"))
			clicked++;
		if (clicked & 1)
		{
			params = SendSettings(params, Mode, MusicStatic, EffectsStatic, CheckMusic, CheckEffects, window);
		}
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
	if (ImGui::Begin("MPos", p_open,
		ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_AlwaysAutoResize |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoFocusOnAppearing |
		ImGuiWindowFlags_NoNav))
	{
		ImGui::Text("Mouse Position: (%.1f,%.1f)", ImGui::GetIO().MousePos.x, ImGui::GetIO().MousePos.y);
	}
	ImGui::End();
}

static ImVec2 GetWindowPos(int corner)
{
	const float DISTANCE = 10.0f;
	return ImVec2((corner & 1) ? ImGui::GetIO().DisplaySize.x - DISTANCE : DISTANCE, (corner & 2) ? ImGui::GetIO().DisplaySize.y : DISTANCE);

}

static ImVec2 GetWindowPivot(int corner)
{
	return ImVec2
	((corner & 1) ? 1.0f : 0.0f, (corner & 2) ? 1.0f : 0.0f);
}

static SettingsInit::SetUp SendSettings(SettingsInit::SetUp params, int Mode, int MusicStatic, int EffectsStatic, bool CheckMusic, bool CheckEffects, RenderWindow & window)
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	if (Mode == 1)
		window.create(VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "TextQuest", Style::Fullscreen);
	else
	{
		window.create(VideoMode(desktop.width / 2, desktop.height / 2, 32), "TextQuest", sf::Style::None);

	}
	params.FullScreenMode = Mode;
	params.Effects = EffectsStatic;
	params.Music = MusicStatic;
	params.MEffects = CheckEffects;
	params.MMusic = CheckMusic;
	SettingsInit obj;
	obj.UpdateSettings(params);
	return params;
}