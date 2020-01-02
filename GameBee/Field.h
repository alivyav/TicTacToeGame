#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Field : public Drawable
{
private:
	Sprite spritex;
	const Texture texturex; 
	Sprite spriteo;
	const Texture textureo;
	int which = 0;

	bool isClicked{ false };
public:
	Field();
	~Field() = default;
	void draw(RenderTarget& target, RenderStates states) const override;
	void position(float x, float y);
	
	Sprite getSprite() const;

	void setField(bool status);
	bool getField() const;
	int getWhich();
	void setWhich(int which);
	//void color(Color color);
	//bool Update(Vector2f position, Event event);
};


