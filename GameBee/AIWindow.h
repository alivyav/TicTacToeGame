#pragma once
#include<SFML/Graphics.hpp>
#include "Button.h"
#include "DEF.h"
#include "Field.h"

class AIWindow : public Drawable
{
private:
	Field fields[3][3];
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
	Sprite sprite;
	Sprite spritegame;

	int bestMove[2]{};

	void minimax();
	int isWin();
	int min();
	int max();

public:
	AIWindow();
	~AIWindow();
	void update(RenderWindow& window, Event& event);
	void draw(RenderTarget& target, RenderStates states) const override;
	int getWhoWon();
};

