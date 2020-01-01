#include "Field.h"

Field::Field()
{
	const_cast<Texture&>(texturex).loadFromFile("Resources/res/X.png");
	spritex.setTexture(texturex);

	const_cast<Texture&>(textureo).loadFromFile("Resources/res/O.png");
	spriteo.setTexture(textureo);
}

void Field::position(float x,float y)
{
	spritex.setPosition(x,y);
	spriteo.setPosition(x, y);
}

void Field::setField(bool status)
{
	this->isClicked = status;
}

bool Field::getField() const
{
	return this->isClicked;
}

Sprite Field::getSprite() const
{
	return spritex;
}

void Field::setWhich(int which)
{
	this->which = which;
}

int Field::getWhich()
{
	return which;
}

void Field::draw(RenderTarget& target, RenderStates states) const
{
	if (which == 2)
		target.draw(spritex);
	else if(which == 1)
		target.draw(spriteo);

}