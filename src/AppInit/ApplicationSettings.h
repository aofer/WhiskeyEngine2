#pragma once

#include <Common/WECommon.h>
#include <string>
NAMESPACE_BEGIN(AppInit)

struct WindowSettings 
{
	int m_windowHeight;
	int m_windowWidth;
	std::string m_name;
	int m_position_x, m_position_y;
	bool m_isReshapable;
};

struct ApplicationSettings
{
	WindowSettings m_winSettings;
	std::string		m_resourcesFolder;
};


NAMESPACE_END