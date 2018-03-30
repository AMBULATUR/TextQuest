#pragma once
using namespace sf;

	/// <summary>
	/// ��������� �������������� ������
	/// </summary>
	void SetFullScreen(RenderWindow & window, Vector2u sz)
	{
		window.create(VideoMode(sz.x, sz.y, 32), "TextQuest", sf::Style::Fullscreen);
	}
/// <summary>
/// ��������� �������� ������
/// </summary>
void SetWindowResolution(RenderWindow & window, Vector2u WindowVector)
{
	window.create(VideoMode(WindowVector.x / 2, WindowVector.y / 2, 32), "TextQuest", sf::Style::None);
}
/// <summary>
/// �������� ������� Esc
/// </summary>
void Sleep()
{
	while (!Keyboard::isKeyPressed(Keyboard::Escape));
}
