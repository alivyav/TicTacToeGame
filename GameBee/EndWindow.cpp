#include "EndWindow.h"
EndWindow::EndWindow()
{
	const_cast<Texture&>(texture).loadFromFile("Resources/res/pobrane.png");
	sprite.setTexture(texture);
	sprite.setPosition(200, 200);

	font.loadFromFile("Resources/fonts/Neon.ttf");
	text.setFont(font);
	text.setString("Do you want to play again?");
	text.setCharacterSize(55);
	text.setFillColor(sf::Color::Magenta);
	text.setPosition(50, 550);

	yes = new Button(100, 700, 120, 70, "Yes!",70);
	yes->setColors();
	no = new Button(500, 700, 170, 70, "No :(",65);
	no->setColors();
	settings = new Button(700, 900, 50, 50, "S", 50);
	settings->setColors();

}
EndWindow::~EndWindow()
{

}

void EndWindow::update(RenderWindow& window, Event& event)
{
	Vector2f position = Vector2f(Mouse::getPosition(window));
	if (yes->Update(position, event))
	{
		states = States::START;
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
}
