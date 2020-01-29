#include "StartWindow.h"

StartWindow::StartWindow()
{
	const_cast<Texture&>(textureb).loadFromFile("Resources/res/over.png");
	spriteb.setTexture(textureb);
	spriteb.setPosition(0, 0);

	font.loadFromFile("Resources/fonts/beon.ttf");
	text.setFont(font);
	text.setString("tic tac toe ");
	text.setCharacterSize(90);
	text.setFillColor(Color::Magenta);
	text.setPosition(50, 50);
	//const_cast<Texture&>(texture).loadFromFile("Resources/res/tic.png");
	//sprite.setTexture(texture);
	//sprite.setPosition(250, 250);

	button = new Button(250,700,290,100,"START",100);
	button->setColors();
	button2 = new Button(285,850,215,100, "EXIT",100);
	button2->setColors();
}

StartWindow::~StartWindow()
{

}

void StartWindow::update(RenderWindow& window, Event& event)
{
	Vector2f position = Vector2f(Mouse::getPosition(window));
	if (button->Update(position, event))
	{
		states = States::OPTION;
	}
	if (button2->Update(position, event))
	{
		window.close();
	}
}

void StartWindow::draw(RenderTarget& target, RenderStates states) const 
{
	target.draw(spriteb);
	target.draw(sprite);
	target.draw(text);
	target.draw(*button);
	target.draw(*button2);
}
