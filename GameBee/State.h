#pragma once
#include <SFML/Graphics.hpp>
class State : public sf::Drawable
{	
public:
	virtual void Init() = 0;
	virtual void HandleInput() = 0;
	//virtual void Update(float dt)=0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) = 0;
	virtual void Pause() {}
	virtual void Resume() {}

};

