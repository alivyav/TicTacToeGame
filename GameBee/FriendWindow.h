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

	int maxColumnX = 0;
	int maxColumnO = 0;
	int maxRowX = 0;
	int maxRowO = 0;
	int whoWon;

	Text text;
	Text text2;
	Font font;
	const Texture texture;
	const Texture texturegame;
	Sprite sprite;
	Sprite spritegame;
public:
	FriendWindow();
	~FriendWindow();
	void update(RenderWindow& window, Event& event);
	void draw(RenderTarget& target, RenderStates states) const override;
	int getWhoWon();
};

