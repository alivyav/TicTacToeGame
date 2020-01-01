#pragma once
#include<SFML/Graphics.hpp>
#include "Button.h"
#include "DEF.h"

using namespace sf;

class StartWindow : public sf::Drawable
{
private:
	const sf::Texture texture;
	sf::Sprite sprite;

	Button* button;
	Button* button2;
	Button* button3;

public:
	StartWindow();
	~StartWindow();
	void update(RenderWindow& window, Event& event);
	void draw(RenderTarget& target, RenderStates states) const override;
};

