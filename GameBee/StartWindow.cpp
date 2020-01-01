#include "StartWindow.h"

StartWindow::StartWindow()
{
	const_cast<Texture&>(texture).loadFromFile("Resources/res/ttt.png");
	sprite.setTexture(texture);
	sprite.setPosition(100, 50);

	button = new Button(50,650,290,100,"START",100);
	button->setColors();
	button2 = new Button(50,800,215,100, "EXIT",100);
	button2->setColors();
	button3 = new Button(700, 900, 50, 50, "S",50);
	button3->setColors();

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
	if (button3->Update(position, event))
	{

	}
}
void StartWindow::draw(RenderTarget& target, RenderStates states) const 
{
	target.draw(sprite);
	target.draw(*button);
	target.draw(*button2);
	target.draw(*button3);
}
