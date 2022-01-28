#pragma once

enum Display {
	WINDOW, FULLSCREEN
};

class EngineConfiguration
{
public:
	enum Display display;
	int res_x;
	int res_y;
	int fps;
	bool keyboard;
	bool mouse;
	static EngineConfiguration getDefaultConfig();
};

