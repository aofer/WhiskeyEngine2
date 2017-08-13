#include "Application.h"
#include "GLContextInfo.h"
#include "Init_GLFW.h"
#include <Rendering/ShaderManager.h>
#include <Common/WELogger.h>

NAMESPACE_BEGIN(AppInit)

int Application::Init(ApplicationSettings settings)
{
	m_settings = settings;

	GLContextInfo context(4, 5, true);

	try {
		//Init Logger
		Logger::WELogger::GetInstance().Init();
		//LOG_ERROR("Initializing application");
		Init_GLFW glfwContext;
		glfwContext.Init(settings.m_winSettings, context);
		Rendering::ShaderManager::GetInstance().SetResourcesFolder(settings.m_resourcesFolder);
		
		glfwContext.Run();

	}
	catch (const std::exception& e) {
		//log here
		LOG_ERROR("Something went wrong with application init");
		return 1;
	}
	return 0;

}


NAMESPACE_END
