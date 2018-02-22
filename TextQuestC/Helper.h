#pragma once
using namespace sf;
/// <summary>
/// Установка полноэкранного режима
/// </summary>
void SetFullScreen(RenderWindow & window, Vector2u sz)
{
	window.create(VideoMode(sz.x, sz.y, 32), "TextQuest", sf::Style::None);
}
/// <summary>
/// Установка оконного режима
/// </summary>
void SetWindowResolution(RenderWindow & window, Vector2u sz)
{
	window.create(VideoMode(sz.x/2, sz.y/2, 32), "TextQuest", sf::Style::None);
}
/// <summary>
/// Ожидание нажатия Esc
/// </summary>
void Sleep()
{
	while (!Keyboard::isKeyPressed(Keyboard::Escape));
}