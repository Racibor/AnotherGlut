#pragma once

enum Display {
	WINDOW, FULLSCREEN
};

enum Resolution {
	HD, FHD
};

class EngineConfiguration
{
public:
	enum Display display;
	enum Resolution resolution;
	int fps;
	bool keyboard;
	bool mouse;
	static EngineConfiguration getDefaultConfig();
};

