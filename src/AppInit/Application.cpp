#include "Application.h"
#include "GLContextInfo.h"
#include "Init_GLFW.h"
#include <Rendering/ShaderManager.h>

NAMESPACE_BEGIN(AppInit)

int Application::Init(ApplicationSettings settings)
{
	m_settings = settings;

	GLContextInfo context(4, 5, true);

	try {
		Init_GLFW glfwContext;
		glfwContext.Init(settings.m_winSettings, context);
		Rendering::ShaderManager::getInstance().SetResourcesFolder(settings.m_resourcesFolder);
		
		glfwContext.Run();

	}
	catch (const std::exception& e) {
		//log here
		return 1;
	}
	return 0;

}


NAMESPACE_END
