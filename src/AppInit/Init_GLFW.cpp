#include "Init_GLFW.h"

NAMESPACE_BEGIN(AppInit)

GLFWwindow* window = NULL;
/*
Errors callback
*/



void error_callback(int error, const char* description)
{
	throw std::runtime_error(description);
}

void Init_GLFW::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//Managers::InputManager::getInstance().onKeyboardEvent(key, scancode, action, mods); //TODO remove dependency between core and managers
	//if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	//{
	//	glfwSetWindowShouldClose(window, GL_TRUE);
	//}

	//else if (key == GLFW_KEY_A && action == GLFW_PRESS)
	//{

	//}

}

void Init_GLFW::Init(const WindowSettings& winSettings, const GLContextInfo& context)
{
	m_winSettings = winSettings;
	glfwSetErrorCallback(error_callback);

	if (!glfwInit()){
		throw std::runtime_error("glfwInit failed");
	}

	// open a window with GLFW
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(winSettings.m_windowWidth, winSettings.m_windowHeight, winSettings.m_name.c_str(), NULL, NULL);

	if (!window){
		glfwTerminate();
		throw std::runtime_error("failed to create window");
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	AppInit::Init_GLEW::Init();

	// print out some info about the graphics drivers
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

	glfwSetKeyCallback(window, key_callback);
}

void Init_GLFW::Run()
{
	std::cout << "GLFW:\t Start Running  " << std::endl;
	while (!glfwWindowShouldClose(window))
	{
		DisplayCallback();

		// Poll for and process events 
		glfwPollEvents();
	}

	glfwTerminate();
}
void Init_GLFW::DisplayCallback()
{
	double time = glfwGetTime();
	double dt = time - m_lastUpdate;
	m_lastUpdate = time;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glfwSwapBuffers(window);

}


NAMESPACE_END