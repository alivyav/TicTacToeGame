#include "OptionWindow.h"

OptionWindow::OptionWindow()
{
	//FONT
	font.loadFromFile("Resources/fonts/Neon.ttf");
	text.setFont(font);
	text.setString("Choose your game option: ");
	text.setCharacterSize(55);
	text.setFillColor(sf::Color::Magenta);
	text.setPosition(50, 50);

	//sprite.setTexture(texture);
	//sprite.setPosition(50, 100);

	button = new Button(130, 200, 535, 50, "PLAY WITH COMPUTER",50);
	button->setColors();

	const_cast<Texture&>(ai).loadFromFile("Resources/res/computer.png");
	spritea.setTexture(ai);
	spritea.setPosition(300, 300);

	button2 = new Button(170, 525, 440, 50, "PLAY WITH FRIEND",50);
	button2->setColors();

	const_cast<Texture&>(friends).loadFromFile("Resources/res/friend.png");
	spritef.setTexture(friends);
	spritef.setPosition(300, 600);

	settings = new Button(700, 900, 50, 50, "S", 50);
	settings->setColors();
}
OptionWindow::~OptionWindow()
{

}

void OptionWindow::update(RenderWindow& window, Event& event)
{
	window.clear(Color(26, 0, 26));
	Vector2f position = Vector2f(Mouse::getPosition(window));
	if (button->Update(position, event))
	{
		Sleep(200);
		states = States::GAME_AI;
	}
	if (button2->Update(position, event))
	{
		Sleep(200);
		states = States::GAME_FR;
	}
	if (settings->Update(position, event))
	{

	}

}
void OptionWindow::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(text);
	//target.draw(sprite);
	target.draw(spritea);
	target.draw(spritef);
	target.draw(*button);
	target.draw(*button2);
	target.draw(*settings);
}

