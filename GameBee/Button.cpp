#include "Button.h"
Button::Button(float x, float y, float width, float height, std::string text, int size, std::string fontName)
{
	font.loadFromFile("Resources/fonts/beon.ttf");

	this->shape.setSize(Vector2f(width, height));
	this->shape.setPosition(x, y);
	this->shape.setFillColor(Color::Transparent);

	this->text.setString(text);
	this->text.setFont(font);
	this->text.setCharacterSize(size);
	this->text.setPosition(x, y);

	clickBuffer.loadFromFile("Resources/Button.wav");
	buttonBuffer.loadFromFile("Resources/Click.wav");

	buttonSound.setBuffer(buttonBuffer);
	clickSound.setBuffer(clickBuffer);
}

void Button::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(shape);
	target.draw(text);
}

bool Button::Update(Vector2f position, Event event)
{
	isClicked = false;
	bState = NO_CLICKED;

	if (shape.getGlobalBounds().contains(position))
	{
		bState = ON_BUTTON;
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
		{
			bState = CLICKED;
			isClicked = true;
		}
	}

	switch (this->bState)
	{
	case NO_CLICKED:
		text.setFillColor(no_clicked);
		break;
	case ON_BUTTON:
		buttonSound.play();
		text.setFillColor(on_button);
		break;
	case CLICKED:
		clickSound.play();
		text.setFillColor(clicked);
		break;
	default:
		break;
	}
		
	return isClicked;

}
void Button::setColors(Color no_clicked, Color on_button, Color clicked)
{
	this->no_clicked = no_clicked;
	this->on_button = on_button;
	this->clicked = clicked;
}
