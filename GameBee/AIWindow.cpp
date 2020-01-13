#include "AIWindow.h"
#include<iostream>
AIWindow::AIWindow()
{
	//const_cast<Texture&>(texturegame).loadFromFile("Resources/res/game.png");
	//spritegame.setTexture(texturegame);
	//spritegame.setPosition(0, 0);

	font.loadFromFile("Resources/fonts/beon.ttf");
	text.setFont(font);
	text.setString("Get 3 of your marks in a row ");
	text.setCharacterSize(48);
	text.setFillColor(Color(255, 255, 0));
	text.setPosition(50, 50);

	settings = new Button(700, 900, 50, 50, "S", 50);
	settings->setColors();

	const_cast<Texture&>(texture).loadFromFile("Resources/res/Grid.png");
	sprite.setTexture(texture);
	sprite.setPosition(150, 300);


	float x1 = 145, y1 = 295, x2 = 145;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fields[i][j].position(x1, y1);
			x1 = x1 + 160;
		}
		x1 = x2;
		y1 = y1 + 160;
	}

}
AIWindow::~AIWindow()
{

}

int AIWindow::minimax(int depth, bool isMaximizing)
{
	int result = this->isWin();
	if (result != 100)
	{
		return result;
	}
	if (isMaximizing)
	{
		int bestScore = -10000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (fields[i][j].getWhich() == 0)
				{
					fields[i][j].setWhich(1);
					int score = minimax(depth + 1, false);
					fields[i][j].setWhich(0);
					if (score > bestScore)
						bestScore = score;
				}
			}
		}
		return bestScore;
	}
	else
	{
		int bestScore = 100000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (fields[i][j].getWhich() == 0)
				{
					fields[i][j].setWhich(2);
					int score = minimax(depth + 1, true);
					fields[i][j].setWhich(0);
					if (score < bestScore)
						bestScore = score;
				}
			}
		}
		return bestScore;
	}
}

int AIWindow::isWin()
{
	int counter = 0;
	for (int i = 0; i < 3; i++)
	{
		if ((fields[i][0].getWhich() == 1 && fields[i][1].getWhich() == 1 && fields[i][2].getWhich() == 1) ||
			(fields[0][i].getWhich() == 1 && fields[1][i].getWhich() == 1 && fields[2][i].getWhich() == 1))
		{
			return -10;
		}
		if ((fields[i][0].getWhich() == 2 && fields[i][1].getWhich() == 2 && fields[i][2].getWhich() == 2) ||
			(fields[0][i].getWhich() == 2 && fields[1][i].getWhich() == 2 && fields[2][i].getWhich() == 2))
		{
			return 10;
		}
		for (int j = 0; j < 3; j++)
			if (fields[i][j].getWhich() == 0)
				counter++;
	}
	if ((fields[0][0].getWhich() == 1 && fields[1][1].getWhich() == 1 && fields[2][2].getWhich() == 1) ||
		(fields[0][2].getWhich() == 1 && fields[1][1].getWhich() == 1 && fields[2][0].getWhich() == 1))
	{
		return -10;
	}
	if ((fields[0][0].getWhich() == 2 && fields[1][1].getWhich() == 2 && fields[2][2].getWhich() == 2) ||
		(fields[0][2].getWhich() == 2 && fields[1][1].getWhich() == 2 && fields[2][0].getWhich() == 2))
	{
		return 10;
	}
	
	if (counter == 0) return 0;
	return 100;
}

void AIWindow::update(RenderWindow& window, Event& event)
{
	window.clear(Color(159, 128, 255));
	if (this->amount % 2 == 0)
	{
		text2.setFont(font);
		text2.setString("IT'S X TURN!");
		text2.setCharacterSize(50);
		text2.setFillColor(Color::Black);
		text2.setPosition(250, 220);
	}

	else
	{
		text2.setFont(font);
		text2.setString("IT'S O TURN!");
		text2.setCharacterSize(50);
		text2.setFillColor(Color::White);
		text2.setPosition(250, 220);
	}


	Vector2f position = Vector2f(Mouse::getPosition(window));
	if (settings->Update(position, event))
	{

	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << fields[i][j].getWhich() << " - ";
		}
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------" << std::endl;

	if (this->amount % 2 != 0)
	{
		int bestScore = -1000000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (fields[i][j].getWhich() == 0)
				{
					fields[i][j].setWhich(1);
					int score = minimax(0, false);
					fields[i][j].setWhich(0);
					if (score > bestScore)
					{
						bestScore = score;
						this->bestMoveX = i;
						this->bestMoveY = j;
					}
				}
			}
		}
		fields[bestMoveX][bestMoveY].setWhich(1);
		fields[bestMoveX][bestMoveY].setField(true);
		this->amount++;
	}
	else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && (this->amount % 2 == 0))
	{
		if (isOk)
		{
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (fields[a][b].getSprite().getGlobalBounds().contains(position) && !fields[a][b].getField())
					{
						fields[a][b].setField(true);
						fields[a][b].setWhich(2);
						std::cout << fields[a][b].getWhich() << std::endl;
						this->amount++;
						isOk = false;
					}

				}

			}

			if (this->amount == 9)
			{
				whoWon = 0;
				states = States::WIN;
			}

			
		}

	}
	else if (event.type == Event::MouseButtonReleased)
		isOk = true;
	int result = this->isWin();
	if (result == 10)
	{
		whoWon = 2;
		states = States::WIN;
	}
	else if (result == -10)
	{
		whoWon = 1;
		states = States::WIN;
	}
	//gra
}

int AIWindow::getWhoWon()
{
	return whoWon;
}

void AIWindow::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(spritegame);
	target.draw(sprite);
	target.draw(text);
	target.draw(text2);
	target.draw(*settings);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (fields[i][j].getField())
				target.draw(fields[i][j]);
}
