#pragma once
#include <Common/WECommon.h>
#include "Init_GLEW.h"
#include <GLFW\glfw3.h>
#include "ApplicationSettings.h"
#include "GLContextInfo.h"

NAMESPACE_BEGIN(AppInit)

class Init_GLFW
{
public:
	//void error_callback(int error, const char* description);
	void Init(const WindowSettings& winSettings, const GLContextInfo& context);
	void Run(void);
	void DisplayCallback(void);
private:

	WindowSettings m_winSettings;
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
public:

	double m_lastUpdate = 0.0;
};

NAMESPACE_END