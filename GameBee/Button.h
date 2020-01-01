#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

enum bColors{NO_CLICKED, ON_BUTTON, CLICKED};

class Button : public Drawable
{
private:
	Font font{};
	Text text{};
	RectangleShape shape;
	int bState{ NO_CLICKED };
	bool isClicked;
	Color no_clicked;
	Color on_button;
	Color clicked;

public:
	Button() = delete;
	Button(float x, float y, float width, float height, std::string text, int size=30, std::string fontName = "arial");
	~Button() = default;
	void draw(RenderTarget& target, RenderStates states) const override;
	bool Update(Vector2f position, Event event);
	void setColors(Color no_clicked=Color::White, Color on_button=Color::Cyan, Color clicked = Color::Magenta);
};

