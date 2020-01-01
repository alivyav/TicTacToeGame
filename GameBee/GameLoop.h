#pragma once
#include "StartWindow.h"
#include "OptionWindow.h"
#include "EndWindow.h"
#include "FriendWindow.h"
#include "AIWindow.h"
#include "DEF.h"

using namespace std;
using namespace sf;

class GameLoop
{
public:
	GameLoop() = delete;
	GameLoop(unsigned int width, unsigned int height, string title);
	~GameLoop();
private: 
	StartWindow* startWindow;
	OptionWindow* optionWindow;
	EndWindow* endWindow;
	FriendWindow* friendWindow;
	AIWindow* aiWindow;
	RenderWindow window;

	void Loop();
};


