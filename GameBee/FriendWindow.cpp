#include "FriendWindow.h"
FriendWindow::FriendWindow() 
{
	font.loadFromFile("Resources/fonts/Neon.ttf");
	text.setFont(font);
	text.setString("Get 3 of your marks in a row ");
	text.setCharacterSize(52);
	text.setFillColor(Color(255, 255, 0));
	text.setPosition(50, 50);

	//text2.setFont(font);
	//text2.setString("IT'S ... TURN!");
	//text2.setCharacterSize(50);
	//text2.setFillColor(sf::Color::Red);
	//text2.setPosition(250, 220);

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
FriendWindow::~FriendWindow()
{

}
void FriendWindow::update(RenderWindow& window, Event& event)
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
	if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
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
						if (this->amount % 2 == 0)
							fields[a][b].setWhich(2);
						else
							fields[a][b].setWhich(1);
						this->amount++;
						isOk = false;
					}
					if (fields[a][b].getWhich() == 1)
						maxRowX++;
					if(fields[a][b].getWhich() == 2)
						maxRowO++;

				}

			}
			if (maxRowO == 3)
			{
				states = States::WIN;
				//	maxRowO = 0;
			}
			if (maxRowX == 3)
			{
				states = States::WIN;
				//	maxRowX = 0;
			}
		}
			
	}
	else if (event.type == Event::MouseButtonReleased)
		isOk = true;
	//gra
}
void FriendWindow::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(sprite);
	target.draw(text);
	target.draw(text2);
	target.draw(*settings);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if(fields[i][j].getField())
				target.draw(fields[i][j]);
}
