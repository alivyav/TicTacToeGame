#include "GameLoop.h"

GameLoop::GameLoop(unsigned int width, unsigned int height, string title)
{
	this->startWindow = new StartWindow();
	this->optionWindow = new OptionWindow();
	this->endWindow = new EndWindow();
	this->friendWindow = new FriendWindow();
	this->aiWindow = new AIWindow();

	states = States::START;
	this->window.create(VideoMode(width, height), title, Style::Close | Style::Titlebar);
	this->window.setActive(true);
	this->window.setVerticalSyncEnabled(true);
	this->Loop();

}

void GameLoop::Loop()
{
	while (window.isOpen())
	{
		Event event;
		window.clear(Color::Black);
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}
		if (isOk && states == States::WIN)
		{
			if (isOk2)
			{
				endWindow->setWhoWon(friendWindow->getWhoWon());
			}
			else
			{
				endWindow->setWhoWon(aiWindow->getWhoWon());
			}

			isOk = false;
		}

		switch (states)
		{
		case States::START:
			startWindow->update(window, event);
			window.draw(*startWindow);
			break;
		case States::OPTION:
			optionWindow->update(window, event);
			window.draw(*optionWindow);
			break;
		case States::GAME_AI:
			aiWindow->update(window, event);
			window.draw(*aiWindow);
			isOk2 = false;
			break;
		case States::GAME_FR:
			friendWindow->update(window, event);
			window.draw(*friendWindow);
			isOk2 = true;
			break;
		case States::WIN:
			endWindow->update(window, event);
			window.draw(*endWindow);
			break;
		case States::NEW_START:
			newGame();
			states = States::START;
			isOk = true;
			break;
		}
		
		window.display();
	}
}

void GameLoop::newGame()
{
	delete this->startWindow;
	delete this->friendWindow;
	delete this->aiWindow;
	delete this->optionWindow;
	delete this->endWindow;

	this->startWindow = new StartWindow();
	this->optionWindow = new OptionWindow();
	this->endWindow = new EndWindow();
	this->friendWindow = new FriendWindow();
	this->aiWindow = new AIWindow();
}
GameLoop::~GameLoop()
{
	delete this->startWindow;
	delete this->friendWindow;
	delete this->aiWindow;
	delete this->optionWindow;
	delete this->endWindow;
}
