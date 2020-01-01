#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Button.h"
#include "DEF.h"

using namespace sf;

class OptionWindow : public sf::Drawable
{
private:
	const Texture texture;
	const Texture friends;
	const Texture ai;
	Sprite sprite;
	Sprite spritef;
	Sprite spritea;

	Text text;
	Font font;
	Button* button;
	Button* button2;
	Button* settings;
public:
	OptionWindow();
	~OptionWindow();
	void update(RenderWindow& window, Event& event);
	void draw(RenderTarget& target, RenderStates states) const override;
};

