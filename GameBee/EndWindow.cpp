#include "EndWindow.h"
EndWindow::EndWindow()
{
	const_cast<Texture&>(texture).loadFromFile("Resources/res/over.png");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	font.loadFromFile("Resources/fonts/beon.ttf");
	text.setFont(font);
	text.setString("Do you want to play again?");
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Yellow);
	text.setPosition(50, 700);

	yes = new Button(100, 800, 120, 70, "Yes!",70);
	yes->setColors();
	no = new Button(500, 800, 170, 70, "No :(",65);
	no->setColors();
	settings = new Button(700, 900, 50, 50, "S", 50);
	settings->setColors();

}
EndWindow::~EndWindow()
{

}

void EndWindow::setWhoWon(int whoWon)
{
	this->whoWon = whoWon;
}

void EndWindow::update(RenderWindow& window, Event& event)
{
	switch (whoWon)
	{
	case 0:
		const_cast<Texture&>(winnertx).loadFromFile("Resources/res/draw.png");
		winner.setTexture(winnertx);
		winner.setPosition(205, 200);
		break;
	case 1:
		const_cast<Texture&>(winnertx).loadFromFile("Resources/res/owon.png");
		winner.setTexture(winnertx);
		winner.setPosition(205, 200);
		break;
	case 2:
		const_cast<Texture&>(winnertx).loadFromFile("Resources/res/xwon.png");
		winner.setTexture(winnertx);
		winner.setPosition(205, 200);
		break;
	}

	window.clear(Color::Yellow);
	Vector2f position = Vector2f(Mouse::getPosition(window));
	if (yes->Update(position, event))
	{
		states = States::NEW_START;
	}
	if (no->Update(position, event))
	{
		window.close();
	}
	if (settings->Update(position, event))
	{

	}

}
void EndWindow::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(sprite);
	target.draw(text);
	target.draw(*yes);
	target.draw(*no);
	target.draw(*settings);
	target.draw(winner);
}
