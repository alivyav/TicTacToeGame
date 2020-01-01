#include "InputManager.h"

bool InputManager::IsSpriteClicked(Sprite object, Mouse::Button button, RenderWindow& window)
{
	if (Mouse::isButtonPressed(button))
	{
		IntRect playButton (object.getPosition().x, object.getPosition().y, object.getGlobalBounds().height, object.getGlobalBounds().width);

		if (playButton.contains(Mouse::getPosition(window)))
		{
			return true;
		}
		
	}
	else
		return false;
}
Vector2i InputManager::GetMousePostion(RenderWindow& window)
{
	return Mouse::getPosition(window);
}
