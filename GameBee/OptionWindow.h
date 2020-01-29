#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

	bool first=true;

	Text text;
	Font font;
	Button* button;
	Button* button2;
public:
	OptionWindow();
	~OptionWindow();
	void update(RenderWindow& window, Event& event);
	void draw(RenderTarget& target, RenderStates states) const override;
};

