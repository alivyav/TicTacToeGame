#pragma once
#include<SFML/Graphics.hpp>
#include "Button.h"
#include "DEF.h"
#include "Field.h"

class FriendWindow : public Drawable
{
private:
	Field fields[3][3];
	Button* settings;

	int amount = 0;
	bool isOk{ true };

	Text text;
	Text text2;
	Font font;
	const sf::Texture texture;
	sf::Sprite sprite;
public:
	FriendWindow();
	~FriendWindow();
	void update(RenderWindow& window, Event& event);
	void draw(RenderTarget& target, RenderStates states) const override;
};

