#include "ShaderProgram.h"
#include <Common//WECommon.h>
#include <iostream>
#include <fstream>

NAMESPACE_BEGIN(Rendering)

//TODO: move this into a common util class
static std::string ReadFileIntoString(const std::string& filename)
{

	std::string content;
	std::ifstream file(filename, std::ios::in);

	if (!file.good()) {
		std::cout << "Can't read file " << filename.c_str() << std::endl;
		std::terminate();
	}

	file.seekg(0, std::ios::end);
	content.resize((unsigned int)file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&content[0], content.size());
	file.close();

	return content;
}

NAMESPACE_END