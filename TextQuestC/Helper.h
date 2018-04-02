#pragma once
using namespace sf;
/// <summary>
/// ��������� �������������� ������
/// </summary>
void SetFullScreen(RenderWindow & window, Vector2u sz)
{
	window.create(VideoMode(sz.x, sz.y, 32), "TextQuest", sf::Style::None);
}
/// <summary>
/// ��������� �������� ������
/// </summary>
void SetWindowResolution(RenderWindow & window, Vector2u sz)
{
	window.create(VideoMode(sz.x/2, sz.y/2, 32), "TextQuest", sf::Style::None);
}
/// <summary>
/// �������� ������� Esc
/// </summary>
void Sleep()
{
	while (!Keyboard::isKeyPressed(Keyboard::Escape));
}