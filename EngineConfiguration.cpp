#include "EngineConfiguration.h"

EngineConfiguration EngineConfiguration::getDefaultConfig()
{
	EngineConfiguration conf = EngineConfiguration();
	conf.display = WINDOW;
	conf.resolution = HD;
	conf.fps = 60;
	conf.keyboard = true;
	conf.mouse = true;
	return conf;
}
