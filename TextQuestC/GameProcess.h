#pragma once
#pragma execution_character_set("utf-8")
#include "Helper.h"
#include <fstream>


using namespace sf;


ImFont*  youFont = nullptr;
const string PATH = "Story/";
string filename = "file1.txt";
string questions[1000];
int numOfQuestions;
string way[1000];




void SaveLoad()
{
	ofstream fon;
	fon.open(PATH + "SaveFile.txt");
	if (fon.is_open())
	{
		fon << filename;
	}
}

string ParseFile(string path)
{

	ifstream fin;
	fin.open(PATH + path);
	string out = "";
	char temp[10000] = "";
	if (fin.is_open())
		while (!fin.eof())
		{
			out += temp;
			fin.getline(temp, 10000);
			if (temp[0] != '@')
			{
				out += temp;
				continue;
			}
			else
			{
				char temp1[10000];
				for (int i = 0; !fin.eof(); i++)
				{
					fin.getline(temp1, 10000);
					questions[i] = temp1;
					fin.getline(temp1, 10000);
					way[i] = temp1;
				}
			}
		}
	return out;
}







void GameProcess(RenderWindow & window, SettingsInit::SetUp params, Vector2u WindowVector)
{
	//Загрузка текстур
	window.clear();
	Texture gameBackground, sprite;
	gameBackground.loadFromFile("images/GameInterface.jpg");
	sprite.loadFromFile("images/1.png");
	//Преобразование в спрайт
	Sprite background(gameBackground), GSprite(sprite);
	//Начало отрисовки

	if (params.FullScreenMode == 0)
	{
		WindowVector.x = WindowVector.x / 2;
		WindowVector.y = WindowVector.y / 2;
	}
	ImVec2

		WindowSize(WindowVector.x / 2.30f, WindowVector.y / 1.68f),
		AnswerSize(static_cast<float>(WindowVector.x), WindowVector.y / 2.0f),
		ExitSize(WindowVector.x / 4.0f, WindowVector.y / 4.0f),
		ExitWindowPos(WindowVector.x / 2.5f, WindowVector.y / 2.5f),
		TextWindowPos(WindowVector.x * 0.055f, WindowVector.y * 0.065f), // 0.55f , 0.65f
		AnswerWindowPos(WindowVector.x * 0.055f, WindowVector.y / 1.4f); // 0.055f, 1.4f
	GSprite.setPosition(WindowVector.x / 1.99f, WindowVector.y * 0.065f);

	// RightBotWindowPos(WindowVector.x / 2.0f, WindowVector.y / 2.0f);

	const Vector2f defaultResolution = Vector2f(1920.0F, 1080.0F); //<---- Разрешения исходной пикчи.
	background.setScale(static_cast<float>(WindowVector.x) / defaultResolution.x, static_cast<float>(WindowVector.y) / defaultResolution.y);
	GSprite.setScale(static_cast<float>(WindowVector.x) / defaultResolution.x, static_cast<float>(WindowVector.y) / defaultResolution.y);
	// размер спрайта по x = (Текущее разрешение.x/Разрешение background.png.x)
	// размер спрайта по y = (Текущее разрешение.y/Разрешение background.png.y)
	// адаптивный размер спрайта = setScale(x,y)

#pragma region ImGuiPars
//	ImGui::SFML::Init(window);
	ImGui::StyleColorsDark();
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowRounding = 0.0f;
	style.WindowBorderSize = 0;
	static char buf[32];
	bool Exit = false;
	bool Menu = false;
#pragma endregion

	sf::Clock deltaClock;
	while (!Exit) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);
		}
		ImGui::SFML::Update(window, deltaClock.restart());

#pragma region TextWindow

		ImGui::SetNextWindowBgAlpha(0.0f);
		ImGui::Begin("Text", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
		ImGui::SetWindowSize(WindowSize);
		ImGui::SetWindowPos(TextWindowPos);
		const string tt = ParseFile(filename);
		const char *RR = tt.c_str();

		ImGui::TextWrapped(RR);

		ImGui::End();
#pragma endregion
#pragma region AnswerWindow
		ImGui::SetNextWindowBgAlpha(0.0f);
		ImGui::Begin("Answer", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
		ImGui::SetWindowSize(AnswerSize);
		ImGui::SetWindowPos(AnswerWindowPos);

		static int selected = -1;
		for (int n = 0; n < 5; n++)
		{

			sprintf(buf, questions[n].c_str());
			if (ImGui::Selectable(buf, selected == n)) {
				selected = n;
				filename = way[selected];
			}
		}
		ImGui::End();
		if (Keyboard::isKeyPressed(Keyboard::Escape)) Menu = true;
		if (Menu)
		{
			ImGui::Begin("Exit", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
			ImGui::SetWindowSize(ExitSize);
			ImGui::SetWindowPos(ExitWindowPos);

			if (ImGui::Button("Resume"))
				Menu = false;
			if (ImGui::Button("Save"))
				SaveLoad();
			if (ImGui::Button("Exit to MM"))
				Exit = true;
			ImGui::End();
		}


#pragma endregion




		ImGui::ShowTestWindow(); // DEBUG
		window.clear();
		window.draw(background);
		window.draw(GSprite);
		ImGui::SFML::Render(window);
		window.display();

	}
}

void GameProcess(RenderWindow & window, SettingsInit::SetUp params, Vector2u WindowVector, string save) {
	filename = save;
	GameProcess(window, params, WindowVector);
}