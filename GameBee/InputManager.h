#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class InputManager
{
public: 
	bool IsSpriteClicked(Sprite object, Mouse::Button button, RenderWindow& window);
	Vector2i GetMousePostion(RenderWindow& window);

};

