#include "Application.h"
#include "GLContextInfo.h"
#include "Init_GLFW.h"

NAMESPACE_BEGIN(AppInit)

int Application::Init(ApplicationSettings settings)
{
	m_settings = settings;

	//WindowsInfo window(std::string("Shadow Mapping Demo"), 400, 200, WINDOW_WIDTH, WINDOW_HEIGHT, true);
	GLContextInfo context(4, 5, true);

	try {
		Init_GLFW glfwContext;
		glfwContext.Init(settings.m_winSettings, context);
		
		glfwContext.Run();

	}
	catch (const std::exception& e) {
		//log here
		return 1;
	}
	return 0;

}


NAMESPACE_END
