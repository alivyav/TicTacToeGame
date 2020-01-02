#pragma once
#include<SFML/Graphics.hpp>
#include "Button.h"
#include "DEF.h"

using namespace sf;
class EndWindow : public Drawable
{private:
	const Texture texture;
	const Texture winnertx;
	Sprite sprite;
	Sprite textSprite;
	Sprite winner;
	Text text;
	Font font;

	Button* yes;
	Button* no;
	Button* settings;

public:
	EndWindow();
	~EndWindow();
	void update(RenderWindow& window, Event& event);
	void draw(RenderTarget& target, RenderStates states) const override;
};

