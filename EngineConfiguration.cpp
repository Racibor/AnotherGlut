#include "EngineConfiguration.h"

EngineConfiguration EngineConfiguration::getDefaultConfig()
{
	EngineConfiguration conf = EngineConfiguration();
	conf.display = WINDOW;
	conf.res_x = 1280;
	conf.res_y = 720;
	conf.fps = 60;
	conf.keyboard = true;
	conf.mouse = true;
	return conf;
}
