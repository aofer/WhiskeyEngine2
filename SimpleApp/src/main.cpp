#include <AppInit/Application.h>

using namespace WhiskeyEngine;
int main(int argc, char *argv[])
{
	AppInit::ApplicationSettings settings;
	AppInit::WindowSettings winSettings;
	winSettings.m_windowHeight = 768;
	winSettings.m_windowWidth = 1024;
	winSettings.m_isReshapable = false;
	winSettings.m_isReshapable = "Simple Game";
	settings.m_winSettings = winSettings;
	AppInit::Application app;
	app.Init(settings);
	return 0;
}